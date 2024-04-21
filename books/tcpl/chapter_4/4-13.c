#include <stdio.h>

void reverse(char s[]) {
	static int i = 0;
	static int start = 0;
	static int end   = 0; 

	if (s[i] == '\0') {
		i++;
		end = i;
		reverse(s);
	} 	

	s[start++] = s[end--];
	// s[end] = '\0';
}

int main(void) {
	char s[] = "hello";
	reverse(s);
	printf("%s\n", s);
	return 0;
}
