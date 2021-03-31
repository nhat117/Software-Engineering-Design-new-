#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main (void) {
	ofstream outfile("result.csv");
	// Initialization
	int x;
	int y;
	long int numline;
	long int range;
	
	// UI
	cout << "Enter total line number of your csv file: " << endl;
	cin >> numline;
	cout << "Enter maximum num in range: ";
	cin >> range;
	
	// Csv generator algorithm
	outfile << "x,y" << "\n";
	for (int i = 0; i < numline; i ++) {
		x = rand() % range + 1;
		y = rand() % range + 1;

		// Using insertion operator
		outfile << x << "," << y;
		if ( i != numline -1) {
			outfile << "\n";
		}
	}

	outfile.close();
	return 0;
}