#include <fmt/core.h>

#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

int main() {
    int N = static_cast<int>(std::floor(1000 * std::log10(2))) + 1;
    std::vector<int> digits(N);

    digits[0] = 1; // 2^0
    for (int i = 0; i < 250; ++i) {
        int r = 0;
        for (int j = 0; j < N; ++j) {
            int d = (digits[j] * 16) + r;
            r = d / 10;
            digits[j] = d % 10;
        }
    }

    fmt::println("{}", std::ranges::fold_left(digits, 0, std::plus{}));

    return 0;
}
