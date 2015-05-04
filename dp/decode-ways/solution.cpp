class Solution {
public:
    int numDecodings(string s) {
        string seg;
        int num;
        int n = s.length();
        if(n == 0)
            return 0;
        int dp[n+1];
        memset(dp, 0, (n+1) * sizeof(int));
        dp[0]=1;
        for(int i = 1; i <= n; ++i) {
            seg = s.substr(i-1, 1);
            num = atoi(seg.c_str());
            if(num >= 1 && num <= 9)
                dp[i] += dp[i-1];
            
            if(i == 1)
                continue;
            seg = s.substr(i-2, 2);
            num = atoi(seg.c_str());
            if(num <= 26 && num >= 10)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};