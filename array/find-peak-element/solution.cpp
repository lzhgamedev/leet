class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int begin = 0;
        int end = num.size() - 1;
        int target;
        while(begin <= end) {
            target = (begin + end) / 2;
            if(checkValid(target, num)) {
                break;
            }
            if(num.at(target) <= num.at(begin) && target != begin ||
                num.at(target) > num.at(begin) && num.at(target) < num.at(target-1)) {
                end = target - 1;
            }
            else if(num.at(target) <= num.at(end) && target != end ||
                num.at(target) > num.at(end) && num.at(target) < num.at(target+1)) {
                begin = target + 1;
            }
        }
        return target;
    }
    
    bool checkValid(int index, const vector<int> &num) {
        int val = num.at(index);
        if(num.size() == 1)
            return true;
        if(index == 0 && val > num.at(1) ||
            index == num.size() - 1 && val > num.at(index-1))
            return true;
        if(index > 0 && index < num.size() - 1 &&
            val > num.at(index-1) && val > num.at(index+1))
            return true;
        return false;
    }
    
};