#include <iostream>
#include <vector>


using namespace std;


void initializeArrayList(vector<char>&);
vector<char> getCross(vector<char>&, vector<char>&);
vector<char>& getMinus(vector<char>&, vector<char>&);
void printArrayList(vector<char>&);


void initializaeArrayList(vector<char>& list)
{
    char c;
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == ',')
            continue;
        else
            list.push_back(c);
    }
}

vector<char> getCross(vector<char>& l1, vector<char>& l2)
{
    vector<char> theCross;

    vector<char>::iterator i = l1.begin();
    vector<char>::iterator j = l2.begin();

    while (i != l1.end() && j != l2.end())
    {
        if (*i < *j)
            i++;
        else if (*i > *j)
            j++;
        else
        {
            if (!theCross.empty())
            {
                if (theCross.back() != *i)
                    theCross.push_back(*i);

                i++;
                j++;
            }
            else
            {
                theCross.push_back(*i);
            }
        }
    }

    return theCross;
}

vector<char>& getMinus(vector<char>& l1, vector<char>& l2)
{ // return l1 = l1 - l2
    if (l1.empty() || l2.empty())
        return l1;

    vector<char>::iterator i = l1.begin();
    vector<char>::iterator j = l2.begin();

    while (i != l1.end() && j != l2.end())
    {
        if (*i < *j)
            i++;
        else if (*i > *j)
            j++;
        else
        {
            l1.erase(i);
        }
    }

    return l1;
}

void printArrayList(vector<char>& list)
{
    if (list.empty())
        return;

    for (int i = 0; i < list.size() - 1; i++)
    {
        cout << list[i] << ',';
    }
    cout << list.back() << endl;
}


int main()
{
    vector<char> L[3];

    // initialize
    for (int i = 0; i < 3; i++)
        initializaeArrayList(L[i]);

    // get cross
    vector<char> theCross = getCross(L[1], L[2]);

    // minus
    getMinus(L[0], theCross);

    // output
    printArrayList(L[0]);

    return 0;
}