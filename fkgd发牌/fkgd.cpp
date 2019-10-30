#include<iostream>
#include<vector>
#include<algorithm>

#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
struct pai123{
	int pai;
	int num;
};
int BeiLv = 8658;
const int cnt = 27;
ofstream ofile;
int suijicishu = 0;
const int cishu = 10000;
vector<int> nPlayer[4];
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
void xieru(vector<int> A, vector<int> P[])
{

	int sumzha = 0;
	for (int i = 0; i < 4; i++)
	{
		sumzha += A[i];

	}
	ofile << "总炸弹数" << sumzha << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		ofile << "炸弹数" << A[i] << "   " << "五炸" << suanzhadanwu(P[i]) << "百搭牌个数" << suanbaida(P[i]) << endl;
		for (int j = 0; j < P[i].size(); j++)
		{
			ofile << P[i][j] << " ";
			//cout << P[i][j] << " ";
		}
		ofile << endl;
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
	vector<int> soult;
	int souls[1000] = { 0 };
	soult.clear();
	while (1)
	{
		int index = rand() % a.size();
		for (int i = index; i < index + 4; i++)
		{
			if (souls[i] == 0 && i < a.size())
			{
				soult.push_back(a[i]);
				souls[i] = 1;
			}
		}
		if (soult.size() >= 108)
		{
			break;
		}
	}
	/*for (int i = 0; i < soult.size(); i++)
	{
		cout << soult[i] << " ";
	}
	cout << endl;
	cout << soult.size();*/
	return soult;
}
vector<int> fapai(vector<int> a){
	for (int i = 0; i < 4; i++)
	{
		nPlayer[i].clear();
	}
	int nowfen = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (i % 5 == 0 && i != 0)
		{
			nowfen = (nowfen + 1) % 4;
		}
		while (1)
		{
			if (nPlayer[nowfen].size() >= cnt)
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
		nPlayer[nowfen].push_back(a[i]);
	}
	for (int i = 0; i < 4; i++)
	{
	/*	sort(nPlayer[i].begin(), nPlayer[i].end());
		for (int j = 0; j < nPlayer[i].size(); j++)	{
			cout << nPlayer[i][j] << " ";
		}
		cout << endl;*/
	}
	return a;
}
bool cmp(pai123 a, pai123 b)
{
	return a.num < b.num;
}
void dealSuperBoom();
void deletedan()
{
	int tongji[4][1000] = { 0 };
	vector<int> duopai;
	for (int i = 0; i < 4; i++)
	{
		sort(nPlayer[i].begin(), nPlayer[i].end());
		for (int j = 0; j < nPlayer[i].size(); j++)
		{
			tongji[i][nPlayer[i][j]]++;
		}
		for (int j = 1; j < 14; j++)
		{	
			//cout << j << " "<< tongji[i][j] << endl;
			if (tongji[i][j] < 4)
			{
				for (int ss = 0; ss < tongji[i][j];ss++)
					duopai.push_back(j);
				for (int z = 0; z < nPlayer[i].size(); z++)
				{
					if (nPlayer[i][z] == j)
					{
						nPlayer[i].erase(nPlayer[i].begin() + z);
						z--;
					}
				}
			}
		}
		//cout << duopai.size() << endl;
		//cout << nPlayer[i].size() << endl;
	}
	int errornum = 0;
	//for (int i = 0; i < 4; i++)
	//{
	//	errornum += nPlayer[i].size();
	//	for (int j = 0; j < nPlayer[i].size(); j++)
	//	{
	//		cout << nPlayer[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//errornum += duopai.size();
	//cout << endl;
	//cout << errornum;
	sort(duopai.begin(), duopai.end());
	int zhadan[16] = { 0 };
	//cout << duopai.size() << endl;
	for (int i = 0; i < duopai.size(); i++)
	{
		zhadan[duopai[i]]++;
	}
	vector<pai123> paicards;
	for (int i = 1; i < 14; i++)
	{
		pai123 sffs;
		sffs.pai = i;
		sffs.num = zhadan[i];
		paicards.push_back(sffs);
	}
	sort(paicards.begin(), paicards.end(), cmp);
	//for (int i = 0; i < paicards.size(); i++)
	//{
	//	cout << paicards[i].pai << " " << paicards[i].num<< endl;
	//}
	cout << endl;
	int nowindex = -1;
	while (1)
	{
		sort(paicards.begin(), paicards.end(), cmp);
		nowindex = (nowindex + 1) % 4;
		int flag = 0;
		for (int i = 0; i < 4; i++)
		{
			if (nPlayer[i].size() < cnt)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		if (nPlayer[nowindex].size() >= cnt)
		{
			continue;
		}
		if (cnt - nPlayer[nowindex].size() < 4)
		{
			for (int i = 0; i < paicards.size(); i++)
			{
				while (1)
				{
					if (nPlayer[nowindex].size() >= cnt)
						break;
					if (paicards[i].num <= 0)
						break;
					paicards[i].num--;
					nPlayer[nowindex].push_back(paicards[i].pai);
				}
				if (nPlayer[nowindex].size() >= cnt)
					break;;
			}
			if (nPlayer[nowindex].size() >= cnt)
				continue;
		}
		else
		{
			for (int i = paicards.size() - 1; i >= 0; i--)
			{
				while (1)
				{
					if (nPlayer[nowindex].size() >= cnt)
						break;
					if (paicards[i].num <= 0)
						break;
					paicards[i].num--;
					nPlayer[nowindex].push_back(paicards[i].pai);
				}
				if (nPlayer[nowindex].size() >= cnt)
					break;
			}
			if (nPlayer[nowindex].size() >= cnt)
				continue;
		}
	}
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < nPlayer[i].size(); j++)
		{
			cout << nPlayer[i][j] << " ";
		}
		cout << endl;
		cout << nPlayer[i].size() << endl;
	}*/
	dealSuperBoom();
	
	//vector<int> soul = reZha(nPlayer);
	//int zhadans = 0;
	//for (int i = 0; i < soul.size(); i++)
	//{
	//	zhadans += soul[i];
	//}
	//xieru(soul, nPlayer);
}
struct CardsValue{
	int Value;
	int Num;
	bool operator < (const CardsValue &b){
		return Num > b.Num;
	}
	friend ostream& operator << (ostream &input,CardsValue b)
	{
		input << b.Value;
		input << " ";
		input << b.Num;
		input << " ";
		return input;
	}
};
int pandaunzhongjian[1000];
void dfsTonghao(vector<CardsValue> CardsValues, int Value, vector<CardsValue> TMPANS, int JokersNum,int &MAX,vector<CardsValue> &AllSoultion,int &joker)
{
	int flag = true;
	for (int i = 0; i < CardsValues.size(); i++)
	{
		if (pandaunzhongjian[i] == 0)
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{ 
		if (MAX < TMPANS.size())
		{
			AllSoultion = TMPANS;
			joker = JokersNum;
		}
		return;
	}
	pandaunzhongjian[Value] = 1;
	int CardsInFo = CardsValues[Value].Value;
	int CardsNum = CardsValues[Value].Num;
	
	TMPANS.push_back(CardsValues[Value]);
	CardsValues[Value].Num = 0;
	int sts = 0;
	for (int i = 0; i < CardsValues.size(); i++)
	{
		if (i == Value) continue;
		if (CardsValues[i].Num + JokersNum >= CardsNum  && abs(CardsValues[i].Value - CardsInFo) < 2)
		{
			if (CardsValues[i].Num < CardsNum)
			{
				JokersNum -= CardsNum - CardsValues[i].Num;
			}
			int tsssss = CardsValues[i].Num;
			CardsValues[i].Num = CardsNum;
			dfsTonghao(CardsValues, i, TMPANS, JokersNum,MAX,AllSoultion,joker);
			JokersNum += CardsNum - tsssss;
			sts = 1;
		}
		else if (CardsValues[i].Num +JokersNum < CardsNum)
		{
			pandaunzhongjian[Value] = 1;
		}
	}
	if (sts == 0)
	{
		if (MAX < TMPANS.size())
		{
			AllSoultion = TMPANS;
			joker = JokersNum;
		}
		return;
	}
}
struct chaihoushuju{
	vector<int> Values;
	int num;
};
vector<chaihoushuju> Playerchai[4];
int lianzhageshu = 0;
int countffsfasf5 = 0;
int countffsfasf6 = 0;
int countffsfasf7 = 0;
int countffsfasf8 = 0;
void followLianZha(vector<CardsValue> CardsValues,int JokersNum,int seat)
{
	vector<CardsValue> wuyuntongdashacha = CardsValues;
	vector<CardsValue> PplayerChai[4];
	for (int i = 0; i < 4; i++)
	{
		PplayerChai[i].clear();
	}
	for (int i = 0; i < CardsValues.size(); i++)
	{
		vector<CardsValue> TMPANS;
		memset(pandaunzhongjian, 0, sizeof(pandaunzhongjian));
		int MAX = 0;
		vector<CardsValue> SoulTion;
		int joker = JokersNum;
		if (CardsValues[i].Num >= 4){
			dfsTonghao(CardsValues, i, TMPANS, JokersNum,MAX,SoulTion,joker);
		}
		if (SoulTion.size() > 1)
		{
			chaihoushuju ss;
			JokersNum = joker;
			int numsss = CardsValues[i].Num;
			ss.num = numsss;
			for (int j = 0; j < SoulTion.size(); j++)
			{
				for (int z = 0; z < CardsValues.size(); z++)
				{
					if (SoulTion[j].Value == CardsValues[z].Value)
					{
						CardsValues[z].Num -= numsss;
						if (CardsValues[z].Num < 0)
						{
							CardsValues[z].Num = 0;
						}
						ss.Values.push_back(SoulTion[j].Value);
					}
				}
			}
		/*	cout << joker << endl << endl;
			for (int j = 0; j < SoulTion.size(); j++)
			{
				cout << SoulTion[j];
			}*/
			Playerchai[seat].push_back(ss);
		}
	
	}
	//ofile << "第" << seat << "玩家     ";
	//ofile << "特殊炸    ";

	for (int i = 0; i < Playerchai[seat].size(); i++)
	{
		//lianzhageshu = 0;
		lianzhageshu += 1;
		/*for (int j = 0; j < Playerchai[seat][i].Values.size(); j++)
		{
			ofile << Playerchai[seat][i].Values[j] << " ";
		}*/
	/*	ofile << lianzhageshu;
		ofile << " ";
		ofile << Playerchai[seat][i].num << "             ";*/
	}

	for (int i = 0; i < wuyuntongdashacha.size(); i++)
	{
		if (wuyuntongdashacha[i].Num == 5)
			countffsfasf5++;
		if (wuyuntongdashacha[i].Num == 6)
			countffsfasf6++;
		if (wuyuntongdashacha[i].Num == 7)
			countffsfasf7++;
		if (wuyuntongdashacha[i].Num == 8)
			countffsfasf8++;
	}
	//ofile << "普通炸    " << countffsfasf5 << " " << countffsfasf6 << " " << countffsfasf7 << " " << countffsfasf8 ;
	//ofile << endl;
	//system("pause");
}
int CardsNumsss[100] = { 0 };
void dealSuperBoom()
{
	ofile << "第" << suijicishu << "次" << endl;
	for (int i = 0; i < 4; i++)
	{
		Playerchai[i].clear();
	}
	lianzhageshu = 0;
	 countffsfasf5 = 0;
	 countffsfasf6 = 0;
	 countffsfasf7 = 0;
	countffsfasf8 = 0;
	for (int z = 0; z < 4; z++)
	{
		vector<int> Cards;
		Cards = nPlayer[z];
		int JokerNum = 0;
		memset(CardsNumsss, 0, sizeof(CardsNumsss));
		vector<CardsValue> CardsValues;
		CardsValues.clear();
		sort(Cards.begin(), Cards.end());
		for (int i = 0; i < Cards.size(); i++)
		{
			CardsNumsss[Cards[i]]++;
			if (Cards[i] == 100)
			{
				JokerNum++;
			}
		}
		for (int i = 0; i < 100; i++)
		{
			if (CardsNumsss[i] != 0)
			{
				CardsValue MidValueCardInfo;
				MidValueCardInfo.Num = CardsNumsss[i];
				MidValueCardInfo.Value = i;
				CardsValues.push_back(MidValueCardInfo);
			}
		}
		//cout << endl;
		sort(CardsValues.begin(), CardsValues.end());
		for (int i = 0; i < CardsValues.size(); i++)
		{
			//cout << CardsValues[i];
		}

		followLianZha(CardsValues, JokerNum,z);
		//system("pause");
	}
	ofile << "特殊炸    " << lianzhageshu;
	ofile << "普通炸    " << countffsfasf5 << " " << countffsfasf6 << " " << countffsfasf7 << " " << countffsfasf8 ;
	ofile << endl;
}
int main()
{
	vector<int> A;
	vector<int> B;
	ofile.open("d:\\jhdsb.txt");
	for (int i = 0; i < cishu; i++)
	{
		A.clear();
		int baidapai = rand() % 13 + 1;
		for (int k = 0; k < 2; k++)
		{
			if (k == 0)
			{
				for (int j = 1; j < 16; j++)
				{
					if (baidapai == j)
					{
						for (int s = 0; s < 3; s++)
							A.push_back(j);
						A.push_back(100);
					}
					else if (j < 14)
					{
						for (int ss = 0; ss < 4; ss++)
							A.push_back(j);
					}
					else
					{
						for (int sss = 0; sss < 1; sss++)
						{
							A.push_back(j);
						}
					}
				}
			}
			if (k == 1)
			{
				for (int j = 15; j >= 1; j--)
				{
					if (baidapai == j)
					{
						for (int s = 0; s < 3; s++)
							A.push_back(j);
						A.push_back(100);
					}
					else if (j < 14)
					{	
						for (int ss = 0; ss < 4; ss++)
							A.push_back(j);
					}
					else
					{
						for (int sss = 0; sss < 1; sss++)
						{
							A.push_back(j);
						}
					}
				}
			}
		}
		for (int i = 0; i < A.size(); i++)
		{
			if ((A[i] == 14 || A[i] == 15) && (i == 53 || i == 54 || i == 55 || i == 56))
			{
				int s = rand() % A.size();
				swap(A[i], A[s]);
				continue;
			}
		}
		//for (int i = 0; i < A.size(); i++)
		//{
		//	cout << A[i];
		//}
		//cout << endl;
		//cout << A.size() << endl
		suijicishu++;
		B = A;
		B = dealpai(B);
		B = fapai(B);
		deletedan();
	}

		system("pause");
}
