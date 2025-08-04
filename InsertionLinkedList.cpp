#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
} node;

//Traversing the LinkedList
void Traversal(node *ptr){
    while(ptr!=NULL){
        cout << "\nElement: " << ptr->data << "\nAddress: " << ptr->next << "\n";
        ptr = ptr->next;
    }
}
//Function to add node at the Begin
node *start(node *head,int data){
    node *begin = new node;
    begin->data = data;
    begin->next = head;
    return begin;
}

//Function to add Node at the END
void end(node *ptr,int data){
    node *last = new node;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    last->data = data;
    last->next = NULL;
    ptr->next = last;
}

//Function to add node at the given INDEX
void index(node *ptr,int index,int data){
    node *indexed_node = new node;
    int i = 0;
    while(i!=index-1){
        ptr = ptr->next;
        i += 1;
    }
    indexed_node->next = ptr->next;
    ptr->next = indexed_node;
    indexed_node->data = data;
}

//Function to add Node after given Node
void after_node(node *given, int data){
    node *new_node = new node; 
    new_node->next=given->next;
    given->next = new_node;
    new_node->data = data;
}
int main()
{
    // Creation of Node pointer
    node *head = new node;
    node *second = new node;
    node *third = new node;
   
    //Linking the nodes

    //Node 1
    head->data = 1;
    head->next = second;

    //Node 2
    second->data = 2;
    second->next = third;

    //Node 3
    third->data = 3;
    third->next = NULL;


    // TO add Node at the Begin
    // head=start(head, 0);


    //To add node at the end
    // end(head, 4);


    // To add node at given INDEX
    // index(head, 2, 10);

    // To add node after another given node
    // after_node(second, 9);

    //Calling the traversal function
    Traversal(head);
    return 0;
}
