#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> va;
	int n;

	while (cin >> n)
	{
		va.push_back(n);
	}

	int len = va.size();

	for (int i = len - 1; i > 0; i--)
	{
		if (va[i] < va[i - 1])
		{
			int temp = va[i];
			va[i] = va[i - 1];
			va[i - 1] = temp;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		cout << va[i] << " ";
	}
	cout << va.back();


	return 0;
}