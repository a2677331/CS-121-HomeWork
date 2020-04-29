// Jian Zhong
// Prof. Mackay
// May 13, 2019
// Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int CHAR_SIZE = 58; //total # of characters to be counted

//struct for storing each character and each occureence of each character
struct occurrenceListType
{
    int occurrNumber;//the number of occurrences of each character
    char ch;//character to be counted
};


//function prototype
void getFileName(ifstream& inFile, ofstream& outFile, string& filePath);
void countWords(ifstream& inFile, int& wordCounter);
void countChars(ifstream& inFile, occurrenceListType occurrenceList[],
                int& wordCounter, char ch);
void sortChars(occurrenceListType occurrenceList[]);
void printCount(ifstream& inFile, ofstream& outFile, string filePath, int& wordCounter,
                occurrenceListType occurrenceList[], double percentageList[]);


int main()
{
    /**************************variable declarations******************/
    occurrenceListType occurrenceList[CHAR_SIZE];
    ifstream inFile;
    ofstream outFile;
    string filePath;
    int wordCounter; //for counting total words
    double percent[CHAR_SIZE]; //array for storing the percentage of each character
    char ch = '\0'; //initialize before read in each character

    /**************************function call**************************/
    getFileName(inFile, outFile, filePath);
    countWords(inFile, wordCounter);
    countChars(inFile, occurrenceList, wordCounter, ch);
    sortChars(occurrenceList);
    printCount(inFile, outFile, filePath, wordCounter, occurrenceList, percent);

    return 0;
}


//get file name and open
void getFileName(ifstream& inFile, ofstream& outFile, string& filePath)
{
    cout << "Input the name (including path) of the input file: ";
    getline(cin, filePath); //get the file path

    inFile.open(filePath); //read in file path
    outFile.open("zhongProj3Results.txt");

    if (inFile) // if read successfully
        cout << endl << filePath << " is a valid file.\n";
    else // if cannot read right format
    {
        cout << "Error Reading File\n";
        exit(0); //end the program
    }
}


//count words
void countWords(ifstream& inFile, int& wordCounter)
{
    //check if there is space, new line, return key or tab key
    if (' ' == inFile.peek() || '\n' == inFile.peek()
        || '\r' == inFile.peek() || '\t' == inFile.peek() || !inFile)
        wordCounter++; //if so, counter one word
}


//count characters
void countChars(ifstream& inFile, occurrenceListType occurrenceList[],
                int& wordCounter, char ch)
{
    wordCounter = 0; //initialization

    for (int i = 0; i < CHAR_SIZE; i++) // make every location back to 0.
    {
        occurrenceList[i].occurrNumber = 0; //initialization for occurrence
        occurrenceList[i].ch = i + '!'; //assign proper character to the struct for sorting
    }

    while (inFile >> ch) //if can read in a character
    {
        countWords(inFile, wordCounter); //peek the next the character to counter word

        ch = toupper(ch); //capitalize each character
        int index = static_cast<int>(ch) - static_cast<int>('!'); //assign each character to proper location
        if (index >= 0 && index <= 57)
            occurrenceList[index].occurrNumber++; //if so, update the occurrence of letter
    }
}


//Insertion sort
void sortChars(occurrenceListType occurrenceList[])
{
    for (int loc = 1; loc < CHAR_SIZE; loc++)
    {
        int j = loc - 1;
        int occTemp = occurrenceList[loc].occurrNumber; //for swapping occurrences
        occurrenceListType structTemp = occurrenceList[loc]; //for swapping structs

        //sort in descending order of occurrence
        while (j >= 0 && occurrenceList[j].occurrNumber < occTemp)
        {
            occurrenceList[j + 1] = occurrenceList[j];
            j--;
        }
        occurrenceList[j + 1] = structTemp;
    }
}


//Print out results
void printCount(ifstream& inFile, ofstream& outFile, string filePath, int& wordCounter,
                occurrenceListType occurrenceList[], double percentageList[])
{
    // total characters
    double total = 0;
    for(int j = 0; j < CHAR_SIZE; j++)
    {
        total += occurrenceList[j].occurrNumber;
    }

    // put percentage of each char into the percent array and print
    for (int i = 0; i < CHAR_SIZE; i++)
        percentageList[i] = (occurrenceList[i].occurrNumber / total) * 100;

    outFile << "The File name is : " << filePath
            << "\nThere are " << wordCounter << " words in the file.\n\n"
            << "Character Count Percentage\n";

    //print out each character, occurrence and percentage in required format
    outFile << fixed << showpoint << setprecision(4);
    for (int i = 0; i < CHAR_SIZE; i++)
        outFile << setw(5) << occurrenceList[i].ch
                << setw(8) << occurrenceList[i].occurrNumber
                << setw(10) << percentageList[i] << "%\n";

    inFile.close();  //close file
    outFile.close(); //close file
}
