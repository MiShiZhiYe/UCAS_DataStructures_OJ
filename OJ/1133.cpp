#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    char c;
    int temp = 0;
    int flag = 1;
    queue<int> input;
    c = getchar();
    while ((c = getchar()) != '\n')
    {
        if ('0' <= c && c <= '9')
            temp = 10 * temp + int{ c - '0' };
        else if (c == '-')
            flag = -1;
        else if (c == ' ')
        {
            input.push(flag * temp);
            flag = 1;
            temp = 0;
        }
    }
    if (temp != 0)
    {
        input.push(flag * temp);
        flag = 1;
        temp = 0;
    }

    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (a[i][j] == 1)
            {
                a[i][j] = input.front();
                input.pop();
            }

    c = getchar();
    while ((c = getchar()) != '\n')
    {
        if ('0' <= c && c <= '9')
            temp = 10 * temp + int{ c - '0' };
        else if (c == '-')
            flag = -1;
        else if (c == ' ')
        {
            input.push(flag * temp);
            flag = 1;
            temp = 0;
        }
    }
    if (temp != 0)
    {
        input.push(flag * temp);
        flag = 1;
        temp = 0;
    }

    int** b = new int* [rows];
    for (int i = 0; i < rows; i++)
        b[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> b[i][j];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (b[i][j] == 1)
            {
                b[i][j] = input.front();
                input.pop();
            }

    int** sum = new int* [rows];
    for (int i = 0; i < rows; i++)
        sum[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum[i][j] = a[i][j] + b[i][j];

    int** ans = new int* [rows];
    for (int i = 0; i < rows; i++)
        ans[i] = new int[cols];

    queue<int> ret;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (sum[i][j] == 0)
                ans[i][j] = 0;
            else
            {
                ans[i][j] = 1;
                ret.push(sum[i][j]);
            }

    if (ret.empty())
        cout << endl;
    else
    {
        int n = ret.size();
        for (int i = 0; i < n - 1; i++)
        {
            cout << ret.front() << ' ';
            ret.pop();
        }
        cout << ret.front() << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
            cout << ans[i][j] << ' ';
        cout << ans[i][cols - 1] << endl;
    }

    return 0;
}