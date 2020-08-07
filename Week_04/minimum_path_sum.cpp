// 一维DP
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         if(m == 0 || n == 0)
//             return 0;
//         vector<int> dp(n);
//         // 初始化
//         dp[0]=grid[0][0];

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(i == 0 && j == 0) 
//                     continue;
//                 else if(i == 0)
//                     dp[j] = dp[j - 1] + grid[i][j];
//                 else if(j == 0)  
//                     dp[j] += grid[i][j];
//                 else
//                     dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
//             }
//         }
//         return dp[n - 1];
//     }
// };

// 二维DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) 
                    continue;
                else if(i == 0)
                    grid[i][j] += grid[i][j - 1];
                else if(j == 0)  
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
