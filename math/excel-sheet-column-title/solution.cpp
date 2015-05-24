class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n > 0) {
            char cap[2] = {'\0', '\0'};
            int offset = n % 26;
            cap[0] = offset > 0 ? offset + 64 : 'Z';
            ans = cap + ans;
            n = n / 26;
            if(n > 0) {
                n = offset > 0 ? n : n - 1;
            }
        }
        return ans;
    }
};