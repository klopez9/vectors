#include "MyVectorUtil.h"
#include "MyVector.h"
#include <iostream>
#include <string>

using namespace std;

void MyVectorUtil::readOneMyVector(MyVector &onlyMyVector) {
	cout << endl;
	cout << "Please enter the details of the vector" << endl;
	cin >> onlyMyVector;
}

void MyVectorUtil::readTwoMyVectors(MyVector &firstMyVector, MyVector &secondMyVector) {
	cout << endl;
	cout << "Please enter the details of the first vector" << endl;
	cin >> firstMyVector;

	cout << "Please enter the details of the second vector" << endl;
	cin >> secondMyVector;
}

bool MyVectorUtil::runSimpleMathGame() {
	cout << "--------------------------------" << endl;
	cout << "Welcome to the Simple Math-Game" << endl;
	cout << "--------------------------------" << endl << endl;
	cout << "Please choose among the following options:" << endl;
	cout << "add" << endl;
	cout << "subtract" << endl;
	cout << "multiply" << endl;
	cout << "equals" << endl;
	cout << "assignment" << endl;
	cout << "copy" << endl;
	cout << "output" << endl;
	cout << "quit" << endl;

	bool oneMoreTime = true;

	string userOption;
	MyVector firstMyVector, secondMyVector, answerMyVector;

	cout << "Please enter your option: ";
	cin >> userOption;
	if (userOption == "quit") {
		cout << "Thank you for playing the Simple Math Game! Goodbye." << endl;
		oneMoreTime = false;

	} else if (userOption == "add")  {
		readTwoMyVectors(firstMyVector, secondMyVector);
		answerMyVector = firstMyVector + secondMyVector;
		cout << answerMyVector;

	} else if (userOption == "subtract") {
		readTwoMyVectors(firstMyVector, secondMyVector);
		answerMyVector = firstMyVector - secondMyVector;
		cout << answerMyVector;

	} else if (userOption == "multiply") {
		readTwoMyVectors(firstMyVector, secondMyVector);
		answerMyVector = firstMyVector * secondMyVector;
		cout << answerMyVector;

	} else if (userOption == "equals") {
		readTwoMyVectors(firstMyVector, secondMyVector);
		if (firstMyVector == secondMyVector) {
			cout << "The two myVectors are equal." << endl;
		} else {
			cout << "The two myVectors are not equal." << endl;
		}

	} else if (userOption == "assignment") {
		readOneMyVector(firstMyVector);
		answerMyVector = firstMyVector;
		cout << answerMyVector;

	} else if (userOption == "copy") {
		readOneMyVector(firstMyVector);
		MyVector copiedMyVector(firstMyVector);
		cout << copiedMyVector;

	} else if (userOption == "output") {
		readOneMyVector(firstMyVector);
		cout << firstMyVector;

	} else {
		cout << "The option '" <<  userOption << "' is not valid. " << endl;
	}
	return oneMoreTime;
}
