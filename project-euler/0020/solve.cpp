#include <fmt/ranges.h>

#include <algorithm>
#include <cstdint>
#include <vector>

using u64 = std::uint64_t;

int main() {
    constexpr u64 MOD = 1e10;
    std::vector<u64> chunks; // each chunk is at most 10^10

    chunks.push_back(1);

    for (u64 n = 1; n <= 100; ++n) {
        u64 r = 0;
        for(u64 &c : chunks) {
            c = (c * n) + r;
            r = c / MOD;
            c %= MOD;
        }
        if (r > 0) {
            chunks.push_back(r);
        }
    }

    u64 ret = std::ranges::fold_left(chunks, 0, [](u64 acc, u64 chunk) {
        while (chunk > 0) {
            acc += chunk % 10;
            chunk /= 10;
        }
        return acc;
    });

    fmt::println("{}", ret);

    return 0;
}
