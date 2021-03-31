#include <iostream>

using namespace std;

int main(void) {
	cout.setf(ios :: showpos | ios :: showpoint);
	cout.unsetf(ios :: showpos); // Unsetflag

	auto flags = ios :: showpos | ios :: showpoint | ios :: showbase;
	cout.flags(flags);
	cout << 100.2 << endl;
	cout << -65.2 << endl;
	cout << 10.22 << endl;
	return 0;
}