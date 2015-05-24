class Solution {
public:
    int longestValidParentheses(string s) {
          int ans = 0;
          int l = s.length();
          int dp[l];
          memset(dp, 0, sizeof(dp));
          for(int i = 0; i < l; ++i) {
              if(s[i] == '(') 
                  continue;
              int j = i - 1;
              while(j >= 0) {
                  if(dp[j] > 0)
                    j -= dp[j];
                  else if(s[j] == ')')
                    break;
                  else if(s[j] == '(') {
                      dp[i] = i - j + 1 + (j >= 1 ? dp[j-1] : 0);
                      ans = max(dp[i], ans);
                      break;
                  }
              }
          }
          return ans;
    }
};