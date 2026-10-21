
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tg = accumulate(gas.begin(),gas.end(),0);
        int tc = accumulate(cost.begin(),cost.end(),0);
        if(tg<tc) return -1;
        int total = 0;
        int ind = 0;
        for(int i=0;i<n;i++){
            total = total + gas[i] - cost[i];
            if(total<0){
                total = 0;
                ind = i+1;
            }
        }
        return ind;
    }
};
