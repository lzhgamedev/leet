class Solution {
public:
    bool search(int A[], int n, int target) {
        int begin = 0;
        int end = n - 1;
        
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if(A[mid] == target || A[begin] == target || A[end] == target) {
                return true;
            }
            if(A[mid] < A[end]) {
                if(target > A[mid] && target < A[end])
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
            else if(A[mid] > A[end]) {
                if(target < A[mid] && target > A[end])
                    end = mid - 1;
                else
                    begin = mid + 1;
            }
            else
                end--;
        }
        return false;
    }
};