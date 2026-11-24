#include <fmt/core.h>

#include <algorithm>
#include <array>
#include <functional>
#include <ranges>
#include <string_view>

constexpr std::array<std::string_view, 20> ones{
    "",         "one",     "two",     "three",     "four",     "five",    "six",
    "seven",    "eight",   "nine",    "ten",       "eleven",   "twelve",  "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
constexpr std::array<std::string_view, 10> tens{
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
constexpr std::string_view hundred = "hundred";
constexpr std::string_view thousand = "thousand";
constexpr std::string_view conjunction = "and";

constexpr int len(std::string_view s) { return static_cast<int>(s.size()); }

// Letters in the British English name of n (1..1000); spaces and hyphens do not count.
// "and" appears after "hundred" only when something follows it: 100 is "one hundred",
// 115 is "one hundred and fifteen".
constexpr int letters(int n) {
    if (n == 1000) {
        return len(ones[1]) + len(thousand);
    }
    if (n < 20) {
        return len(ones[n]);
    }
    if (n < 100) {
        return len(tens[n / 10]) + len(ones[n % 10]);
    }
    const int head = len(ones[n / 100]) + len(hundred);
    const int rest = n % 100;
    return rest == 0 ? head : head + len(conjunction) + letters(rest);
}

// Examples from the problem statement.
static_assert(letters(342) == 23);
static_assert(letters(115) == 20);
static_assert(letters(1) + letters(2) + letters(3) + letters(4) + letters(5) == 19);

int main() {
    constexpr int last = 1000;
    fmt::println("{}", std::ranges::fold_left(std::views::iota(1, last + 1) |
                                                  std::views::transform(letters),
                                              0, std::plus{}));

    return 0;
}
