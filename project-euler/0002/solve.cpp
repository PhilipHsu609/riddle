#include <cmath>
#include <iostream>

constexpr int MAX = 4e6;

constexpr int sum_fibonacci_even() {
    int sum = 0;
    int f[3] = {0, 1, 1};

    do {
        sum += f[0];
        f[0] = f[1] + f[2];
        f[1] = f[0] + f[2];
        f[2] = f[0] + f[1];
    } while (sum < MAX);

    return sum;
}

int main() {
    constexpr int sum = sum_fibonacci_even();
    std::cout << sum << std::endl;
    return 0;
}