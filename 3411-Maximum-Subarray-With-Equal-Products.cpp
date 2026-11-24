class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        const long long LIMIT = 2520LL * 10;

        for (int i = 0; i < n; i++) {
            long long prod = 1, l = 1, g = 0;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (prod > LIMIT) break;       // can never equal again
                if (prod == l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};