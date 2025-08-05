#include<iostream>
using namespace std;

//Creation and declaration of Node structure
typedef struct Node{
    int data;
    struct Node *next;
} node;

//Declaration of head and tail node
node *head = NULL;
node *tail = NULL;

// Creation of LinkedList
void append(int value){
    node *temp = new node{value,head};
    if(head == NULL){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
        tail->data = value;
    }
}

// Display LinkedList
void display(int stop){
    int i = 0;
    node *ptr = head;
    while(i<stop){
        cout << ptr->data << " -> ";
        i++;
        ptr = ptr->next;
    }
}

//Insert Node at the begining
void insert_at_beginning(int data){
    node *begin = new node{data,head};
    tail->next = begin;
    head = begin;
}


//*Body of the main function
int main()
{
    int n,data;
    cout << "Enter Number of nodes to insert: ";
    cin >> n;
    for (int i = 0; i < n;i++){
        cout << "Enter Element " << i + 1 << ": ";
        cin >> data;
        append(data);
    }
    display(n);
    return 0;
}