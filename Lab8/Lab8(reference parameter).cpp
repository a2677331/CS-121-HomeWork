// Jian Zhong
// diff between value parameters and reference parameters
// ⚠️value parameter does not affect the actual parameter, but reference parameter affects the actual parameter
// Apr 12 2019
// Lab 8


#include <iostream>
#include <cmath>    //included for some pre-defined functions

using namespace std;

//function PROTOTYPES will go here
void getValues(double&, double&, double&, double&, double&);
double calcMean(double, double, double, double, double);
double calcDev(double, double&, double, double, double, double, double);
void printResults(double, double);

//DO NOT CHANGE ANYTHING IN THE MAIN FUNCTION!!!
int main()
{
    //Defining variables to store the values, the mean and the standard deviation
    double x1, x2, x3, x4, x5;
    double mean, stDev;
    
    
    // calling all the functions
    getValues(x1, x2, x3, x4, x5);        // asks and reads in the 5 values. //⚠️ actual parameter
    mean = calcMean(x1, x2, x3, x4, x5);    //calculates the mean
    calcDev(mean, stDev, x1, x2, x3, x4, x5);    //calculates the standard deviation
    printResults(mean, stDev);            //displays the results
    
    return 0;
}

//the function DEFINITIONS will go below
//⚠️getValues里用到reference value会改变main里x1, x2, x3, x4, x5的值，用value parameters则不会改变，只是copy他们到这个function。
void getValues(double& a1, double& a2, double& a3, double& a4, double& a5)  //⚠️ formal parameter
{                                                                           //⚠️ Two kinds of formal parameter:
    //⚠️ 1 value parameters(receive a copy of AP) and 2 reference parameter(receive location of Actual Parameter)
    cout << "Please enter 5 integers: ";
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
}

double calcMean(double b1, double b2, double b3, double b4, double b5)
{
    double m;
    m = (b1 + b2 + b3 + b4 + b5) / 5;
    
    return m;
}

double calcDev(double mn, double& sD, double c1, double c2, double c3, double c4, double c5)
// ⚠️using reference parameter because want to affect the stDev(actual parameter), and then print it out.
{
    sD = sqrt(((pow(c1 - mn, 2) + pow(c2 - mn, 2) + pow(c3 - mn, 2)+ pow(c4 - mn, 2) + pow(c5 - mn, 2)) / 5));
    
    return sD;
}

void printResults(double mean, double stDev)
{
    cout << "The mean of the 5 values is: " << mean << endl;
    cout << "The St. Dev. of the 5 values is: " << stDev << endl;
}
