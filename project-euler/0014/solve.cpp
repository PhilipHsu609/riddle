#include <array>
#include <fmt/core.h>

constexpr long long N = 1'000'000;
std::array<long long, N + 1> cache{};

int main() {
    auto collatz = [](long long n) {
        long long l = 1;
        long long x = n;
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = (3 * n) + 1;
            }
            if (n <= N && cache[n] != 0) {
                return cache[x] = l + cache[n];
            }
            ++l;
        }
        return cache[x] = l;
    };

    long long maxl = 1;
    long long maxn = 1;

    for (long long n = 1; n <= N; ++n) {
        long long l = collatz(n);
        if (l > maxl) {
            maxl = l;
            maxn = n;
        }
    }

    fmt::println("n: {}, len: {}", maxn, maxl);

    return 0;
}
