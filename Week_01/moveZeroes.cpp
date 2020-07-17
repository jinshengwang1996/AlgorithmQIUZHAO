class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        for ( ; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) swap(nums[fast], nums[slow++]);
        }
    }
};