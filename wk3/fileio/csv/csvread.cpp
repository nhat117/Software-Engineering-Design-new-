#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Prototype
bool Numberchk(string & inputstr);
int Fsize(ifstream &infile);
int Line(ifstream & infile);

int main(void) {
	ifstream file("tset.csv");
	int size = Fsize(file);
	int sizeline = Line(file);
	int index = 0;

	// Initialize pointer
	int *x = NULL;
	int *y = NULL;

	// Allocate Memory
	x = new int[sizeline];
	y = new int [sizeline];

	for(int i = 0; !file.eof() ; i ++) {
		//Initialize Buffer
		string bufx, bufy;
		//Use getline to read data from csv
		getline(file, bufx, ','); 
		getline(file, bufy, '\n');
		if(Numberchk(bufx) == true &&  Numberchk(bufy) == true) {
			x[index] = stoi(bufx);
			y[index] = stoi(bufy);
			index ++; // Increase index
		} else {
			continue;
		}
	}

	for (int i = 0; i < sizeline - 1; i ++) {
		cout << "x :" << x[i] << " " << "y: " << y[i] << endl;
	}
	
	// Delete allocated memory
	delete [] x;
	delete [] y;

	return 0;
}

// Numberchk
bool Numberchk(string & inputstr) {
    return inputstr.find_first_not_of("0123456789") == string::npos; // Find if the string have number in it
}

// Filesize check to see how many elements
int Fsize(ifstream &infile) {
	int fsize = 0;
	streampos begin, end;
	//Tellg return the position of File Handler
	begin = infile.tellg(); // Determine the beginning position
	infile.seekg(0, ios :: end); // Move the file handler to the eof
	end = infile.tellg();
	fsize = end - begin;
	// Reset filehandler position
	infile.seekg(0, ios :: beg);
	return fsize; 
}

// File size check to see how mant lione
int Line(ifstream & infile) {
	string temp;
	int size = 0;
	while(!infile.eof()) {
		getline(infile, temp);
		size ++;
	}
	// Reset file handler position
	infile.seekg(0, ios :: beg);
	return size;
}
