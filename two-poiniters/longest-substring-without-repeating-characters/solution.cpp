class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = s.length();
        int max_len = 0;
        int p = 0, q = 0;
        int record[256];
        memset(record, 0, sizeof(record));
        while(q < L && p + max_len < L) {
            if(record[s[q]] == 0) {
                record[s[q]] = 1;
                q++;
            }
            else {
                record[s[p]] = 0;
                p++;
            }
            max_len = max(max_len, q-p);
        } 
        return max_len;
    }
};