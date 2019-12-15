#pragma once
#include <iostream>
#include <string>
#include "Person.h"

class Station //Nodes
{
private:
	int stationNumber;
	MyList<Person>* personList;

public:
	Station() {
		this->personList = NULL;
	}
	Station(int number) {
		this->personList = NULL;
		this->stationNumber = number;
	}
	Station(const Station& station) {
		this->stationNumber = station.stationNumber;
		this->personList = station.personList;
	}
	MyList<Person>* getPersonList() {
		return this->personList;
	}
	int getStationNumber() {
		return this->stationNumber;
	}
	void setStationNumber(int number) {
		this->stationNumber = number;
	}
	void setPersonList(MyList<Person>* personList) {
		this->personList = personList;
	}
	Station operator=(const Station& station) {
		this->stationNumber = station.stationNumber;
		this->personList = station.personList;
		return *this;
	}
};