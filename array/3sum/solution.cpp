class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<int> solution(3);
        vector<vector<int> > result;
        if(num.size() < 3)
            return result;
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size() - 2; ++i) {
            if(i > 0 && num[i] == num[i-1]) 
                continue;
            int left_val = -num[i];
            int begin = i + 1;
            int end = num.size() - 1;
            solution[0] = num[i];
            while(begin < end) {
                solution[1] = num[begin];
                solution[2] = num[end];
                if(solution[1] + solution[2] == left_val) {
                    result.push_back(solution);
                    while(begin < end && solution[1] == num[begin])
                        ++begin;
                    while(begin < end && solution[2] == num[end])
                        --end;
                }
                else if(solution[1] + solution[2] < left_val) {
                    ++begin;
                }
                else {
                    --end;
                }
            }
        }
        
        return result;
    }
};