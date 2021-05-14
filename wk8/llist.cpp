#include "llist.h"
#include "node.h"
llist :: llist () {
	this -> head = NULL;
}

llist :: llist(node *node) {
	this -> head = node;
}
// If allocate memory dynamically, have to delette it manually
~llist :: llist () {
	while (head -> getNext() != NULL) {
		removeLast();
	}
	if (head != NULL) {
		delete head;
	}
}

bool llist :: insertFont(int data) {
	//1. cREAT A NEW node
	node * tmp = new node (data);
	//2. Set Next of new node to head
	tmp -> setNext(head);
	//3. Set head to new node
	head = tmp;
	return true;
}

bool llist :: removeLast() {
	node *tmp = head;
	while (tmp -> getNext() != NULL) {
		tmp = tmp -> getNext();
	}
	delete tmp;
	return true;
}

bool insertMiddle (int data) {
	//1. creat a new node
	node *tmp = new node (data);
	//2. Loops until we can insert a new node
	node *current = head;
	while (current -> getNext() != NULL ) {
		node *prev = current;
		if(current -> getData() > data) {
			//1. 
			tmp -> setNext(curent);
			prev -> setNext(tmp);
			return true;
		}
	}
	current -> setNext(tmp);
	return true;
}

llist :: printList() {
	node *tmp = head;
	while (tmp -> getNext() != NULL) {
		cout << tmp -> getData();
		
	}
}