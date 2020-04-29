//********************************************************
//
// Jian Zhong
// Professor MacKay
// CS121-01
// Lab 3
// 2/17/2019
// Program Name: calculate the downpayment
// Program file:
// Input Files:
// Output Files:
// Included files:
// Purpose:
//
//********************************************************

#include <iostream>
#include <string>
#include <cmath>        // needed for using pow function
#include <iomanip>      // needed for using setpresicision
using namespace std;

int main()
{
	string name;
	double loanAmount;
	double annualInterest;
	double totalPayment;
	double years;
	double monthlyPayment;
	double R;
	double N;
	double L;

	cout << "Please enter your name: \n";
	cin >> name;
	cin.ignore(200, '\n');	// ⚠️除第一个string外，其他都不取。ignore next 200 chars till next line
                            // ⚠️用cin.ignore()默认跳过后一个值，取之后的值。
                            // ⚠️这里是用在输入name的后面，用来省略多余的那么之后的值，为了不影响后面的计算。
	cout << "Please enter amount of the loan:  \n";
	cin >> loanAmount;
	cout << "Please enter annual interest rate(%):  \n";
	cin >> annualInterest;
	cout << "Please enter number of years of the loan \n";
	cin >> years;

	R = annualInterest * 0.01 / 12;
	N = years * 12;
	L = loanAmount;

	monthlyPayment = L * R * pow(1 + R, N) / (pow(1 + R, N) - 1);		//main fomular
	totalPayment = monthlyPayment * N;

	cout << setprecision(2);									        // keep two digits decimal
	cout << fixed;
	cout << "Name: " << setw(44) << name << '\n'
		<< "Loan Amount:                 $" << setw(20) << loanAmount << '\n';

	cout << setprecision(0);					                        //let decimal disappear
	cout << "Monthly Interest Rate:       " << setw(20) << R * 100 << "%" << '\n';
	cout << "Number of Payments:           " << setw(20) << N << '\n';

	cout << setprecision(2);                                        // keep two digits decimal again
	cout << fixed;
	cout << "Monthly Payment:             $" << setw(20) << monthlyPayment << '\n';
	cout << "Total Amount Paid:           $" << setw(20) << totalPayment << '\n'
		<< "Interest Amount:             $" << setw(20) << totalPayment - loanAmount << '\n';
    
	return 0;
}
