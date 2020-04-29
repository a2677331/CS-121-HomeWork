//********************************************************
// Jian Zhong
// Professor MacKay
// CS121
// May 15, 2019
// Lab 10
//********************************************************

#include<iostream>

using namespace std;

#include "group.h"

// Implementation File
// The default constructor // every element of the array will be set to zero
group::group()
{
    for (int index = 0; index < SIZE; index++)
        members[index] = 0;
}

// constructor which sets every element of the array to the parameter
group::group(int a)
{
    for (int index = 0; index < SIZE; index++)
        members[index] = a; // output: 5555555555
}


// function which prints the values in the array
void group::printVals()
{
    cout << "The group is: ";
    
    for (int index = 0; index < SIZE; index++)
        cout << members[index] << ' ';
    
    cout << endl;
}

// function which asks the user for values to put in the array
void group::assignVals()
{
    cout << "Please enter 10 numbers: ";
    
    for (int i = 0; i < SIZE; i++)
    {
        cin >> members[i];
        while(!cin)
        {
            cout << "Invalid input, try again: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> members[i];
        }
    }
}

// function to find the smallest element of the array
int group::smallest() // ⚠️别忘了加group::
{
    int smallestNum = members[0];
    
    for (int i = 0; i < SIZE; i++)
        if (smallestNum > members[i]) //⚠️不要用smallestNum > members[i + 1]，不然会out of bound的，因为i+1=SIZE！
            smallestNum = members[i];
    
    return smallestNum;
}

// function to find the biggest element of the array
int group::biggest()
{
    int biggestNum = members[0];
    
    for (int i = 0; i < SIZE; i++)
        if (biggestNum < members[i])
            biggestNum = members[i];
    
    return biggestNum;
}

//⚠️怎样能输出每个数字的位置，可以改main的情况下！
// function which returns the position of the parameter value
int group::position(int n) // (-1 if not in the array)
{
    for(int p = 0; p < SIZE; p++)
    {
        if (members[p] == n)
            return p + 1;
    }
    return -1;
}
