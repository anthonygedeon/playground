#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-3.h"

/**
 * Expand the range of ascii characters from a-zA-Z0-9
 * @param s1 range of string
 * @param s2 the expanded range of s1
 */
void expand(const char *s1, char *s2) {
	int start = 0;
	int end   = 0;
	int pos   = 0;

	for (int i = 0; i < strlen(s1); i += 1) {
		if (s1[i] == '-') {
			start = i - 1;
			end   = i + 1;
				
			for (int ascii = s1[start]; ascii <= s1[end]; ascii += 1) {
				s2[pos] = ascii;
				pos += 1;
			}
		}
	}

	s2[pos] = '\0';
}

