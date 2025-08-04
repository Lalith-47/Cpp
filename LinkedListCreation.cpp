#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
} node;
//Declaration and intializing head and tail Pointer
node *head = NULL;
node *tail = NULL;
//Function to create and insert new node at END
void Insert(int val){
    node *temp = new node{val, NULL};

    if (head == NULL){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
//Function to traverse and print the LinkedList
void Traversal(node *ptr){
    while(ptr!=NULL){
        cout << "\nElement: " << ptr->data << "\nAddress: " << ptr << endl;
        ptr = ptr->next;
    }
}
int main()
{
    int n, val;
    cout << "Enter Size: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter ELement " << i +1<< ": ";
        cin >> val;
        Insert(val);
    }
    Traversal(head);
}