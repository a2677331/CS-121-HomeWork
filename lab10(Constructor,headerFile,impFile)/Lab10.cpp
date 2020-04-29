//********************************************************
// Jian Zhong
// Professor MacKay
// CS121
// May 15, 2019
// Lab 10
//********************************************************

#include <iostream>

using namespace std;

#include "group.h"

int main()
{
    int num, pos;
    
    group numbers;
    group numbers2(5);//⚠️跟后面参数5跟constructor有关，有数字就用group（int），没有就用group（）。
    
    numbers.printVals();
    numbers2.printVals();
    
    numbers.assignVals();
    numbers2.assignVals();
    
    cout << "What number are you looking for? ";
    cin >> num;
    
    pos = numbers.position(num);
    
    if(pos == -1)
        cout << "The number " << num <<  " is not in the first group\n";
    else
        cout << "The number " << num <<  " is at position " << pos << " of the first group\n";
    
    pos = numbers2.position(num);
    
    if(pos == -1)
        cout << "The number " << num << " is not in the second group\n";
    else
        cout << "The number " << num << " is at position " << pos << " of the second group\n";
    
    cout << "The smallest value in the first group is: " << numbers.smallest() << endl;
    cout << "The largest value in the first group is: " << numbers.biggest() << endl;
    cout << "The smallest value in the second group is: " << numbers2.smallest() << endl;
    cout << "The largest value in the second group is: " << numbers2.biggest() << endl;
    
    numbers.printVals();
    numbers2.printVals();
    
    return 0;
}
