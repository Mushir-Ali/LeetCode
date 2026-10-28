class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>v;
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(e>=intervals[i][0]){
                s = min(s,intervals[i][0]);
                e = max(e,intervals[i][1]);
            }
            else{
                v.push_back({s,e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        v.push_back({s,e});
        return v;
    }
};