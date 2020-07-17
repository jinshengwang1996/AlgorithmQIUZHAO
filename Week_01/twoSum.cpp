class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = nums;
        int l = 0, r = nums.size() - 1;
        vector<int> ans;

        sort(nums.begin(), nums.end());
        while (l < r) {
            if (nums[l] + nums[r] == target) break;
            else if (nums[l] + nums[r] > target) --r;
            else ++l;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (v[i] == nums[l] || v[i] == nums[r]) ans.push_back(i);
        }
        return ans;
    }
};