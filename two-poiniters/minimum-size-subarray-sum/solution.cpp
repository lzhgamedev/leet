class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        int L = nums.size();
        int ans = L + 1;
        if(L == 0)
            return 0;
        while(i <= L) {
            if(sum >= s) {
                ans = min(ans, i-j);
                if(ans == 1)
                    break;
                sum -= nums[j];
                j++;
            } else {
                sum += nums[i];
                ++i;
            }
        }
        return ans <= nums.size() ? ans : 0;
    }
};