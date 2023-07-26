#include <stdio.h>
#include <stdlib.h>

#define LEN(arr) sizeof(arr) / sizeof(arr[0])
#define HIST_BUF 15

void repeat(char* buffer, char c, int amount);

int main() {
	int cw = 0;
	int nw = 0;
	// TODO: this is bad because I can type more than 6 words into the buffer..
	int words[6];

	int is_word = 0;

	int character;
	while ((character = getchar()) != EOF) {
		if (character == ' ' || character == '\n') {
		  is_word = 1;
		} else if (character != '\n' && character != '\t' && character != ' ') {
		  is_word = 0;
		  cw++;
		}

		if (is_word) {
		  words[nw] = cw;
		  printf("%i\n",nw );
		  nw += 1;
		  cw = 0;
		}
	}

	// for (int i = 0; i < LEN(words); i++) {
	// 	printf("%i\n", words[i]);
	// }

	// int words[] = {5, 4, 2, 7, 2, 4};
	int histogram[HIST_BUF] = {0};
	
	// TODO: get max number in word array and set that to the len of histogram

	for (int i = 0; i < LEN(words); i++) {
		histogram[words[i]]++;
	}

	printf("HISTOGRAM - Word length\n");
	for (int i = 0; i < LEN(histogram); i++) {
		char string[histogram[i]];
		repeat(string, '*', histogram[i]);
		printf("%02d %s\n", i, string);
	}

	return 0;
}

void repeat(char *buffer, char c, int amount) {
	if (buffer == NULL) {
		return;
	}
	for (int i = 0; i < amount; i++) {
		buffer[i] = c;
	}
	buffer[amount] = '\0';

	return;
}
