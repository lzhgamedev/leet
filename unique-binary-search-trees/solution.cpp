class Solution {
public:
    int numTrees(int n) {
        int* solve = new int [n+1];
        solve[0] = 1;
        solve[1] = 1;
        //solve[n] = root(1, n) + root(2, n) + ... root(n,n);
        //root(i, j) = solve[i-1] * solve[j-i];
        for(int j = 2; j <= n; j++) {
            solve[j] = 0;
            for(int i = 1; i <= j ; i++) {
                solve[j] += solve[i-1] * solve[j-i];
            }
        }
        return solve[n];
    }
};