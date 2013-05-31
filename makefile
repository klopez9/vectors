

# Specifiy the target
all: myVector.exe

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
myVector.exe: MyVector.o MyVectorUtil.o MyVectorUser.o
	g++  MyVector.o MyVectorUtil.o MyVectorUser.o -o myVector.exe

# Specify how the object files should be created from source files
MyVector.o: MyVector.cpp
	g++  -c  MyVector.cpp

MyVectorUtil.o: MyVectorUtil.cpp
	g++  -c  MyVectorUtil.cpp


MyVectorUser.o: MyVectorUser.cpp
	g++  -c  MyVectorUser.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o myVector.exe 
