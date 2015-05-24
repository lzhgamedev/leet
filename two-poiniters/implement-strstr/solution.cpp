class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if(n == 0)
            return 0; 
        if(m < n)
            return -1;
        int next[n+1];
        calNext(next, needle);
        int i = 0, j = 0;
        while(i < m) {
            while(haystack[i] == needle[j]) {
                if(j == n-1)
                    return i-j;
                i++;
                j++;
            }
            if(j == 0) {
                i++;
            } else {
                j = next[j];
            }
        }
        return -1;
        
    }
    void calNext(int* next, string& s) {
        int i, j;
        next[0] = 0;
        next[1] = 0;
        j = next[1];
        for(int i = 1; i < s.length(); ++i) {
            while(j > 0 && s[i] != s[j])
                j = next[j];
            if(s[i] == s[j])
                j++;
            next[i+1] = j;
        }
    }
};