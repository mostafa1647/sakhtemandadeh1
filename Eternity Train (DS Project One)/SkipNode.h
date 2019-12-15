#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

//template <class T>
//union Down
//{
//	SkipNode<T>* snDown;
//	Node<T>* nDown;
//};

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
	SkipNode(T data, SkipNode<T>* down) {
		this->data = data;
		this->next = nullptr;
		this->down = down;
	}
	SkipNode(const SkipNode& node){
		this->data = node.data;
		this->next = node.next;
		this->down = node.down;
	}
	void setData(T data) {
		this->data = data;
	}
	void setNext(SkipNode* next) {
		this->next = next;
	}
	void setDown(SkipNode* down) {
		this->down = down;
	}
	T getData() {
		return this->data;
	}
	SkipNode* getNext() {
		return this->next;
	}
	SkipNode* getDown() {
		return this->down;
	}

protected:
	//Empty

private:
	T data;
	SkipNode* next;
	SkipNode* down;
};
