class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int a[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j ==0) {
                    a[i][j] = grid[i][j];
                } else {
                    int left = j > 0 ? a[i][j-1] : 9999;
                    int top = i > 0 ? a[i-1][j] : 9999;
                    a[i][j] = min(left, top) + grid[i][j]; 
                }
            }
        }
        return a[m-1][n-1];
    }
};