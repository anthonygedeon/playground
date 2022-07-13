#include <iostream>

int main()
{
    constexpr bool inBigClassroom { false };
    constexpr int classSize{ inBigClassroom ? 30 : 20};
    std::cout << "The class size is: " << classSize;

    return 0;
}
