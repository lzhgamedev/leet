class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_contain = 0;
        int pre_height = -1;
        int begin = 0, end = height.size() - 1;
        int current;
        while(begin < end) {
            if(height.at(begin) > height.at(end) ) {
              checkFromLeft(begin, end, max_contain, height);
            }
            else{
              checkFromRight(end, begin, max_contain, height);
            }        
        }
        return max_contain;
    }
    
    void checkFromLeft(int &begin, int &end, int &max_contain, vector<int> &height) {
        for(int i = end ; i >= begin + 1 ; --i) {
            if(height.at(begin) == 0)
                break;
            if(height.at(i) <= height.at(end) && i != end)
               continue;
            int contain = min(height.at(begin), height.at(i)) * (i - begin);
            max_contain = max(max_contain, contain);
        }
        int check = begin + 1;
        while(height.at(check) <= height.at(begin) && check < end)
            check++;
        begin = check;
    }
    
    void checkFromRight(int &begin, int &end, int &max_contain, vector<int> &height) {
        for(int i = end ; i <= begin - 1 ; ++i) {
            if(height.at(begin) == 0)
                break;
            if(height.at(i) <= height.at(end) && i != end)
               continue;
            int contain = min(height.at(begin), height.at(i)) * (begin - i);
            max_contain = max(max_contain, contain);
        }
        int check = begin - 1;
        while(height.at(check) <= height.at(begin) && check > end)
            check--;
        begin = check;
    }
};