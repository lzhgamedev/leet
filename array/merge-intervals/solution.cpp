/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int length = intervals.size();
        if(length <= 1) 
            return intervals;
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), compare);
        Interval last = intervals[0];
        for(int i = 1; i < length; i++) {
            if(intervals[i].start > last.end) {
                ans.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        ans.push_back(last);
        return ans;
    }
};