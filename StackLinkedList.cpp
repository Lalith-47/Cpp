#include <iostream>
#include "codes.h"
using namespace std;

// Declaration of node of Node Structure
typedef struct Node
{
    struct Node *prev;
    int data;
} node;

// Declaration of top pointer
node *top = NULL;

//*Function prototypes
void push(int);   // Function to append new data and update the top pointer
int pop();        // Function to remove the top most Element in the Stack
node *peek();     // Function returns address of top Element
void insert(int); // Function to enter set of data values to stack
void peek_info(); // Function to display the top element and the address of the element
void display();   // Function to display all the Elements in the Stack
void remove(int); // Function to remove set of values form the stack
void clear();     // Function to clear the Entire stack

// Body of the main function
int main()
{
    cout << cls << home;
    int n, choice = 0;
    cout << "Enter no of values to enter: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        push(value);
    }
    display();
    while (1)
    {
        cout << "\nEnter number to perform choice"
             << "\n 0: To exit the Loop"
             << "\n 1: To display all ELements"
             << "\n 2: To insert an ELement in the stack"
             << "\n 3: To insert set of values in the stack"
             << "\n 4: To remove top Element from the stack"
             << "\n 5: To remove set of Elements from the stack"
             << "\n 6: To get details of the top Element"
             << "\n 7: To clear the Stack"
             << "\nChoice: ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "Code Terminated" << endl;
            break;
        }

        else if (choice == 1)
        {
            display();
        }

        else if (choice == 2)
        {
            int val;
            cout << "Enter Value: ";
            cin >> val;
            push(val);
        }

        else if (choice == 3)
        {
            int opt;
            cout << "Enter no of values to enter: ";
            cin >> opt;
            insert(opt);
        }

        else if (choice == 4)
        {
            pop();
            display();
        }

        else if (choice == 5)
        {
            int x;
            cout << "Enter no of values to remove: ";
            cin >> x;
            remove(x);
            display();
        }

        else if (choice == 6)
        {
            peek_info();
        }
        else if (choice == 7)
        {
            clear();
            cout << "Empty Stack" << endl;
        }

        else
        {
            // Optional: Handle invalid choice
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

// Function to remove the top most Element in stack and return the removed element
int pop()
{
    if (top == NULL)
    {
        cout << "Stack UnderFlow" << endl;
        return -1;
    }
    else
    {
        node *trash = top;
        int value = top->data;
        if (top->prev == NULL)
        {
            delete top;
            top = NULL;
        }
        else
        {
            top = top->prev;
            delete trash;
        }
        return value;
    }
}

// Function to append new data and update the top pointer
void push(int data)
{
    node *temp = new node{NULL, data};
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->prev = top;
        top = temp;
    }
}

// Function to return index or address of the Top Element
node *peek()
{
    return top;
}

// Function to enter set of data values to stack
void insert(int n)
{
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter data: ";
        cin >> data;
        push(data);
    }
}

// Function to display the top element and the address of the element
void peek_info()
{
    if (top != NULL)
    {
        cout << "\nData: " << top->data << endl;
        cout << "Address: " << top << endl;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}

// Function to display all the Elements in the Stack
void display()
{
    if (top != NULL)
    {
        node *temp = top;
        cout << "\nStack contents (top to bottom):" << endl;
        while (temp != NULL)
        {
            if (temp == top)
            {
                cout << temp->data << " <- Top" << endl;
            }
            else
            {
                cout << temp->data << endl;
            }
            temp = temp->prev;
        }
    }
    else
    {
        cout << "Stack is Empty\nNothing to Display" << endl;
    }
}

// Function to remove set of values from the stack
void remove(int n)
{
    for (int i = 0; i < n; i++)
    {
        pop();
    }
}

// Function to Clear the Entire stack
void clear()
{
    while (top != NULL)
    {
        pop();
    }
}