#include <cmath>
#include <iostream>

constexpr long long N = 600'851'475'143;

constexpr long long lpf(long long n) {
    long long f = 2, lpf = 0;
    while (n > 1) {
        if (n % f == 0) {
            lpf = f;
            while (n % f == 0) {
                n /= f;
            }
        }
        f = (f == 2) ? 3 : f + 2;
    }
    return lpf;
}

int main() {
    constexpr long long p = lpf(N);
    std::cout << p << std::endl;
    return 0;
}