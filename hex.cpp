#include <iostream>
#include <ctype.h>
using namespace std;
#define MaxInput 1
// Function prototype
int checkrange(char *input);
int checkcase (char *input);
//Function definition
int main(int argc, char *argv[] ) {
	//Check for number of arg
	if (argc < MaxInput) {
		cout << "Invalid Number of Arg" << endl;
		return -1;
	}
	//Check for the hex in range, check for format of the hex
	if (argv[1][0] != '0' || tolower(argv[1][1]) != 'x') {
		cout << "Invalid Number Format" << endl;
			return -1;
	}
	for (int i = 2 ; i < 4; i ++) {
		cout << checkcase(&argv[1][i]) << endl;
		if (checkcase(&argv[1][i]) == -1) {
			cout << argv[1];
			cout << "  is an Invalid Hex" << endl;
			return -1;
		}
		continue;
	}
	cout << argv[1];
	return 0;
}

int checkrange(char *input) {
		if (*input < '0' || (*input < '9' && *input < 'A') || *input > 'F' ) {
			return -2;
		}
		else return 0;
}

int checkcase (char *input) {
	if (isalpha(*input) ) {
		if (!isupper(*input)) {
			return -1;
		}
	}
	if(checkrange(input) == -2)
		return -1;
	return 0;
}