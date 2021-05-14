#include <stdlib.h>
#include <iostream>

using namespace std;

typedef  struct Node{
	int data;
	Node * next;
} Node;

//Function Prototype
void Insert (Node ** head, int x);
inline void Insert(Node **head,int data, int n);
inline void Delete (int n, Node **head) ;
inline void Deletecontent (int data, Node **head);
inline void Print (Node *head);
inline void Reverse(Node ** head);
void PrintRec (Node * p);

int main() {
	Node * head = NULL; // Empty list;
	Insert(&head, 2, 1); //First node
	Insert(&head, 3, 2);
	Insert(&head, 4, 1);
	Insert(&head, 5, 2);
	// Print(head);
	PrintRec(head);
	// Delete(2, &head);
	// Deletecontent(4, &head);
	Reverse(&head);
	cout << " " << endl;
	PrintRec(head);
	return 0;
}

// Insert a node at the beginning of the linked list
void Insert (Node ** head, int x) {
	Node * tmp = (Node *) malloc (sizeof(Node));
	tmp -> data = x;
	tmp -> next = NULL;
	if (*head != NULL) 
		tmp -> next = *head;
	*head = tmp;
}
// Insert at the nth position

inline void Insert(Node **head,int data, int n) {
	Node * tmp1 = new Node ();
	tmp1 -> data = data;
	tmp1 -> next = NULL;
	if (n == 1) {
		tmp1 -> next = *head;
		*head = tmp1;
		return;
	}
	Node * tmp2 = *head;
	for (int i = 0; i < n-2 ; i++) {
		tmp2 = tmp2 -> next;
	}
	tmp1 -> next = tmp2 -> next;
	tmp2 -> next = tmp1;
};

// Delete the node at nTh position
inline void Delete (int n, Node **head) {
	Node * temp1 = *head;
	if (n ==1) {
		*head = temp1 -> next; // head now points to second node
		free(temp1);
		return;
	}

	for (int i = 0; i < n-2 ; i ++) {
		temp1 = temp1 -> next;
	}  
	// Temp1 point to (n-1 ) th node
	Node * temp2 = temp1 -> next;
	temp1 -> next = temp2 -> next; // (n+1) th node
	free (temp2); // Delete temp2
}

//Delete content of the linkelist
inline void Deletecontent (int data, Node **head) {
	Node * temp1 = *head;
	Node * temp2;

	if (data == temp1 -> data) {
		*head = temp1 -> next; // head now points to second node
		free(temp1);
		return;
	}

	while (temp1 != NULL && temp1 -> data != data) {
		temp1 = temp1 -> next;
	} 

	if (temp1 == NULL) 
		return;
	temp2 -> next = temp1 -> next;
	temp1 -> next = temp2 -> next;
	free(temp1);

}

//Reverse linked listed
inline void Reverse(Node ** head) {
	Node *current = *head;
	Node *prev = NULL, *next;
	while (current != NULL) {
		next = current -> next;  // Set the adress of current -> next =to the adresse of next node
		current -> next = prev;
		prev = current;
		current = next;
	} 
	*head = prev; //Update the head
}

inline void Print (Node *head) {
	cout << "List is: ";
	while (head != NULL) {
		cout << head -> data <<" ";
		head = head -> next;
	}
	cout << endl;
}

void PrintRec( Node * p) { // Print in reverse order
	if (p == NULL) {
		cout << endl;
		return;} // Exit Condition
	cout << p-> data << " ";
	PrintRec (p-> next); // Recursive call
}

void ReverseRec(Node *p, Node ** head) {
	if (p -> next == NULL) {
		*head = p;
		return;
	}
	
	Node * q = p-> next;
	q -> next = p;
	p -> next = NULL;
	ReverseRec(p -> next, head);
}