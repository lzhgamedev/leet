class Solution {
public:
    bool isPalindrome(string s) {
        s = convert(s);
        int L = s.length();
        if(L == 0) {
            return true;
        }
        int a = 0;
        int b = L - 1;
        while(a < b) {
            if(s[a] != s[b])
                return false;
            a++;
            b--;
        }
        return true;
    }
    string convert(string& s) {
        string ans;
        for(int i = 0; i < s.length(); ++i) {
            if(isalphanumeric(s[i]))
                ans += touppercase(s[i]);
        }
        return ans;
    }
    bool isalphanumeric(char a) {
        return (a >= 65 && a <= 90 || a >= 97 && a <= 122 || a >= 48 && a <= 57);
    }
    char touppercase(char a) {
        return a >= 97 ? a - 32 : a;
    }
};