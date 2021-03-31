#include <iostream>
#include <cstring>

#define MAXARG 3 // Accept 10 input argument from the user
#define MAXDOT 1
using  namespace std;

//Function prototype
int floatchk(char *input, float *inputarr);
void printarr(float *inputarr);
int inout(char *input[], float *inputarr, int *argc);

//Function Definition
int main(int argc, char *argv[]) {
	//Initialise
	float arrfloat[MAXARG - 1] = {'\0'};
	//User input chk
	if(argc == 1 || argc > MAXARG) {
		cout << "Invalid number of input" << endl;
		return -1;
	}
	//Feed the function 
	inout(argv, arrfloat, &argc);
	return 0;
}

int floatchk(char *input, float *inputarr) {
	int res = 0, DotCount = 0;
	for (int i = 0; i < sizeof(*input) / sizeof(input[0]); i ++) {
		if (isdigit(input[i]) != 0 || input[i] == '.') { // Check to see if enter digit and punctuation is valid
			if (input[i] == '.') {
				DotCount ++;
			}
			res = 0;
		} else {
			res = -1;
			cout << "Invalid int" <<endl;
			break;
		}
	}
	// Check for res
	if(res == 0 && DotCount <= MAXDOT) {
		*inputarr = atof(input); //Convert str arr to float and store in the array
		return res;
	} else {
		return res;
	}
}

void printarr(float *inputarr) {
	for (int i = 0; i < MAXARG - 1; i ++) {
		cout  << "Valid num is : "<< *(inputarr + i) << " ";
	}
	cout << endl;
}

int inout(char *input[], float *inputarr, int *argc) {
	int res;
	// Feed floatchk 
	for (int i = 1; i <= *argc - 1; i ++ ) {
		if (floatchk(input[i], &inputarr[i -1]) == -1) {
				res = -1;
				cout << input[i] <<" is an Invalid int" << endl; //Print out error position
				continue; //Skip to the next position
		} else {
			res = 0;
			printarr(inputarr);
		}
	}
	return res;
}

