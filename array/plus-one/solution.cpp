class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int length = digits.size();
        digits.at(length - 1) += 1;
        for(int i = length - 1; i >= 0; i--) {
            int res = digits.at(i);
            int high = res / 10;
            int low = res % 10;
            digits.at(i) = low;
            if(high > 0 && i == 0)
                digits.insert(digits.begin(), high);
            else if(i > 0)
                digits.at(i-1) += high;
        }
        return digits;
    }
};