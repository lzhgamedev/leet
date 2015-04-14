class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int *p_begin, *p_end;
        int count = 0;
        if(n == 0)
            return 0;
        p_begin = &A[0];
        p_end = &A[n-1];
        while(p_begin < p_end) {
            if(*p_end == elem) {
                --p_end;
            } 
            else if(*p_begin == elem) {
                swap_val(p_begin, p_end);
                ++p_begin;
                --p_end;
                ++count;
            } else {
                ++p_begin;
                ++count;
            }
            
        }
        if(*p_begin != elem)
            ++count;
        return count;
    }
    void swap_val(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};