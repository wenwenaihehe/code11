#include<iostream>
#include<vector>
#include<algorithm>

#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int BeiLv = 8658;
const int cnt = 27;
ofstream ofile;
int suijicishu = 0;
int suanbaida(vector<int> A)
{

	int x = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == 100 || A[i] == 15 || A[i] == 14)
			x++;
	}
	
	return x;
}
int suanzhadanwu(vector<int> A)
{
	int Soul[1010] = { 0 };
	int x = 0;
	for (int i = 0; i < A.size(); i++)
	{
		Soul[A[i]]++;
	}
	for (int i = 0; i < 15; i++)
	{
		if (Soul[i] >= 5)
		{
			x++;
			cout << "有五炸拉" << endl;
		}
	}
	return x;
}
void xieru(vector<int> A,vector<int> P[])
{

	int sumzha = 0;
	for (int i = 0; i < 4; i++)
	{
		sumzha += A[i];
		
	}
	ofile << "总炸弹数" << sumzha << endl<<endl;
	for (int i = 0; i < 4; i++)
	{
		ofile << "炸弹数" << A[i] << "   " << "五炸" << suanzhadanwu(P[i]) << "百搭牌个数" << suanbaida(P[i]) << endl;
		for (int j = 0; j < P[i].size(); j++)
		{
			//ofile << P[i][j] << " ";
			//cout << P[i][j] << " ";
		}
		//ofile << endl;
		//cout << endl;
	}
	ofile << endl;

}
int suanzhadan(vector<int> A)
{
	int Soul[1000] = { 0 };
	int x = 0;
	for (int i = 0; i < A.size(); i++)
	{
		Soul[A[i]]++;
	}
	for (int i = 0; i < 15; i++)
	{
		if (Soul[i] >= 4)
			x++;
	}
	return x;
}

vector<int> reZha(vector<int> P[])
{
	vector<int> fanhui;
	fanhui.clear();


	for (int i = 0; i < 4; i++)
	{
		fanhui.push_back(suanzhadan(P[i]));
	}
	
	return fanhui;
}
vector<int> dealpai(vector<int> a)
{


	ofile << "第" << suijicishu << "次" <<endl;

	
	int xiPaiCount = 0; // 洗牌次数
	vector<int> AllYou;
	vector<int> pPlayer[4];
	int zhadan = 0;
	while (1)
	{
		int t = rand() % a.size();
		reverse(a.begin() + t, a.end());
		reverse(a.begin(), a.begin() + t);
		reverse(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++)
		{
			//cout << a[i] << endl;
		}
		zhadan = 0;
		for (int i = 0; i<=3;i++)
			pPlayer[i].clear();
		xiPaiCount++;
		int AllCount = rand() % 10000;
		if (xiPaiCount >3)
		{
			break;
		}
		int nowfen = 0;
		for (int i = 0; i < a.size(); i++)
		{
			//cout << a.size() << endl;
			if (i % 4 == 0 && i != 0)
			{
				nowfen++;
				if (nowfen > 3)
				{
					nowfen = 0;
				}
			}
			while (1)
			{
				if (pPlayer[nowfen].size() >= cnt)
				{
					nowfen++;
					if (nowfen > 3)
					{
						nowfen = 0;
					}
				}
				else
					break;
			}
			pPlayer[nowfen].push_back(a[i]);
		}
		vector<int> soul = reZha(pPlayer);
		
		for (int i = 0; i < soul.size(); i++)
		{
			zhadan += soul[i];
		}
		xieru(soul, pPlayer);
		if (zhadan >= 10)
		{
			break;
		}
		if (AllCount > 8658)
		{
			break;
		}
		
	}
	vector<int> fanhui;
	return fanhui;
}


int main()
{
	vector<int> A; 
	ofile.open("d:\\jhdsb.txt");


	//cout << A.size() << endl;
	vector<int> B;
	for (int i = 0; i < 10000; i++)
	{
		A.clear();

		int baidapai = rand() % 13 + 1;

		for (int k = 0; k < 2; k++)
		{
			if (k == 0)
			{

				for (int i = 1; i < 16; i++)
				{
					if (baidapai == i)
					{
						for (int j = 0; j < 3; j++)
							A.push_back(i);
						A.push_back(100);
					}
					else if (i < 14)
					{
						for (int j = 0; j < 4; j++)
							A.push_back(i);
					}
					else
					{
						for (int z = 0; z < 1; z++)
							A.push_back(i);
						int k = rand() % A.size();
						swap(A[k], A[A.size() - 1]);
					}
				}
			}
			else
			{
				for (int i = 15; i >= 1; i--)
				{
					if (baidapai == i)
					{
						for (int j = 0; j < 3; j++)
							A.push_back(i);
						A.push_back(100);
					}
					else if (i < 14)
					{
						for (int j = 0; j < 4; j++)
							A.push_back(i);
					}
					else
					{
						for (int z = 0; z < 1; z++)
							A.push_back(i);
						int k = rand() % A.size();

						swap(A[k], A[A.size()-1]);
					}
				}
			}

		}
		for (int i = 0; i < A.size(); i++)
		{
		//	cout << A[i] << endl;
		}
		//cout << A.size() << endl;
		suijicishu++;
		B = A;
		B = dealpai(B);
	}
	system("pause");

}