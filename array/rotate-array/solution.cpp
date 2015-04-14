class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int *temp = new int[n];
        k = k % n;
        for(int i = 0; i < k; i++) {
            temp[i] = nums[n-k+i];
        }
        for(int i = 0; i < n - k; i++) {
            nums[n-1-i] = nums[n-1-i-k];
        }
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};