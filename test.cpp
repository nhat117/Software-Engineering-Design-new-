#include <iostream>
 
using namespace std;

int main (void) {
	int a = 100, b = 100;
	int n = 10;
	a <<= n; //Equal a * 2^n
	b >>= n; // Equal a / 2*n
	cout << a << endl;
	cout << b << endl;
}