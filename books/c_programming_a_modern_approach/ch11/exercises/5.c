#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void) {
	int hr;
	int min;
	int sec;
	split_time((long)33621, &hr, &min, &sec);
	printf("Hours: %i\nMinutes: %i\nSeconds: %i\n", hr, min, sec);
	return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec) {
	*hr = (total_sec / 3600) % 24;
	*min = (total_sec / 60) % 60;
	*sec = ((int)total_sec) % 60;
}
