class Solution {
public:
    int minDistance(string word1, string word2) {
        int ans;
        int L1 = word1.length();
        int L2 = word2.length();
        int dp[L1+1][L2+1];
        
        for(int i = 0; i < L1+1; ++i) {
            dp[i][0] = i;
        }
        for(int j = 0; j < L2+1; ++j) {
            dp[0][j] = j;
        }
        for(int i = 1; i < L1+1; ++i) {
            for(int j = 1; j < L2+1; ++j) {
                int cost = (word1[i-1] == word2[j-1]) ? 0 : 1;
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1] + cost);
            }
        }
        
        return dp[L1][L2];
    }
};