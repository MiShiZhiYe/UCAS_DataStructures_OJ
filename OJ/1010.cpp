#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int value;
	node* next;
};

node* createLinkList(vector<int>, int);
node* deleteLinkListElement(node*, int, int);
void printLinkList(node*);

node* createLinkList(vector<int> arr, int size)
{
    node* list = new node;

	node* l = list;
	for (int i = 0; i < size; i++)
	{
		node* temp = new node;
		temp->value = arr[i];
		l->next = temp;
		l = l->next;
	}
	l->next = nullptr;

	return list;
}

node* deleteLinkListElement(node* list, int mink, int maxk)
{
    node* before = list;

    before = before->next;
    while (before != nullptr && before->next->value <= mink)
    {
        before = before->next;
    }
    if (before == nullptr)
    {
        return list;
    }

    node* after = before;
    while (after != nullptr && after->value < maxk)
    {
        after = after->next;
    }
    if (after == nullptr)
    {
        before->next = nullptr;
        return list;
    }
    else
    {
        before->next = after;
        return list;
    }

}

void printLinkList(node* list)
{
    if (list->next == nullptr)
    {
        return;
    }

    node* l = list;
    l = l->next;
    while (l->next != nullptr)
    {
        cout << l->value << " ";
        l = l->next;
    }
    cout << l->value << endl;
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

    int mink;
    int maxk;
    cin >> mink >> maxk;

    node* deleteLinkList = deleteLinkListElement(list, mink, maxk);
    printLinkList(deleteLinkList);

    return 0;
}