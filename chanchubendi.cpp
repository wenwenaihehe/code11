#include<iostream>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int A[100][100] ={
{ 50, 45, 3, 2, 0, 0 },
{ 25, 25, 20, 15, 10, 5 },
{ 15, 15, 5, 15, 20, 30 },
{ 15, 15, 5, 15, 20, 30 },
{ 25, 25, 20, 15, 10, 5 },
{ 20, 20, 15, 20, 15, 10 }
};
int _cd5;
int _cd6;
int choujiang(int _index)
{
	int trand = rand() % 100;
	int st = 0;
	int jl = -1;
	for (int i = 0; i < 6; i++)
	{
		st += A[_index][i];
		if (trand < st)
		{
			jl = i;
			break;
		}
	}

	if (jl == 4 && _cd5 <= 1)
	{
		jl = rand() % 4;
		_cd5 = _cd5 + 1;
	}
	if (jl == 5 && _cd6 <= 2)
	{
		jl = rand() % 4;
		_cd6 = _cd6 + 1;
	}
	if (jl == 4)
	{
		_cd5 = 1;
		_cd6++;
	}
	else if(jl == 5)
	{
		_cd6 = 1;
		_cd5++;
	}
	else 
	{
		_cd5++;
		_cd6++;
	}
	return jl;
}
int main()
{
	for (int i = 0; i < 6; i++)
	for (int j = 0; j < 6; j++)
	{
		//cout << A[i][j] << endl;
	}
	int _index;
	long long int choujiangcishu;
	while (1)
	{
		cin >> _index;
		cin >> choujiangcishu;
		if (_index > 5 || _index < 0)
		{
			cout << "输入不正确" << endl;
			continue;
		}
		_cd5 = 999;
		_cd6 = 999;
		int cishu[7] = { 0 };
		for (int j = 0; j < choujiangcishu; j++)
		{
			int t = choujiang(_index);
			if (t == -1)
			{
				cout << "有错误" << endl;
				continue;
			}
			cishu[t]++;
		}
		for (int i = 0; i < 6; i++)
		{
			cout << double(cishu[i]*1.000 / choujiangcishu*1.0) << " ";
		}
		cout << endl;
	}
	system("pause");
}