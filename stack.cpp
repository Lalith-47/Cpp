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
    int n, val;
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
    display();
    clear();
    cout << s->top;
    display();
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
        for (int i = 0; i <= s->top;i++){
            cout << s->arr[i] << endl;
        }
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