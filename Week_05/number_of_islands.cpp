// // BFS
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.empty() || grid[0].empty())
//             return 0;
//         queue<pair<int, int>> q;
//         int r = grid.size(), c = grid[0].size(), ans = 0;
//         for(int i = 0; i < r; i++) {
//             for(int j = 0; j < c; j++) {
//                 if(grid[i][j] == '1') {
//                     grid[i][j] = '0';
//                     ans++;
//                     q.push({i, j});
//                 }
//                 while(!q.empty()) {
//                     auto t = q.front();
//                     int x = t.first, y = t.second;
//                     q.pop();
//                     if(x - 1 >= 0 && grid[x-1][y] == '1') {
//                         q.push({x - 1, y});
//                         grid[x-1][y] = '0';
//                     }
//                     if(x + 1 < r && grid[x+1][y] == '1') {
//                         q.push({x + 1, y});
//                         grid[x+1][y] ='0';
//                     }
//                     if(y - 1 >= 0 && grid[x][y-1] == '1') {
//                         q.push({x, y - 1});
//                         grid[x][y-1] = '0';
//                     }
//                     if(y + 1 < c && grid[x][y+1] == '1') {
//                         q.push({x, y + 1});
//                         grid[x][y+1]='0';
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
// DFS
class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int l = grid.size(), r = grid[0].size();
        grid[i][j] = '0';
        if(i+1<l&&grid[i+1][j]=='1') dfs(i+1,j,grid);
        if(i-1>=0&&grid[i-1][j]=='1') dfs(i-1,j,grid);
        if(j+1<r&&grid[i][j+1]=='1') dfs(i,j+1,grid);
        if(j-1>=0&&grid[i][j-1]=='1') dfs(i,j-1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if(grid.size() == 0) return 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                } 
            }
        }
    return ans;
    }
};
