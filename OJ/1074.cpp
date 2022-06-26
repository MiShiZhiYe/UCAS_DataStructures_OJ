#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int X, Y;
int start_x, start_y, key_x, key_y, end_x, end_y;
char maze[100][100];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

struct point
{
    int x, y;
    vector<point> path;
};

inline bool checkEdge(int x, int y)
{
    return (x >= 0 && y >= 0 && x < X && y < Y);
}

vector<point> BFS(int begin_x, int begin_y, int fin_x, int fin_y)
{
    point start, next;
    start.x = begin_x;
    start.y = begin_y;
    start.path.push_back(start);
    queue<point> q;
    q.push(start);
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        if (start.x == fin_x && start.y == fin_y)
            return start.path;
        for (int i = 0; i < 4; i++)
        {
            next.x = start.x + dir[i][0];
            next.y = start.y + dir[i][1];
            if (checkEdge(next.x, next.y) && maze[next.x][next.y] != '1')
            {
                maze[next.x][next.y] = '1';
                next.path = start.path;
                next.path.push_back(next);
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> X;
    cin >> Y;
    memset(maze, 0, sizeof(maze));
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'R')
            {
                start_x = i;
                start_y = j;
            }
            else if (maze[i][j] == 'Y')
            {
                key_x = i;
                key_y = j;
            }
            else if (maze[i][j] == 'C')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    vector<point> path1 = BFS(start_x, start_y, key_x, key_y);
    vector<point> path2 = BFS(key_x, key_y, end_x, end_y);
    for (auto it = path1.begin(); it != path1.end(); it++)
    {
        cout << (*it).x + 1 << " " << (*it).y + 1 << endl;
    }
    for (auto it = path2.begin() + 1; it != path2.end(); it++)
    {
        cout << (*it).x + 1 << " " << (*it).y + 1 << endl;
    }
    return 0;
}