#include <fmt/core.h>

#include <chrono>

namespace stdc = std::chrono;
using namespace std::chrono_literals;

int zeller(int y, int m, int d) {
    if (m == 1 || m == 2) {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    int ret = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    return (ret + 7) % 7;
}

int main() {
    int ret = 0;
    int ret2 = 0;
    for (int y = 1901; y <= 2000; ++y) {
        for (int m = 1; m <= 12; ++m) {
            if (zeller(y, m, 1) == 1) {
                ++ret;
            }
        }
    }

    for (auto ym = 1901y / stdc::January; ym <= 2000y / stdc::December;
         ym += stdc::months{1}) {
        ret2 += static_cast<int>(stdc::weekday{stdc::sys_days{ym / 1}} == stdc::Sunday);
    }

    fmt::println("{}", ret);
    fmt::println("{}", ret2);
    return 0;
}
