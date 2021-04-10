#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip>
using namespace std;

int filesize(ifstream &infile);
void outputinsertion (ifstream & input,char *&buffer ,int size);
void outputread (ifstream &infile, char *&buffer, int size);

int main()
{
	setbase(16);
	char *buffer = NULL;
	//Init
	ifstream outfile3("insertion.hex", ios:: in | ios::binary);
	if (!outfile3)
	{
		cerr << "issue opening file for binary output" << endl;
		return 1;
	}
	int size = filesize(outfile3);
	buffer = new char[size];
	cout << size << endl;
	outputinsertion(outfile3, buffer,size);
	// outputread(outfile3, buffer, size);
	delete [] buffer;
	outfile3.close();
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

void outputinsertion (ifstream &input, char *&buffer ,int size) {
	for (int i = 0; i < size ; i ++) {
		// input >> buffer[i]; // User insertion operator
		input.get(buffer[i]);
		cout << buffer[i];
	}
	cout << endl;
	cout << size <<endl;
}

void outputread (ifstream &infile, char *&buffer, int size) {
	infile.read(buffer, size);
	cout << "Read output : ";
	for (int i =0; i < size ; i ++) {
		cout << buffer[i];
		// cout << i;
	}
	cout << endl;
}