#include <iostream>
#include <string.h>

#define MAXARG 3
#define MAXLEN 8

using namespace std;

// Function prototype
int chkleng(char *input);
int chkcomponent(char *input);
int bintodec(char *input);

//Function definition
int main(int argc, char *argv[]) {
	// Check number of arg
	if (argc != MAXARG )  { // Minimum argc is 2 inorder for commandline arg to worl
		cout << "Invalid Number of arg. Please enter " << MAXARG - 1 << "  commandline arg. " << endl;
		return -1;
	}
	for (int i = 1; i < MAXARG ; i++) {
		if (chkleng(argv[i]) == 0 && chkcomponent(argv[i]) != -1) {
			cout << argv[i] << " in decimal: " << bintodec(argv[i]) << endl;
		} else {
			cout << argv[i] << " Is a invalid bin" << endl;
			return -1;
		}
	}
	return 0;
}

int chkleng(char *input) {
	if (strlen(input) == MAXLEN)
		return 0;
	else 
		cout << "Invalid length" << endl;
		return -1;
}

int chkcomponent(char *input) {
	for (int i = 0; i < MAXLEN; i ++) {
		if (input[i] != '1' && input[i] != '0') {
			cout << "Invalid bin input" << endl;
			return -1;
		}
	}
	return 0;
}

int bintodec(char *input) {
	int tmp = atoi(input);
	int dec = 0;
	// Binary to decimal algorithnm
	//Initilizing base value to 1
	int base = 1;
	while(tmp) {
		int last_digit = tmp % 10;
		tmp /= 10; // Increase Tmp position
		dec += last_digit * base;
		base *=2;
	}
	return dec;
}



