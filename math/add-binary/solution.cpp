class Solution {
public:
    string addBinary(string a, string b) {
        int ans = 0;
        int l_a = a.length();
        int l_b = b.length();
        int L = max(l_a, l_b);
        string res;
        int add = 0;
        for(int i = 1; i <= L; ++i) {
            int m = l_a-i >= 0 ? atoi(a.substr(l_a-i,1).c_str()) : 0;
            int n = l_b-i >= 0 ? atoi(b.substr(l_b-i,1).c_str()) : 0;
            ans = m + n + add;
            add = ans / 2;
            res = to_string(ans % 2) + res;
        }
        if(add > 0)
            res = "1" + res;
        return res;
    }
};