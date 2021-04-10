#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std;

int main()
{	cout << "Enter value 0, 1, 2 : ";
	int value = 0;
	cin >> value;
	char line[] = { 0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F };
	int ints[] = { 23, 36, 10, 00, 127, 256, 873, 365, 1024, 3425, 5096, 231, 943 };
	double doubles[] = { 34.25, 9e15, 3e-09, 935.23, -634.23, 345.92, -254.76, 8.9e5, 436.34e10 };
	char *ptr;
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
		ptr = (char *) ints;
		for (int i = 0; i < sizeof(ints); i++)
		{
			outfile1 << *ptr;
			outfile2.put(*ptr);
			ptr ++;
		}
		outfile3.write((char*)ints, sizeof(ints));
		break;
	case 2:
		ptr = (char *) doubles; //Pointer type casting to transfer from int to char
		for(int i=0; i<sizeof(doubles); i++)
		{
			outfile1 << *ptr;
			outfile2.put(*ptr);
			ptr++; // Pointer arithmetic
		}
		outfile3.write((char*)doubles, sizeof(doubles));
		break;
	default:
		cerr << "Invalid choice of output option" << endl;
		return 1;
	}
	
	outfile1.close();
	outfile2.close();
	outfile3.close();

	return 0;
}