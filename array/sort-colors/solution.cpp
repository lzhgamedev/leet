class Solution {
public:
    void sortColors(int A[], int n) {
        int *low = &A[0];
        int *high = &A[n-1];
        int *current = low;
        while(current <= high) {
            if(*current == 0 && current > low) {
                swap_val(low, current);
                low++;
            } 
            else if(*current == 2) {
                swap_val(high, current);
                high--;
            }
            else {
                current++;
            }
        }
    }
    void swap_val(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};