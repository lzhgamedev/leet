class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int length = candidates.size();
        int index = 0;
        int left_value = target;
        int visit_0[length], record[length];
        vector<vector<int> > result;
        memset(record, 0, length * sizeof(int));
        memset(visit_0, 0, length * sizeof(int));
        sort(candidates.begin(), candidates.end());
        while(index >= 0)
        {
            if(index == length || candidates[index] > target)
            {
                index--;
                continue;
            }
            if(!visit_0[index]) {
                visit_0[index] = true;
                index++;
            }
            else if(candidates[index] <= left_value)
            {
                left_value -= candidates[index];
                record[index] += 1;
                index++;
                if(left_value == 0 )
                {
                    vector<int> ans;
                    for (int i = 0; i < length; i++)
                    {
                        if(candidates[i] > target)
                            break;
                        int j = record[i];
                        while (j > 0)
                        {
                            ans.push_back(candidates[i]);
                            j--;
                        }
                    }
                    result.push_back(ans);
                }
            }
            else
            {
                left_value += record[index] * candidates[index];
                record[index] = 0;
                visit_0[index] = 0;
                index--;
            }
        }
        return result;
    }
};