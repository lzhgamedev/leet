class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index_a = 0, index_b = 0;
        int length_a = m;
        while(index_a < length_a && index_b < n) {
            if(A[index_a] <= B[index_b]) {
                ++index_a;
            } else {
                insert(A, length_a, index_a, B[index_b]);
                ++length_a;
                ++index_a;
                ++index_b;
            }
        }
        while(index_b < n) {
            A[length_a++] = B[index_b++];
        }
    }
    void insert(int A[], int length, int index, int val) {
        while(length > index) {
            A[length] = A[length-1];
            --length;
        }
        A[index] = val;
    }
};