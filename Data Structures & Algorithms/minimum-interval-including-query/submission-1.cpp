class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());  
        // sort by left endpoint, then right endpoint

        int m = queries.size();
        vector<pair<int, int>> sortedQueries; 
        // {query value, original index}
        for (int i = 0; i < m; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(m, -1);

        // min-heap of {interval length, right endpoint}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int i = 0; // pointer for intervals

        for (auto& [q, idx] : sortedQueries) {
            // Add all intervals whose start <= current query
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                int len = r - l + 1;
                pq.push({len, r});
                i++;
            }

            // Remove intervals that cannot cover q anymore
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            // Top of heap is smallest valid interval
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};