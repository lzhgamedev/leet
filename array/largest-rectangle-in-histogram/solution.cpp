class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ans = 0;
        int L = height.size();
        for(int i = 0; i < L; ++i) {
            if(i < L - 1 && height[i] <= height[i+1])
                continue;
            int min_height = height[i];
            for(int j = i; j >= 0; --j) {
                min_height = min(height[j], min_height);
                int area = min_height * (i - j + 1);
                ans = max(ans, area);
            }
        }
        return ans;
    }
};