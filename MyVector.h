
#ifndef MYVECTOR_H__
#define MYVECTOR_H__

#include <iostream>

class MyVector {
 public:
    // empty constructor
    MyVector();

    // explicit value constructor
    MyVector(int myVectorSize, double seedValue); 

    // copy constructor
    MyVector(const MyVector& f); 

    // destructor
    ~MyVector();


    // overloaded operators
    //    friend bool operator == (const MyVector & f1, const MyVector & f2);
    bool operator==(const MyVector & myV2);

    MyVector operator+(const MyVector &myV1) const;
    MyVector operator-(const MyVector &myV1) const;
    MyVector operator*(const MyVector &myV1) const;
    const MyVector& operator=(const MyVector &myV);

    // friend functions 
    friend std::istream& operator>>(std::istream& in, MyVector & myV);
    friend std::ostream& operator<< (std::ostream& out, const MyVector& myV);

 private:
    int myVectorSize;  
    double *myDoubleVector;

};

#endif // MYVECTOR_H__
