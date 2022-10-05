#include <bitset>
#include <iostream>

template<std::size_t N>
std::bitset<N> bxor(std::bitset<N>, std::bitset<N>);

int main() {
        std::bitset<8> bits{0b0000'0101};
        bits.set(3);
        std::cout << bits << '\n';

        bits.flip(4);
        std::cout << bits << '\n';

        bits.reset(4);
        std::cout << bits << '\n';


        constexpr std::bitset<7> bits_a{0b1010'0001};
        constexpr std::bitset<7> bits_b{0b1000'0101};

        std::cout << bxor(bits_a, bits_b) << '\n';
        std::cout << (bits_a ^ bits_b) << '\n';

        return 0;
}

// Returns the xor'd result of N length bits as a bitset.
template<std::size_t N>
std::bitset<N> bxor(std::bitset<N> a, std::bitset<N> b) {
    if (a.size() != b.size()) std::domain_error("length of bitset a does not equal bitset b");
    std::bitset<N> bin {};
    
    for (int i = 0; i < a.size(); ++i) {
       if (a.test(i) != b.test(i)) {
           bin.flip(i);
       }
    }

    return bin;
}
