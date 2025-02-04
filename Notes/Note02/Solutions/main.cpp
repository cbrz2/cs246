#include <iostream>
#include "util.h"

int main()
{
    size_t n;

    std::cout << "Enter a positive number: ";
    std::cin >> n;

    std::cout << "Fibonacci(" << n << ") = " << ds::Fib(n) << "\n";
    std::cout << "Fibonacci(" << n << ") = " << ds::FiB(n) << "\n";
    return 0;
}