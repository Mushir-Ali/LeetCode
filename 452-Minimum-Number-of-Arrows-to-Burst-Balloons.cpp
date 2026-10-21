class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int s = points[0][0];
        int e = points[0][1];
        int ans = 1;
        for(int i=1;i<n;i++){
            if(points[i][0]<=e){
                s = max(s,points[i][0]);
                e = min(e,points[i][1]);
            }
            else{
                ans++;
                s = points[i][0];
                e = points[i][1];
            }
        }
        return ans;
    }
};