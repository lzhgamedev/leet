class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin, end , mid, index;
        begin = 0;
        end = n - 1;
        while(begin <= end) {
            mid = (begin + end) / 2;
            if(A[mid] == target) {
                index = mid;
                break;
            }
            if(A[mid] > target) {
                index = mid;
                end = mid - 1;
            }
            if(A[mid] < target) {
                index = mid + 1;
                begin = mid + 1;
            }
        }
        return index;
    }
};