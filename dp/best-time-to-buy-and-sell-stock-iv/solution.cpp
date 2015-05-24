class Solution {
public:
    int maxProfit_all(vector<int> &prices) {
        int n = prices.size();
        int sum = 0;
        for(int i = 1;i < n;i++){
            if(prices[i] > prices[i-1]){
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        int l[length+1] = {0};
        int g[length+1] = {0};
        if(k >= length/2){
            return maxProfit_all(prices);    
        }
        for(int i = 1; i < length; ++i) {
            int diff = prices[i] - prices[i-1];
            for(int j = k; j >= 1; --j) {
                l[j] = max(g[j-1]+max(0, diff), l[j]+diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }

};