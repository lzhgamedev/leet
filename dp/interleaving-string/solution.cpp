class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int L1 = s1.length();
        int L2 = s2.length();
        bool dp[L1+1][L2+1];
        
        if(L1 == 0) 
            return s2 == s3;
        if(L2 == 0)
            return s1 == s3;
        if(L1 + L2 != s3.length())
            return false;
        
        for(int i = 1; i <= L1; ++i) {
            dp[i][0] = s1.substr(0,i) == s3.substr(0,i);
        }
        for(int j = 1; j <= L2; ++j) {
            dp[0][j] = s2.substr(0,j) == s3.substr(0,j);
        }
        for(int i = 1; i <= L1; ++i) {
            for(int j = 1; j <= L2; ++j) {
                dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1] || dp[i-1][j] && s1[i-1] == s3[i+j-1];
            }
        }
        return dp[L1][L2];
    }
};