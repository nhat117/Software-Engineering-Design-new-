#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//Function Prototype
int filesize(ifstream &infile);
void outputinsertion (ifstream &infile, char *&buffer, int size);
void outputget (ifstream &infile, char *&buffer, int size);
void outputread (ifstream &infile, char *&buffer, int size);

//Function definition
int main(void) {
	//Variable Initialize
	//Prepare NULL pointer for dynamic memory allocation
	char *bufferinsert = NULL; 
	char *bufferget = NULL; 
	char *bufferread = NULL; 

	// Initialize file stream
	ifstream insertionfile("insertion.hex", ios :: in | ios :: binary);
	ifstream putfile("put.hex", ios :: in | ios :: binary); // Setfile as an output methode
	ifstream writefile("write.hex", ios :: in | ios :: binary);

	// Error check
	if (!insertionfile || !putfile || !writefile) {
		cerr <<"Issue opening file" << endl;
		return -1;
	}

	// size check
	int sizeins = filesize(insertionfile);
	int sizeput = filesize(putfile);
	int sizeread = filesize(writefile);

	// Allocate memory for buffer
	bufferinsert = new char[sizeins]; 
	bufferget = new char [sizeput];
	bufferread = new char [sizeread];

	// Function call
	outputinsertion(insertionfile, bufferinsert, sizeins);
	outputget(putfile, bufferget, sizeput);
	outputread(writefile, bufferread, sizeread);
	
	cout << sizeins;
	
	// Delete dynamic allocated memory
	delete [] bufferinsert;
	delete [] bufferget;
	delete [] bufferread;

	// Close file
	insertionfile.close();
	putfile.close();
	writefile.close();
	return 0;
}

int filesize(ifstream &infile) {
	int fsize = 0;
	streampos begin, end;
	// tellg() return the position of filehandler
	begin = infile.tellg();
	infile.seekg(0, ios :: end); // Move the file ehandler to eof
	end = infile.tellg();
	fsize = end - begin;
	// Reset file handler position
	infile.seekg(0, ios :: beg);
	return fsize;
}

void outputinsertion (ifstream &infile, char *&buffer, int size) {
	cout << "Insertion output : ";
	for (int i = 0 ; i < size; i ++) {
		infile >> buffer[i]; // Use insertion operator
		// Print value
		cout.setf(ios :: hex);
		cout << buffer[i];
	} 
	cout << endl;
}

void outputget (ifstream &infile, char *&buffer, int size) {
	cout << "Get output : ";
	for (int i = 0 ; i < size; i ++) {
		infile.get(buffer[i]); // Use get method
		// Print value
		cout.setf(ios :: hex);
		cout << buffer[i];
	} 
	cout << endl;
}

void outputread (ifstream &infile, char *&buffer, int size) {
	infile.read(buffer, size);
	cout << "Read output : ";
	for (int i =0; i < size ; i ++) {
		cout.setf(ios :: hex);
		cout << buffer[i];
	}
	cout << endl;
}