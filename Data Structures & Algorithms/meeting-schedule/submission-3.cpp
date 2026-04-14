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
        if (intervals.empty())
            return true;
        
        int maxi = INT_MIN;

        for (auto& i : intervals)
            maxi = max(maxi, i.end);

        // Use a vector instead of a static array and initialize it with zeros
        vector<int> overlappingArray(maxi + 1, 0);

        for (auto& i : intervals) {
            overlappingArray[i.start]++;
            overlappingArray[i.end]--;
        }  

        int sum = 0;

        for (int i = 0; i < maxi + 1; ++i) {
            sum += overlappingArray[i];
            if (sum >= 2)
                return false;
        }
        return true;
    }
};
