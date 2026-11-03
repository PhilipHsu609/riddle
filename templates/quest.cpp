#include "utils.hpp"

#include <fmt/core.h>

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// Custom input parser - modify based on quest
auto read_input(const fs::path &path) { return utils::read_lines(path); }

template <typename T>
auto part1(const std::vector<T> &input) {
    return 0;
}

template <typename T>
auto part2(const std::vector<T> &input) {
    return 0;
}

template <typename T>
auto part3(const std::vector<T> &input) {
    return 0;
}

int main() {
    utils::set_working_dir(__FILE__);

    utils::Timer timer;
    fmt::print("Part1: {} ({:.3f}ms)\n", part1(read_input("./part1.txt")), timer.elapsed_and_reset());
    fmt::print("Part2: {} ({:.3f}ms)\n", part2(read_input("./part2.txt")), timer.elapsed_and_reset());
    fmt::print("Part3: {} ({:.3f}ms)\n", part3(read_input("./part3.txt")), timer.elapsed());

    return 0;
}
