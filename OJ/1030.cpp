#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int rows;
    int cols;
    cin >> rows;
    cin >> cols;

    int** m = new int *[rows];
    for (int i = 0; i < rows; i++)
        m[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> m[i][j];

    int** rowMin = new int *[rows];
    for (int i = 0; i < rows; i++)
        rowMin[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            rowMin[i][j] = 0;

    for (int i = 0; i < rows; i++)
    {
        int theMin = INT_MAX;
        for (int j = 0; j < cols; j++)
            theMin = theMin < m[i][j] ? theMin : m[i][j];

        for (int j = 0; j < cols; j++)
            if (theMin == m[i][j])
                rowMin[i][j] = 1;
    }

    int** colMax = new int *[rows];
    for (int i = 0; i < rows; i++)
        colMax[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            colMax[i][j] = 0;

    for (int j = 0; j < cols; j++)
    {
        int theMax = INT_MIN;
        for (int i = 0; i < rows; i++)
            theMax = m[i][j] < theMax ? theMax : m[i][j];

        for (int i = 0; i < rows; i++)
            if (theMax == m[i][j])
                colMax[i][j] = 1;
    }

    int** ans = new int *[rows];
    for (int i = 0; i < rows; i++)
        ans[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ans[i][j] = rowMin[i][j] & colMax[i][j];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (ans[i][j] == 1)
                cout << m[i][j] << ' ';

    return 0;
}