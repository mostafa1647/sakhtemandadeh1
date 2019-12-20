#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class SkipNode
{
public:
	SkipNode() {
		this->next = nullptr;
		this->down = nullptr;
	}
	SkipNode(T data) {
		this->data = data;
		this->next = nullptr;
		this->down = nullptr;
	}
	SkipNode(T data, Node<T>* down) {
		this->data = data;
		this->next = nullptr;
		this->down = down;
	}
	SkipNode(const SkipNode<T>& node){
		this->data = node.data;
		this->next = node.next;
		this->down = node.down;
	}
	void setData(T data) {
		this->data = data;
	}
	void setNext(SkipNode<T>* next) {
		this->next = next;
	}
	void setDown(SkipNode<T>* down) {
		this->down = down;
	}
	T getData() {
		return this->data;
	}
	SkipNode<T>* getNext() {
		return this->next;
	}
	Node<T>* getDown() {
		return this->down;
	}

protected:
	//Empty

private:
	T data;
	SkipNode<T>* next;
	Node<T>* down;
};
