#include<iostream>
#include<vector>
#include<algorithm>

#include<fstream>
#include<string>
#include<iomanip>
#include<map>
using namespace std;
int BeiLv = 8658;
const int cnt = 27;
int ncount = 0;
ofstream ofile;
vector<int> B;
vector<int> A;
vector<int> C;
vector<int> D;
vector<int> pPlayer[4];
void xipai()
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

						swap(A[k], A[A.size() - 1]);
					}
				}
			}

		}

}
//三张三张凑一对 
void fenpai(){
	B.clear();
	int sizeA = A.size();
	for (; sizeA > 0;)
	{
		if (sizeA <= 0)
		{
			break;
		}
		int tmp;
		int m = rand() % sizeA;
		for (int i = 0; i < 3; i++)
		{
			if (m > A.size() - 1)
			{
				break;
			}
			if (sizeA <= 0)
			{
					break;
			}
			tmp = A[m];
			B.push_back(tmp);
			A[m] = A[sizeA - 1];
			sizeA--;
			m++;
		}
	}
}

void fenwanjiapai()
{
	int nowfen = 0;
	for (int i = 0; i < 4; i++)
	{
		pPlayer[i].clear();
	}
	for (int i = 0; i < B.size(); i++)
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
		pPlayer[nowfen].push_back(B[i]);
	}
}

void tongjidanpai(){
	map<int, map<int, vector<int> >> perNumCards; //每个玩家手里的牌值大小的单牌
	map<int, vector<int> > perAloneCards; // 玩家手里的单牌总共
	map<int, vector<int> > aloneCards;  //牌值大小单牌
	for (int i = 0; i < 4; i++)
	{
		vector<int> s;
		s.clear();
		s= pPlayer[i];
		std::map<int , vector<int> > numCards;
		for (int j = 0; j < s.size(); j++)
		{
			numCards[s[j]].push_back(s[j]);
		}
		perNumCards[i] = numCards;
		std::map<int, vector<int>>::iterator it;
		for (it = numCards.begin(); it != numCards.end(); it++)
		{
			int num = it->first;
			vector<int> aloneCard = it->second;
			if (1 == aloneCard.size())
			{
				if (2 <= num && num <= 9)
				{
					aloneCards[num].push_back(aloneCard[0]);
					perAloneCards[i].push_back(aloneCard[0]);
				}
			}
			if (6 <= aloneCard.size())
			{
				for (int k = 0; k < 2; k++)
				{
					aloneCards[num].push_back(aloneCard[k]);
					perAloneCards[i].push_back(aloneCard[k]);
				}
			}
		}

	}
	if (aloneCards.size() == 0){
		return;
	}
	//（二）先删除每个人手中的单牌
	for (int seat = 0; seat < 4; seat++)
	{
		vector<int> perAlones = perAloneCards[seat];
		for (int i = 0; i < perAlones.size(); i++)
		{
			vector<int>::iterator pos;
			pos = find(pPlayer[seat].begin(), pPlayer[seat].end(), perAlones[i]);
			if (pos != pPlayer[seat].end())
			{
				pPlayer[seat].erase(pos);
			}
		}
	}
	//（三）重新分配单牌
	for (int seat = 0; seat < 4; seat++)
	{
		vector<int> perAlone = perAloneCards[seat];
		for (int i = 0; i < perAlone.size(); i++)
		{
			vector<int> desSeat;
			map<int, int> addSeat;
			int maxCount = 0;
			int num =	perAlone[i];
			for (int sit = 0; sit < 4; sit++)
			{
				vector<int> handCards = pPlayer[sit];
				if (sit != seat && handCards.size() < cnt)
				{
					desSeat.push_back(sit);
					addSeat[sit] = 0;
					std::map<int, vector<int> > cardNum = perNumCards[sit]; //perNumCards取删除之后的？perNumCards每加回一张牌后要不要重新统计
					std::map<int, vector<int> >::iterator it = cardNum.find(num);
					if (it == cardNum.end()){
						continue;
					}
					int count = it->second.size();
					addSeat[sit] = count;
				}
			}
			if (addSeat.size() == 0)
			{
				addSeat[seat] = 0;
				desSeat.push_back(seat);
			}
			//int randSeat = rand() % desSeat.size();
			//tmpCards[desSeat[randSeat]].push_back(perAlone[i]);

			int min = 0;
			int toseat = 0;
			map<int, int>::iterator to = addSeat.begin();
			if (addSeat.size() == 3){
				to++;
				to++;
				toseat = to->first;
			}
			else if (addSeat.size() == 2){
				to++;
				toseat = to->first;
			}
			else{
				toseat = to->first;
			}
			pPlayer[toseat].push_back(perAlone[i]);
		}
	}
}
int tongjizhadan(){
	int Soul[1000] = { 0 };
	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		memset(Soul, 0, sizeof(Soul));
		for (int j = 0; j < pPlayer[i].size(); j++)
		{
			Soul[pPlayer[i][j]]++;
		}
		for (int z = 0; z < 15; z++)
		{
			if (Soul[z] >= 4)
				x++;
		}
	}

	return x;
}
int zhadanshu(int seat)
{
	int Soul[1000] = { 0 };
	int x = 0;
	for (int j = 0; j < pPlayer[seat].size(); j++)
	{
		Soul[pPlayer[seat][j]]++;
	}

	for (int i = 0; i < 15; i++)
	{
		if (Soul[i] >= 4)
			x++;
	}
	return x;
}
int wuZhashu(int seat)
{
	int Soul[1000] = { 0 };
	int x = 0;
	for (int j = 0; j < pPlayer[seat].size(); j++)
	{
		Soul[pPlayer[seat][j]]++;
	}

	for (int i = 0; i < 15; i++)
	{
		if (Soul[i] >= 5)
			x++;
	}
	return x;
}
int baidapai(int seat)
{
	int x = 0;
	for (int i = 0; i < pPlayer[seat].size(); i++)
	{
		if (pPlayer[seat][i] == 100 || pPlayer[seat][i] == 15 || pPlayer[seat][i] == 14)
			x++;
	}

	return x;
}
void dayin(){
	ofile << "第" << ncount << "次" << endl;
	ofile << "总炸弹数" << tongjizhadan() << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		ofile << "炸弹数" << zhadanshu(i) << " ";
		ofile << "五炸数" << wuZhashu(i) << " ";
		ofile << "百搭牌个数" << baidapai(i) << " ";
		ofile << endl;
	}
}
int main()
{

	ofile.open("d:\\jhcjdsb.txt");
	for (int i = 0; i < 10000; i++)
	{
		ncount++;
		xipai();
		fenpai();
		fenwanjiapai();
		tongjidanpai();
		dayin();
	}
	system("pause");

}