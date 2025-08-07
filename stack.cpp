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
void peek(); //Function to print the top most Element along with the index
int isEmpty();//Function to check if the stack is Empty
int isFull(); //Function to check if the stack is full
void insert(int); //Function to insert set of data into stack

// Body of the main function
int main(){
    int n,x,opt,choice,sizeOfStack=0,temp=0;
    cout << "Enter size of the stack: ";
    cin >> n;
    s->top = -1;
    s->size = n;
    s->arr = new int[n];
    cout << "Enter number of values to Enter: ";
    cin >> x;
    sizeOfStack += x;
    if (sizeOfStack <= n)
    {
        insert(x);
    }
    else{
        cout << "No of data to be Entered is more than size of Stack  ";
        cout << "\nStack space available: " << n <<endl;
        sizeOfStack -= x;
        return 0;
    }
    while(1){

        cout << "\n\nEnter the number to perform the operation:"
             << "\n  0: To Exit the loop"     
             << "\n  1: display all Elements"
             << "\n  2: pop top Element"
             << "\n  3: Remove n Elements starting with the top"
             << "\n  4: Empty the Stack"
             << "\n  5: Print Top Element and index"
             << "\n  6: To Check if Stack is empty"
             << "\n  7: To Check if Stack is Full"
             << "\n  8: To add values"
             << "\nchoice: ";
        cin >> choice;
        if(choice==0){
            break;
        }
        else{
            if (choice==1)
            {
                display();
            }
            else if(choice == 2){
                pop();
                display();
            }
            else if(choice == 3){
                cout << "Enter No of Elements to remove: ";
                int x = 1;
                cin >> x;
                remove(x);
                display();
            }
            else if(choice == 4){
                clear();
                display();
                cout << "Do you wish to add data to Stack?"
                     << "\n1 -> Yes"
                     << "\n0 -> No"
                     << "\nChoice: ";
                cin >> opt;
                if (opt == 1)
                {
                    cout << "Enter number of values to Enter: ";
                    cin >> x;
                    sizeOfStack += x;
                    if (sizeOfStack <= n)
                    {
                        insert(x);
                    }
                else{
                    cout << "Stack OverFlow";
                    cout << "\nStack space available: " << n <<endl;
                    sizeOfStack -= x;
                }
                }
                else if(opt == 0){
                    cout << "Code Terminated\n";
                    return 0;
                }
                else{
                    cout << "Invalid Input";
                }
            }
            else if(choice == 5){
                peek();
            }
            else if(choice == 6){
                if(isEmpty()){
                    cout << "Stack is Empty\n";
                }
                else{
                    cout << "Stack contains data\n";
                }
            }
            else if(choice == 7){
                if(isFull()){
                    cout << "Stack is Full\n";
                }
                else{
                    cout << "Stack has space\n";
                }
            }
            else if(choice==8){
                cout << "Enter number of values to Enter: ";
                cin >> x;
                temp = n - sizeOfStack;
                sizeOfStack += x;
                if (sizeOfStack <= n)
                {
                    insert(x);
                }
                else{
                    cout << "Stack OverFlow";
                    cout << "\nStack space available: " << temp <<endl;
                    sizeOfStack -= x;
                }
                temp = 0;
            }
            else{
                cout << "Invalid Input\n";
            }
        }
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

//Function to insert set of data to Stack
void insert(int n){
    int val;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter data: ";
        cin >> val;
        push(val);
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
        cout << "Empty Stack\n";
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

//Function to print the top Element and index
void peek(){
    cout << "Element: " << s->arr[s->top] << endl;
    cout << "Index: " << s->top << endl;
}
//Function to check if Stack is empty
int isEmpty(){
    if(s->top==-1){
           return 1;
    }
    else{
        return 0;
    }
}

//Function to check if Stack is Full
int isFull(){
    if(s->top==s->size-1){
        return 1;
   }
   else{
        return 0;
    }
}

