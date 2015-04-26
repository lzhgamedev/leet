class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> ans(4);
        if(num.size() < 4)
            return result;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 3; ++i) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            ans[0] = num[i];
            for(int j = i + 1; j < num.size() - 2; ++j) {
                if(j > i + 1 && num[j] == num[j-1])
                    continue;
                ans[1] = num[j];
                int begin = j + 1;
                int end = num.size() - 1;
                int left_val = target - ans[0] - ans[1];
                while(begin < end) {
                    ans[2] = num[begin];
                    ans[3] = num[end];
                    if(ans[2] + ans[3] == left_val) {
                        result.push_back(ans);
                        while(num[begin] == ans[2] && begin < end) 
                            begin++;
                        while(num[end] == ans[3] && begin < end)
                            end--;
                    }
                    else if(ans[2] + ans[3] < left_val) {
                        begin++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }
        return result;
    }
};