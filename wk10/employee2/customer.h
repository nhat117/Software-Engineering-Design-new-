#include <iostream>
#include "employee.h"
class CustomerService : public Employee {
	private :
		string ContractType;
		CustomerService *ptr;
	public :
		CustomerService() {ContractType = "Nothing";}
		CustomerService (string Name, int InputId, string Sex, int RateofPay, int StandardWorkHour, int OverTime, string ContractType) : Employee (Name, InputId, Sex, RateofPay, StandardWorkHour, OverTime) {this -> ContractType = ContractType;}
		//Copy
		CustomerService (CustomerService &obj) {
			ptr = new CustomerService;
			*ptr = *obj.ptr;
		}
		//Setter
		void setContract (string TypeContract);

		void setAllCustomerService(string name, int id, string sex, int RateofPay, int StandardWorkHour, int Overtime, string ContractType);
		//Getter
		string getContract () {return this -> ContractType;}

		friend ostream &operator << (ostream &stream,  CustomerService &obj);
		~CustomerService () {delete ptr;}

		//Methode
		int salary();
};