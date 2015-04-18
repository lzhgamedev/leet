class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 )
            return 0;
        int **a = new int* [m];
        for(int i = 0; i < m; i++) {
            a[i] = new int[n];
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    a[i][j] = 1;
                else {
                    int left = i > 0 ? a[i-1][j] : 0;
                    int top = j > 0 ? a[i][j-1] : 0;
                    a[i][j] = obstacleGrid[j][i] == 1 ? 0 : left + top;
                }
            }
        }
        return a[m-1][n-1];
    }
};