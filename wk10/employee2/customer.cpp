#include <iostream>
#include "customer.h"

using namespace std;

void CustomerService :: setContract (string TypeContract) {
	if (TypeContract == "Full Time" || TypeContract ==  "Part Time" || TypeContract == "Casual") {
		this -> ContractType = TypeContract;
	}
}

ostream &operator << (ostream &stream,  CustomerService &obj)  {
	stream << obj;
	stream << "Contractype: " << obj.getContract() << endl;
	return stream;
}

void CustomerService :: setAllCustomerService(string name, int id, string sex, int RateofPay, int StandardWorkHour, int Overtime, string ContractType) {
	this -> setAll(name, id, sex, RateofPay, StandardWorkHour, Overtime);
	this -> setContract(ContractType);
}

int CustomerService::salary() {
	int rate ;
	if (this -> getContract() == "Full Time") {rate = 1;}
	else if (this -> getContract() == "Part Time") {rate = 2;}	 
	else if (this -> getContract() == " Casual") {rate = 3;}

	int salary = (this -> getWorkHour().Standard *this -> getRateofPay() * rate ) + (this -> getWorkHour().Overtime * this -> getRateofPay() * 2);
	return salary;
}