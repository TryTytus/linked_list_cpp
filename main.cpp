#include <iostream>

using namespace std;

struct NODE
{
    NODE *prev;
    int info;
    NODE *next;
};

void InsertAfter(NODE *pNode, int val)
{

    NODE *next = pNode->next;
    pNode->next = new NODE();
    pNode->next->prev = pNode;
    pNode->next->info = val;
    pNode->next->next = next;
    if (next != NULL)
        next->prev = pNode->next;
}

void print(NODE *first)
{
    cout << first->info << " ";
    while (first->next != NULL)
    {
        first = first->next;
        cout << first->info << " ";
    }
    cout << endl;
}

void printr(NODE *first)
{
    cout << first->info << " ";
    while (first->prev != NULL)
    {
        first = first->prev;
        cout << first->info << " ";
    }

    cout << endl;
}
int main()
{
    NODE *node = new NODE();

    node->prev = NULL;
    node->info = 0;
    node->next = NULL;

    InsertAfter(node, 1);
    InsertAfter(node, 2);
    InsertAfter(node, 3);
    InsertAfter(node, 4);
    InsertAfter(node->next->next->next->next, 5);
    printr(node->next->next->next->next->next);
    print(node);

    return 0;
}