#pragma once
#include <iostream>
#include <string>
#include "MyStack.h"
using namespace std;

class Person //Nodes
{
	//Type Of Food = Unknown
public:
	Person() {
		this->id = 0;
		this->foods = NULL;
	}
	Person(int id) {
		this->setId(id);
		this->foods = new MyStack<int>();
	}
	Person(const Person& person) {
		this->id = person.id;
		this->foods = person.foods;
	}
	void setId(int id) {
		this->id = id;
	}	
	void setFoods(MyStack<int>* food) {
		this->foods = food;
	}
	void setFoods(int food[], int n) {
		for (int i = 0; i < n; i++)
		{
			this->foods->push(food[i]);
		}
	}
	int getId() {
		return this->id;
	}
	MyStack<int>* getFoods() {
		return this->foods;
	}
	Person operator=(const Person& person) {
		this->id = person.id;
		this->foods = person.foods;
		return *this;
	}
private:
	int id;
	MyStack<int>* foods;
};