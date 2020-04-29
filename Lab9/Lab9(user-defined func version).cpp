// this programs uses user-defined funcs to do the same thing as Lab9.cpp
// it includes func Prototype, File Streams, and Array.

#include <fstream>A
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// func prototypes
void getCorrectAnswer(char[]); //与func declaration相比， 多了双引号（；），少了名字（sAnswer),其他一样。
void getStudentID_and_Answers(char [], string sID);
int calScores(char [], char [], int);
void calGrades(int);


ifstream inFile;//input file steam
const int SIZE = 20; //number of students' answers
int main()
{
    inFile.open("Lab9data.txt"); //open file

    string studentID;
    char studentAnswer[SIZE];
    char correctAnswer[SIZE];

    //get and store the correct answer
    getCorrectAnswer(correctAnswer); //⚠️call array的时候不要加[]!!!!

    
  //cal the scores and output grades
    int scoresCounter = 0; // count the total scores
    while(inFile >> studentID) //⚠️当加了循环while(inFile >> studentID)️,48行的位置不要再重复加infile >> studentID了！
    {
        getStudentID_and_Answers(studentAnswer, studentID);
        cout << setw(4) << calScores(studentAnswer, correctAnswer, scoresCounter);
        calGrades(scoresCounter = calScores(studentAnswer, correctAnswer, scoresCounter));//⚠️（括号里不能单单是scoresCounter，如果是就每一次都按0计算， 必须func call将上一个function的结果assign进去）
        cout << endl;
    }
    inFile.close(); //close file


    return 0; //Program ends
}

// store the the correct answer
void getCorrectAnswer(char cAnswer[])
{
    for(int i = 0; i < SIZE; i++)
        inFile >> cAnswer[i];
}

// get student id, and student answer
void getStudentID_and_Answers(char sAnswer[], string sID)
{
    cout << sID << setw(2);

    inFile.ignore();
    for (int i =0; i < 20; i++)
    {
        sAnswer[i] = inFile.get();
        cout << sAnswer[i];
    }
}

//cal student's scores
int calScores(char sAnswer[], char cAnswer[], int sCounter)
{
    sCounter = 0;
    for (int i =0; i < 20; i++)
    {
        if (sAnswer[i] == cAnswer[i])
            sCounter = sCounter + 2;
        else if (sAnswer[i] == ' ') {}
        else
            sCounter = sCounter - 1;
    }
    return sCounter;
}

// cal student's grades
void calGrades(int sCounter)
{
    if (sCounter >= 36 && sCounter <= 40)
        cout << setw(2) << 'A';
    else if (sCounter >= 32 && sCounter < 36)
        cout << setw(2) << 'B';
    else if (sCounter >= 28 && sCounter < 32)
        cout << setw(2) << 'C';
    else if (sCounter >= 24 && sCounter < 28)
        cout << setw(2) << 'D';
    else if (sCounter < 24)
        cout << setw(2) << 'F';
}

/* ⚠️The array [size] is part of the type
 void f ( int [10] );
 void g ( int [] );
 void h ( int * );

 int main()
 {
 int x[10];
 f(x);
 g(x);
 h(x);
 }

 void f ( int a[10] )
 {
 }

 void g ( int a[] )
 {
 }

 void h ( int *p )
 {
 }
 */
