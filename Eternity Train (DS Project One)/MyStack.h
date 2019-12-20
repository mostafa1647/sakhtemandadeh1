#pragma once
#include <iostream>
#include "Node.h"
#include "MyList.h"

template <class T>
class MyStack
{
public:
	MyStack() {
		list = new MyList<T>();
	}
	bool isEmpty() {
		return this->list->isEmpty();
	}
	bool push(T data) {
		return this->list->push_back(data);
	}
	bool push(Node<T> node) {
		return this->list->push_back(node);
	}
	T pop() {
		return this->list->pop_back();
	}
	int getSize() {
		return this->list->getSize();
	}
	Node<T>* begin() {
		return this->list->begin();
	}
	Node<T>* end() {
		return this->list->end();
	}
private:
	MyList<T>* list;
};