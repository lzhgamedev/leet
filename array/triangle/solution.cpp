class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> record(1, triangle[0][0]);
        int height = triangle.size();
        int pre_val = 0;
        int min_sum = triangle[0][0];
        for(int i = 1; i < height; i++) {
            for(int j = 0; j < i + 1; j++) {
                int left = j > 0 ? pre_val : record[j];
                int right = j < i ? record[j] : pre_val;
                if(j < i) {
                    pre_val = record[j];
                    record[j] = triangle[i][j] + min(left, right);
                }
                else {
                    record.push_back(triangle[i][j] + min(left, right));
                }
                if(i == height - 1) {
                    min_sum = j == 0 ? record[0] : min(record[j], min_sum);
                }
            }
        }
        return min_sum;
    }
};