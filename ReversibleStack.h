#ifndef REVSTACK_H
#define REVSTACK_H

#include <iostream>

using namespace std;

class ReversibleStack
{
private:
	struct Node
	{
		int data;
		Node *next;

		Node(int num);
	};

	Node *_top;
public:
	ReversibleStack(void);

	~ReversibleStack(void);

	// prints my name and ID number on screen
	void Header(void);

	// pushes an integer onto stack
	void Push(int num);

	// pops an item off stack and returns its value
	int Pop(void);

	// Checks if stack is empty
	bool isEmpty(void);

	// Reverses the order of the items on the stack
	void Reverse(void);
};

#endif
