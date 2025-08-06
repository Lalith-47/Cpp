#include<iostream>
using namespace std;

//Defining the STACK
typedef struct STACK{
    int top;
    int size;
    int *arr;
} stack;

stack *s= new stack; //Stack declaration and memory allocation

//*Function Declaration
void push(int);  //Push Function for stack
void display(); //Function to display all Elements stack
int pop(); //Fuction to remove the top most element in the stack
void remove(int); //Function to remove n number of elements form the top
void clear(); //Function to empty the stack

// Body of the main function
int main(){
    int n, val,choice;
    cout << "Enter size of the stack: ";
    cin >> n;
    s->top = -1;
    s->size = n;
    s->arr = new int[n];
    for (int i = 0; i < n;i++){
        cout << "Enter data: ";
        cin >> val;
        push(val);
    }
    cout << "Enter the number to perform the operation:"
         << "\n1: display all Elements"
         << "\n2: pop top Element"
         << "\n3: Remove n Elemens starting with the top"
         << "\n4: Empty the Stack"
         <<"\nchoice: ";
    cin >> choice;
    if (choice==1)
    {
        display();
    }
    else if(choice == 2){
        pop();
    }
    else if(choice == 3){
        cout << "Enter No of Elements to remove: ";
        int x = 1;
        cin >> x;
        remove(x);
    }
    else if(choice == 4){
        clear();
    }
    else{
        cout << "Invalid Input";
    }

    return 0;
}

//Push function for stack
void push(int data){
   if(s->top==s->size-1){
       cout<<"\nStack overflow\n";
   }
   else{
        s->top++;
        s->arr[s->top]= data;
    }
}

//Function to display all the Elements in the stack
void display(){
    if(s->top!=-1){
        for (int i = s->top; i > -1;i--){
            cout << s->arr[i] << endl;
        }
        cout << "Top: " << s->arr[s->top] << endl;
    }
    else{
        cout << "\nEmpty Stack\n";
    }
}

// Function to remove the top most Element in the stack
int pop(){
    if(s->top==-1){
        cout << "Stack Underlow\n";
        return -1;
    }
    else{
        int data = s->arr[s->top];
        s->top--;
        return data;
    }
}

//Function to remove N number of elements in the Stack
void remove(int n){
    for (int i = 0; i < n;i++){
        pop();
    }
}

//Function to clear the Entire Stack
void clear(){
    while(s->top!=-1){
        s->top--;
    }
}