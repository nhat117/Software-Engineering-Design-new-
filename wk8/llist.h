#include <iostream>
#include "node.h"

class llist {
	node * head;
	public:
		llist ();
		llist(node *);
		~llist();

		bool insertFont(int data);
		bool insertMiddle(int data);
		bool deleteNode(int data);
		bool aapendback(int data);
		bool removeLast();
};
