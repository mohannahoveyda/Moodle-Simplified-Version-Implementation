#include "Header.h"
bool streql(char a[], char b[]) {
	bool equal = true;
	int counter = 0;
	while (a[counter] != 0 || b[counter] != 0) {
		if (a[counter] != b[counter]) {
			equal = false;
		}

		counter++;
	}
	return equal;
}