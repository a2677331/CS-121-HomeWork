#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 20; //number of students' answers

int main()
{
    ifstream inFile;
    ofstream outFIle;


    inFile.open("Lab9data.txt");


    char rightAnswer[SIZE];    //correct answer
    char studentAnswer[SIZE];  //student answer
    string studnetID;          //student number


    //get and store the right answers from file
    for (int i = 0; i < SIZE; i++)
        inFile >> rightAnswer[i];


    while (inFile >> studnetID)
    {
        cout << studnetID << ' ';


        inFile.ignore(); //ignore the space before the grades


        //get all the student grades
        for (int i = 0; i < SIZE; i++)
        {
            studentAnswer[i] = inFile.get();
            cout << studentAnswer[i] << ' ';
        }


        //calculate grades
        int gradeCounter = 0; // student grade

        for (int i = 0; i < SIZE; i++)
        {
            if (studentAnswer[i] == rightAnswer[i])
                gradeCounter = gradeCounter + 2;

            else if (studentAnswer[i] == ' ')
            {
            }

            else
                gradeCounter = gradeCounter - 1;
        }

        cout << setw(3) << gradeCounter << ' ';

        //output final grade
        if (gradeCounter >= 36 && gradeCounter <= 40)
            cout << 'A';
        else if (gradeCounter >= 32 && gradeCounter < 36)
            cout << 'B';
        else if (gradeCounter >= 28 && gradeCounter < 32)
            cout << 'C';
        else if (gradeCounter >= 24 && gradeCounter < 28)
            cout << 'D';
        else if (gradeCounter < 24)
            cout << 'F';


        cout << endl;
    }

    inFile.close();

    return 0;
}
