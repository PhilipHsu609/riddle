#include <fmt/core.h>
#include <fmt/std.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <ranges>
#include <string>
#include <string_view>

namespace fs = std::filesystem;

constexpr int score(int idx, std::string_view name) {
    int ret = 0;
    for (char ch : name) {
        ret += ch - 'A' + 1;
    }
    return ret * idx;
}

int main() {
    auto path = fs::current_path() / "names.txt";
    std::ifstream file(path);
    if (!file.is_open()) {
        fmt::println("Failed to open {}", path);
        return 1;
    }

    std::string line;
    std::getline(file, line);

    auto names = line | std::views::split(',') | std::views::transform([](const auto &n) {
                     auto sv = std::string_view{n};
                     sv.remove_prefix(1);
                     sv.remove_suffix(1);
                     return sv;
                 }) |
                 std::ranges::to<std::vector<std::string_view>>();

    std::ranges::sort(names);

    int ret = std::ranges::fold_left(std::views::zip(std::views::iota(1), names), 0,
                                     [](int acc, const auto &p) {
                                         auto [i, sv] = p;
                                         return acc + score(i, sv);
                                     });

    static_assert(score(938, "COLIN") == 49714);

    fmt::println("{}", ret);

    return 0;
}
