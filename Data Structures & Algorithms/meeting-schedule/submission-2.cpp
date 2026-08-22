/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

        int i = 0;
        while(i < intervals.size() - 1)
        {
            if (intervals[i + 1].start < intervals[i].end) return false;
            ++i;
        }
        return true;
    }
};
