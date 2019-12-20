#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class MyList
{
	Node<T>* head;
	Node<T>* rear;
	int size;
public:
	MyList() {
		this->head = NULL;
		this->rear = NULL;
		this->size = 0;
	}
	Node<T>* begin() {
		return this->head;
	}
	Node<T>* end() {
		return this->rear;
	}
	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		if (this->size == 0 || (this->head == NULL && this->rear == NULL))
		{
			return true;
		}
		return false;
	}
	bool push_back(T data) {
		Node<T>* temp = new Node<T>(data);
		return push_back(temp);
	}
	bool push_front(T data) {
		Node<T>* temp = new Node(data);
		return this->push_front(temp);
	}
	bool push_back(Node<T> node) {
		Node<T>* temp = new Node<T>(node);
		return push_back(temp);
	}
	bool push_front(Node<T> node) {
		Node<T>* temp = new Node(node);
		return this->push_front(temp);
	}
	T pop_back() {
		if (this->isEmpty())
		{
			return false;
		}
		else if (this->rear == this->head) {
			Node<T>* temp = this->rear;
			T data = temp->getData();
			this->rear = NULL;
			this->head = NULL;
			delete temp;
			this->size--;
			return data;
		}
		else
		{
			Node<T>* temp = this-> rear;
			T data = temp->getData();
			//this->rear = temp->getPrev();
			Node<T>* i;
			for (i = this->head; i->getNext() != rear; i = i->getNext());
			this->rear = i;
			this->rear->setNext(NULL);
			delete temp;
			this->size--;
			return data;
		}
	}
	T pop_front() {
		if (this->isEmpty())
		{
			this->size = 0;
			return false;
		}
		else
		{
			Node<T>* temp = this -> head;
			T data = temp->getData();
			this->head = temp->getNext();
			delete temp;
			this->size--;
			return data;
		}
	}
	Node<T> findNode(T data) {
		Node<T>* current = this->head;
		for (; current->getNext() != NULL; current = current->getNext())
		{
			if (current->getData() == data)
			{
				break;
			}
		}
		return *current;
	}
private:
	bool push_back(Node<T>* temp) {
			if (temp == nullptr)
			{
				return false;
			}
			if (isEmpty())
			{
				this->head = temp;
				this->rear = temp;
				this->head->setNext(NULL);
				//this->head->setPrev(NULL);
			}
			else {
				this->rear->setNext(temp);
				//temp->setPrev(this->rear);
				temp->setNext(NULL);
				this->rear = temp;
			}
			this->size++;
			return true;
		}
	bool push_front(Node<T>* temp) {
			if (temp == NULL)
			{
				return false;
			}
			if (this->isEmpty())
			{
				this->head = temp;
				this->rear = temp;
				this->head->setNext(NULL);
				//this->head->setPrev(NULL);
			}
			else
			{
				//this->head->setPrev(temp);
				temp->setNext(this->head);
				//temp->setPrev(nullptr);
				this->head = temp;
			}
			this->size++;
			return true;
		}
};