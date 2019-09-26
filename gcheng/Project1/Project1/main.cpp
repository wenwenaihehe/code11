#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	while (1)
	{
		string t;
		//cin >> t;
		getline(cin, t);
		string s = "";
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i] <= 126 && t[i] >= 0)
			{

			}
			else
			{
				s = s + t[i];
			}
		}
		cout << endl;
		cout << s << endl;
		system("pause");
	}
}