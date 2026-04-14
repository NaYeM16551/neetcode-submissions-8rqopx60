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
        int n = intervals.size();
        if(n==0)return 0;

        int maxEnd = INT_MIN;

        for(auto& interval : intervals)
        {
            maxEnd=max(maxEnd,interval.end);
        }

        vector<int> sweepLine(maxEnd+2,0);

        for(auto& interval:intervals)
        {
            sweepLine[interval.start]++;
            sweepLine[interval.end]--;

        }

        int sum = 0;
        int maxSum = sum;

        for(int i=0;i<=maxEnd+1;++i)
        {
            sum+=sweepLine[i];
            maxSum=max(sum,maxSum);
        }

        return maxSum;
    }
};
