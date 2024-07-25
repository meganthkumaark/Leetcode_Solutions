class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            int lastStart = merged.back()[0];
            int lastEnd = merged.back()[1];
            if (currentStart <= lastEnd) {
                merged.back()[1] = max(lastEnd, currentEnd);
            } else {
                merged.push_back({currentStart, currentEnd});
            }
        }
        return merged;
    }
};