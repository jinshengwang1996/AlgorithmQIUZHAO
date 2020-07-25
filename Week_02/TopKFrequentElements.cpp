// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> map;
//         for(int i : nums) map[i] ++; //遍历
//         priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q; //最小堆
//         for(auto it : map) 
//             if(q.size() == k) { //队列满了
//                 if(it.second > q.top().first) { //堆排
//                     q.pop();
//                     q.push(make_pair(it.second, it.first));
//                 }
//             }
//             else q.push(make_pair(it.second, it.first));
//         vector<int> res;
//         while(q.size()) { //将优先队列中k个高频元素存入vector
//             res.push_back(q.top().second);
//             q.pop();
//         }
//         return vector<int>(res.rbegin(), res.rend());
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i : nums) map[i] ++;
        vector<pair<int,int>> res;
        for(auto it : map) res.push_back(make_pair(it.second, it.first));
        sort(res.begin(), res.end());
        for(int i = 1; i <= k; i ++) nums.push_back(res[res.size() - i].second);
        return vector<int>(nums.end() - k, nums.end());
    }
};
