#pragma once
#include <iostream>

template <class T>
class ArrayList
{
public:
	ArrayList(int capacity = 10) {
		this->data = new T[10];
		this->size = 0;
		this->capacity = capacity;
	}
	~ArrayList() {
		delete data;
	}
	int getCapacity() {
		return this->capacity;
	}
	int getSize() {
		return this->size;
	}
	void push_back(T object) {
		if (this->size < this->capacity) {
			this->data[size] = object;
		}
		else
		{
			T* temp = new T[2 * capacity];
			for (int i = 0; i < this->size; i++)
			{
				temp[i] = this->data[i];
			}
			this->data = temp;
			this->capacity *= 2
		}
		this->size++;
	}
	T pop_back() {
		if (this->size == 0)
		{
			return false;
		}
		else
		{
			T* temp = new T[this->capacity];
			for (int i = 0; i < this->size - 1; i++)
			{
				temp[i] = this->data[i];
			}
			return 
		}
	}
private:
	int size;
	int capacity;
	T* data;
};

