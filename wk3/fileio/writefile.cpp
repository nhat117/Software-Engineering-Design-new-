#include <iostream>
#include <fstream>

using namespace std;

//Create a custom file structure

int main(void) {

	ofstream outfile("player.txt");

	cout << "Enter player ID and Money" << endl;
	cout << "Press ctrl + z to quit\n" << endl;

	//Variable initialization

	int idNumber;
	string name;
	double money;

	//Create an loops
	while(cin >> idNumber >> name >> money) {
		outfile << idNumber << ' ' << name << ' ' << money << endl;
		//Redirect out stream to file
	}
	return 0;
}