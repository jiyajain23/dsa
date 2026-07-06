class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int minus = 0;
        int n = intervals.size();
        for (int i = 0; i < n - 1; i++) {
            if (intervals[i + 1][0] == intervals[i][0]) {
                if (intervals[i + 1][1] >= intervals[i][1]) {
                    minus++;
                    continue;
                } else {
                    minus++;
                    intervals[i + 1][0] = intervals[i][0];
                    intervals[i + 1][1] = intervals[i][1];
                }
            } else {
                if (intervals[i + 1][1] <= intervals[i][1]) {
                    minus++;
                    intervals[i + 1][0] = intervals[i][0];
                    intervals[i + 1][1] = intervals[i][1];
                }
            }
        }
        return n - minus;
    }
};