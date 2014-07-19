#include "ReversibleStack.h"

ReversibleStack::Node::Node(int num)
{
	data = num;
	next = nullptr;
}

ReversibleStack::ReversibleStack(void)
{
	_top = nullptr;
}

ReversibleStack::~ReversibleStack(void)
{
	delete _top;
	return;
}

// prints my name and ID number on screen
void ReversibleStack::Header(void)
{
	cout << "Cammi Smith\n" << "11366085\n" << endl;
	return;
}

// pushes an integer onto stack
void ReversibleStack::Push(int num)
{
	if (_top == nullptr)
	{
		Node *new_node = new Node(num);
		_top = new_node;
		return;
	}
	Node *new_node = new Node(num);
	Node *temp = _top;
	_top = new_node;
	_top->next = temp;
	return;
}

// pops an item off stack and returns its value
int ReversibleStack::Pop(void)
{
	int num;
	if (_top == nullptr) // if stack is empty, return
	{
		return -1;
	}
	if (_top->next == nullptr) // if stack has only onle element, set element to null
	{
		num = _top->data;
		_top = nullptr;
		return num;
	}
	num = _top->data;
	_top = _top->next;
	return num;
}

// Checks if stack is empty
bool ReversibleStack::isEmpty(void)
{
	if (_top == nullptr)
	{
		return true;
	}
	return false;
}

// Reverses the order of the items on the stack
void ReversibleStack::Reverse(void)
{
	if (_top == nullptr)
	{
		return;
	}
	Node *next = _top->next, *curr = _top, *prev = nullptr;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	_top = prev;
	return;
}
