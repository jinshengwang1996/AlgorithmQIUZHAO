class Solution {
public:
    bool isMatch(string s, string p) {
        int size = s.size(), psize = p.size();
        vector<vector<bool>> dp(size+1, vector<bool>(psize+1, false));
        dp[0][0] = true;
        for(int i = 0; i <= size; i++){
            for(int j = 1; j <= psize; j++){
                if(p[j-1] != '*')
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                else
                    dp[i][j] = dp[i][j-1] || (i > 0 && dp[i-1][j]);
            }
        }
        return dp[size][psize];
    }
};