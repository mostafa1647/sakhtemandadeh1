// Eternity Train (DS Project One).cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include "Node.h"
#include "MyList.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "Person.h"
#include "Station.h"
using namespace std;

#define NUMBER_OF_STATIONS 50
const string foodsName[] = { ""
};


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

int main()
{
	int firstTrainPeople, secondeTrainPeople;
	pair<int*, int> firstTrainStops;
	pair<int*, int> secondeTrainStops;
	string oneLine;

	cin >> firstTrainPeople;
	cin >> secondeTrainPeople;	
	getline(cin, oneLine);
	firstTrainStops = split(oneLine, '-');
	getline(cin, oneLine);
	secondeTrainStops = split(oneLine, '-');
	for (int i=0;i<firstTrainStops.second;i++)
	{
		cout << firstTrainStops.first[i] << endl;
	}


	

	delete[] firstTrainStops.first;
	delete[] secondeTrainStops.first;
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
