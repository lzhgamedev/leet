class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int *begin = &A[0];
        int *check = &A[1];
        int length = 1;
        int same_count = 0;
        if(n <= 1)
            return n;
        while(*begin <= *check && check <= &A[n-1]) {
            if(*begin == *check && same_count == 0 || *begin < *check) {
                if(same_count == 0) {
                    same_count = 1;
                }
                if(*begin < *check ) {
                    same_count = 0;
                }
                swap(begin+1,check);
                length++;
                begin++;
                check++;
            }
            else {
                check++;
            }
        }
        return length;
    }
    
    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};