#include <iostream>
#include "employee.h"
using namespace std;
class Engineer : public Employee {
	private :
		string HighestDegree;
		string Expertise;
		Engineer *ptr;
	public :
			//Constructor
			Engineer ();
			Engineer (string Name, int InputId, string Sex, int RateofPay, int StandardWorkHour, int OverTime, string Degree, string Expertise);

			Engineer (const Engineer &obj) { //Copy
				ptr = new Engineer;
				*ptr = *obj.ptr;
			}

			//Setter
			void setDegree (string Degree) {
				if (Degree == "Diploma" || Degree ==  "Master" || Degree == "Bachelor" || Degree == "Doctorate") {
					this -> HighestDegree = Degree;
				}
			}

			void setExpertise (string Expertise) {
				if (Expertise == "Database" || Expertise ==  "ML" || Expertise == "Security" || Expertise == "Web" || Expertise == "Cryptography" || Expertise == "Networking") {
					this -> Expertise = Expertise;
				}
			}

			void setAllEngineer(string name, int id, string sex, int RateofPay, int StandardWorkHour, int Overtime, string Degree, string Expertise) {
				this -> setAll(name, id, sex, RateofPay, StandardWorkHour, Overtime);
				this -> setExpertise(Expertise);
				this -> setDegree(Degree);
			}

			//Getter
			string getDegree () {return this -> HighestDegree;}
			string getExpertise () {return this -> Expertise;}

			friend ostream &operator << (ostream &stream,  Engineer &obj);

			//Destructor
			~Engineer() {delete ptr;} //Destructor

			//Methode

			
};
