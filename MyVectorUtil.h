
#ifndef MYVECTOR_UTIL_H__
#define MYVECTOR_UTIL_H__

#include "MyVector.h"

class MyVectorUtil {
 public:
    
    // the driver method
    bool runSimpleMathGame();

    // utility method to read two Vectors
    void readTwoMyVectors(MyVector &firstMyVector, MyVector &secondMyVector);

    // utility method to read one Vector
    void readOneMyVector(MyVector &onlyMyVector);

};

#endif // MYVECTOR_UTIL_H__
