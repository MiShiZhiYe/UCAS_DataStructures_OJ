#include <iostream>

using namespace std;

struct node
{
	int value;
	node* next;
};

node* createLinkList(int*, int);
node* connect2LinkList(node*, node*, int, int);
void printLinkList(node*);

node* createLinkList(int* arr, int size)
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

node* connect2LinkList(node* ha, node* hb, int m, int n)
{
	node* hc = hb;
	node* temp = hc;

	while (temp->next != nullptr)
		temp = temp->next;

	temp->next = ha->next;

	ha = hb = nullptr;

	return hc;
}

void printLinkList(node* linkList)
{
	node* temp = linkList;

	temp = temp->next;
	while (temp->next != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << temp->value << endl;
}

int main()
{
	int m, n;
	cin >> m >> n;

	int* a = new int[m];
	int* b = new int[n];

	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	node* ha = createLinkList(a, m);
	node* hb = createLinkList(b, n);

	node* hc = connect2LinkList(ha, hb, m, n);
	printLinkList(hc);

	return 0;
}