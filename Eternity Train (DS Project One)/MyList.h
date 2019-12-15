#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class MyList
{
	Node<T>* head;
	Node<T>* rear;
public:
	MyList() {
		this->head = NULL;
		this->rear = NULL;
	}
	Node<T>* begin() {
		return this->head;
	}
	Node<T>* end() {
		return this->rear;
	}
	bool isEmpty() {
		if (this->head == NULL && this->rear == NULL)
		{
			return true;
		}
		return false;
	}
	bool push_back(T data) {
		Node<T>* temp = new Node<T>(data);
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
		return true;
	}
	bool push_front(T data) {
		Node<T>* temp = new Node(data);
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
		return true;
	}
	bool push_back(Node<T> node) {
		Node<T>* temp = new Node<T>(node);
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
		return true;
	}
	bool push_front(Node<T> node) {
		Node<T>* temp = new Node(node);
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
		return true;
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
			return data;
		}
		else
		{
			Node<T>* temp = this-> rear;
			T data = temp->getData();
			this->rear = temp->getPrev();
			this->rear->setNext(NULL);
			delete temp;
			return data;
		}
	}
	T pop_front() {
		if (this->isEmpty())
		{
			return false;
		}
		else
		{
			Node<T>* temp = this -> head;
			T data = temp->getData();
			this->head = temp->getNext();
			this->head->setPrev(NULL);
			delete temp;
			return data;
		}
	}

};