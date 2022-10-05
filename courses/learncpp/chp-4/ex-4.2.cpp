#include <cstdint> // for fixed-width integers
#include <iostream>

int main()
{
    std::uint_fast16_t sometype { 0 };
    --sometype; // intentionally overflow to invoke wraparound behavior

    std::cout << sometype;

    return 0;
}
