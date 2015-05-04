class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ans;
        string seg;
        int i = 1, start = 1;
        ans.push("/");
        while(i < path.length()) {
            if(path[i] != '/' && i < path.length() - 1) {
                ++i;
                continue;
            } else {
                seg = path.substr(start, i - start + 1);
                if((seg == "../" || seg == "..") && ans.top() != "/")
                    ans.pop();
                else if(seg != "../" && seg != "/" && seg != "./" && seg != "." && seg != "..")
                    ans.push(seg);
                ++i;
                start = i;
            }
        }
        seg = "";
        while(!ans.empty()) {
            seg = ans.top() + seg;
            ans.pop();
        }
        int L = seg.length();
        if(seg[L-1] == '/' && seg.length() > 1)
            seg = seg.substr(0, L-1);
        return seg;
    }
};