#pragma once
#include <iostream>
#include "SkipNode.h"
#include "MyList.h"
#include "Node.h"

template <class T>
class SkipList
{
private:
	SkipNode<T>* head;
	SkipNode<T>* rear;

public:
	static SkipList<T>* generator(MyList<T> list, int size)
	{
		SkipList<T>* tempList = new SkipList<T>();
		SkipNode<T>* newNode = new SkipNode<T>(list.begin()->getData(), list.begin());
		tempList->push_back(newNode);
		for (Node<T>* i = list.begin(); i->getNext()!=NULL; )
		{
			for (int n = 0; n < sqrt(size) - 1 && i->getNext() != NULL; n++)
			{
				i = i->getNext();
			}
			tempList->push_back(i->getData(), i);
		}
		return tempList;
	}
	SkipList() {
		this->head = NULL;
		this->rear = NULL;
	}
	SkipNode<T>* begin(){
		return this->head;
	}
	SkipNode<T>* end() {
		return this->rear;
	}
	bool isEmpty() {
		return (this->head == NULL && this->rear == NULL);
	}
	void push_back(T data, Node<T>* down) {
		SkipNode<T>* temp = new SkipNode<T>(data, down);
		this->push_back(temp);
	}
	void push_back(const Node<T> node) {
		SkipNode<T>* temp = new SkipNode<T>(node);
		this->push_back(temp);
	}
	Node<T> findNode(T data) {
		SkipNode<T>* current = this->head;
		for (;current->getNext() != NULL; current = current->getNext())
		{
			if (current->getNext()->getData() >= data)
			{
				break;
			}
		}
		Node<T>* temp = current->getDown();
		for (; temp->getNext() != NULL ; temp = temp->getNext())
		{
			if (temp->getData() == data)
			{
				break;
			}
		}
		return *temp;
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
