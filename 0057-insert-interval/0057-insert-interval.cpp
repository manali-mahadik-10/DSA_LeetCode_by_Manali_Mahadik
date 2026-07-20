class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        bool inserted = false;

        // Step 1: Insert newInterval into sorted position
        for (int i = 0; i < intervals.size(); i++) {
            if (!inserted && newInterval[0] <= intervals[i][0]) {
                temp.push_back(newInterval);
                inserted = true;
            }
            temp.push_back(intervals[i]);
        }
        if (!inserted) {
            temp.push_back(newInterval);
        }

        // Step 2: Merge intervals
        vector<vector<int>> res;
        int start = temp[0][0];
        int end = temp[0][1];

        for (int i = 1; i < temp.size(); i++) { // Fixed: using temp.size() instead of original n
            int s = temp[i][0];
            int e = temp[i][1];

            if (end >= s) {
                end = max(end, e);
            } else {
                res.push_back({start, end});
                start = s;
                end = e;
            }
        }
        res.push_back({start, end});
        return res;
    }
};