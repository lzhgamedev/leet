class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int length = S.size();
        int loop = (1 << length) - 1;
        vector<vector<int> > result;
        sort(S.begin(), S.end());
        for(int i = 0; i <= loop; i++) {
            vector<int> record;
            for(int j = 0; j < length; j++) {
                int tmp = 1 << j;
                if(tmp & i) {
                    record.push_back(S[j]);
                }
            }
            result.push_back(record);
        }
        return result;
    }
};