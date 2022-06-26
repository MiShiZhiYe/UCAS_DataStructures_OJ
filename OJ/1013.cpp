#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct node
{
    int element;
    int frequency;
    node* prior;
    node* next;
    int position;

    node(node* thePrior, node* theNext, int theElement)
    {
        this->element = theElement;
        this->frequency = 0;
        this->prior = thePrior;
        this->next = theNext;
        this->position = INT_MAX;
    }
};

struct list
{
    node* head;
    int size;

    list(int theSize, int* theElement);
    void print() const;
    void locate(int theElement, int thePosition);
};

list::list(int theSize, int* theElement)
{
    this->size = theSize;
    this->head = new node(nullptr, nullptr, theElement[0]);
    node* p;
    node* q = head;
    for (int i = 1; i < theSize; i++)
    {
        p = new node(q, nullptr, theElement[i]);
        q->next = p;
        q = p;
    }
    q->next = head;
    head->prior = q;
}

void list::locate(int theElement, int thePosition)
{
    node* p = head;
    while (p->element != theElement)
        p = p->next;
    p->frequency++;
    p->position = p->position > thePosition ? thePosition : p->position;

    node* q = p->prior;
    while (p->frequency >= q->frequency && p != head)
    {
        if (p->frequency == q->frequency && p->position >= q->position)
            break;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        p->prior = q->prior;
        p->next = q;
        q->prior->next = p;
        q->prior = p;
        if (q == head)
            head = p;
        q = p->prior;
    }
}

void list::print() const
{
    node* p = head;
    for (int i = 0; i < this->size; i++)
    {
        cout << p->element << " ";
        p = p->next;
    }
}

int main()
{
    int size;
    cin >> size;
    int* buffer = new int[size];
    for (int i = 0; i < size; i++)
        cin >> buffer[i];
    list L(size, buffer);

    vector<int> input;
    int temp;
    char c;
    while (true)
    {
        cin >> temp;
        input.push_back(temp);
        if ((c = getchar()) == '\n')
            break;
    }
    for (int i = 0; i < input.size(); i++)
        L.locate(input[i], i);
    L.print();

    return 0;
}