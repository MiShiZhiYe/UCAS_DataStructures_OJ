#include<iostream>

using namespace std;

int main()
{
    int x_exp_max, y_exp_max;
    cin >> x_exp_max >> y_exp_max;

    int** x = new int *[x_exp_max];
    for (int i = 0; i < x_exp_max; i++)
        x[i] = new int[y_exp_max];

    for (int i = 0; i < x_exp_max; i++)
        for (int j = 0; j < y_exp_max; j++)
            cin >> x[i][j];

    bool is_first = true;
    for (int i = x_exp_max - 1; i >= 0; i--)
    {
        for (int j = y_exp_max - 1; j >= 0; j--)
        {
            if (x[i][j] != 0)
            {
                if (!is_first)
                {
                    cout << '+';
                }
                else
                {
                    is_first = false;
                }

                if (x[i][j] != 1)
                {
                    cout << x[i][j];
                }

                if (i != 0)
                {
                    cout << "xE" << i;
                }
                if (j != 0)
                {
                    cout << "yE" << j;
                }
            }
        }
    }

    return 0;
}