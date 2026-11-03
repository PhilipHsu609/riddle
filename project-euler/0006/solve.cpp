#include <iostream>

int main() {
    int ssq = 101 * 101 * 100 * 100 / 4;
    int sqs = 100 * 101 * 201 / 6;
    std::cout << ssq - sqs << std::endl;
}