#include <iostream>

using namespace std;

class Vct{
	private :
		int x;
		int y;
	public:
		Vct () {
			int x , y = 0;
		}
		// Constructor
		Vct (int a, int b) {
			x = a;
			y = b;
		}
		//This is a pointer
		// Getter 
		inline int GetX() {return this -> x;}
		inline int GetY() {return this -> y;}
		//Setter
		void SetX (int a) {this -> x = a;}
		void SetY (int b) {this -> y = b;}

		//Operator overload
		Vct operator + (Vct &a) {
			Vct tmp;
			tmp.x = this -> x + a.x;
			tmp.y = this -> y + a.y;
			return tmp;
		}

		Vct operator - (Vct &a) {
			Vct tmp;
			SetX(this -> x - a.x);
			SetY(this -> y - a.y);
			return tmp;
		}

		int operator * (Vct &a) {
			int res;
			res = this -> x * a.x + this -> y * a.y;
			return res;
		}

		//Friend function declaration
		friend ostream &operator << (ostream &output, Vct &a);
		friend istream & operator >> (istream & input, Vct &a);
		friend Vct operator * (int a, Vct &b);

};

//Scalar multiplication
Vct operator * (int a, Vct &b) {
	Vct tmp;
	tmp.SetX(b.x * a);
	tmp.SetY(b.y * a); 
	return tmp;
}

//Stream overloading

//Input overloading
istream & operator >> (istream & input, Vct &a) {
	input >> a.x >> a.y;
	return input;
}

//Output overloading
ostream &operator << (ostream &output, Vct &a) {
	output << "( " << a.GetX() << ", " << a.GetY() << " )";
	return output;
}

int main(void) {
	Vct a, b, c; 
	int scalar;
	cout << "Enter 1st vector: ";
	cin >> a;
	cout << "Enter 2nd vector: ";
	cin >> b; 
	c = a + b;
	cout << a <<" + " << b << " = " << c << endl;
	cout << "Enter Scalar ";
	cin >> scalar;
	c = scalar * a;
	cout << scalar << "*" << a << " = " << c << endl;
	cout << a << " . " << b << "is " << a * b << endl;
 	return 0;
}