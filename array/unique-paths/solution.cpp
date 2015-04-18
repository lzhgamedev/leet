class Solution {
public:
    int uniquePaths(int m, int n) {
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
                    a[i][j] = left + top;
                }
            }
        }
        return a[m-1][n-1];
    }
};