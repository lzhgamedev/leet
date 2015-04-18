class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = begin;
        while(begin <= end && nums[begin] > nums[end]) {
            mid = (begin + end) / 2;
            if(nums[mid] > nums[mid+1]) {
                return nums[mid+1];
            } 
            else if(nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            if(nums[mid] < nums[begin]) {
                end = mid;
            }
            else if(nums[mid] > nums[begin]) {
                begin = mid;
            }
        }
        return nums[mid];
    }
};