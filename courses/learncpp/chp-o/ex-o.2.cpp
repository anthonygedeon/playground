#include <iostream>
#include <bitset>

#include <cassert>

template <std::size_t N>
std::bitset<N> rotl(std::bitset<N> bits, int rotate_n);

template <std::size_t N>
std::bitset<N> rotr(std::bitset<N> bits, int rotate_n);

template <std::size_t N>
std::bitset<N> rotl_nts(std::bitset<N> bits);

int main() {
	// rotl
	std::bitset<4> bits1{ 0b0001 };
	std::bitset<4> bits2{ 0b1001 };
	std::bitset<4> bits3{ 0b1101 };
	std::bitset<4> bits4{ 0b1101 };
	std::bitset<4> bits5{ 0b0101 };

	assert((rotl(bits1, 1) == std::bitset<4>{0b0010})  && "shift_left_once");
	assert((rotl(bits2, 1) == std::bitset<4>{0b0011})  && "shift_left_once");
	assert((rotl(bits3, 1) == std::bitset<4>{0b1011})  && "shift_left_once");
	assert((rotl(bits4, 3) == std::bitset<4>{0b1110})  && "shift_left_3_times");
	assert((rotl(bits5, 10) == std::bitset<4>{0b0101}) && "shift_left_10_times");

	// rotr
	std::bitset<4> bits6{ 0b0001 };
	std::bitset<4> bits7{ 0b1001 };
	std::bitset<4> bits8{ 0b1101 };
	std::bitset<4> bits9{ 0b0101 };
	assert((rotr(bits6, 1) == std::bitset<4>{0b1000})  && "shift_right_once");
	assert((rotr(bits7, 1) == std::bitset<4>{0b1100})  && "shift_right_once");
	assert((rotr(bits8, 1) == std::bitset<4>{0b1110})  && "shift_right_once");
	assert((rotr(bits9, 3) == std::bitset<4>{0b1010})  && "shift_right_3_times");
	
	std::bitset<4> bits10{ 0b1010  };
	std::bitset<4> bits11{ 0b0001 };
	std::bitset<4> bits12{ 0b1001 };
	assert((rotl_nts(bits10) == std::bitset<4> {0b0101}));
	assert((rotl_nts(bits11) == std::bitset<4> {0b0010}));
	assert((rotl_nts(bits12) == std::bitset<4> {0b0011}));

	std::cout << "All Tests Pass" << '\n';

	return 0;
}

// Rotate the bit set to the left n times.
template <std::size_t N>
std::bitset<N> rotl(std::bitset<N> bits, int rotate_n) {
	for (int i = 0; i < rotate_n; ++i) {
		if (bits.test(bits.size()-1)) { // get msb
			bits = (bits << 1) | std::bitset<N>{0b1}; 
		} else {
			bits <<= 1;
		}
	}
	return bits;
}

// Rotate the bit set to the right n times.
template <std::size_t N>
std::bitset<N> rotr(std::bitset<N> bits, int rotate_n) {
	for (int i = 0; i < rotate_n; ++i) {
		if (bits.test(0)) { // get lsb
			bits = (bits >> 1) | (std::bitset<N>{0b1} << bits.size()-1);
		} else {
			bits >>= 1;
		}
	}
	return bits;
}

//template<std::size_t N>
//std::bitset<N> rot_nts(std::bitset<N> bits) {
//	const bool leftbit{ bits.test(3) };
//
//	bits <<= 1; // do left shift
//
//	if (leftbit)
//		bits.set(0);
//
//	return bits;	
//}


// Do not use test or set for function.
template<std::size_t N>
std::bitset<N> rotl_nts(std::bitset<N> bits) {
	return ((bits << 1) | (bits >> (bits.size()-1)));	
}
