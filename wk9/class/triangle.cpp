#include "triangle.h"

using namespace std;

float Triangle :: area() {
	return this -> getw() * this -> geth() / 2.0;
}