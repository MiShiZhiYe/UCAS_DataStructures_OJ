#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int value;
    node* next;
};

node* createLinkList(int*);
node* deleteIndex(node*, int);
void printLinkList(node*);

node* createLinkList(vector<int> arr, int size)
{
    node* list = new node;

    node* l = list;
    l->value = arr[0];
    l->next = nullptr;
    for (int i = 1; i < size; i++)
    {
        node* temp = new node;
        temp->next = nullptr;
        temp->value = arr[i];
        l->next = temp;
        l = l->next;
    }

    return list;
}

node* deleteIndex(node* linkList, int index)
{
    if (index == 0)
    {
        return linkList->next;
    }

    node* l = linkList;

    for (int i = 0; i < index - 1; i++)
    {
        l = l->next;
    }
    l->next = l->next->next;

    return linkList;
}

void printLinkList(node* linkList)
{
    if (linkList == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }

    node* temp = linkList;
    while (temp->next != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << temp->value << endl;
}

int main()
{
    vector<int> input;
    int temp;
    char c;

    while (true)
    {
        cin >> temp;
        input.push_back(temp);
        if ((c = getchar()) == '\n')
        {
            break;
        }
    }

    node* list = createLinkList(input, input.size());

    int index;
    cin >> index;

    node* deleteList = deleteIndex(list, index);
    printLinkList(deleteList);

    return 0;
}