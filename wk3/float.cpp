#include <iostream>
#include <ctype.h>
#include <fstream>

#define MAXARG 3
#define MAXDOT 1

using namespace std;

bool floatchk(char arr[], int size);
void dotchk(char arr[], int &dot, int i);
void printarr(char inarr[]);

int main (int argc, char *argv[]) {
	// File open use freopen()
	freopen ("err.txt","w",stderr);
	// Check for num of arg
	if (argc > MAXARG || argc == 1) {
		cerr << "Invalid number of arg" << endl;
		return -1;
	}
	cerr << "Invalid: " << endl;
	float farr[argc];
	// Loop throught the arg
	for (int i = 1 ; i < argc; i ++) {
		// cout << argv[i];
		int size = sizeof(argv[i]) / sizeof(argv[i][0]);
		if(floatchk(argv[i], size) != false) {
			farr[i -1] = stof(argv[i]);
		} else {
			cerr << argv[i] << endl;
			continue;
		}
		// cout << floatchk(argv[i], size);
	}
	// Output valid res
	cout << "Valid num : " << endl;
	for (int i = 0; i < argc - 1; i++) {
		cout << farr[i] << " ";
	}
	// Output err to file
	cout << endl;
	return 0;
}

bool floatchk(char *arr, int size) {
	// Check for + and point,
	int dot = 0;
	if (arr[0] == '+'|| arr[0] == '-' || isdigit(arr[0]) != 0 || arr[0] == '.') {
		dotchk(arr, dot, 0);
	} else {
		return false;
	}
	for(int i = 1; arr[i] != '\0'; i ++) {
		if (isdigit(arr[i]) != 0 || arr[i] == '.') {
			dotchk(arr, dot, i);
		} else {
			return false;
		}
	}
	if(dot > MAXDOT) {
		return false;
	}
	return true;
}

void dotchk(char *arr, int &dot, int &i) {
	if(arr [i] == '.') {
		dot ++;
	} 
}
void printarr(char inarr[]) {
	
}
 