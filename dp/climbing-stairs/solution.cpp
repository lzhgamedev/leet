class Solution {
public:
    int climbStairs(int n) {
        int G[n+1];
        G[0] = 1;
        G[1] = 1;
        for(int i = 2; i <= n; ++i) {
            G[i] = G[i-2] + G[i-1];
        }
        return G[n];
    }
};