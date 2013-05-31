
#include "MyVector.h"
#include <iostream>
#include <math.h>

using namespace std;

MyVector::MyVector(): myDoubleVector(0), myVectorSize(0) {
    // remember that the data members in the initialization list
    // are initialized in the order in which they are declared
    // in the class, and NOT in the order in which they are
    // listed in the list above.
}

MyVector::MyVector(int myVectorSizeIn, double seedValueIn) {
  myVectorSize = myVectorSizeIn;
  myDoubleVector = new double[myVectorSize];
  for (int i=0; i<myVectorSize; i++) {
    myDoubleVector[i] = seedValueIn * i;
  }
}

// copy constructor
MyVector::MyVector(const MyVector& f) {
    cout << "copy constructor called" << endl;
    // FIXME: add code here
    // Check if the array inside f is null
    if (f.myDoubleVector == NULL) {
      // If so, set myDoubleVector to be null and return
      myDoubleVector = NULL;
      return;
    }
    // Set myVectorSize to the corresponding size in f
    myVectorSize = f.myVectorSize;
    // Allocate myDoubleVector to the correct size
    // delete [] myDoubleVector;
    myDoubleVector = new double [f.myVectorSize];
    // initialize myDoubleVector using values in f.myDoubleVector
    for (int i = 0; i < myVectorSize; i++) {
      myDoubleVector[i] = f.myDoubleVector[i];
    }
}


MyVector MyVector::operator+(const MyVector &f) const {
    MyVector result;
    // FIXME: add code here
    // add only if the two vectors of the same size
    if (myVectorSize == f.myVectorSize) {
      result.myVectorSize = myVectorSize;
      result.myDoubleVector = new double [myVectorSize];
    // in a loop add values from f.myDoubleVector and myDoubleVector
      for (int i = 0; i < myVectorSize; i++) {
	// the result should be stored in the myDoubleVector of result.
	result.myDoubleVector[i] = myDoubleVector[i] + f.myDoubleVector[i];
      }
    }
    return result;
}

MyVector MyVector::operator-(const MyVector &f) const {
    MyVector result;
    // FIXME: add code here
    // only if the two vectors are of equal size
    if (myVectorSize == f.myVectorSize) {
      result.myVectorSize = myVectorSize;
      result.myDoubleVector = new double [myVectorSize];
    // in a loop subtract values of f.myDoubleVector and myDoubleVector
      for (int i = 0; i < myVectorSize; i++) {
	// the result should be stored in the myDoubleVector of result.
	result.myDoubleVector[i] = myDoubleVector[i] - f.myDoubleVector[i];
      }
    }
    // Same logic as in operator+
    return result;
}

MyVector MyVector::operator*(const MyVector &f) const {
    MyVector result;
    // FIXME: add code here
    // only if the two vectors are of equal size
    if (myVectorSize == f.myVectorSize) {
      result.myVectorSize = myVectorSize;
      result.myDoubleVector = new double [myVectorSize];
    // in a loop multiply values of f.myDoubleVector and myDoubleVector
      for (int i = 0; i < myVectorSize; i++) {
	// the result should be stored in the myDoubleVector of result.
	result.myDoubleVector[i] = myDoubleVector[i] * f.myDoubleVector[i];
      }
    }    
    // Same logic as in operator+
    return result;
}

bool MyVector::operator == (const MyVector & f2) {
  // FIXME: add code here
  // Check if the elements of the arrays in myDoubleVector and 
  // f.myDoubleVector are the same
  if (myVectorSize == f2.myVectorSize) {
    double epsilon = 0.00001;
    // in a loop compare values of f.myDoubleVector and myDoubleVector
    for (int i = 0; i < myVectorSize; i++) {
      if (fabs(myDoubleVector[i] - f2.myDoubleVector[i]) >= epsilon)
	return false;
    }
    return true;
  }
  // Comparing doubles is done this way
  // double epsilon = 0.00001;
  // if ( abs(d1 - d2) < epsilon) return true;
  return false;
} 


istream& operator >> (istream & in, MyVector & f) {
    cout << "Enter the size of the vector: ";
    in >> f.myVectorSize;
    // Read the seed value
    double seed;
    cout << "Enter the seed value: ";
    in >> seed;
    // Allocate an array for f.myDoubleVector
    // of the size input by the user
    f.myDoubleVector = new double [f.myVectorSize];
    // In a for loop, initialize f.myDoubleVector
    for (int i = 0; i < f.myVectorSize; i++) {
      f.myDoubleVector[i] = seed + i;
    }
    cout << f << endl;
    return in;
}


ostream& operator << (ostream& out, const MyVector& f) {
  cout << "MyVector is: " << endl;
  // in a loop print out all the elements of f.myDoubleArray
  // FIXME: add code here
  for (int i = 0; i < f.myVectorSize; i++) {
    out << f.myDoubleVector[i] << '\n';
  }
  return out;
}

const MyVector& MyVector::operator=(const MyVector& f) {
    if (this != &f) { // make sure it is not the same object 
      // delete memory if needed.
      // FIXME: write code for the assignment if the sizes are equal
      cout << "assign operator is called " << endl;
      // if myVectorSize is > 0, or if it is not NULL:
      if (myVectorSize > 0 || myDoubleVector != NULL)
	delete [] myDoubleVector;
	// Allocate myDoubleVector to the size of f.myDoubleVector
      myVectorSize = f.myVectorSize;
      myDoubleVector = new double [f.myVectorSize];
	// In a loop copy from f.myDoubleVector to myDoubleVector
	for (int i = 0; i < f.myVectorSize; i++) {
	  myDoubleVector[i] = f.myDoubleVector[i];
	}
      }
    return *this;
}

MyVector::~MyVector() {
    // FIXME
    // delete the data member that is a pointer
    delete [] myDoubleVector;
}
