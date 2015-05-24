class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length();
        int n = s.length();
        int count = std::count(p.begin(), p.end(), '*');
        if(m - count > n)
            return false;
        bool dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1; i < m+1; ++i) {
            dp[i][0] = (p[i-1] == '*') && dp[i-1][0] ? true : false;
        }
        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < n+1; ++j) {
                if((dp[i-1][j] || dp[i][j-1]) && p[i-1] == '*') {
                    dp[i][j] = true;
                } else if((p[i-1] == '?' || s[j-1] == p[i-1]) && dp[i-1][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[m][n];

    }
};