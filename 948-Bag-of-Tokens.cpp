class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=n-1;
        int score = 0;
        int maxi = 0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                maxi = max(maxi,score);
                i++;
            }
            else if(score>=1 and i<j){
                power+=tokens[j];
                score--;
                j--;
            }
            else return maxi;
        }
        return maxi;
    }
};