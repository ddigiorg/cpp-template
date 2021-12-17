#include "source_file.hpp"

#include <chrono>
#include <iostream>

using namespace MyNamespace;

int main(int argc, char *argv[]) {

    MyClass mc;

    auto t0 = std::chrono::high_resolution_clock::now();
    mc.myFunc();
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = t1 - t0;
    std::cout << "t=" << diff.count() << std::endl;

    return 0;
}