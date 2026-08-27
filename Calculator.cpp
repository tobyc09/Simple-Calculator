#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}


double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

void waitForEnter()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void showResult(double result, double a, char operation, double b)
{
    system("cls");
    if (b == 0 && operation == '/')
    {
        cout << "Cannot divide by 0.";
        waitForEnter();
        return;
    }
    cout << a << operation << b << "=" << result;
    waitForEnter();
}


main()
{
    double a;
    double b;
    char operation;
    
    while (true)
    {
        system("cls");
        cout << "Welcome To Calculator!\n======================\n";

        cout << "Please enter your first value: "; cin >> a;
    
        cout << "\nPlease enter your operator of choice(+, -, *, /): "; cin >> operation;
    
        cout << "\nPlease enter your second value: "; cin >> b;

        switch (operation)
        {
            case '+':
            {
                double result = add(a,b);
                showResult(result,a,operation,b);
                continue;
            }
            case '-':
            {
                double result = subtract(a,b);
                showResult(result,a,operation,b);
                continue;
            }
            case '*':
            {
                double result = multiply(a,b);
                showResult(result,a,operation,b);
                continue;
            }
            case '/':
            {
                double result = divide(a,b);
                showResult(result,a,operation,b);
                continue;
            }
            default:
            {
                system("cls");
                cout << "Invalid input. Please try again.";
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
        }
    }
}