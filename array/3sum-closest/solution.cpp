class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int L = num.size();
        if(L < 3)
            return 0;
        int sum = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for(int i = 0; i < L - 2; i++) {
            int l = i + 1;
            int r = L - 1;
            while(l < r) {
                int three_sum = num[i] + num[l] + num[r];
                if(three_sum < target)
                    l++;
                else if(three_sum > target)
                    r--;
                else 
                    return target;
                if(abs(three_sum - target) < abs(sum - target))
                    sum = three_sum;
            }
        }
        return sum;
    }
};