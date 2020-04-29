//********************************************************
// Jian Zhong
// Professor MacKay
// CS121-01
// Lab 2
// 2/8/2019
// program name: convert from feet to centimeter
//********************************************************

#include <iostream>

using namespace std;


//This is called a named constant, do NOT change this
// It is similar to a variable, but you can't change the value
const double CONVERT = 2.54; 

int main ()
{
        //declare variables
    int feet, inches;
	int totalInches; // ";" is important
    double centimeters;

        //Statements
    cout << "Enter two integers, one for feet and "
         << "one for inches: ";                       
    cin >> feet >> inches;                            
    cout << endl;
    
    cout << "The numbers you entered are " << feet
         << " for feet and " << inches
         << " for inches. " << endl;                  

	totalInches = 12 * feet + inches;
    
    cout << "The total number of inches = "
         << totalInches << endl;                      
    
    centimeters = CONVERT * totalInches;  // important

    cout << "The number of centimeters = "
         << centimeters << endl;                       

	return 0;
}
