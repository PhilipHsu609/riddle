#include <fmt/core.h>

#include <cmath>
#include <numbers>

/*
 * Binet's formula: F_n \approx \frac{\phi^{n}}{\sqrt{5}}
 *
 * \log_{10}{F_n} > 999
 * => \log_{10}{\frac{\phi^{n}}{\sqrt{5}}} > 999
 * => \log_{10}{\phi^{n}} - \log_{10}{\sqrt{5}} > 999
 * => \log_{10}{\phi^{n}} > 999 + \log_{10}{\sqrt{5}}
 */

int main() {
    int ret =
        std::ceil((999.0 + std::log10(std::sqrt(5))) / std::log10(std::numbers::phi));
    fmt::println("{}", ret);
    return 0;
}
