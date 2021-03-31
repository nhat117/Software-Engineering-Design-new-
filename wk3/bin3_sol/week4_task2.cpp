#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std;

int main()
{
	int value = 2; // Modify the value to select mode
	char line[] = { 0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F };
	int ints[] = { 23, 36, 10, 00, 127, 256, 873, 365, 1024, 3425, 5096, 231, 943 };
	double doubles[] = { 34.25, 9e15, 3e-09, 935.23, -634.23, 345.92, -254.76, 8.9e5, 436.34e10 };

	ofstream outfile1("insertion.hex", ios::out | ios::binary);
	ofstream outfile2("put.hex", ios::out | ios::binary);
	ofstream outfile3("write.hex", ios::out | ios::binary);

	if (!outfile1 || !outfile2 || !outfile3)
	{
		cerr << "issue opening file for binary output" << endl;
		return 1;
	}
	switch (value)
	{
	case 0:
		for (int i = 0; i < sizeof(line) / sizeof(char); i++)
		{
			outfile1 << line[i];
			outfile2.put(line[i]);
		}
		outfile3.write(line, sizeof(line));
		break;
	case 1:
		for (int i = 0; i < sizeof(ints) / sizeof(int); i++)
		{
			outfile1 << ints[i];
			outfile2.put((char)ints[i]);
		}
		outfile3.write((char*)ints, sizeof(ints));
		break;
	case 2:
		for(int i=0; i<sizeof(doubles)/sizeof(double); i++)
		{
			outfile1 << doubles[i];
			outfile2.put((char)doubles[i]);
		}
		outfile3.write((char*)doubles, sizeof(doubles));
		break;
	default:
		cerr << "Invalid choice of output option" << endl;
		return 1;
	}
	
	//Close file
	outfile1.close();
	outfile2.close();
	outfile3.close();

	return 0;
}