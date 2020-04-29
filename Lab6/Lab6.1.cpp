// this programs is the same as Lab6, but is more flexible
// due to you can easily change d1 and d2 to any numbers you want

#include <iostream>
using namespace std;

int main()
{
    int n1, n2, d1 = 3, d2 = 6;   // Start number, End number
    char answer;                  // answer for trying again or not
    bool done = false;
    
    while (!done)
    {
        // enter the Start number
        cout << "Enter 2 numbers, with the first less than the second\n";
        cout << "Start Number? ";
        cin >> n1;
        while (!cin || (cin.peek() != '\n'))
        {   // makes sure user hit the return key before enter the next number instead of space key
            cout << "Invalid input, try again: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> n1;
        }

        // enter the End number
        cout << "End Number? ";
        cin >> n2;
        while (!cin || (cin.peek() != '\n'))
        {
            cout << "Invalid input, try again: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> n2;
        }
    
        // when n1 is larger than or equal to n2, display a message
        if (n1 >= n2)
            cout << "The starting number must be less than the second\n";
        
        // when n1 is less than n2, get the numbers between n1 and n2
        else
        {
            // check if the numbers are divisible by 3 to 6, if so, display a message
            while (n1 <= n2)
            {
                while (d1 <= d2)
                {
                    if (n1 % d1 == 0)
                        cout << "The number " << n1 << " is divisible by " << d1 << endl;
                    d1 = d1 +1;
                }
                n1 = n1 +1;
                d1 = 3;      //  always forget to update, and it is 3, not 0.
            }
        }
        
        // run the program again or not
        cout << "Again? (Y/N)? ";
        cin >> answer;
        if (answer != 'Y')
            done = true;
    }
    cout << "The program ends successfully!\n";
    return 0;
}
