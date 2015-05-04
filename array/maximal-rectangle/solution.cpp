class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int M = matrix.size();
        if(M == 0)
            return 0;
        int N = matrix[0].size();
        if(N == 0)
            return 0;
        pair<int, int> dp[M][N];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(matrix[i][j] == '0')
                    continue;
                int x = 1, y = 1; 
                if(i > 0) y += dp[i-1][j].second;
                if(j > 0) x += dp[i][j-1].first;
                dp[i][j] = make_pair(x, y);
                int min_height = y;
                for(int k = j; k > j - x; --k) {
                    min_height = min(min_height, dp[i][k].second);
                    ans = max(ans, min_height * (j - k + 1));
                }
            }
        }
        return ans;
    }
};