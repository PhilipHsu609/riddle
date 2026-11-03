#include <iostream>

int pow(int a, int b) {
    return (b == 0) ? 1 : pow(a, b - 1) * a;
}

int main() {
    int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    int p[8] = {4, 2, 1, 1, 1, 1, 1, 1};

    int prod = 1;
    for (int i = 0; i < 8; i++)
        prod *= pow(primes[i], p[i]);

    std::cout << prod << std::endl;

    return 0;
}