class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int N = intervals.size();

        // Add all intervals that end before the newInterval starts
        while(i < N && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while(i < N && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Add the remaining intervals
        while(i < N){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
