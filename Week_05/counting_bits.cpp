// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> res(num + 1);
//         for (int i = 1; i <= num; ++i)
//             res[i] = res[i >> 1] + (i & 1);
//         return res;
//     }
// };


class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        vector<int> dp(num + 1, 0);
        vector<int> step(30, 1);
        for(int i = 1; i < 30; i++) step[i] = step[i-1] * 2;
        int j = 0;
        for(int i = 1; i <= num; i++){
            if(step[j] == i) dp[i] = 1, j++;
            else dp[i] = dp[i-step[j-1]] + 1;
        }
        return dp;
    }
};