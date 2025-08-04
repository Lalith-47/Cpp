#include<iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} node;
void LinkedListTravesal(node *ptr){
    while (ptr!=NULL){
    cout << "Element: " << ptr->data << "\nAddress: "<<ptr<<"\n\n";
    ptr = ptr->next;
    }
}
int main()
{  //Pointer creation
    node *head = new node;
    node *second = new node;
    node *third = new node;
   //Linking the nodes and also giving the data for the node

    // Node 1
    head->data = 1;
    head->next = second;

    // Node 2
    second->data = 2;
    second->next = third;

    // Node 3
    third->data = 3;
    third->next = NULL;

    // Traverse and print the linked list
    LinkedListTravesal(head);
    
    return 0;
}