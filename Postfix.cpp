#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0; // For invalid operators or parentheses
}
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";
    for (char c : infix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push('(');
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
    cout << "\033[2J" << "\033[H";
    string infix;
    cout << "\033[1;35m Enter Expression: \033[0m";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "\033[1;35m Infix: \033[0m" << infix << endl;
    cout << "\033[1;35m Postfix: \033[0m" << postfix << endl;
    return 0;
}