#include "utils.hpp"

#include <fmt/core.h>

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <ranges>
#include <vector>

namespace fs = std::filesystem;

// Custom input parser - modify based on quest
auto read_input(const fs::path &path) {
    auto lines = utils::read_lines(path);
    return utils::split<int>(lines[0], ",");
}

template <typename T>
auto part1(const std::vector<T> &input) {
    auto cost = [](int n) {
        int c = std::ceil(std::sqrt(n));
        return (c * c) - n;
    };
    return std::ranges::fold_left(input | std::views::transform(cost), 0, std::plus{});
}

template <typename T>
auto part2(const std::vector<T> &input) {
    auto cost = [](int n) {
        int c = std::max((n + 4 + 3) / 4, 3);
        return (4 * c) - 4 - n;
    };
    return std::ranges::fold_left(input | std::views::transform(cost), 0, std::plus{});
}

template <typename T>
auto part3(const std::vector<T> &input) {
    auto cost = [](int n) {
        int c = std::ceil(std::sqrt(n + 1));
        c += c % 2 == 0 ? 1 : 0;
        return (c * c) - 1 - n;
    };
    return std::ranges::fold_left(input | std::views::transform(cost), 0LL, std::plus{});
}

int main() {
    utils::set_working_dir(__FILE__);

    utils::Timer timer;
    fmt::print("Part1: {} ({:.3f}ms)\n", part1(read_input("./part1.txt")),
               timer.elapsed_and_reset());
    fmt::print("Part2: {} ({:.3f}ms)\n", part2(read_input("./part2.txt")),
               timer.elapsed_and_reset());
    fmt::print("Part3: {} ({:.3f}ms)\n", part3(read_input("./part3.txt")),
               timer.elapsed());

    return 0;
}
