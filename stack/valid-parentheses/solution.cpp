class Solution {
public:
    stack<char> list;
    bool isValid(string s) {
        int L = s.length();
        int i = 0;
        while(i < L) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                list.push(s[i]);
            else if(!list.empty() && (s[i] == ')' && list.top() == '(' ||
                    s[i] == ']' && list.top() == '[' ||
                    s[i] == '}' && list.top() == '{'))
                    list.pop();
            else
                return false;
            i++;
        }
        if(list.empty())
            return true;
        else
            return false;
    }
};