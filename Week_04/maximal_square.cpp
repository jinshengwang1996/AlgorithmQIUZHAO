class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            ans = max(ans, matrix[i][0] - '0');
        }
        for(int j=0; j<n; j++){
            ans = max(ans, matrix[0][j] - '0');
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == '1'){
                    matrix[i][j] = 1+ min(min(matrix[i][j-1], matrix[i-1][j]),matrix[i-1][j-1]);
                    ans = max(ans, (matrix[i][j]-'0') * (matrix[i][j] - '0'));
                }
            }
        }
        return ans;
    }
};
