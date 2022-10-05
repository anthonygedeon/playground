#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> byte_1{0b0000'0001};
    std::bitset<8> byte_2{0xFB};

    std::cout << byte_1 << ' ' << byte_2 << '\n';
    return 0;
}
