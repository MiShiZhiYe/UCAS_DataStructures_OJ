#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int i = 0;
    int j = s.size() - 2;

    while (i <= (s.size() - 1) / 2)
    {
        if (s[i] != s[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{
    vector<int> ans;

    string s;
    while (cin >> s)
    {
        ans.push_back(solution(s));
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}