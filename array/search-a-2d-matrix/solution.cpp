class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0)
            return false;
        
        int begin = 0;
        int end = m - 1;
        int row = -1;
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if(target < matrix[mid][0])
                end = mid - 1;
            else if(target > matrix[mid][0])
                begin = mid + 1;
            else
                return true;
        }
        if(end >= 0) {
            row = end;
            begin = 0;
            end = n - 1;
        } else {
            return false;
        }
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if(target < matrix[row][mid])
                end = mid - 1;
            else if(target > matrix[row][mid])
                begin = mid + 1;
            else
                return true;
        }
        return false;
    }
};