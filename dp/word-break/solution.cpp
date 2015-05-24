class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int L = s.length();
        bool dp[L+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for(int i = 1; i <= L; ++i) {
            for(int j = i; j <= L; ++j) {
                if(dp[j])
                    continue;
                if(wordDict.find(s.substr(i-1, j-i+1)) != wordDict.end() && dp[i-1]) {
                    dp[j] = true;
                }
            }
        }
        return dp[L];
    }
};