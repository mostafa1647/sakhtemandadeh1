// Eternity Train (DS Project One).cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Node.h"
#include "MyList.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "Person.h"
#include "Station.h"
#include "SkipNode.h"
#include "SkipList.h"
using namespace std;

#define NUMBER_OF_STATIONS 50
const string foodsName[] = {""};

int* shuffle(int* arr) {
	int random, temp;
	srand((unsigned)time(NULL));
	for (int i = 0; i < NUMBER_OF_STATIONS; i++)
	{
		random = rand() % 50;
		temp = arr[i];
		arr[i] = arr[random];
		arr[random] = temp;
	}
	return arr;
}
pair<int*, int> split(string str, char pattern) {
	int* tokens = new int[50];
	int prevLocation = 0, j = 0;
	for (int i = 0; str[i] != NULL; i++)
	{
		if (str[i] == pattern)
		{
			tokens[j] = stoi(str.substr(prevLocation, str.find(pattern, prevLocation) - prevLocation));
			prevLocation = i + 1;
			j++;
		}
	}
	tokens[j] = stoi(str.substr(prevLocation, str.size()));
	return make_pair(tokens, ++j);
}
void printOutput(int firstTrainPeople, int secondTrainPeople,
	MyList<Station>* firstTarinStationList, MyList<Station>* secondTarinStationList,
	MyQueue<Person>* firstTrainPassengersQueueu, MyQueue<Person>* secondTrainPassengersQueueu,
	SkipList<Station>* firstTrainSkipList) {

	cout << (char)201;
	for (int i = 0; i < 45; i++)
		cout << (char)205;

	cout << (char)187 << endl;
	cout << (char)186 << " Number of people on the first train: " << firstTrainPeople << "    " << (char)186 << endl;
	cout << (char)186 << " Number of people on the second train: " << secondTrainPeople << "   " << (char)186 << endl;

	Node<Station>* current = secondTarinStationList->begin();
	int currentStationNumber, AtoB, BtoA;
	for (; current != NULL; current = current->getNext())
	{
		currentStationNumber = current->getData().getStationNumber();
		cout << (char)186 << setw(3) << currentStationNumber << ": ";
		AtoB = firstTrainSkipList->findNode(currentStationNumber).getData().getPersonList()->getSize();
		BtoA = current->getData().getPersonList()->getSize();
		cout << "A -> B = ";
		cout << setw(3) << AtoB << "   " << (char)186 << "   " << "B -> A = ";
		cout << setw(3) << BtoA;
		for (int i = 0; i < 9; i++)
		{
			cout << " ";
		}
		cout << (char)186 << endl;
	}
	cout << (char)200;
	for (int i = 0; i < 45; i++)
		cout << (char)205;

	cout << (char)188 << endl;

	Person p;
	MyStack<int>* f;
	cout << "First Train Food Queue:" << endl;
	for (; !firstTrainPassengersQueueu->isEmpty();)
	{
		p = firstTrainPassengersQueueu->dequeueu();
		f = p.getFoods();
		cout << setw(3) << p.getId() << ":[";
		for (;!f->isEmpty();)
		{
			cout << f->pop();
			if (!f->isEmpty()) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
	cout << endl << "Second Train Food Queue:" << endl;
	for (; !secondTrainPassengersQueueu->isEmpty();)
	{
		p = secondTrainPassengersQueueu->dequeueu();
		f = p.getFoods();
		cout << setw(3) << p.getId() << ":[";
		for (;!f->isEmpty();)
		{
			cout << f->pop();
			if (!f->isEmpty()) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
}


int main()
{
	int firstTrainPeople, secondTrainPeople, oneTillFifty[NUMBER_OF_STATIONS];
	MyList<Station>* firstTarinStationList = new MyList<Station>();
	MyList<Station>* secondTarinStationList = new MyList<Station>();
	MyQueue<Person>* firstTrainPassengersQueueu = new MyQueue<Person>();
	MyQueue<Person>* secondTrainPassengersQueueu = new MyQueue<Person>();
	SkipList<Station>* firstTrainSkipList;
	int *firstTrainStops, numberOfFirstTrainStops;
	int *secondeTrainStops, numberOfSecondTrainStops;
	int numberOfPassenger, id, ignoreStation, numberOfFood;
	int numberOfPassengerTransferredFromAtoB;
	int numberOfPassengerTransferredFromBtoA;
	
	for (int i = 0; i < NUMBER_OF_STATIONS; i++)
	{
		firstTarinStationList->push_back(i + 1);
		oneTillFifty[i] = i + 1;
	}
	shuffle(oneTillFifty);
	for (int i = 0; i < NUMBER_OF_STATIONS; i++)
	{
		secondTarinStationList->push_back(oneTillFifty[i]);
	}
	firstTrainSkipList = SkipList<Station>::generator(*firstTarinStationList, firstTarinStationList->getSize());


	cin >> firstTrainPeople;
	cin >> secondTrainPeople;	
	cin >> numberOfFirstTrainStops;
	firstTrainStops = new int[numberOfFirstTrainStops];
	for (int i = 0; i < numberOfFirstTrainStops; i++)
	{
		cin >> firstTrainStops[i];
	}
	cin >> numberOfSecondTrainStops;
	secondeTrainStops = new int[numberOfSecondTrainStops];
	for (int i=0;i<numberOfSecondTrainStops;i++)
	{
		cin >> secondeTrainStops[i];
	}


	Person* newPersonPointer;
	int foodVariable;
	MyList<Person>** firstTrainPassengerListsArray = new MyList<Person> * [numberOfFirstTrainStops];
	for (int i = 0; i < numberOfFirstTrainStops; i++)
	{
		cin >> ignoreStation;
		cin >> numberOfPassenger;
		firstTrainPassengerListsArray[i] = new MyList<Person>();
		for (int j = 0; j < numberOfPassenger; j++)
		{
			cin >> id;
			newPersonPointer = new Person(id);
			cin >> numberOfFood;
			for (int k = 0; k < numberOfFood; k++)
			{
				cin >> foodVariable;
				newPersonPointer->getFoods()->push(foodVariable);
			}
			firstTrainPassengersQueueu->enqueue(*newPersonPointer); //Add to Food Queue
			firstTrainSkipList->findNode(ignoreStation).getData().getPersonList()->push_back(*newPersonPointer); //Add to Station List
			firstTrainPassengerListsArray[i]->push_back(*newPersonPointer);
		}
	}

	MyList<Person>** secondTrainPassengerListsArray = new MyList<Person> * [numberOfSecondTrainStops];
	for (int i = 0; i < numberOfSecondTrainStops; i++)
	{
		cin >> ignoreStation; //Station
		cin >> numberOfPassenger;
		secondTrainPassengerListsArray[i] = new MyList<Person>();
		for (int j = 0; j < numberOfPassenger; j++)
		{
			cin >> id;
			newPersonPointer = new Person(id);
			cin >> numberOfFood;
			for (int k = 0; k < numberOfFood; k++)
			{
				cin >> foodVariable;
				newPersonPointer->getFoods()->push(foodVariable);
			}
			secondTrainPassengersQueueu->enqueue(*newPersonPointer); //Add to Food Queue
			secondTarinStationList->findNode(ignoreStation).getData().getPersonList()->push_back(*newPersonPointer); //Add to Station List
			secondTrainPassengerListsArray[i]->push_back(*newPersonPointer);
		}
	}

	numberOfPassengerTransferredFromAtoB = firstTrainPassengersQueueu->getSize();
	numberOfPassengerTransferredFromBtoA = secondTrainPassengersQueueu->getSize();
	firstTrainPeople = firstTrainPeople - numberOfPassengerTransferredFromAtoB + numberOfPassengerTransferredFromBtoA;
	secondTrainPeople = secondTrainPeople + numberOfPassengerTransferredFromAtoB - numberOfPassengerTransferredFromBtoA;

	printOutput(firstTrainPeople, secondTrainPeople,
		firstTarinStationList, secondTarinStationList,
		firstTrainPassengersQueueu, secondTrainPassengersQueueu,
		firstTrainSkipList);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
