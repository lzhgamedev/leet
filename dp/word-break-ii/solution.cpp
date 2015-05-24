class Solution {
public:
    vector<string> ans;
    string record;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int L = s.length();
        if (!wordBreakPossible(s, wordDict)) return ans;
        helper(s, 0, wordDict);
        return ans;
    }
    void helper(string& s, int index, unordered_set<string>& wordDict) {
        if(index == s.length()) {
            string e = record.substr(0, record.length()-1); 
            ans.push_back(e);
        }
        for(int i = index; i < s.length(); ++i) {
            if(wordDict.find(s.substr(index, i-index+1)) != wordDict.end()) {
                string e = s.substr(index, i-index+1) + " ";
                record += e;
                helper(s, i+1, wordDict);
                record = record.substr(0, record.length()-e.length());
            }
        }
    }
    bool wordBreakPossible(const string &s, const unordered_set<string> &dict) {
        int N = s.size();
        bool canBreak[N+1];
        memset(canBreak, false, sizeof(canBreak));
        canBreak[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[N];
    }
};