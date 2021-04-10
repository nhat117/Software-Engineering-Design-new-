#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//fUNCTION CALL BACK HELP WITH INCREASE CODE USABILITY
//fUNCTION POINTER TO HELP FUNCTION CALL ANOTHER FUNCTIOIN BY REFERENCE

int comp(const void * a,const void *b) { // Have to be 2 constant variable (void to keep generic)
	int A = *((int *) a); //Type casting pointer; 
	int B = *((int *) b); //Type casting pointer;
	return A-B; // If possitive rank higher
}

int main(void) {
	int i, A[] = {9,2,6,1,5,3};
	qsort(A, 6, sizeof(int), comp);
	for (i = 0; i < 6; i ++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return  0;
} 