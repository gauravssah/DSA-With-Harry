#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;

    struct Node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }

    // At this p points to the last node of this circular linked list.

    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    fourth->next = head;

    linkedListTraversal(head);

    // Insert at the first node.
    cout << "Insert At the first Node" << endl;
    head = insertAtFirst(head, 44);
    linkedListTraversal(head);

    return 0;
}
