class Solution {
public:
    void nextPermutation(vector<int> &num) {
        for(int i = num.size() - 2; i >= 0; i--) {
            if(num[i] < num[i+1]) {
                for(int j = num.size() - 1; j > i; j-- ) {
                    if(num[j] > num[i]) {
                        swap(&num[i], &num[j]);
                        sort(num.begin() + i + 1, num.end());
                        return;
                    }
                }
            }
        }
        sort(num.begin(), num.end());
        return;
    }
    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};