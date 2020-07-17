class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int k = 0; k + 2 < nums.size(); ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            int l = k + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[k] + nums[l] + nums[r];

                if (sum > 0) {
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
                else if (sum < 0) {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                }
                else {
                    ans.push_back({nums[k], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;

                }
            }
        }
        return ans;
    }
};