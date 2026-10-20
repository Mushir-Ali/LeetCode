class Solution {
public:
    int maxi = 1e5;
    vector<bool> primes;
    vector<long long> prefix;

    void f(int n) {
        int maxi = max(100000, n);

        primes.assign(maxi + 1, true);
        prefix.assign(maxi + 1, 0);

        primes[0] = primes[1] = false;

        for (int i = 2; 1LL * i * i <= maxi; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= maxi; j += i) {
                    primes[j] = false;
                }
            }
        }

        for (int i = 1; i <= maxi; i++) {
            prefix[i] = prefix[i - 1] + (primes[i] ? i : 0);
        }
    }
    vector<int> maxPrimes(int n, int s) {
        f(n);
        vector<int> ans;
        long long sum = 0;
        for (int i = 2; i <= n; i++) {
            if (primes[i] && sum + i <= s) {
                sum += i;
                ans.push_back(i);
            }
        }
        return ans;
    }
};