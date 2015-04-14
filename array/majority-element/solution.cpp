class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> maps;
        int result = 0;
        int count = 0;
        int length = num.size();
        for(int i = 0; i < length; ++i) {
            maps[num[i]]++;
            if(maps[num[i]] > count) {
                result = num[i];
                count = maps[num[i]];
            }
        }
        return result;
    }
};