class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int L = nums.size();
        int G[L];
        int m = 0;
        for(int i = 0; i < L; ++i) {
            int k = 0;
            for(int j = max(0, i-3); j < i - 1; ++j) {
                k = max(k, G[j]);
            }
            G[i] = k + nums[i];
            m = max(m, G[i]);
        }
        return m;
    }
};