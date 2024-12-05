#include <iostream>
using namespace std;

int main()
{
    int a , b ;

    char opt ;

    cout << "Enter First Number : " << endl;
    cin >> a ;

    cout << "Enter Second Number : " << endl;
    cin >> b ;

    cout << "Enter Operator + or - or * or / : " << endl;
    cin >> opt ;

    if (opt == '+')
    cout << "Sum = " << a + b << endl;

    else if (opt == '-')
    cout << "Subtraction = " << a - b << endl;

    else if (opt == '*')
    cout << "Product = " << a * b << endl;

    else if (opt == '/')
    cout << "Division = " << a / b << endl;

    else 

    cout << "You choose wrong: " << endl;
    
}