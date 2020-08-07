// class Solution {
// public:
//     int countSubstrings(string s) {
//         if (s.empty()) return 0;
//         int size = s.size(), res = 0;
//         vector<vector<bool>> dp(size, vector<bool>(size));
//         for (int i = size - 1; i >= 0; --i) {
//             for (int j = i; j < size; ++j) {
//                 dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
//                 if (dp[i][j]) ++res;            
//             }            
//         }
//         return res;
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int size = s.size(), res = 0;
        for (int i = 0; i < size; ++i) {
            helper(s, i, i, res);
            helper(s, i, i + 1, res);
        }
        return res;
    }

    void helper(string &s, int i, int j, int &res) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i, ++j, ++res;
        }
    }
};
