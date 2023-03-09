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

    NODE *oldNext = pNode->next;
    NODE newNode = {
        pNode, // prev
        *ptrObj, // info
        oldNext, // next
    };
    *pNode->next = newNode;
    if (oldNext != NULL)
        oldNext->prev = pNode->next;
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
    printr(node->next->next->next->next->next);
    print(node);

    return 0;
}