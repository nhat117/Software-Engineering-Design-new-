#include <iostream>
#include <string.h>
#define MAXARG 2
using namespace std;
// Function prototype
int chkleng(char *input);
int main(int argc, char *argv[]) {
	// Check number of arg
	if (argc > MAXARG) {
		cout << "Invalid Number of arg" << endl;
		return -1;
	}
	for (int i = 1; i < MAXARG ; i++) {
		cout << chkleng(argv[i]);
	}
	return 0;
}

int chkleng(char *input) {
	if (strlen(input) != 8)
		return -1;
	return strlen(input);
}
