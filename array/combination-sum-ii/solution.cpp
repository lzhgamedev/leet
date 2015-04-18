class Solution {
public:
    vector<int> record;
    vector<vector<int> > result;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        helper(0, target, num);
        return result;
    }
    void helper(int index, int target, vector<int> &num) {
        if (target == 0) {
            result.push_back(record);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            if (num[i] > target) {
                return;
            }
            if (i > index && num[i] == num[i-1]) {
                continue;
            }
            record.push_back(num[i]);
            helper(i+1, target-num[i], num);
            record.pop_back();
        }
    }
};