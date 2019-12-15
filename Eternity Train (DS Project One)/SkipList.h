#pragma once
#include <iostream>
#include "SkipNode.h"

template <class T>
class SkipList
{
private:
	SkipList<T>* head;
	SkipList<T>* rear;

public:
	SkipList() {
		this->head = NULL;
		this->rear = NULL;
	}
	SkipNode<T>* begin(){
		return this->head;
	}
	SkipList<T>* end() {
		return this->rear;
	}
	bool isEmpty() {
		return (this->head == NULL && this->rear == NULL);
	}
	void push_back(T data, SkipNode* down) {
		SkipNode<T>* temp = new SkipNode<T>(data, down);
		this->push_back(temp);
	}
	void push_back(const SkipNode<T> node) {
		SkipNode<T>* temp = new SkipNode<T>(node);
		this->push_back(temp);
	}

private:
	void push_back(SkipNode<T>* temp) {
		if (this->isEmpty())
		{
			this->head = temp;
			this->rear = temp;
			this->head->setNext(NULL);
		}
		else
		{
			this->rear->setNext(temp);
			temp->setNext(NULL);
			this->rear = temp;
		}
	}
};
