#include <fmt/core.h>

#include <array>
#include <ranges>
#include <vector>

int d(int n) {
    int ret = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i * i == n) {
                ret += i;
            } else {
                ret += i + (n / i);
            }
        }
    }
    return ret;
}

constexpr int N = 28124;

int main() {
    std::array<bool, N> expressible{};

    auto abundant = std::views::iota(1, N) |
                    std::views::filter([](int n) { return d(n) - n > n; }) |
                    std::ranges::to<std::vector<int>>();

    auto m = std::ssize(abundant);
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            if (abundant[i] + abundant[j] > N) {
                break;
            }
            expressible[abundant[i] + abundant[j]] = true;
        }
    }

    int ret = 0;
    for (int i = 1; i < N; ++i) {
        if (!expressible[i]) {
            ret += i;
        }
    }
    fmt::println("{}", ret);
    return 0;
}
