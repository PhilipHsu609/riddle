#include <iostream>
#include <vector>

std::vector<long long> primes{2, 3};

long long next_prime() {
    long long p = primes.back() + 2;

    while (true) {
        bool is_prime = true;

        for (long long v : primes) {
            if (p % v == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes.push_back(p);
            break;
        }

        p += 2;
    }

    return p;
}

int main() {
    while (primes.size() != 10001)
        next_prime();

    std::cout << primes.back() << std::endl;
}