class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int>* last = new vector<int> (1, 1);
        
        if(numRows == 0)
            return result;
        result.push_back(*last);
        for(int i = 2; i <= numRows; ++i) {
            vector<int> current(i, 1);
            for(int j = 1; j < i - 1; ++j) {
                current.at(j) = (*last).at(j-1) + (*last).at(j);
            }
            result.push_back(current);
            last = &result.back();
        }
        return result;
    }
};