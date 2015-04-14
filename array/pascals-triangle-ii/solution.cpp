class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(1,1);
        vector<int>::iterator iter;
        int pre_val, temp_val;
        if(rowIndex == 0)
            return result;
        while(rowIndex > 0) {
            --rowIndex;
            iter = result.begin() + 1;
            pre_val = 1;
            while(iter != result.end()) {
                temp_val = *iter;
                *iter = *iter + pre_val;
                pre_val = temp_val;
                ++iter;
            }
            result.push_back(1);
        }
        return result;
    }
};