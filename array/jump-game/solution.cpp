class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = nums[0];
        int target_index = nums.size() - 1;
        for(int i = 0; i <= max_index; i++){
            if(nums[i] + i > max_index)
                max_index = nums[i] + i;
            if(max_index >= target_index)
                return true;
        }
            return false;
    }
};