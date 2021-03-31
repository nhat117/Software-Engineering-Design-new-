#include <iostream>
#include <fstream>

using namespace std;

//Function prototype
int getWhatTheyWant();
void displayItems(int choice);

// Main function
int main(void) {
	int whatTheyWant;
	whatTheyWant = getWhatTheyWant();

	while(whatTheyWant != 4) { //Loop through the Menufunction
		whatTheyWant = getWhatTheyWant(); // Keep calling the function until value 4 is returned
		switch (whatTheyWant) {
			case 1:
				displayItems(1);
				break;
			case 2:
				displayItems(2);
				break;
			case 3:
				displayItems(3);
				break;
		}
	}
	return 0;
}

// getWhatTheyWant function (Menu function)
int getWhatTheyWant() {
	int choice;

	cout << "1 - just plain items" << endl;
	cout << "2 - helful items" << endl;
	cout << "3 - harmful items" << endl;
	cout << "4 - quit program" << endl;

	cin >> choice;
	return choice;
}

//display items function
void displayItems(int choice) {
	ifstream obj("objects.txt"); // Make if stream objects
	string NameObj;
	double power;

	if (choice == 1) {
		while (obj >> NameObj >> power) {
			if (power == 0) {
				cout << NameObj << ' ' << power << endl;
			}
		}
	}

	if (choice == 2) {
		while (obj >> NameObj >> power) {
			if (power > 0) {
				cout << NameObj << ' ' << power << endl;
			}
		}
	}

	if (choice == 3) {
		while (obj >> NameObj >> power) {
			if (power < 0) {
				cout << NameObj << ' ' << power << endl;
			}
		}
	}
}
