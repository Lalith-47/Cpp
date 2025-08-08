#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Declaration of Stack datatype
struct node
{
    char ch;
    struct node *next;
};

// Declaration of pointer top
node *top = NULL;

//*Function prototypes
void push();              // Function to push the Element at the top of the stack
int pop();                // Function to pop the top Element from the top of the stack
int isEmpty();            // Function to check if stack is Empty
void paranthesis(string); // Function to check if the expression contains valid parenthesis

// Body of the main function
int main()
{
    string s;
    cout << "\n\033[6;34m \u2139 You Can Enter along with spaces \033[0m"
         << "\n  \033[35m Enter Expression: \033[0m";
    getline(cin, s);
    paranthesis(s);
    return 0;
}

// Function to push the Element at the top of the stack
void push()
{
    node *temp = new node{'(', NULL};
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

// Function to pop the Top Element from stack
int pop()
{
    if (isEmpty())
    {
        cout << "\033[33m⚠️ Parenthesis Mismatched\033[0m" << endl;
        exit(0);
    }
    else
    {
        node *trash = top;
        top = top->next;
        delete trash;
        return 1;
    }
}
// Function to check if stack is Empty
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to check if the given expression had valid no of parenthesis or not
void paranthesis(string s)
{
    for (char ch : s)
    {
        if (ch == '(')
        {
            push();
        }
        else if (ch == ')')
        {
            pop();
        }
    }
    if (isEmpty())
    {
        cout << "\033[32m✅ Parenthesis Matched\033[0m"
             << "\n\033[34m   Valid Expression \033[0m\n";
        exit(0);
    }
    else
    {
        cout << "\033[33m⚠️ Parenthesis Mismatched\033[0m" << endl;
    }
}