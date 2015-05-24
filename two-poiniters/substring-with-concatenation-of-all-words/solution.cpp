class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) return res;
        unordered_map<string, int> need;
        for (int i = 0; i < L.size(); ++i)
            need[L[i]]++;
        int n = L[0].length(), m = L.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> find;
            for (int start = i, end = i, count = 0; end + n <= S.length(); end += n) {
                string str = S.substr(end, n);
                auto it = need.find(str);
                if (it == need.end()) {
                    start = end + n;
                    find.clear();
                    count = 0;
                    continue;
                }
                while (find.find(str) != find.end() && find[str] >= need[str]) {
                    string subStart = S.substr(start, n);
                    find[subStart]--;
                    start += n;
                    --count;
                }
                find[str]++;
                ++count;
                if (count != m) continue;
                res.push_back(start);
            }
        }
        return res;
    }
};