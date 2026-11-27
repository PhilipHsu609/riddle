#include <fmt/core.h>

#include <algorithm>
#include <functional>
#include <ranges>

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

bool is_amicable(int x) {
    int a = d(x) - x;
    return x != a && d(a) - a == x;
}

int main() {
    constexpr int N = 10'000;
    int ret = std::ranges::fold_left(
        std::views::iota(1, N + 1) | std::views::filter(is_amicable), 0, std::plus{});
    fmt::println("{}", ret);
    return 0;
}
