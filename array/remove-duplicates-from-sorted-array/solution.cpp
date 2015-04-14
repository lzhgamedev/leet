class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int *begin, *check;
        int count = 1;
        if(n <= 1)
            return n;
        begin = &A[0];
        check = &A[1];
        while(*check >= *begin && check <= &A[n-1]) {
            if(*check == *begin) {
                ++check;
            }
            else {
                swap_val(begin+1, check);
                ++check;
                ++begin;
                ++count;
            }
        }
        return count;
    }
    void swap_val(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};