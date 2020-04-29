// Jian Zhong
// Prof. Mackay
// Apr 5, 2019
// Lab 7

#include <iostream>
#include <cmath>    //included for some pre-defined functions

using namespace std;

//Put the function definitions here
double calcMean(double, double, double); //⚠️function prototype(declearation), needs semi colon ';'
double calcDev(double, double, double, double); // ⚠️can skip the name of the parameters
void printResults(double, double);      // ⚠️： do not have body


//DO NOT CHANGE ANYTHING IN THE MAIN FUNCTION!!!
int main()
{
    //Defining variables to store the values
    double grade1, grade2, grade3;
    double mean, deviation;
    
    
    //getting the info
    cout << "Please enter 3 grades: ";
    cin >> grade1 >> grade2 >> grade3;
    
    //calling the functions and storing their return values
    mean = calcMean(grade1, grade2, grade3);    //calculates the mean
    deviation = calcDev(mean, grade1, grade2, grade3);    //calculates the standard deviation
    
    //displaying the results
    printResults(mean, deviation);
    
    return 0;
}

double calcMean(double grade1, double grade2, double grade3) //⚠️function definition, do not put semi colon ';' here! and hava body.
{
    double mean;
    mean = (grade1 + grade2 + grade3) / 3;
    return mean;
}

double calcDev(double mean, double grade1, double grade2, double grade3)
{
    double deviation;
    deviation = sqrt(((pow(grade1 - mean, 2) + pow(grade2 - mean, 2) + pow(grade3 - mean, 2)) / 3));
    return deviation;
}

void printResults(double mean, double deviation)
{
    cout << "The mean of the three grades is: " << mean << endl;
    cout << "The standard deviation is: " << deviation;
}



