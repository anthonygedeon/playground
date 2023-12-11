#include "word_count.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <regex.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

#define WORD_REGEX "[[:alnum:]']+([[:alnum:]])?"

int count_words(const char *sentence, word_count_word_t *words) {
	regex_t regex;
	regmatch_t matches;

	if (regcomp(&regex, WORD_REGEX, REG_EXTENDED) != 0 ) {
		return -1;
	}
	
	size_t offset = 0;
	size_t word_index = 0;
	size_t word_count = 0;
	char word[MAX_WORD_LENGTH];
	while (regexec(&regex, sentence + offset, 1, &matches, 0) == 0) {
		int len = matches.rm_eo - matches.rm_so;
		memcpy(word, sentence + offset, len);
		word[len] = '\0';
		printf("word: %s\n", word);

		for (word_index = 0; word_index < word_count; word_index++) {
			if (strcmp(word, words[word_index].text) == 0) {
				break;
			}
		}

		if (strlen(words[word_index].text) == 0) {
			memcpy(words[word_index].text, sentence + offset, len);
			words[word_index].count = 1;
		} else {
			words[word_index].count++;
		}

		if (word_index == word_count) {
			word_count++;
		}
		
		offset += matches.rm_eo + 1;
		if (offset > strlen(sentence)) {
			break;
		}
	}


	// for (int i = 0; i < MAX_WORDS; i++) {
	// 	printf("{ word: \"%s\" count: %d }\n", words[i].text, words[i].count);
	// }

	return word_count;
}

