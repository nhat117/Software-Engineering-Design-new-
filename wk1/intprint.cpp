#include <iostream>
#include <cstring>

#define MAXARG 11 // Accept 10 input argument from the user

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
	int res = 0;
	for (int i = 0; i < sizeof(*input) / sizeof(input[0]); i ++) {
		if (isdigit(input[i]) == 0) { // Check to see if enter digit is valid
			cout << isdigit(input[i]) << endl; 
			cout << "Invalid int" <<endl;
			res = -1;
			break;
		} else {
			res = 0;
		}
	}
	// Check for res
	if(res == 0) {
		*inputarr = atof(input); //Convert str arr to float and store in the array
	}
	return res;
}

void printarr(float *inputarr) {
	for (int i = 0; i < MAXARG - 1; i ++) {
		cout << *(inputarr + i) << " ";
	}
	cout << endl;
}

int inout(char *input[], float *inputarr, int *argc) {
	int res;
	// Feed floatchk 
	for (int i = 1; i <= *argc - 1; i ++ ) {
		if (floatchk(input[i], &inputarr[i -1]) == -1) {
				cout << "Invalid int" << endl;
				res = -1;
				break;
		} else {
			res = 0;
			printarr(inputarr);
		}
	}
	return res;
}

