
class ProductOfNumbers {
private:
    vector<long long> prefix;
    int val = 0;
    int lastZero = 0;

public:
    ProductOfNumbers() {
        const int sz = 4e4 + 5;
        prefix.resize(sz);
        prefix[0] = 1;
    }

    void add(int num) {
        val++;

        if (num == 0) {
            prefix.clear();
            prefix[0] = 1;
            val = 0;
        } else {
            prefix[val] = prefix[val - 1] * num * 1ll;
        }
    }

    int getProduct(int k) {
        if (val - k < lastZero)
            return 0;

        return prefix[val] / prefix[val - k];
    }
};
