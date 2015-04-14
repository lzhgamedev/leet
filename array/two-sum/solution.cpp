class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> answers;
        map<int, int> num_map;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(num_map.find(target-numbers[i]) != num_map.end())
            {
                answers.push_back(num_map[target-numbers[i]]+1);
                answers.push_back(i+1);
                break;
            }
            num_map[numbers[i]] = i;
        }
        return answers;
    }
};