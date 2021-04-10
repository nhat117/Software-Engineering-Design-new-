#include <iostream>
#include <math.h>
using namespace std;
//Flag to change increase number
// Flag to set mode of buble sort
int cmp(int a, int b);
void BubbleSort (int * A, int n, int (*cmp) (int ,int));
//Sort absolute
int abscmp(int a, int b);


int main(void) {
	int i, A [] = {-3,2,-5,1,6,4,9};
	// BubbleSort (A,7, cmp);
	BubbleSort(A, 7, abscmp);
	for (i = 0; i < 6; i ++) {
		cout << A[i] << " " << endl;
	} 
}

void BubbleSort (int * A, int n, int (*cmp) (int ,int)) { // Function pointer to call back function
	int i, j ,tmp;
	for (i = 0; i < n; i ++) {
		for (j = 0; j < n-1; j ++) {
			if (cmp(A[j],A[j + 1]) > 0) { // Cmp A[j] with A[j +1]
				tmp = A [j];
				A [j] =  A [j + 1];
				A [j+1] = tmp;
			}
		}
	}
}

int cmp(int a, int b) {
	if (a > b)
		return 1; 
	return -1;
}

int abscmp(int a, int b) {
	if (abs(a) > abs(b))
		return 1; 
	return -1;
}