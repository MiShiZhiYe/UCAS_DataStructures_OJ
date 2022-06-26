#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unordered_set<string> dictionary;
    int number;
    string word;
    vector<string> ans;
    while (cin >> number >> word)
    {
        switch (number)
        {
        case 1:
            dictionary.insert(word);
            break;
        case 2:
            dictionary.erase(word);
            break;
        case 3:
            if (dictionary.find(word) != dictionary.end())
                ans.push_back("True");
            else
                ans.push_back("False");
        }
    }
    for (auto& i : ans)
        cout << i << endl;
    return 0;
}