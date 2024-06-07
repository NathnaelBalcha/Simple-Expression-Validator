#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int Reinput_fail = 0;
const int sizes = 20;
char Stack_Array[sizes];
int Top_For_Array = -1;

void Header()
{
    cout << "\n\t\t\t     MEKELLE UNIVERSITY\n";
    cout << "\t\t  ETHIOPIAN INSTITUTE OF TECHNOLOGY (EIT-M)\n";
    cout << "\t\t       DEPARTMENT OF COMPUTER SCIENCE\n";
    cout << "\t\t       AUTOMATA AND COMPLEXITY THEORY\n\n\n";
}

void Error_Message()
{
    system("cls");
    Header();
    cout << " \t\t\t       Alert /!\\" << endl;
    cout << "\t\t    ---------------------------------\n";
    cout << "\t\t    You have used unknown keyword! \n";
    cout << "\t\t    Peace choose the correct keyword.";
    cout << "\n\t\t    ---------------------------------\n";
}

bool isFull() {
    return Top_For_Array == (sizes - 1);
}

bool isEmpty() {
    return Top_For_Array == -1;
}

void push(char data) {
    if (!isFull()) {
        Stack_Array[++Top_For_Array] = data;
    }
}

void pop() {
    if (!isEmpty()) {
        Top_For_Array--;
    }
}

char top() {
    if (!isEmpty()) {
        return Stack_Array[Top_For_Array];
    }
    return '\0';
}

bool isOperator(char input_Operator) {
    return input_Operator == '+' || input_Operator == '-' || input_Operator == '*' || input_Operator == '/' || input_Operator == '^' || input_Operator == '%';
}

bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosingBracket(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

bool isMatchingBracket(char open, char close) {
    return (open == '(' && close == ')' || open == '{' && close == '}' || open == '[' && close == ']');
}

bool validateArray(string User_Input_Array) {
    int openBrackets = 0;
    bool lastWasOperator = true;
    bool lastWasOpeningBracket = false;

    for (char ch : User_Input_Array) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            lastWasOperator = false;
            lastWasOpeningBracket = false;
        } else if (isOpeningBracket(ch)) {
            openBrackets++;
            push(ch);
            lastWasOperator = true;
            lastWasOpeningBracket = true;
        } else if (isClosingBracket(ch)) {
            if (isEmpty() || !isMatchingBracket(top(), ch)) {
                return false;
            }
            pop();
            openBrackets--;
            lastWasOperator = false;
            lastWasOpeningBracket = false;
        } else if (isOperator(ch)) {
            if (lastWasOperator || lastWasOpeningBracket) {
                return false;
            }
            lastWasOperator = true;
        } else {
            return false;
        }
    }

    return openBrackets == 0 && !lastWasOperator;
}

int main()
{
    string userInput;
    int Main_Menu_Choice, Looping_Choice, DoRe = 0;
    system("cls");
    Header();
    do
    {
        do
        {
            Reinput_fail = 0;
            cout << "\n        ___________________________________________________________\n";
            cout << "        |                                                         |\n";
            cout << "        |   [1] Check expression                                  |\n";
            cout << "        |                                                         |\n";
            cout << "        |   [2] Exit                                              |\n";
            cout << "        |_________________________________________________________|";
            cout << "\n\n\t Enter your Choice ";
            cin >> Main_Menu_Choice;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                Error_Message();
                Reinput_fail = 1;
            }
        }
        while (Reinput_fail == 1);
        switch (Main_Menu_Choice)
        {
        case 1:
            system("cls");
            Header();
            do
            {
                system("cls");
                Header();
                cout << " Check expression";
                cout <<"\n --------------------------------------------------\n\n";
                string ArrayExpression;
                cout << "Enter an expression: ";
                cin >> ArrayExpression;
                system("cls");
                Header();
                do
                {
                    do
                    {
                        Reinput_fail = 0;
                        if (validateArray(ArrayExpression)) {
                        cout << "  Your input expression: " << ArrayExpression << endl;
                        cout << "  The expression is valid." << endl;
                        } else {
                        cout << "  Your input expression: " << ArrayExpression << endl;
                        cout << "  Error Invalid expression." << endl;
                        }
                        cout <<"\n---------------------------------------------\n";
                        cout << " [1] Check For Another expression\n";
                        cout << " [2] Back\n";
                        cout <<"\n---------------------------------------------\n";
                        cout << " Enter your Choice ";
                        cin >> Looping_Choice;
                        while (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                            Error_Message();
                            Reinput_fail = 1;
                        }
                    }
                    while (Reinput_fail == 1);
                    if (Looping_Choice == 1)
                    {
                        system("cls");
                        Header();
                        DoRe = 1;
                    }
                    else if (Looping_Choice == 2)
                    {
                        system("cls");
                        Header();
                        DoRe = 2;
                    }
                    else
                    {
                        system("cls");
                        Header();
                        Error_Message();
                        Reinput_fail = 2;
                    }
                }
                while (Reinput_fail == 2);
            }
            while (DoRe == 1);
            break;
        case 2:
            return 0;
            break;
        default:
            system("cls");
            Header();
            Error_Message();
        }
        DoRe = 2;
    }
    while (DoRe == 2);
    return 0;
}
