class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(0, 0, s, p);
    }
    bool helper(int s_begin, int p_begin, string& s, string& p) {
        if(s_begin == s.length() && p_begin == p.length())
            return true;

        if(p[p_begin+1] == '*') {
            while((s[s_begin] == p[p_begin] || p[p_begin] == '.') && s_begin < s.length())  {
                if(helper(s_begin, p_begin + 2, s, p))
                        return true;
                s_begin++;
            }
            return helper(s_begin, p_begin + 2, s, p);
        }
        else {
            if(s[s_begin] == p[p_begin] || p[p_begin] == '.')
                return helper(s_begin+1, p_begin+1, s, p);
            else
                return false;
        }
    }

};