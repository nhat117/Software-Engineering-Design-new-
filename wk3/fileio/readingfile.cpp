#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	ifstream file("player.txt"); //Initializ file stream bject 
	// Automatically being close 

	// Initialize storing variable
	int id;
	string name;
	double money;
	// Every file have eof marker
	while (file >> id >> name >> money) { // Loop through the while loop if have new pc of new info, advance the pointer, store in to variable

		//Output
		cout <<id << ", " << name << ", " <<money << endl;

	}
}