#include <iostream>

using namespace std;

struct OBJECT_TYPE
{
    int value;
};

struct NODE
{
    NODE *prev;
    OBJECT_TYPE info;
    NODE *next;
};

void InsertAfter(NODE *pNode, OBJECT_TYPE *ptrObj)
{

    NODE *next = pNode->next;
    pNode->next = new NODE();
    pNode->next->prev = pNode;
    pNode->next->info = *ptrObj;
    pNode->next->next = next;
    if (next != NULL)
        next->prev = pNode->next;
}

void InsertLast(NODE **first, OBJECT_TYPE *pObj)
{
    NODE *current = *first;
    while (current->next != NULL)
    {
        current = current->next;
    }
    InsertAfter(current, pObj);
}

void InsertBefore(NODE **first, NODE *pNode, OBJECT_TYPE *pObj)
{
    if (pNode->prev == NULL)
    {
        NODE *newNode = new NODE();
        newNode->prev = pNode->prev;
        newNode->info = *pObj;
        newNode->next = *first;

        *first = newNode;
        pNode->prev = *first;
    }
    else
    {
        NODE *prev = pNode->prev;
        pNode->prev = new NODE();
        pNode->prev->prev = prev;
        pNode->prev->info = *pObj;
        pNode->prev->next = pNode;
    }
}

void print(NODE *first)
{
    cout << first->info.value << " ";
    while (first->next != NULL)
    {
        first = first->next;
        cout << first->info.value << " ";
    }
    cout << endl;
}

void printr(NODE *first)
{
    cout << first->info.value << " ";
    while (first->prev != NULL)
    {
        first = first->prev;
        cout << first->info.value << " ";
    }

    cout << endl;
}

OBJECT_TYPE *mk(int x)
{
    OBJECT_TYPE *result = new OBJECT_TYPE();
    result->value = x;
    return result;
}

int main()
{
    NODE *node = new NODE();

    node->prev = NULL;
    node->info = *mk(0);
    node->next = NULL;

    InsertAfter(node, mk(1));
    InsertAfter(node, mk(2));
    InsertAfter(node, mk(3));
    InsertAfter(node, mk(4));
    InsertAfter(node->next->next->next->next, mk(5));
    InsertBefore(&node, node, mk(6));
    InsertLast(&node, mk(7));
    printr(node->next->next->next->next->next->next->next);
    print(node);

    return 0;
}