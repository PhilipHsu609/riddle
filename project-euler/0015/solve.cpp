#include <fmt/core.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <ranges>

using u64 = unsigned long long;

constexpr u64 paths(u64 n) {
    return std::ranges::fold_left(std::views::iota(u64{1}, n + 1), u64{1},
                                  [n](u64 r, u64 k) { return r * (n + k) / k; });
}

int main() {
    static_assert(paths(2) == 6);
    static_assert(paths(20) == 137846528820ULL);
    fmt::println("{}", paths(20));
    return 0;
}
