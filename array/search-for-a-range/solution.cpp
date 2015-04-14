class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        int low = -1;
        int high = -1;
        int begin = 0;
        int end = n-1;
        while(begin <= end) {
            int mid = (begin + end) / 2;
            if(A[mid] == target) {
                low = mid;
                high = mid;
                break;
            }
            else if(A[mid] < target) {
                begin = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        while(low >= 1 && A[low-1] == target) {
             low--;
        }
        while(high <= n - 2  && A[high+1] == target) {
             high++;
        }
        result.push_back(low);
        result.push_back(high);
        return result;
    }
};