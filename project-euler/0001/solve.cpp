#include <iostream>

constexpr int UPPER_BOUND = 1000;

constexpr int sum_of_multiples(int n) {
    int p = (UPPER_BOUND - 1) / n;
    return n * p * (p + 1) / 2;
}

int main() {
    constexpr int sum = sum_of_multiples(3) + sum_of_multiples(5) - sum_of_multiples(15);
    std::cout << sum << std::endl;
    return 0;
}