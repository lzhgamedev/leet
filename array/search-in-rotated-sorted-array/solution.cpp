class Solution {
public:
    int search(int A[], int n, int target) {
        int begin = 0;
        int end = n - 1;
        int index = -1;
        while(begin < end && A[begin] > A[end]) {
           int mid = (begin + end) / 2;
           if(A[mid] < A[mid-1]) {
               begin = mid;
               end = n + mid - 1;
               break;
           }
           if(A[mid] > A[mid+1]) {
               begin = mid + 1;
               end = n + mid;
               break;
           }
           if(A[mid] > A[begin]) {
               begin = mid;
           }
           if(A[mid] < A[begin]) {
               end = mid;
           }
        }
        
        while(begin <= end) {
            int mid = (begin + end) / 2;
            if(A[mid % n] == target) {
                index = mid % n;
                break;
            }
            else if(A[mid % n] < target) {
                begin = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return index;
    }
};