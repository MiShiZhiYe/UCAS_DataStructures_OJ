#include <iostream>

using namespace std;

struct school
{
	char name;				// school name
	int MScore = 0;			// score of male
	int FScore = 0;			// score of female
	int score = 0;			// total score
};

struct match
{
	char projectName;			// project name
	char sex;					// sex
	char schoolName;			// school name
	int projectScore;			// project score
};

int main()
{
	int n = 0;
	match* m = new match[n];
	while (cin >> m[n].projectName >> m[n].sex >> m[n].schoolName >> m[n].projectScore)
	{
		n++;
	}

	for (int i = 0; i < n; i++)
		cin >> m[i].projectName >> m[i].sex >> m[i].schoolName >> m[i].projectScore;

	school s[5];
	string schoolName = "ABCDE";
	for (int i = 0; i < 5; i++)
		s[i].name = schoolName[i];

	for (int i = 0; i < n; i++)
	{
		if (m[i].sex == 'M')
		{
			s[m[i].schoolName - 'A'].MScore += m[i].projectScore;
			s[m[i].schoolName - 'A'].score += m[i].projectScore;
		}
		else
		{
			s[m[i].schoolName - 'A'].FScore += m[i].projectScore;
			s[m[i].schoolName - 'A'].score += m[i].projectScore;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (s[i].MScore)
			cout << s[i].name << " M " << s[i].MScore << endl;
		if (s[i].FScore)
			cout << s[i].name << " F " << s[i].FScore << endl;
		if (s[i].score)
			cout << s[i].name << " " << s[i].score << endl;
	}

	return 0;
}