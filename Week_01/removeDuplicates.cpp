class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0;
        for (int i = 1 ; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) nums[++slow] = nums[i]; 
        }
        return slow + 1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            nums[count++] = nums[i];
        }
        return count;
    }
};