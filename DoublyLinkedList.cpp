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
// Inserting New Node to the Doubly LinkedList
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

//Function to convert doubly LinkedList to Circular doubly LinkedList
void convertToCircularLinkedList(){
    head->prev = tail;
    tail->next = head;
}
void traverse(){
    node *ptr = head;
    while(ptr!=NULL){
        cout << "\nPrev: " << ptr->prev << endl;
        cout << "data: " << ptr->data << endl;
        cout << "Next: " << ptr->next << endl;
        ptr = ptr->next;
    }
}

//Function to display number of nodes
void display(int n){
    node *ptr = head;
    int i = 0;
    while(i<n){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
        i++;
    }
}

//Function to display and traverse BACKWARDS    
void displayBackward(int n){
    node *ptr = tail;
    int i = 0;
    while(i<n){
        cout << ptr->data << " -> ";
        ptr = ptr->prev;
        i++;
    }
}
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
    cout<<"Enter respective number to choose the operation";
    cout << "\n1: Display all Elements";
    cout << "\n2: Convert to circular Linked List(Doubly)";
    cout << "\n3: Display n Elements";
    cout << "\n4: Display n Elements Backwards\n";
    cout << "Choice: ";
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
        if(x<n){
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