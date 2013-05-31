

#include <iostream>
#include "MyVectorUtil.h"

using namespace std;

int main ( ) {

    bool oneMoreTime = true;

    MyVectorUtil myVectorUtil;
    while(oneMoreTime) {
	oneMoreTime = myVectorUtil.runSimpleMathGame();
    }

}
