class Solution {
public:
    string minWindow(string s, string t) {
        int M = s.length();
        int N = t.length();
        if(M < N)
            return "";
        int check[256];
        int need[256];
        int begin = 0, end = 0;
        int count = 0;
        int m=0, n=M;
        memset(need, 0, sizeof(need));
        memset(check, 0, sizeof(check));
        for(int i = 0; i < N; ++i) {
            need[t[i]] += 1;
        }
        for(;end < M; ++end) {
            if(need[s[end]] == 0)
                continue;
            if(check[s[end]] < need[s[end]]) {
                ++count;
            }
            check[s[end]] += 1;
            if(count < N)
                continue;
            for(;begin <= end; begin++) {
                if(need[s[begin]] == 0)
                    continue;
                if(check[s[begin]] <= need[s[begin]]) 
                    break;
                else if(check[s[begin]] > 0)
                    check[s[begin]]--;
            }
            if(n-m > end-begin) {
                n = end;
                m = begin;
            }
        }
        return n!=M ? s.substr(m, n-m+1) : "";
    }
};