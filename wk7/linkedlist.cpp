#include <stdlib.h>
#include <iostream>
using namespace std;
typedef  struct Node{
	int data;
	Node * next;
} Node;

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

void Print (Node *head) {
	cout << "List is: ";
	while (head != NULL) {
		cout << head -> data <<" ";
		head = head -> next;
	}
	cout << endl;
}

int main() {
	Node * head = NULL; // Empty list;
	Insert(&head, 2, 1); //First node
	Insert(&head, 3, 2);
	Insert(&head, 4, 1);
	Insert(&head, 5, 2);
	Print(head);
}