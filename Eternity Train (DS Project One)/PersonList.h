//#pragma once
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//#include "Person.h"
//using namespace std;
//
//class PersonList {
//private:
//	Person* head;
//	Person* rear;
//	int size;
//
//public:
//	PersonList() {
//		this->head = NULL;
//		this->rear = NULL;
//		this->size = 0;
//	}
//	Person* begin() {
//		return this->head;
//	}
//	Person* end() {
//		return this->rear;
//	}
//	int getSize() {
//		return this->size;
//	}
//	bool isEmpty() {
//		return (this->head == NULL && this->rear == NULL);
//	}
//	void push_back(Person* human) {
//		if (this->isEmpty())
//		{
//			this->head = human;
//			this->rear = human;
//			human->setNext(NULL);
//			human->setPrev(NULL);
//		}
//		else
//		{
//			human->setPrev(this->rear);
//			human->setNext(NULL);
//			this->rear->setNext(human);
//			this->rear = human;
//		}
//		this->size++;
//	}
//	void push_front(Person* human) {
//		if (this->isEmpty())
//		{
//			this->head = human;
//			this->rear = human;
//			human->setNext(NULL);
//			human->setPrev(NULL);
//		}
//		else
//		{
//			human->setNext(this->head);
//			human->setPrev(NULL);
//			this->rear->setPrev(human);
//			this->rear = human;
//		}
//		this->size++;
//	}
//};
