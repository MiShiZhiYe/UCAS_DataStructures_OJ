#include <iostream>

using namespace std;

int main()
{
	int x0;
	int n;
	cin >> x0 >> n;

	int* a = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
	}

	int ans = 0;

	for (int i = 0; i <= n; i++)
	{
		ans = ans * x0 + a[n - i];
	}

	cout << ans << endl;

	return 0;
}