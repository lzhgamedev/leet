class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length == 0)
            return 0;
        int min_val = prices[0];
        int profit[length];
        profit[0] = 0;
        for(int i = 1; i < length; i++) {
            profit[i] = max(profit[i-1], prices[i] - min_val);
            min_val = min(min_val, prices[i]);
        }
        return profit[length-1];
    }
};