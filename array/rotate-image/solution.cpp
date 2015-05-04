class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cycle;
        if(n & 0x1)
            cycle = n / 2 + 1;
        else
            cycle = n / 2;
        for(int i = 0; i < cycle; ++i) {
            for(int j = i; j < n - i - 1; ++j) {
                swap(i, j, n - 2*i, matrix);
            }
        }
    }
    void swap(int i, int j, int length, vector<vector<int>>& matrix) {
        int tmp;
        int offset = j - i;
        tmp = matrix[i][j];
        matrix[i][j] = matrix[length-1+i-offset][i];
        matrix[length-1+i-offset][i] = matrix[length-1+i][length-1+i-offset];
        matrix[length-1+i][length-1+i-offset] = matrix[i+offset][length-1+i];
        matrix[i+offset][length-1+i] = tmp;
    }
};