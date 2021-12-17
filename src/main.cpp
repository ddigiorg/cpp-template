#include "source_file.hpp"

#include <vector> // for vectors
#include <chrono> // for high resolution clock
#include <random> // for mersenne twister pseudo random number generator
#include <cstdint> // for uint32_t
#include <iostream> // for printing messages

using namespace MyNamespace;

int main(int argc, char *argv[]) {

    // Basic class stuff
    MyClass mc;
    mc.myFunc();

    // Example for shortening really long types
    typedef std::chrono::high_resolution_clock hrc;

    // High resolution timer setup
    hrc::time_point t0, t1;
    hrc::duration diff;

    // Mersenne Twister setup
    uint32_t seed = (uint32_t)hrc::now().time_since_epoch().count();
    std::mt19937 rng(seed);

    // Variables for multiply, xnor, and xor performance tests
    const uint32_t NUM = 100000000;
    std::vector<uint32_t> a(NUM);
    std::vector<uint32_t> b(NUM);
    std::vector<uint32_t> c(NUM);

    // Randomize vectors
    t0 = hrc::now();
    for (uint32_t i=0; i<NUM; i++) {
        a[i] = rng();
        b[i] = rng();
    }
    t1 = hrc::now();
    diff = t1 - t0;
    std::cout << "ran=" << diff.count() / 1e9 << "s" << std::endl;

    // Multiply test
    t0 = hrc::now();
    for (uint32_t i=0; i<NUM; i++) {
        c[i] = a[i] * b[i];
    }
    t1 = hrc::now();
    diff = t1 - t0;
    std::cout << "mul=" << diff.count() / 1e9 << "s" << std::endl;

    // XNOR test
    t0 = hrc::now();
    for (uint32_t i=0; i<NUM; i++) {
        c[i] = ~(a[i] ^ b[i]);
    }
    t1 = hrc::now();
    diff = t1 - t0;
    std::cout << "xnr=" << diff.count() / 1e9 << "s" << std::endl;

    // XOR Test
    t0 = hrc::now();
    for (uint32_t i=0; i<NUM; i++) {
        c[i] = a[i] ^ b[i];
    }
    t1 = hrc::now();
    diff = t1 - t0;
    std::cout << "xor=" << diff.count() / 1e9 << "s" << std::endl;
}