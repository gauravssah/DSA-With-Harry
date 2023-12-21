#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
};

void traversLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        cout << "Data In Node : " << head->data << endl;
        head = head->next;
    }
    cout << "Now reversing" << endl;

    if (head == NULL)
    {
        cout << "Data : " << head->data << endl;
        head->pre;

        while (head->pre != NULL)
        {
            cout << "Data : " << head->data << endl;
            head->pre;
        }
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fivth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fivth = (struct Node *)malloc(sizeof(struct Node));

    // Linking First and Second.
    head->pre = NULL;
    head->data = 4;
    head->next = second;

    // Linking Second and third.
    second->pre = head;
    second->data = 8;
    second->next = third;

    // Linking third and fourth.
    third->pre = second;
    third->data = 12;
    third->next = fourth;

    // Linking fourth and fivth.
    fourth->pre = third;
    fourth->data = 22;
    fourth->next = fivth;

    // Linking fourth and fivth.
    fivth->pre = fourth;
    fivth->data = 28;
    fivth->next = NULL;

    traversLinkedList(head);

    return 0;
}