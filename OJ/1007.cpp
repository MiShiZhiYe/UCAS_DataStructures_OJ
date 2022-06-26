#include <iostream>
#include <vector>

using namespace std;

void input(vector<char>&);

void input(vector<char>& v)
{
	char n;
	char c;
	while (cin >> n)
	{
		v.push_back(n);
		if ((c = getchar()) == '\n')
			break;
	}
}

int main()
{
	vector<char> va, vb;
	input(va);
	input(vb);

	int i;
	for (i = 0; i < min(va.size(), vb.size()); i++)
	{
		if (va[i] != vb[i])
			break;
	}

	if (i == va.size() && i == vb.size())
	{
		cout << "0" << endl;
	}
	else if (i == va.size() && i != vb.size() || i != va.size() && i != vb.size() && va[i] < vb[i])
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "2" << endl;
	}

	return 0;
}