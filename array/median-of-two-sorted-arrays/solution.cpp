class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int k = (m + n) / 2;
        
        if(m+n & 0x1)
            return findKthSortedArrays(nums1, 0, nums2, 0, k+1);
        else
           return  (findKthSortedArrays(nums1, 0, nums2, 0, k) + findKthSortedArrays(nums1, 0, nums2, 0, k+1)) / 2;
    }
    
    double findKthSortedArrays(vector<int>& nums1, int s_1, vector<int>& nums2, int s_2, int k) {
        int l_1 = nums1.size() - s_1;
        int l_2 = nums2.size() - s_2;
        if(l_1 > l_2) {
            return findKthSortedArrays(nums2, s_2, nums1, s_1, k);
        }
        if(l_1 == 0)
            return nums2[s_2+k-1];
        if(k == 1)
            return min(nums1[s_1], nums2[s_2]);
        int c_1 = min(k/2, l_1);
        int c_2 = k - c_1;
        int a = nums1[s_1+c_1-1];
        int b = nums2[s_2+c_2-1];
        if(a < b) {
            return findKthSortedArrays(nums1, s_1 + c_1, nums2, s_2, k - c_1);
        } else if(a > b) {
            return findKthSortedArrays(nums1, s_1, nums2, s_2 + c_2, k - c_2);
        } else {
            return a;
        }
    }
};