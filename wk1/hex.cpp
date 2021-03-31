#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

#define MaxargInput 3
#define Hexpos1 2
#define Hexpos2 2
#define err1 -1
#define err2 -2
// Function prototype
int checkrange(char *input);
int checkcase (char *input);
int checklength(char *input);

//Function definition
int main(int argc, char *argv[] ) {
	//Check for number of arg
	if (argc > MaxargInput || argc == 1) {
		cout << "Invalid Number of Arg" << endl;
		return err1;
	}
	//Check for the hex in range, check for format of the hex
	for (int i1 = 1; i1 < MaxargInput; i1 ++) {
		if(checklength(argv[i1]) == err1)
			return err1;
		// Check for base
		if (argv[i1][0] != '0' || tolower(argv[i1][1]) != 'x') {
			cout << "Invalid Number Format" << endl;
			return err1;
		}	
		for (int i = Hexpos1 ; i < Hexpos2; i ++) {
			// cout << checkcase(&argv[i1][i]) << endl; //Debug
			if (checkcase(&argv[i1][i]) == err1) {
				cout << argv[i1];
				cout <<argv [i1] <<"  is an Invalid Hex" << endl;
				return err1;
			}
			continue;
		}
		cout <<argv[i1];
	}
	return 0;
}

int checkrange(char *input) {
		if (*input == '-' || *input == '+')
		if (*input < '0' || (*input < '9' && *input < 'A') || *input > 'F' ) {
			return err2;
		} else 
			return 0;
}

int checkcase (char *input) {
	if (isalpha(*input) ) {
		if (!isupper(*input)) {
			return err1;
		}
	}
	if(checkrange(input) == err2)
		return err1;
	return 0;
}

int checklength(char *input) {
		// Check for the length
		if (strlen(input) != 4) {
			cout <<"Invalid hex" << endl;
			return err1;
		}
	return 0;
}

