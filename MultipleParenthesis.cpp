#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Node structure declaration
struct node
{
    char data;
    struct node *next;
};

// Stack declaration
node *top = NULL;

//*Function prototypes
void push(char);          // Function to push data to the top of Stack
bool pop();               // Function to pop the top element form the Stack
bool isEmpty();           // Functionto return true if Stack is empty
bool parenthesis(string); // Function to check for multiple parenthesis

int main()
{
    string s;
    cout << "\033[34m Expression can be with space\033[0m" << endl;
    cout << "\033[35m Enter expression: \033[0m";
    getline(cin, s);
    if (parenthesis(s))
    {
        cout << "\033[1;32m \u2705 Valid Expression\033[0m" << endl;
    }
    else
    {
        cout << "\033[1;31m \u274C InValid Expression\033[0m" << endl;
    }
    return 0;
}
// Function to push data to the top of Stack
void push(char brackets)
{
    node *temp = new node{brackets, NULL};
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

// Function to pop top Element from the Stack
bool pop(char brackets)
{
    if (!isEmpty())
    {
        if (brackets == top->data)
        {
            node *trash = top;
            top = top->next;
            delete trash;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// Function to check if stack is Empty
bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to check for multiple parenthesis
bool parenthesis(string s)
{
    // Pushing into the stack
    for (char ch : s)
    {
        if (ch == '{')
        {
            push('{');
        }
        else if (ch == '[')
        {
            push('[');
        }
        else if (ch == '(')
        {
            push('(');
        }
        // Removing the top Element
        else if (ch == '}')
        {
            if (!pop('{'))
            {
                return false;
            }
        }
        else if (ch == ']')
        {
            if (!pop('['))
            {
                return false;
            }
        }
        else if (ch == ')')
        {
            if (!pop('('))
            {
                return false;
            }
        }
    }
    if (isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}