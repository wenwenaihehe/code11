
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void GetLog()
{
	string file = "D:/log.log";// ����log�ļ���Ŀ¼

	ifstream logFile(file);        // ����һ���ļ�����ȡ����
	string str;
	string s2 = "commonmult";
	string s3 = "boommult";
	string s4 = "bfmult";
	string s5 = "specialmult";
	ofstream ofile;
	ofstream ofile1, ofile2, ofile3;
	ofile.open("d:\\commonmult.txt");
	ofile1.open("d:\\boommult.txt");
	ofile2.open("d:\\bfmult.txt");
	ofile3.open("d:\\specialmult.txt");

	while (getline(logFile, str))  // ���ж�������
	{
		int index = str.find(s2);// ���ݴ�����
		int index1 = str.find(s3);
		int index2 = str.find(s4);
		int index3 = str.find(s5);
		if (index != str.length())
		{
			for (int j = index; j <= str.length(); j++)
			{
				if (j == str.length())
				{
					//cout << endl;
					ofile << endl;
				}
				cout << str[j];
				ofile << str[j];
			}
		}
		if (index1 != str.length())
		{
			for (int j = index1; j <= str.length(); j++)
			{
				if (j == str.length())
				{
					//cout << endl;
					ofile1 << endl;
				}
				cout << str[j];
				ofile1 << str[j];
			}
		}
		if (index2 != str.length())
		{
			for (int j = index2; j <= str.length(); j++)
			{
				if (j == str.length())
				{
					//cout << endl;
					ofile2 << endl;
				}
				cout << str[j];
				ofile2 << str[j];
			}
		}
		if (index3 != str.length())
		{
			for (int j = index3; j <= str.length(); j++)
			{
				if (j == str.length())
				{
					//cout << endl;
					ofile3 << endl;
				}
				cout << str[j];
				ofile3 << str[j];
			}
		}
		
		str.clear();               // �ظ����أ�����ÿ����Ҫ���
	}
	ofile.close();
	ofile1.close();
	ofile2.close();
	ofile3.close();


	logFile.close();               // �ر��ļ�
}
int main()
{
	GetLog();
}