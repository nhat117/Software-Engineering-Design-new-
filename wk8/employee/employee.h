#include <iostream>
#pragma once // To allow main to call only once.
using namespace std;
typedef struct WorkHour {
	int Standard;
	int Overtime;
} WorkHour;

class Employee {
	private :
		string EmployeeName;
		int Id;
		string EmployeeSex;
		int HourlyRateOfPay;
		WorkHour NumberofWorkHour;
		//Employee ptr;
		Employee *ptr;
	public	:
		//Default Constructor 
		Employee () {
			string EmployeeName = "Default Name";
			Id = 0;
			EmployeeSex = "Default";
			HourlyRateOfPay = 0;
			NumberofWorkHour.Standard = 0;
			NumberofWorkHour.Overtime = 0;
		}
		Employee (Employee &obj) { // Copy Constructor, pass by value , assignemnt: Copy constructor wl be invoke

		}
		Employee (string Name, int InputId, string Sex, int RateofPay, int StandardWorkHour, int Overtime);
		
		//Getter and Setter
		//Setter
		void setName (string s) {EmployeeName = s;}
		void setID (int id) {Id = id;} 
		void setEmployeeSex (string sex) {EmployeeSex = sex; }
		void setRateofPay (int RateofPay) {HourlyRateOfPay = RateofPay;}
		void setWorkHour (int StandardWorkHour, int Overtime);
		//All setter
		void setAll(string name, int id, string sex, int RateofPay, int StandardWorkHour, int Overtime) ;

		//Getter
		string getName () {return this -> EmployeeName;}
		int getID () {return this -> Id;}
		string getSex () {return this -> EmployeeSex;}
		int getRateofPay () {return this -> HourlyRateOfPay;}
		WorkHour getWorkHour () {return this -> NumberofWorkHour;}

		//Class methode
		int salary(); 
		
		friend ostream &operator << (ostream &stream, Employee &obj);

		~Employee() {delete ptr;} //Destructor
};
