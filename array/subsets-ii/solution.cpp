class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> ans;
        if(S.size() == 0)
            return result;
        sort(S.begin(), S.end());
        dfs(S, 0, ans);
        return result;
    }
    
    void dfs(vector<int> &S, int index, vector<int>& ans) {
        result.push_back(ans);
        for(int i = index; i < S.size(); ++i) {
            if(i > index && S[i] == S[i-1])
                continue;
            ans.push_back(S[i]);
            dfs(S, i+1, ans);
            ans.pop_back();
        }
    }
};