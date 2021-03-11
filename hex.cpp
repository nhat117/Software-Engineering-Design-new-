#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

#define MaxargInput 3
// Function prototype
int checkrange(char *input);
int checkcase (char *input);
//Function definition
int main(int argc, char *argv[] ) {
	//Check for number of arg
	if (argc > MaxargInput || argc == 1) {
		cout << "Invalid Number of Arg" << endl;
		return -1;
	}
	//Check for the hex in range, check for format of the hex
	for (int i1 = 1; i1 < MaxargInput; i1 ++) {
		// Check for the length
		if (strlen(argv[i1]) != 4) {
			cout <<"Invalid hex" << endl;
			return -1;
		}
		// Check for base
		if (argv[i1][0] != '0' || tolower(argv[i1][1]) != 'x') {
			cout << "Invalid Number Format" << endl;
			return -1;
		}	
		for (int i = 2 ; i < 4; i ++) {
			// cout << checkcase(&argv[i1][i]) << endl; //Debug
			if (checkcase(&argv[i1][i]) == -1) {
				cout << argv[i1];
				cout <<argv [i1] <<"  is an Invalid Hex" << endl;
				return -1;
			}
			continue;
		}
		cout <<argv[i1];
	}
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

