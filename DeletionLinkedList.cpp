#include<iostream>
using namespace std;

//Node creation
typedef struct Node {
    int data;
    struct Node *next;
} node;

//Head and tail node declaration and Intialization
node *head = NULL;
node *tail = NULL;

//Fuction to insert the data and link it
void insert(int value){
    node *temp = new node{value,NULL};
    if (head == NULL){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

//Fuction to display the Linkedlist
void display(){
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data<<endl;
        ptr = ptr->next;
    }
}

//Fuction to delete Node at the begining
void delete_begin(){
    node *ptr = head;
    head = head->next;
    free(ptr);
}

//Fuction to delete at the given index
void delete_index(int index){
    node *ptr = head;
    int i = 0;
    while (i!=index-1)
    {
        ptr = ptr->next;
        i += 1;
    }
    node *remove = ptr->next;
    ptr->next = ptr->next->next;
    free(remove);
}

// Function to delete node at end
void delete_end()
{
    node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}
void delete_next_node(node *ptr){
    node *free_node = ptr->next;
    ptr->next = ptr->next->next;
    free(free_node);
}
int main()
{
    int n,val,choice,idx,opt;
    cout << "Enter No of Nodes to create: ";
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cout << "Enter value for Node " << i + 1 << ": ";
        cin >> val;
        insert(val);
    }

    //*Delete with respect to User choice
    cout << "Enter respective number \n1: Delete first Node\n2: Delete last Node\n3: Delete node at given index\n4: Delete after the given Node\nEnter number: ";
    cin >> choice;
    if(choice==1){
     delete_begin();
    }
    else if(choice==2){
        delete_end();
    }
    else if(choice==3){
        cout << "Enter index: ";
        cin >> idx;
        delete_index(idx);
    }
    //! Bug when tail is added
    else if(choice==4){
        cout << "Enter node number (1: head or 2: tail): ";
        cin >> opt;
        if (opt == 1)
        delete_next_node(head);
        else
        delete_next_node(tail);
    }
    display();
    return 0;
}