#include <bitset>
#include <regex>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

enum flags {
	n = 0, 
	l, 
	i, 
	v, 
	x, 
};

int main(int argc, char* argv[]) {
	
	const std::regex filename_regex("([a-z]+)\\.txt");

	std::string filename;

	std::bitset<5> flag_mask{};

	for (int i = 1; i < argc; ++i) {
		std::stringstream convert{argv[i]};
		std::string flag_str = convert.str();
		if (flag_str.starts_with('-')) {
			if (flag_str == "-n") {
				flag_mask.set(flags::n);
			} else if (flag_str == "-l") {
				flag_mask.set(flags::l);
			}else if (flag_str == "-i") {
				flag_mask.set(flags::i);
			}else if (flag_str == "-v") {
				flag_mask.set(flags::v);
			} else if (flag_str == "-x") {
				flag_mask.set(flags::x);
			}
		}

		if (flag_str.ends_with(".txt")) {
			filename = flag_str;
		}
	}

	const std::string pattern{ argv[flag_mask.count()+1] };

	if (pattern.ends_with(".txt")) {
		// print help msg
	}

	const std::regex pattern_regex{ pattern };

	std::ifstream ifs{ filename, std::ios::in};

	while (!ifs.eof()) {
		std::string f_line;
		std::getline(ifs, f_line);
		if (std::regex_search(f_line, pattern_regex)) {
			std::cout << f_line << '\n';
		}
	}

	return 0;
}
