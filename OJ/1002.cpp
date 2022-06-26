#include <iostream>

using namespace std;

int main()
{
	int k, m;

	cin >> k >> m;

	int* f = new int[k];

	for (int i = 0; i < k-1; ++i)
	{
		f[i] = 0;
	}
	f[k - 1] = 1;

	for (int i = 0; i < m; ++i)
	{
		int fk = 0;
		for (int j = 0; j < k; ++j)
		{
			fk += f[j];
		}
		for (int j = 0; j < k - 1; ++j)
		{
			f[j] = f[j + 1];
		}
		f[k - 1] = fk;
	}

	cout << f[0] << endl;

	return 0;
}