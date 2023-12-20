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
};

// Case : (1.) Insert At Start
struct Node *insertNodeFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Case : (2.) Insert at index
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case : (3.) Insert At End
struct Node *insertNodeAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case : (4.) InsertAfter a Node

struct Node *InsertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

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

    cout << "Linked list before Insertion." << endl;
    linkedListTraversal(head);
    cout << endl;

    cout << "Linked list after Insertion." << endl;

    // Inserting at the start.

    cout << "Inserting at the start." << endl;
    head = insertNodeFirst(head, 1);
    linkedListTraversal(head);

    // Inserting at the Index.

    cout << "Inserting at the Index." << endl;
    head = insertAtIndex(head, 11, 3);
    linkedListTraversal(head);

    // Inserting at the End.

    cout << "Inserting at the End." << endl;
    head = insertNodeAtEnd(head, 55);
    linkedListTraversal(head);

    // Inserting at the End.

    cout << "Inserting After Node" << endl;
    head = InsertAfterNode(head, second, 242);
    linkedListTraversal(head);

    return 0;
}
