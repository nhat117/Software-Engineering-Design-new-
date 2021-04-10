#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <thread>


using namespace std;
void randoms(long int range,long int index , long int numline, ofstream outfile);

int main (void) {
	ofstream outfile ("result.csv");
	long int numline;
	long int range;
	
	// UI
	cout << "Enter total line number of your csv file: " << endl;
	cin >> numline;
	cout << "Enter maximum num in range: ";
	cin >> range;
	outfile << "x,y" << "\n";
	thread rnd(randoms(range, 0, numline/2, &outfile));
	thread rnd2(randoms(range, numline /2, numline, outfile));
	rnd.join();
	rnd2.join();
	outfile.close();
	return 0;
}

void randoms(long int range,long int index , long int numline, ofstream outfile) {
	int x, y;
	for (int i = index; i < numline; i ++) {
		x = rand() % range + 1;
		y = rand() % range + 1;
		// Using insertion operator
		outfile << x << "," << y;
		if ( i != numline -1) {
			outfile << "\n";
		}
	}
}
