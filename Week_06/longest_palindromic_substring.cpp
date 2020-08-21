class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int start = 0, maxlen = 1, n = s.size();
        vector<vector<int>> dp (n,vector<int>(n));
        for(int i = 0; i < n; ++i) dp[i][i] = true;        
        for(int j = 1; j < n; ++j) {
            for(int i = 0; i < j; ++i) {
                if(s[i] != s[j]) dp[i][j] = false;
                else {
                    if((j-1) - (i+1) + 1 < 2) dp[i][j] = true;    
                    else {
                        if(dp[i+1][j-1]) dp[i][j] = true;        
                    }
                }
                if(dp[i][j] && j - i + 1 > maxlen) {
                    start = i;
                    maxlen = j - i + 1;  
                }  
            }
        }
        return s.substr(start,maxlen);
    }
};