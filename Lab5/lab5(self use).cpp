//********************************************************
//
// Jian Zhong
// Professor MacKay
// CS121
// 03/23/2019
// Program Name: Lab 5
// Program file: Lab 5
// Input Files: Lab5data.txt
// Included files: Lab5data.txt
//
//********************************************************

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("Lab5data.txt");
    
    // Variable declarations
    string fname,lname;                                   // First name, Last name
    int    count_grades = 0, count_students = 0;          // Numbers of grade, Numbers of student
    double grade, average = 0, sum = 0, highest = 0;      // Grade, Average grade, Total grade, and High greade for each student
    double sum_of_classAverage = 0, highest_of_all = 0;   // The sum of students' average, Highest grade for the class
    
    // read in first name, last name and grade
    inFile >> fname >> lname;
    inFile >> grade;
    
    // keep reading the file until the end
    while (inFile)    //⚠️always uses "while(inFile)" instead of "while(!inFile.eof())", update: both are good, just do not use xcode to do it.
    {
        count_students++; // count the number of students
        
        // Scenario 1: when a student has no grades (except for the -1), their average is 0
        if (grade == -1)    //⚠️难点：while loop只有在第一个没有-1时才能用的，所以用if（第一个是-1）else（第一个不是-1）
        {
            cout << "The average for "
            << fname << " " << lname << " is: 0\n";
            
            inFile >> fname >> lname;    //⚠️Do not forget it, when in while loop, it needs update
            inFile >> grade;  //⚠️Do not forget it, when in while loop, it needs update
            ;
        }
        
        // Scenario 2: when a student has grades, get the average and the highest grade
        else if(grade >= 0)
        {
            while (grade != -1)
            {
                count_grades++;
                sum += grade;
                if (highest < grade)
                    highest = grade;
                inFile >> grade;    //⚠️update a new grade (should put at last line, or will affect the highest number)
            }// end while
            
            // get each one's average and the class average
            average = sum / count_grades;   //⚠️ 不能放在计算each one的while loop里面，loop只负责计算总数和总次数！！
            sum_of_classAverage += average;   //⚠️ 不能放在计算each one的while loop里面，否则会多计算average！！！
            
            // get the high grade for the class
            if (highest_of_all < highest)
                highest_of_all = highest;
            
            // output the average and the highest grade for each one
            cout << fixed << showpoint << setprecision(1);
            cout << "The average for " << fname << " " << lname
                 << " is: " << average
                 << " and the high grade is: "
                 << highest << endl;
            
            // update and read the next student
            count_grades = 0;
            sum = 0;
            highest = 0;
            inFile >> fname >> lname;
            inFile >> grade;
        }
    }// end while
    
    // output the average and the highest grade for the class
    if(count_students > 0)
        cout << "\n\n"
             << "The average for the class is: "
             << sum_of_classAverage / count_students
             << " and the high grade for the class is: "
             << highest_of_all
             << "\n\n";
    
    // Scenario 3: when there are no students in the class, the class average is 0.
    else
        cout << "The average for the class is: 0\n\n";
    
    inFile.close();
    return 0;
}
