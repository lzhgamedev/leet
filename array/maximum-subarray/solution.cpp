class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int a[length];
        int max_sum;
        if(length == 0)
            return 0;
        max_sum = nums[0];
        a[0] = nums[0];
        for(int i = 1; i < length; i++) {
            a[i] = max(nums[i], nums[i] + a[i-1]);
            max_sum = max(a[i], max_sum);
        }
        return max_sum;
    }
};