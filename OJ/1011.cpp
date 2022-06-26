#include <iostream>
#include <vector>

using namespace std;

struct node
{
    char value;
    node* next;
};

node* createLinkedList(vector<char>, int);
node* push_front(node*, node*);
node* reverseLinkedList(node*);
void printLinkedList(node*);

node* createLinkedList(vector<char> input, int size)
{
    node* list = new node;

    node* l = list;
    for (int i = 0; i < size; i++)
    {
        node* temp = new node;
        temp->value = input[i];
        l->next = temp;
        l = l->next;
    }
    l->next = nullptr;

    return list;
}

node* push_front(node* theList, node* theNode)
{
    theNode->next = theList->next;
    theList->next = theNode;
    return theList;
}

node* reverseLinkedList(node* list)
{
    node* p = list->next->next;
    list->next->next = nullptr;
    while (p != nullptr)
    {
        node* temp = p;
        p = p->next;
        push_front(list, temp);
    }
    return list;
}

void printLinkedList(node* list)
{
    if (list->next == nullptr)
    {
        return;
    }

    node* l = list;
    l = list->next;
    while (l->next != nullptr)
    {
        cout << l->value << ",";
        l = l->next;
    }
    cout << l->value << endl;
}

int main()
{
    vector<char> input;
    char c;
    while (true)
    {
        c = getchar();
        if (c == ',')
        {
            continue;
        }
        else if (c == '\n')
        {
            break;
        }
        else
        {
            input.push_back(c);
        }
    }

    node* list = createLinkedList(input, input.size());
    reverseLinkedList(list);
    printLinkedList(list);

    return 0;
}