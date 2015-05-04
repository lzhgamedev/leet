class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); ) {
            int val = nums[i];
            if(val > 0 && val <= nums.size() && val != nums[val - 1]) {
                swap(i, val - 1, nums);
            } else {
                ++i;
            }
        }
        for(int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            if(val != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
    void swap(int index_1, int index_2, vector<int>& nums) {
        int tmp = nums[index_1];
        nums[index_1] = nums[index_2];
        nums[index_2] = tmp;
    }
};