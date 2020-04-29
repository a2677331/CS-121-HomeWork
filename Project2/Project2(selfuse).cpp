//*****************************************************************************************
// Jian Zhong
// Professor MacKay
// CS121-01
// 4/6/2019
// Program name: Project2
// Program file: Project2.cpp
// Purpose: This program asks the user for a choice of pattern, and then a choice of size,
//          it will produce a square with the particular pattern of the given size.
//*****************************************************************************************

#include <iostream>
using namespace std;

int main()
{
    int choiceNumber; // choice number
    int size;         // size number

    do
    {
        // display the options first for user to choose
        cout << "Your options are:\n"
             << "     1: a square with a left to right diagonal\n"
             << "     2: a square with a right to left diagonal\n"
             << "     3: a square that fills from left to right\n"
             << "     4: a square that fills from right to left\n"
             << "     5: exit\n\n";
        cout << "Which choice? ";
        cin >> choiceNumber;                   // input choice number


        //executes the loop if choices input is invalid
        while (!cin || (choiceNumber > 5) || (choiceNumber <= 0) || (cin.peek() != '\n'))
        {
            if(cin && (cin.peek() == '\n'))   // when entering valid integer, display a message(⚠️：这个搞了好久才懂，判断是不是整数可以用顺利读入（cin）和第二个读入为换行符（\n）来解决)
            {
                cin.clear();                  // clear bad input
                cin.ignore(200, '\n');        // discard input
                cout << "Not a valid choice, choose 1 - 5\n";
                cout << "Which choice? ";
                cin >> choiceNumber;          // update the choice
            }
            else                              // when not entering an integer, display a message
            {
                cin.clear();                  // clear bad input
                cin.ignore(200, '\n');        // discard input
                cout << "Not an integer, please enter an integer!\n";
                cout << "Which choice? ";
                cin >> choiceNumber;          // update the choice
            }
        }


        // link the choice numbers to patterns
        switch (choiceNumber)
        {

            /* PATTERN 1: a square with a left to right diagonal
             in which the diagonal is the size of the square */

            case 1: // ⚠️? why '1' is not working, because you declare the menu number as integer, datatype does not match if it is '1'
                cout << "Please pick a size, from 1 through 9: ";
                cin >> size;   // input the size number

                //executes the loop below if invalid input
                while (!cin || (size <= 0) || (size > 9) || (cin.peek() != '\n'))
                {
                    if(cin && (cin.peek() == '\n')) // when entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a valid size\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                    else                            // when not entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a an integer, please enter an integer!\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                }
                cout << endl;

                // build pattern 1
                for (int i = 1; i <= size; i++)
                {
                    for (int j = 1; j <= i-1; j++)      // generate and increase the pound signs
                        cout << '#';

                    cout << size;                       // generate one size number for each row

                    for (int l = size; l> i; l--)       // generate and decrease the pound signs
                        cout << '#';

                    cout << endl;
                }
                cout << endl;
                break;

                /* PATTERN 2: a square with a right to left diagonal
               in which the diagonal is the size of the square */

            case 2:
                cout << "Please pick a size, from 1 through 9: ";
                cin >> size;  // input the size number

                //executes the loop below if invalid input
                while (!cin || (size <= 0) || (size > 9) || (cin.peek() != '\n'))
                {
                    if(cin && (cin.peek() == '\n')) // when entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a valid size\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                    else                            // when not entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a an integer, please enter an integer!\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                }
                cout << endl;
                // build choice 2
                for (int i = 1; i <= size; i++)
                {

                    for (int l = size; l> i; l--)       // generate and decrease the pound signs
                        cout << '#';

                    for (int k = size; k <= size; k++)  // generate one size number for each row
                        cout << size;

                    for (int j = 1; j <= i-1; j++)      // generate and increase the pound signs
                        cout << '#';

                    cout << endl;
                }
                cout << endl;
                break;


                /* PATTERN 3: a square that fills from left to right,
                 using the size of the square as the ‘fill’ character */

            case 3:
                cout << "Please pick a size, from 1 through 9: ";
                cin >> size;  // input the size number

                //executes the loop below if invalid input
                while (!cin || (size <= 0) || (size > 9) || (cin.peek() != '\n'))
                {
                    if(cin && (cin.peek() == '\n')) // when entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a valid size\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                    else                            // when not entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a an integer, please enter an integer!\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                }
                cout << endl;
                // build pattern 3
                for (int i = 1; i <= size; i++)
                {
                    for (int j = 1; j <= i; j++)  // generate and increase the size numbers
                        cout << size;

                    for (int k = size; k> i; k--) // generate and decrease the pound signs
                        cout << '#';

                    cout << endl;
                }
                cout << endl;
                break;


                /* PATTERN 4: a square that fills from right to left,
                 using the size of the square as the ‘fill’ character */

            case 4:
                cout << "Please pick a size, from 1 through 9: ";
                cin >> size;  // input the size number

                //executes the loop below if invalid input
                while (!cin || (size <= 0) || (size > 9) || (cin.peek() != '\n'))
                {
                    if(cin && (cin.peek() == '\n')) // when entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a valid size\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                    else                            // when not entering valid integer, display a message
                    {
                        cin.clear();                // clear bad input
                        cin.ignore(200, '\n');      // clear bad input
                        cout << "Not a an integer, please enter an integer!\n";
                        cout << "Please pick a size, from 1 through 9: ";
                        cin >> size;                // update the size
                    }
                }
                cout << endl;
                // build pattern 4
                for (int i = 1; i <= size; i++)
                {
                    for (int k = size; k> i; k--) // generate and decrease the pound signs
                        cout << '#';

                    for (int j = 1; j <= i; j++) // generate and increase the size numbers
                        cout << size;

                    cout << endl;
                }
                cout << endl;
                break;
        }
    } while (choiceNumber != 5); // while choosing option 5, exit the loop, and go next

    cout << "\n\nYou choose to exit, goodbye!";

    return 0;
}
