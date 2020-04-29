//********************************************************
// Jian Zhong
// Professor MacKay
// CS121
// May 15, 2019
// Lab 10
//********************************************************

#ifndef GROUP_H
#define GROUP_H

//Header file
class group
{
public:
    void printVals();    // function which prints the values in the array
    void assignVals();    // function which asks the user for values to put in the array
    int position(int);    // function which returns the position of the parameter value // (-1 if not in the array)
    int smallest();        // function to find the smallest element of the array
    int biggest();        // function to find the biggest element of the array
    group();                // The default constructor // every element of the array will be set to zero
    group(int);             // constructor which sets every element of the array to the parameter
    
private:
    static const int SIZE = 10;  // Initializes the constant SIZE to 10
    int members[SIZE];             // an array of integers
};
#endif
