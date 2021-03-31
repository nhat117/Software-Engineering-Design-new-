#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

//Function Prototype
void outint(int intarr[],int sizearr ,ofstream &insertionfile, ofstream &putfile, ofstream &writefile);
void outchar(char charr[],int sizearr ,ofstream &insertionfile, ofstream &putfile, ofstream &writefile);
void outdouble(double doublearr[],int sizearr ,ofstream &insertionfile, ofstream &putfile, ofstream &writefile);

//Function definition
int main(void) {
	// Initialize array
	char charr[] = {0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F};
	int intarr[] = {23, 36, 10, 00, 127, 256, 873, 365, 1024, 3425, 5096, 231, 943};
	double doublearr[] = { 34.25, 9e15, 3e-09, 935.23, -634.23, 345.92, -254.76, 8.9e5, 436.34e10 };
	// Initialize file stream
	ofstream insertionfile("insertion.hex", ios :: out | ios :: binary);
	ofstream putfile("put.hex", ios :: out | ios :: binary); // Setfile as an output methode
	ofstream writefile("write.hex", ios :: out | ios :: binary);

	// Error check
	if (!insertionfile || !putfile || !writefile) {
		cerr <<"Issue opening file" << endl;
		return -1;
	}
	// Ask user for intput
	int input;
	cout << "Enter mode from 1 to convert int_Arr, 2 to convert char_Arr, 3 to convert double_array: " << endl;
	cin >> input;

	switch(input) {
		case 1: {
		// Involke output intara
			int size_arr = sizeof(intarr) / sizeof(int); 
			outint(intarr, size_arr ,insertionfile, putfile, writefile);
			break;
		}
		case 2: {
		// Involke output charaa
			int size_arr = sizeof(charr) / sizeof(char); 
			outchar(charr, size_arr ,insertionfile, putfile, writefile);
			break;
		}
		case 3 : {
			// Involke output doublearr 
			int size_arr = sizeof(doublearr) / sizeof(double); 
			outdouble(doublearr, size_arr ,insertionfile, putfile, writefile);
			break;
		}
	} 

	// Close file
	insertionfile.close();
	putfile.close();
	writefile.close();
	return 0;
}

void outint(int intarr[],int sizearr ,ofstream &insertionfile, ofstream &putfile, ofstream &writefile) {
	
	// Output 1 character at a time
	for (int i = 0; i < sizearr; i ++) {
		insertionfile << intarr[i]; // << is a insertion operator
		putfile.put((char)intarr[i]); // Use put methode (typecasting the char as an individual character)
	}
	writefile.write((char *)intarr, sizearr * sizeof(int)); // 
}

void outchar(char charr[],int sizearr ,ofstream &insertionfile, ofstream &putfile, ofstream &writefile) {
	// Output 1 character at a time
	for (int i = 0; i < sizearr; i ++) {
		insertionfile << charr[i]; // << is a insertion operator
		putfile.put(charr[i]); // Use put methode
	}
	writefile.write(charr, sizearr * sizeof(char));
}

void outdouble(double doublearr[],int sizearr ,ofstream &insertionfile, ofstream &putfile, ofstream &writefile) {
	// Output 1 character at a time
	for (int i = 0; i < sizearr; i ++) {
		insertionfile << doublearr[i]; // << is a insertion operator
		putfile.put(doublearr[i]); // Use put methode
	}
	writefile.write((char *)doublearr, sizearr * sizeof(double));
}


