#include <fmt/core.h>
#include <fmt/ranges.h>

#include <string>
#include <vector>

/*
 * 9! * 2 + 8! * 6 + 7! * 6 + 6! * 2 + 5! * 5 + 4! * 1 + 3! * 2 + 2! * 1 + 1! * 1 + 0! * 1
 * = 1'000'000
 *
 * 2783915460
 */

int fac(int n) {
    int ret = 1;
    while (n > 0) {
        ret *= n--;
    }
    return ret;
}

int main() {
    int remain = 999'999;

    // Lehmer code
    std::vector<int> codes;
    for (int i = 9; i >= 0; --i) {
        int f = fac(i);
        int c = remain / f;
        remain %= f;
        codes.push_back(c);
    }

    // Map to permutation
    std::string digits = "0123456789";
    std::string perm;
    for (int code : codes) {
        perm += digits[code];
        digits.erase(code, 1);
    }

    fmt::println("{}", perm);

    return 0;
}
