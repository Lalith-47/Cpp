#include<iostream>
using namespace std;

//Defining structure of node
typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} node;

//Defining head,tail and  previous
node *head = NULL;
node *tail = NULL;
node *previous = NULL;

//*All Functions declaration
void convertToCircularLinkedList(); //Function to convert doubly LinkedList to Circular doubly LinkedList
void append(int);  // Function to display number of nodes
void traverse();   //Function to traverse and display all elements
void display(int); // Function to display number of nodes
void displayBackward(int); // Function to display and traverse BACKWARDS

//Body of the main function
int main()
{
    int n,x,y, data,choice;
    cout << "Enter Number of nodes: ";
    cin >> n;
    for (int i = 0; i < n;i++){
        cout << "Enter Element: ";
        cin >> data;
        append(data);
    }
    cout<< "Enter respective number to choose the operation:\n"
    << "1: Display all Elements\n"
    << "2: Convert to Circular Doubly Linked List\n"
    << "3: Display n Elements\n"
    << "4: Display n Elements Backwards\n"
    << "Choice: ";
    
    cin >> choice;
    if (choice == 1)
    traverse();
    else if(choice == 2){
        convertToCircularLinkedList();
        cout << "Enter no of nodes to display: ";
        cin >> y;
        display(y);
    }
    else if (choice == 3)
    {   cout << "Enter number of Elements: ";
        cin >> x;
        if(x<=n){
            display(x);
        }
        else{
            cout << "Enter <= no of nodes\n";
        }
        return 0;
    }
    else if(choice==4){
        displayBackward(n);
    }
    else{
        cout << "Invalid input\n";
    }
}
void append(int data){
    node *temp = new node{NULL,data,NULL};
    if(head == NULL){
        head = tail  = temp;
    }
    else 
    {
        tail->next = temp;
        temp->prev= tail;
        tail = temp;
    }
}
void traverse()
{
    node *ptr = head;
    while(ptr!=NULL){
        cout << "\nPrev: " << ptr->prev << endl;
        cout << "data: " << ptr->data << endl;
        cout << "Next: " << ptr->next << endl;
        ptr = ptr->next;
    }
}
// Function to display number of nodes
void display(int n){
    node *ptr = head;
    int i = 0;
    while(i<n){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
        i++;
    }
}
//Function to convert doubly LinkedList to Circular doubly LinkedList
void convertToCircularLinkedList(){
    head->prev = tail;
    tail->next = head;
}
// Function to display and traverse BACKWARDS
void displayBackward(int n){
    node *ptr = tail;
    int i = 0;
    while(i<n){
        cout << ptr->data << " -> ";
        ptr = ptr->prev;
        i++;
    }
}