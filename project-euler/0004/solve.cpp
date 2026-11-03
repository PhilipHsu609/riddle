#include <iostream>

bool is_palindrome(int n) {
    int tmp = n, rev = 0;
    while (tmp > 0) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return n == rev;
}

int largest_palindrome_product() {
    int ret = 0;
    for (int i = 999; i >= 0; i--) {
        for (int j = 990; j >= 0; j -= 11) {
            int product = i * j;
            if (is_palindrome(product)) {
                ret = std::max(ret, product);
            }
        }
    }
    return ret;
}

int main() {
    std::cout << largest_palindrome_product() << std::endl;
}