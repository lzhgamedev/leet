class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = begin;
        
        while(begin < end) {
            mid = (begin + end) / 2;
            if(nums[mid] > nums[mid+1] && mid+1 <= end) {
                return nums[mid+1];
            } 
            else if(nums[mid] < nums[mid-1] && mid-1 >= begin) {
                return nums[mid];
            }
            if(nums[mid] < nums[end]) {
                end = mid;
            }
            else if(nums[mid] > nums[end]) {
                begin = mid+1;
            }
            else {
                end--;
            }
        }
        return nums[mid];
    }
};