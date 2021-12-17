// =============================================================================
// source_file.hpp
// =============================================================================
#ifndef SOURCE_FILE_HPP
#define SOURCE_FILE_HPP

#include <cstdint>

namespace MyNamespace {

class MyClass {

public:

    MyClass();
    void myFunc();

private:

    uint32_t my_var = 0;
};

} // MyNamespace

#endif