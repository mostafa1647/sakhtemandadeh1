#pragma once
#include <iostream>
#include "Node.h"
#include "MyList.h"

template <class T>
class MyQueue
{
public:
	MyQueue() {
		list = new MyList<T>();
	}
	bool isEmpty() {
		return this->list->isEmpty();
	}
	bool enqueue(T data) {
		return this->list->push_back(data);
	}
	bool enqueue(Node<T> node) {
		return this->list->push_back(node);
	}
	T dequeueu() {
		return this->list->pop_front();
	}
private:
	MyList<T>* list;
};