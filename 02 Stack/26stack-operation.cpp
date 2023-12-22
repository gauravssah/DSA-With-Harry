#include <iostream>
#include <stdlib.h>
using namespace std;

// (26.) Coding Push(), Pop(), isEmpty() and isFull() Operations in Stack Using an Array| C Code For Stack

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        cout << "Stack OverFlow" << endl
             << "At -" << val << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "The stack in UnderFLow! So you can't pop()" << endl;
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    cout << "Stack has been created!" << endl;

    // Cheacking the stack ....
    /*
    if (isEmpty(sp))
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "The stack is not empty!" << endl;
    }

    if (isFull(sp))
    {
        cout << "stack is over flow!" << endl;
    }
    else
    {
        cout << "stack is under flow!" << endl;
    }
*/
    push(sp, 45);
    push(sp, 46);
    push(sp, 47);
    push(sp, 48);
    push(sp, 49);
    push(sp, 50);
    push(sp, 51);
    push(sp, 52);
    push(sp, 53);
    push(sp, 54);
    push(sp, 55);
    push(sp, 56);
    push(sp, 57);
    push(sp, 58);

    /*

    cout << "after pushing.." << endl;
    if (isEmpty(sp))
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "The stack is not empty!" << endl;
    }

    if (isFull(sp))
    {
        cout << "stack is overflow!" << endl;
    }
    else
    {
        cout << "stack is underflow!" << endl;
    }

*/

    cout << "After pop() value : " << pop(sp) << endl;
    return 0;
}