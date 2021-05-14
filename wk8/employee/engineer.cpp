#include "engineer.h"
#include <iostream>
using namespace std;
Engineer :: Engineer () {
	this -> HighestDegree = "Bachelor";
	this -> Expertise = "ML";
}

Engineer :: Engineer (string Name, int InputId, string Sex, int RateofPay, int StandardWorkHour, int OverTime, string Degree, string Expertise) : Employee (Name, InputId, Sex, RateofPay, StandardWorkHour, OverTime) {
	this -> HighestDegree = Degree;
	this -> Expertise = Expertise;
}

ostream &operator << (ostream &stream,  Engineer &obj)  {
	stream << obj;
	stream << "Higheset Degree: " << obj.getDegree() << endl;
	stream << "Expertise: " << obj.getExpertise() << endl;
	return stream;
}