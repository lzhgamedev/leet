class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int step_index = nums[0];
        int jumpable_index = step_index;
        int step = 1;
        for(int i = 0; i < nums.size(); i++) {
            jumpable_index = max(jumpable_index, i + nums[i]);
            if(i == step_index) {
                if(i != nums.size() - 1)
                    ++step;
                step_index = jumpable_index;
            }
        }
        return step;
    }
};