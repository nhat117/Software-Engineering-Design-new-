#include <iostream>

using namespace std;

int *Sum (int * a, int * b); 

int main(void) {
	int a = 5;
	int b = 6;

	cout << "Sum " << a << " and " << b << " is : " << *Sum(&a, & b) << endl;
	return 0;
}

int *Sum (int *a, int * b) {
	int c = *a + *b;
	int *res = &c;
	return res;
}