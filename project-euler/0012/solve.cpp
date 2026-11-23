#include <fmt/core.h>

int d(int n) {
    int cnt = 0;
    int x = 1;
    while (x * x <= n) {
        if (n % x == 0) {
            cnt += (x * x == n) ? 1 : 2;
        }
        ++x;
    }
    return cnt;
}

int main() {
    int n = 1;
    int dn = d(n);
    int dn1 = d((n + 1) / 2);

    while (dn * dn1 <= 500) {
        ++n;
        dn = dn1;
        dn1 = d((n % 2 == 1) ? (n + 1) / 2 : n + 1);
    }

    fmt::println("{}", n * (n + 1) / 2);

    return 0;
}
