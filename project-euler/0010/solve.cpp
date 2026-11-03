#include <algorithm>
#include <cmath>
#include <iostream>

const int LIM = 2'000'000;
bool sieve[LIM];

void init() {
    std::fill(std::begin(sieve), std::end(sieve), true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i < std::sqrt(LIM); i++) {
        if (sieve[i]) {
            for (int j = i * i; j < LIM; j += i)
                sieve[j] = false;
        }
    }
}

int main() {
    long long sum = 0;

    init();
    for (int i = 2; i < LIM; i++) {
        if (sieve[i]) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}