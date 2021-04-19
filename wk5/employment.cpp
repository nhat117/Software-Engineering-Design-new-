#include <iostream>
#include <sstream>
#include <string>

#define MAXDOB 11
#define MAXEMPLOYEE 2

using namespace std;

// Class Declaration 
typedef struct {
	int DD;
	int MM;
	int yyyy;
} DOB;

typedef struct {
	string FirstName;
	string LastName;
	DOB DoB [MAXDOB];
	int id;

} Employee;

//Function Prototype;
void InputEmployee (Employee &input) ;
void getdate (DOB &input, string inp);
bool CheckDay (int day, int month);
bool ChkMonth(int month);
bool Chkyy(int yyyy);
void getDOB (DOB &input);

// Function overloading
int EmployeeSearch (Employee employee[], string Firstname, string LastName); 
int EmployeeSearch (Employee employee[], string Firstname);
int EmployeeSearch (Employee employee[], int id);

ostream &operator << (ostream &output , DOB input) {
	output << input.DD << "/" << input.MM << "/" << input.yyyy << endl;
	return output;
}

ostream &operator << (ostream &output, Employee input) {
	output << "Employee Information : " << endl;
	output << "First Name: ";
	output << input.FirstName << endl;
	output << "Last Name: ";
	output << input.LastName << endl;
	output << "DoB: ";
	output << input.DoB;
	output << "id: ";
	output << input.id;
	return output;
}

//Function Definition
int main(void) {
	string FirstName;
	string LastName;
	Employee employee[MAXEMPLOYEE];
	int id, res;
	//Input Employee
	for(int i = 0; i < MAXEMPLOYEE; i ++) {
		InputEmployee(employee[i]);
	}
	cout << endl;
	//OutputEmployee
	cout << "Employee information Output" << endl;
	for(int i = 0; i < MAXEMPLOYEE; i ++) {
		cout << employee[i];
		cout << endl;
	}
	// While loop to keep iterating until the correct result is Enter
	while (1) {
		cout << "Enter FirstName LastName to search: ";
		cin >> FirstName >> LastName;
		res = EmployeeSearch(employee, FirstName, LastName);
		if (res == 0)
			break;
	}
	
	while (1) {
		// Test Function overloading
		cout << "Enter FirstName to search: ";
		cin >> FirstName;
		res = 	EmployeeSearch(employee, FirstName);
		if (res == 0) {
			break;
		}
	}

	while (1) {
		cout << "Enter Id to search: ";
		cin >> id;
		res = EmployeeSearch(employee, id);
		if (res == 0)
			break;
	}
	return 0;
}

void InputEmployee (Employee &input) {
	cout << "First Name: ";
	cin >> input.FirstName;
	cout << "Last Name: ";
	cin >> input.LastName;
	cout << "DoB: ";
	string DoBinp;
	// Promt user to enter correct DoB
	while (1) {
		cin >> DoBinp;
		getdate (*input.DoB, DoBinp);
		if (Chkyy(input.DoB -> yyyy) == true && CheckDay(input.DoB -> DD, input.DoB -> MM) == true && ChkMonth(input.DoB -> MM) == true) {
			break;
		} else {
			cout << Chkyy(input.DoB -> yyyy) << endl;
			cout <<  CheckDay(input.DoB -> DD, input.DoB -> MM) << endl;
			cout <<  ChkMonth(input.DoB -> MM) << endl;
			cerr << "Please enter DoB in an valid format" << endl;
		}
	}
	cout << "id: ";
	cin  >>input.id;
}

void getdate (DOB &input, string inp) {
	string buff;
	//Turn string into a stream
	stringstream ss(inp);
	//Tokenize the strng stream
	ss >> input.DD;
	getline(ss, buff, '/');
	ss >> input.MM;
	getline (ss, buff, '/' );
	ss >> input.yyyy;
}


bool CheckDay(int day, int month) {	
	if (month % 2 == 0 && month < 7 ) {
		if (day > 30) {
			cerr << "Invalid day";
			return false;
		}
	}
	return true;
}

bool ChkMonth(int month) {
	if (month <= 0 || month > 12) {
		cerr << "Please try again";
		return false;
	}
	return true;
}

bool Chkyy(int yyyy) {
	if (yyyy < 1900 || yyyy > 2021)
		return false;
	return true;
}

void OutputEmployee (const Employee &input) {

}

// Search for employee
int EmployeeSearch (Employee employee[], string Firstname, string LastName) {
	int res = 0;
	for (int i = 0 ; i < MAXEMPLOYEE; i ++) {
		if ( employee[i].FirstName.compare(Firstname) == 0 && LastName.compare(employee[i].LastName) == 0) {
			cout << employee[i];
			return res;
		} 
	}
	res = -1;
	cerr << "Unable to find empoyee, Please try again" << endl;
	return res;
}

// Function overloading
int EmployeeSearch (Employee employee[], string Firstname) {
	int res = 0;
	for (int i = 0 ; i < MAXEMPLOYEE; i ++) {
		if ( employee[i].FirstName.compare(Firstname) == 0)  {
			cout << employee[i].FirstName << " " << employee[i].LastName <<  " " << "Id: " << employee[i].id << endl << endl;;
			return res;
		}
	}
	cerr << "Unable to find the employee. Please Try again." << endl;
	res = -1;
	return res;
}

int EmployeeSearch (Employee employee[], int id) {
	int res = 0;
	for (int i = 0 ; i < MAXEMPLOYEE; i ++) {
		if ( employee[i].id == id)  {
			cout << employee[i].FirstName << " " << employee[i].LastName <<  " " << "Id: " << employee[i].id << endl << endl;;
			return res;
		}
	}
	cerr << "Unable to find the employee with " << id << " number. Please Try again." << endl;
	res = -1;
	return res;
}


