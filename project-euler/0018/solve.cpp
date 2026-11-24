#include <fmt/core.h>

#include <charconv>
#include <ranges>
#include <string_view>
#include <vector>
#include <algorithm>

int to_int(auto &&rng) {
    std::string_view sv(rng);
    int val = 0;
    std::from_chars(sv.data(), sv.data() + sv.size(), val);
    return val;
}

int main() {
    constexpr std::string_view raw = R"(75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23)";

    auto tri = raw | std::views::split('\n') | std::views::transform([](auto row) {
                   return row | std::views::split(' ') |
                          std::views::transform([](auto cell) { return to_int(cell); }) |
                          std::ranges::to<std::vector<int>>();
               }) |
               std::ranges::to<std::vector<std::vector<int>>>();

    int m = std::ssize(tri);
    int n = std::ssize(tri.back());
    std::vector<int> dp(n + 1);

    for(int i = 0; i < m; ++i) {
        for(int j = i; j >= 0; --j) {
            dp[j + 1] = std::max(dp[j + 1], dp[j]) + tri[i][j];
        }
    }

    fmt::println("{}", std::ranges::max(dp));

    return 0;
}
