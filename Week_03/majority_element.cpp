// using hashmap to solve, then traversal the whole map to find the majority number
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> hashmap;
//         for (auto num : nums) if (++hashmap[num] > nums.size() / 2) return num;
//         return -1;
//     }
// };

// class Solution {
// public: 
//     int majorityElement(vector<int>& nums) {
//         int res = 0, max_times = 0;
//         unordered_map<int, int> hashmap;
//         for (auto num : nums) {
//             if (++hashmap[num] > max_times) {
//                 max_times = hashmap[num];
//                 res = num;
//             }
//         }
//         return res;
//     }
// };

// sort the nums, then pick the num at n / 2
class Solution {
public: 
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};