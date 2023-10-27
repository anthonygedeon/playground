#include <stdbool.h>

#define AGE_REQUIREMENT 13

int main(void) {
	int age = AGE_REQUIREMENT;
	bool is_teenager = age >= AGE_REQUIREMENT ? true : false;
	return 0;
}
