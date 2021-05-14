#include <iostream>
#include "triangle.h"

using namespace std;

Triangle :: Triangle() {
	cout << "Create Triangle";
	this -> setw(0);
	this -> seth(0);
}

float Triangle:: Area() {
	return this -> getw() * this ->geth() /2.0;
}



