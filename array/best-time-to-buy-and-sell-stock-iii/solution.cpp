class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = prices.size();
        if(count == 0)
            return 0;
        int L[count], R[count];
        int profit = 0;
        int min_val, max_val;
        min_val = prices[0];
        L[0] = 0;
        for(int i = 1; i < count; ++i) {
            L[i] = max(L[i-1], prices[i] - min_val);
            min_val = min(min_val, prices[i]);
        }
        max_val = prices[count-1];
        R[count-1] = 0;
        for(int i = count - 2; i >= 0; --i) {
            R[i] = max(R[i+1], max_val - prices[i]);
            max_val = max(max_val, prices[i]);
        }
        
        for(int i = 0; i < count - 1; ++i) {
            profit = max(profit, L[i] + R[i+1]);
        }
        profit = max(max(profit, L[count-1]), R[0]);
        return profit;
    }
};