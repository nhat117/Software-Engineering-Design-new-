#include <iostream>
#include <string.h>
#include "employee.h"
using namespace std;

Employee:: Employee (string Name, int InputId, string Sex, int RateofPay, int StandardWorkHour, int OverTime) {
	this -> EmployeeName = Name;
	this -> Id = InputId;
	this -> EmployeeSex = Sex;
	this -> HourlyRateOfPay = RateofPay;
	this -> NumberofWorkHour.Standard = StandardWorkHour;
	this -> NumberofWorkHour .Overtime = OverTime;
}

void Employee :: setWorkHour (int StandardWorkHour, int Overtime) {
	NumberofWorkHour.Standard = StandardWorkHour;
	NumberofWorkHour.Overtime = Overtime;
}

void Employee :: setAll(string name, int id, string sex, int RateofPay, int StandardWorkHour, int Overtime) {
	this -> setName(name);
	this -> setID (id);
	this -> setEmployeeSex(sex);
	this -> setRateofPay(RateofPay);
	this -> setWorkHour(StandardWorkHour, Overtime);
}

//Default Constructor


// Insertion operator overload
ostream &operator << (ostream &stream, Employee &obj)  {
	stream << "Employee name: " << obj.getName() << endl;
	stream << "Id : " << obj.getID() << endl;
	stream << "Sex: " << obj.getSex() << endl;
	stream << "Hourly Pay: " << obj.getRateofPay()<< endl;
	stream << "Standard Work Hour: " << obj.getWorkHour().Standard << endl;
	stream << "Overtime Work Hour: " << obj.getWorkHour().Overtime << endl;
	return stream;
}

