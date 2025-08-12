#include <iostream>
#include "codes.h"
using namespace std;

// Defining structure of Queue
struct queue
{
    int head;
    int tail;
    int size;
    int *arr;
};

//*Function prototypes
bool isEmpty(queue *);      // Function to check if the queue is empty
bool isFull(queue *);       // Function to check if the queue is empty
bool enqueue(queue *, int); // Function to enter data to the queue
bool dequeue(queue *);      // Function to remove the head ELement
bool update(queue *);       // Function to update the values in queue after deletion
bool remove(queue *, int);  // Function to remove set of values in Queue
bool insert(queue *, int);  // Function to insert set of values in queue
bool display(queue *);      // Function to display all Elements in the queue
bool clear(queue *);        // Function to clear all the elements in the queue

// Body of the main function
int main()
{
    cout << cls << home;
    int choice = 0;
    queue *q = new queue;
    cout << magenta << "Enter size of Queue: " << reset;
    cin >> q->size;
    q->arr = new int[q->size];
    q->head = -1;
    q->tail = -1;
    while (1)
    {
        cout << magenta
             << "\nEnter the number to perform the operation:"
             << reset << blue
             << "\n  0: To Exit the loop"
             << "\n  1: display all Elements"
             << "\n  2: remove head Element"
             << "\n  3: Remove n Elements starting with the top"
             << "\n  4: Empty the Queue"
             << "\n  5: Print Top Element"
             << "\n  6: To Check if Queue is empty"
             << "\n  7: To Check if Queue is Full"
             << "\n  8: To add values"
             << "\n  9: To print the tail/last Element of the Top Element"
             << "\nchoice: "
             << reset;
        cin >> choice;
        if (choice == 0)
        {
            cout << green << tick << " Code Terminated" << endl;
            break;
        }
        else
        {
            if (choice == 1)
            {
                display(q);
            }
            else if (choice == 2)
            {
                dequeue(q);
                display(q);
            }
            else if (choice == 3)
            {
                if (!isEmpty(q))
                {
                    int x = 1;
                    cout << "Enter No of Elements to remove: ";
                    cin >> x;
                    if (remove(q, x))
                    {
                        display(q);
                    }
                }
                else
                {
                    cout << red << "Queue is Empty" << reset << endl;
                }
            }
            else if (choice == 4)
            {
                clear(q);
            }
            else if (choice == 5)
            {
                if (!isEmpty(q))
                {
                    cout << magenta << "Element: " << q->arr[q->head] << reset << endl;
                }
                else
                {
                    cout << red << "Queue is Empty" << reset << endl;
                }
            }
            else if (choice == 6)
            {
                if (isEmpty(q))
                {
                    cout << red << "Queue is Empty" << reset << endl;
                }
                else
                {
                    cout << "Queue contains data\n";
                }
            }
            else if (choice == 7)
            {
                if (isFull(q))
                {
                    cout << yellow << "Queue is Full" << reset << endl;
                }
                else
                {
                    cout << "Queue has space\n";
                }
            }
            else if (choice == 8)
            {
                int x = 1;
                cout << "Enter number of values to Enter: ";
                cin >> x;
                if (q->size >= (x + q->tail))
                {
                    insert(q, x);
                }
                else
                {
                    cout << yellow << "No Enough space!";
                    cout << "\nQueue space available: " << (q->size - q->tail - 1) << reset << endl;
                }
            }
            else if (choice == 9)
            {
                if (!isEmpty(q))
                {
                    cout << magenta << "Element: " << q->arr[q->tail] << reset << endl;
                }
                else
                {
                    cout << red << "Queue is Empty" << reset << endl;
                }
            }
            else
            {
                cout << red << "InvalidInput" << reset << endl;
            }
        }
    }
    delete[] q->arr;
    delete q;
    return 0;
}

// Function to check if the queue is empty
bool isEmpty(queue *q)
{
    if (q->head == -1 && q->tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to check if the queue is empty
bool isFull(queue *q)
{
    if (q->tail + 1 == q->size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to enter data in the queue
bool enqueue(queue *q, int data)
{
    if (isEmpty(q))
    {
        q->head = q->tail = 0;
        q->arr[q->head] = data;
        return true;
    }
    else
    {
        if (isFull(q))
        {
            cout << red << "Queue size exceeded!" << reset << endl;
            return false;
        }
        else
        {
            q->arr[++q->tail] = data;
            return true;
        }
    }
}

// Function to remove the head ELement
bool dequeue(queue *q)
{
    if (q->tail == 0)
    {
        q->tail = -1;
        q->head = -1;
        return true;
    }
    if (isEmpty(q))
    {
        cout << red << "No Element to remove!" << reset << endl;
        return false;
    }
    else
    {
        q->head++;
        update(q);
        return true;
    }
}

// Function to update the values in queue after deletion
bool update(queue *q)
{
    if (!isEmpty(q))
    {
        int n = q->head;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= q->tail; j++)
            {
                q->arr[j] = q->arr[j + 1];
            }
            q->tail--;
        }
        q->head = 0;
        return true;
    }
    else
    {

        cout << red << "Queue is empty!" << reset << endl;
        return false;
    }
}

// Function to remove set of values in Queue
bool remove(queue *q, int n)
{
    if (!isEmpty(q))
    {
        for (int i = 0; i < n; i++)
        {
            dequeue(q);
        }
        return true;
    }
    else
    {
        cout << red << "Queue is Empty!" << reset << endl;
        return false;
    }
}

// Function to insert set of values in Queue
bool insert(queue *q, int n)
{
    if (!isFull(q))
    {
        for (int i = 0; i < n; i++)
        {
            int data = 0;
            cout << magenta << "Enter data: " << reset;
            cin >> data;
            enqueue(q, data);
        }
        return true;
    }
    else
    {
        cout << red << "Queue is Full!" << reset << endl;
        return false;
    }
}

bool display(queue *q)
{
    if (!isEmpty(q))
    {
        for (int i = 0; i <= q->tail; i++)
        {
            if (i == q->head)
            {
                cout << q->arr[i] << blue << " <- head" << reset << endl;
            }
            else if (i == q->tail)
            {
                cout << q->arr[i] << blue << " <- tail" << reset << endl;
            }
            else
            {
                cout << q->arr[i] << endl;
            }
        }
        return true;
    }
    else
    {
        cout << red << "Queue was Empty!" << reset << endl;
        return false;
    }
}

// Function to clear the queue
bool clear(queue *q)
{
    if (!isEmpty(q))
    {
        while (q->tail != -1)
        {
            dequeue(q);
        }
        return true;
    }
    else
    {
        cout << red << "Queue is Empty" << reset << endl;
        return false;
    }
}
