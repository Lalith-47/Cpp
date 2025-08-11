#include <iostream>
using namespace std;

// Defining structure of Queue using Linked List
struct node
{
    int data;
    struct node *next;
};

// Head and tail pointer declaration
node *head = NULL;
node *tail = NULL;

//*Function Prototypes
bool enqueue(int);  // Function to Enter the Element at the Start
bool dequeue();     // Function to Remove the ELement at the End
bool isEmpty();     // Function to check if the Queue is empty
void insert(int n); // Function to add set of ELements
bool display();     // Function to display the ELements in the Queue
bool remove(int);   // Function to delete set of values in the Queue

// Body of the Main Function
int main()
{
    cout << "\033[2J" << "\033[H";
    int noOfElements, choice = NULL;
    cout << "\033[1;35m Enter no of ELements to insert: \033[0m";
    cin >> noOfElements;
    insert(noOfElements);
    while (true)
    {
        cout << "\033[1;34m Enter no to perform the operation:  \033[0m"
             << "\n \033[1;36m 0: To Exit the loop"
             << "\n  1: display all Elements"
             << "\n  2: Remove Element"
             << "\n  3: Remove n Elements starting with the top"
             << "\n  4: Empty the Queue"
             << "\n  5: Print Top Element and index"
             << "\n  6: To Check if Queue is empty"
             << "\n  7: To Check if Queue is Full"
             << "\n  8: To add values"
             << "\n  9: Print Last Element and index\033[0m"
             << "\nchoice: ";
        cin >> choice;
        cout << endl;
        if (choice == 0)
        {
            cout << "\033[1;32m Code Terminated\033[0m" << endl;
            break;
        }
        else
        {
            if (choice == 1)
            {
                if (!display())
                {
                    cout << "\033[1;31m Empty Queue!\033[0m" << endl
                         << endl;
                }
            }
            else if (choice == 2)
            {
                if (isEmpty())
                {
                    cout << "\033[1;31m No Data in queue \033[0m" << endl;
                }
                else
                {
                    dequeue();
                    display();
                }
            }
            else if (choice == 3)
            {
                cout << "\033[1;35m Enter no of ELements to delete: \033[0m";
                int x = 0;
                cin >> x;
                if (!remove(x))
                {
                    cout << "\033[1;31mQueue did not have enough data \nQueue was emptied \033[0m" << endl;
                }
                display();
            }
            else if (choice == 4)
            {
                while (!isEmpty())
                {
                    dequeue();
                }
                display();
                int opt;
                cout << "Do you wish to add data to Queue?"
                     << "\n1 -> Yes"
                     << "\n0 -> No"
                     << "\nChoice: ";
                cin >> opt;
                if (opt == 1)
                {
                    int x = 0;
                    cout << "Enter number of values to Enter: ";
                    cin >> x;
                    insert(x);
                }
                else if (opt == 0)
                {
                    cout << "\033[1;32m\u2705 Code Terminated\033[0m" << endl;
                    return 0;
                }
                else
                {
                    cout << "Invalid Input";
                }
            }
            else if (choice == 5)
            {
                if (!isEmpty())
                {
                    cout << "Element: " << head->data << endl;
                    cout << "Address: " << head << endl;
                }
                else
                {
                    cout << "\033[1;31m Empty Queue!\033[0m" << endl
                         << endl;
                }
            }
            else if (choice == 6)
            {
                if (isEmpty())
                {
                    cout << "\033[1;31m Empty Queue!\033[0m" << endl
                         << endl;
                }
                else
                {
                    cout << "\033[1;32mQueue has data!\033[0m" << endl
                         << endl;
                }
            }
            else if (choice == 7)
            {
                node *p = new node;
                if (p == nullptr)
                {
                    cout << "\033[1;31mQueue is Full!\033[0m" << endl
                         << endl;
                }
                else
                {
                    cout << "\033[1;32mQueue has space!\033[0m" << endl
                         << endl;
                }
                delete p;
            }
            else if (choice == 8)
            {
                cout << "\033[1;35m Enter no of values: \033[0m";
                int x = 0;
                cin >> x;
                insert(x);
            }
            else if (choice == 9)
            {
                if (!isEmpty())
                {
                    cout << "Element: " << tail->data << endl;
                    cout << "Address: " << tail << endl;
                }
                else
                {
                    cout << "\033[1;31m Empty Queue!\033[0m" << endl
                         << endl;
                }
            }
            else
            {
                cout << "Invalid Input\n";
            }
        }
    }
    return 0;
}

// Function to add ELements in the queue using the tail pointer
bool enqueue(int val)
{
    node *temp = new node{val, NULL};
    if (temp == nullptr)
    {
        return false;
    }
    if (head == NULL)
    {
        head = tail = temp;
        return true;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        return true;
    }
}
// Function to remove the Element from the head pointer
bool dequeue()
{
    if (!isEmpty())
    {
        node *trash = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete trash;
        return true;
    }
    else
    {
        return false;
    }
}

// Function to check if the queue is Empty
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to add set of Elements in Queue
void insert(int n)
{
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter Element: ";
        cin >> data;
        enqueue(data);
    }
}

// Function to display all the ELements in the Queue
bool display()
{
    node *temp = head;
    if (head == NULL)
    {
        return false;
    }
    do
    {
        if (temp == head)
        {
            cout << temp->data << "\033[34m <- Head\033[0m" << endl;
        }
        else if (temp == tail)
        {
            cout << temp->data << "\033[34m <- Tail\033[0m" << endl;
        }
        else
        {
            cout << temp->data << endl;
        }
        temp = temp->next;
    } while (temp != NULL);
    return true;
}

// Function to delete set of values in the Queue
bool remove(int n)
{
    if (!isEmpty())
    {
        for (int i = 0; i < n; i++)
        {
            if (!dequeue())
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
