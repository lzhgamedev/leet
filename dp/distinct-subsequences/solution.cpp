class Solution {
public:
    int numDistinct(string s, string t) {
        int l_s = s.size();
        int l_t = t.size();
        int dp[l_s+1][l_t+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < l_s+1; ++i) {
            dp[i][0] = 1;
        }
        for(int i = 1; i < l_s+1; ++i) {
            for(int j = 1; j < l_t+1; ++j) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[l_s][l_t];
    }
};