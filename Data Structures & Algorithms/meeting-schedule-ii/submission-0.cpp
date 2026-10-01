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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b)
        {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> rooms;
        for (auto interval: intervals)
        {
            auto start = interval.start;
            auto end = interval.end;

            if (!rooms.empty() && rooms.top() <= start)
            {
                rooms.pop();
            }
            rooms.push(end);
        }
        return rooms.size();
    }
};
