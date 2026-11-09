class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 0;
        int n = digits.size();
        int carry = (digits[n-1] + 1)/10;
        digits[n-1] = (digits[n-1]+1)%10;
        if(!carry) return digits;
        for(int i=n-2;i>=0;i--){
            if(carry){
                carry = (digits[i] + 1)/10;
                digits[i] = (digits[i] + 1)%10;
            }
            else break;
        }
        if(carry){
            digits.push_back(0);
            n = digits.size();
            for(int i=n-1;i>0;i--) digits[i] = digits[i-1];
            digits[0] = carry;
        }
        return digits;
    }
};