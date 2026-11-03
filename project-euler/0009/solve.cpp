#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> factors(int n) {
    std::vector<int> factor;
    for (int i = 1; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            factor.push_back(i);
            factor.push_back(n / i);
        }
    }
    return factor;
}

int main() {
    /*
        If m and n are two odd integers such that m > n > 0, then
            a = mn
            b = (m^2 - n^2) / 2
            c = (m^2 + n^2) / 2
        is a Pythagorean triple.
        (Ref: https://www.wikiwand.com/en/Pythagorean_triple)

        So a + b + c = m^2 + mn = 1000,
        implies m(m + n) = 1000, which means 1000 must be dividible by m.
    */

    int sum = 1000;
    std::vector<int> f = factors(sum);

    for (int m : f) {
        int n = (sum / m) - m;

        if (n < 0 || n > m || (m & n & 1) == 0)
            continue;

        int a = m * n;
        int b = (m * m - n * n) / 2;
        int c = (m * m + n * n) / 2;

        if (a + b + c == sum) {
            std::cout << '(' << a << ',' << b << ',' << c << "): ";
            std::cout << a * b * c << std::endl;
        }
    }

    return 0;
}