#include <iostream>
#include "engineer.h"
#include "customer.h"

using namespace std;

//Drivercode 
int main(void) {
	Engineer employee1;
	cout << employee1;
	employee1.setAllEngineer("Tommy", 2, "Male", 50, 8, 4, "Master", "ML");
	cout << employee1;
	return 0;
}