#include <iostream>

class node {
	int data;
	node *next;
	public:
		node() {
			this -> data =1;
			this -> next = NULL;
		}
		node (int data) {
			this -> data = data;
			this -> next = NULL;
		}

		~node() {
			this -> next = NULL;
		}

		node * getData () {
			return this -> data ;
		}
		node *getNext() {
			return this -> next;
		}
		void node setData (int data) {
			this -> data = data;
		}
 };