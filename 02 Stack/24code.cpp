#include <iostream>
#include <stdlib.h>
using namespace std;

// (24.) C Code For Implementing Stack Using Array in Data Structures

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
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

int isFull(struct stack *ptr)
{
    if (ptr->top >= ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s;

    // Allocate memory for the stack
    s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 4;
    s->top = -1;

    // Allocate memory for the array inside the stack
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 40;
    s->top++;

    if (isEmpty(s))
    {
        cout << "The stack is Empty." << endl;
    }
    else
    {
        cout << "Not empty!" << endl;
    }

    cout << "Now checking isFull or Not..." << endl;
    cout << "s->top : " << s->top << endl;
    cout << "s->size : " << s->size << endl;

    if (isFull(s))
    {
        cout << "The stack is full." << endl;
    }
    else
    {
        cout << "Not full." << endl;
    }

    return 0;
}
