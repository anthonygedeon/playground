#include <stdio.h>

int main() {
	int i;
	int lim = 0;
	int c;
	
	for (i = 0; i < lim-1;++i) {
		if ((c=getchar()) != '\n') {
			if (c != EOF) {
				// do something..
			}
		}
	}

	return 0;
}

