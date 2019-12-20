#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	Node() {
		this->next = nullptr;
		//this->prev = nullptr;
	}
	Node(const Node& node) {
		this->data = node.data;
		this->next = node.next;
		//this->prev = node.prev;
	}
	Node(T data) {
		this->data = data;
		this->next = NULL;
		//this->prev = NULL;
	}
	void setNext(Node<T>* next) {
		this->next = next;
	}
	/*void setPrev(Node<T>* prev) {
		this->prev = prev;
	}*/
	Node<T>* getNext() {
		return this->next;
	}
	/*Node<T>* getPrev() {
		return this->prev;
	}*/
	T getData() {
		return this->data;
	}



private:
	T data;
	Node<T>* next;
	//Node<T>* prev;
};
