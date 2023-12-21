// Delete a Node from Linked List (C Code For Deletion From Beginning, End, Specified Position & Key)
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "The Value is : " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case : ( 1.) Deleting the first element from the linked list.

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case : ( 2.) Deleting the Element at a given index from the linked list.
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Case : ( 3.) Deleting the last Element.

struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

// Case : ( 4.) Deleting the Element with a given value from the linked list.
struct Node *deleteAtvalue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 12;
    second->next = third;

    // Link third and fourth nodes
    third->data = 22;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 40;
    fourth->next = NULL;

    cout << "Linked list before deletion." << endl;
    linkedListTraversal(head);
    cout << endl;

    // For deleting first element of the linked list.

    // head = deleteFirst(head);
    // head = deleteFirst(head);
    // cout << "Linked list After deletion." << endl;
    // linkedListTraversal(head);

    // For deleting the Node at Index.
    // head = deleteAtIndex(head, 2);
    // cout << "Linked list After deletion." << endl;
    // linkedListTraversal(head);

    // For deleting the Node at Index.
    // head = deleteAtLast(head);
    // cout << "Linked list After deletion." << endl;
    // linkedListTraversal(head);

    // For deleting the Node at given Value.
    head = deleteAtvalue(head, 22);
    cout << "Linked list After deletion." << endl;
    linkedListTraversal(head);

    return 0;
}
