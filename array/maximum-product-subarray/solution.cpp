class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int min_val = nums[0], max_val = nums[0];
        int max_prod = nums[0];
        for(int i = 1; i < length; i++) {
            int ta = min_val, tb = max_val;
            min_val = min(min(nums[i], tb * nums[i]), ta * nums[i]);
            max_val = max(max(nums[i], tb * nums[i]), ta * nums[i]);
            max_prod = max(max_val, max_prod);
        }
        return max_prod;
    }
};