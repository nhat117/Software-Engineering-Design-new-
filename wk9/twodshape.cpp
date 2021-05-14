#include <iostream>
#include "twodshape.h"

using namespace std;

TwoDShape :: TwoDShape() {
	this -> width = 0;
	this -> height = 0;
}

TwoDShape :: TwoDShape(float w, float h) {
	this -> width = w;
 	this -> height = h;
}

void TwoDShape :: showDim() {
	cout << "Width = " << this -> getw() << "  height = " << this -> geth() << endl; 
}

void TwoDShape :: seth (float h ) {this -> height = h;}
void TwoDShape :: setw (float w ) {this -> width = w;}

float TwoDShape :: getw() {return this -> width;} 
float TwoDShape :: geth() {return this -> height;} 
