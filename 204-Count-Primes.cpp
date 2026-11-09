
class Solution {
public:
    static vector<bool> primes;
    static void fill() {
        if (!primes.empty()) return;
        int N = 5000000;
        primes.resize(N + 1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; 1LL * i * i <= N; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= N; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    int countPrimes(int n) {
        fill();
        int ans = 0;
        for (int i = 2; i < n; i++) {
            ans += (primes[i]==true);
        }
        return ans;
    }
};

vector<bool> Solution::primes;