// 先排序，然后直接返回前k个数
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort (arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};