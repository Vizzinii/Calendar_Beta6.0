#include<iostream>
#include<iomanip>
#include<vector>
#include<sstream>
#include "fstream"
#include"Control.h"
#include"Model.h"
#include"View.h"
#include"Log.h"
#include"User.h"
#include"Team.h"
using namespace std;

void Team::getmember()
{

	fstream ifile;
	ifile.open("user.txt", ios::in);

	string Temp;
	//string username[100];
	string Name[100];
	int i = 0;
	while (getline(ifile, Temp, '\n'))
	{
		i += 1;
		if (i % 2 == 1)
		{
			Name[(i + 1) / 2] = Temp;
			username[(i + 1) / 2] = Temp;
			total += 1;
		}
	}

	string hz = ".txt";
	for (int j = 0;j < total;j++)
	{
		Name[j] += hz;
	}

	for (int k = 1;k <= total;k++)
	{
		int kk = 0;
		fstream fl;
		fl.open(Name[k], ios::in);
		while (getline(fl, Temp))
		{
			kk += 1;
			string str1;
			string str2;
			string str3;
			string str4;
			string str5;
			int count[5] = { 0 };//4个分号
			int flag = 0;
			for (int ooo = 0; ooo < Temp.size(); ooo++)
			{

				if (Temp[ooo] == ';')
				{
					flag++;
					continue;
				}
				count[flag]++;
			}
			count[4] = (int)Temp.size() - count[0] - count[1] - count[2] - count[3];

			str1 = Temp.substr(0, count[0]);//周几
			str2 = Temp.substr((size_t)(count[0] + 1), (size_t)count[1]);//开始时间
			str3 = Temp.substr((size_t)(count[0] + count[1] + 2), (size_t)count[2]);//结束时间
			str4 = Temp.substr((size_t)(count[0] + count[1] + count[2] + 3), (size_t)count[3]);//日程
			str5 = Temp.substr((size_t)(count[0] + count[1] + count[2] + count[3] + 4), (size_t)count[4]);//是否重复


			istringstream w(str1);
			int ww;
			w >> ww;

			istringstream b(str2);
			int bb;
			b >> bb;

			istringstream e(str3);
			int ee;
			e >> ee;

			istringstream i(str5);
			int ii;
			i >> ii;

			int bb1 = 0;
			int bb2 = 0;
			bb1 = bb / 100;
			bb2 = bb % 100;
			if (bb2 >= 60)
			{
				bb2 -= 60;
				bb1 += 1;
			}
			int ee1 = 0;
			int ee2 = 0;
			ee1 = ee / 100;
			ee2 = ee % 100;
			if (ee2 >= 60)
			{
				ee2 -= 60;
				ee1 += 1;
			}


			User::schedule newif;
			//newif.username = username[k];
			newif.week = ww;
			newif.begintime = bb;
			newif.b1 = bb1;
			newif.b2 = bb2;
			newif.endtime = ee;
			newif.e1 = ee1;
			newif.e2 = ee2;
			newif.wassup = str4;
			newif.ifweekly = ii;

			member[k][kk] = newif;



		}
		fl.close();
	}
	ifile.close();
}


//void Team::setu(User* ppu)
//{
//	this->pu = ppu;
//}

void Team::letoutinf()
{
	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			int a = member[i][j].week;
			string aa;
			switch (a)
			{
			case 1:
				aa = "周一";
				break;
			case 2:
				aa = "周二";
				break;
			case 3:
				aa = "周三";
				break;
			case 4:
				aa = "周四";
				break;
			case 5:
				aa = "周五";
				break;
			case 6:
				aa = "周六";
				break;
			case 7:
				aa = "周日";
				break;
			default:
				break;
			}

			string bb = member[i][j].wassup;

			int c = member[i][j].ifweekly;
			string cc;
			switch (c)
			{
			case 0:
				cc = "不是每周都有";
				break;
			case 1:
				cc = "每周都有";
				break;
			default:
				break;
			}
			if (member[i][j].b1 > member[i][j].e1)
			{
				int temp1 = 0;
				int temp2 = 0;

				temp1 = member[i][j].b1;
				member[i][j].b1 = member[i][j].e1;
				member[i][j].e1 = temp1;

				temp2 = member[i][j].b2;
				member[i][j].b2 = member[i][j].e2;
				member[i][j].e2 = temp2;

			}
			if (member[i][j].b1 == member[i][j].e1 || member[i][j].b2 >= member[i][j].e2)
			{
				int temp3 = 0;
				temp3 = member[i][j].b2;
				member[i][j].b2 = member[i][j].e2;
				member[i][j].e2 = temp3;
			}
			cout << "用户" << username[i] << " ";
			cout << aa << " ";
			cout << setw(2) << setfill('0') << member[i][j].b1;
			cout << ":";
			cout << setw(2) << setfill('0') << member[i][j].b2;
			cout << "-";
			cout << setw(2) << setfill('0') << member[i][j].e1;
			cout << ":";
			cout << setw(2) << setfill('0') << member[i][j].e2;
			cout << " ";
			cout << member[i][j].wassup;
			cout << " ";
			cout << cc;
			cout << endl;
		}
	}
}


void Team::daily()
{
	int which;
	cout << "您想要查找星期几的日报？" << endl;
	cin >> which;

	int flag = 0;
	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			if (which == member[i][j].week)
			{
				flag++;
			}
		}
	}
	if (flag == 0)
	{
		cout << "当天没有成员有日程安排" << endl;
	}


	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			int a = member[i][j].week;
			if (a == which)
			{
				string aa;
				switch (a)
				{
				case 1:
					aa = "周一";
					break;
				case 2:
					aa = "周二";
					break;
				case 3:
					aa = "周三";
					break;
				case 4:
					aa = "周四";
					break;
				case 5:
					aa = "周五";
					break;
				case 6:
					aa = "周六";
					break;
				case 7:
					aa = "周日";
					break;
				default:
					break;
				}

				string bb = member[i][j].wassup;

				int c = member[i][j].ifweekly;
				string cc;
				switch (c)
				{
				case 0:
					cc = "不是每周都有";
					break;
				case 1:
					cc = "每周都有";
					break;
				default:
					break;
				}
				if (member[i][j].b1 > member[i][j].e1)
				{
					int temp1 = 0;
					int temp2 = 0;

					temp1 = member[i][j].b1;
					member[i][j].b1 = member[i][j].e1;
					member[i][j].e1 = temp1;

					temp2 = member[i][j].b2;
					member[i][j].b2 = member[i][j].e2;
					member[i][j].e2 = temp2;

				}
				if (member[i][j].b1 == member[i][j].e1 || member[i][j].b2 >= member[i][j].e2)
				{
					int temp3 = 0;
					temp3 = member[i][j].b2;
					member[i][j].b2 = member[i][j].e2;
					member[i][j].e2 = temp3;
				}
				cout << "用户" << username[i] << " ";
				cout << aa << " ";
				cout << setw(2) << setfill('0') << member[i][j].b1;
				cout << ":";
				cout << setw(2) << setfill('0') << member[i][j].b2;
				cout << "-";
				cout << setw(2) << setfill('0') << member[i][j].e1;
				cout << ":";
				cout << setw(2) << setfill('0') << member[i][j].e2;
				cout << " ";
				cout << member[i][j].wassup;
				cout << " ";
				cout << cc;
				cout << endl;
			}
			else if (a != which)
			{
				continue;
			}
		}
	}

}


void Team::dispatch()
{
	int choice;
	cout << "请输入选择的功能" << endl;
	cout << "----------------0.退出-----------------" << endl;
	cout << "----------1.最少成员空闲的某天---------" << endl;
	cout << "----------2.最多成员空闲的某天---------" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0:
		break;
	case 1:
		finddaybig();
		break;
	case 2:
		finddaysmall();
	default:
		break;
	}
}


void Team::finddaybig()
{
	//每一个日程的日期赋给dayarr[]
	int dayarr[20][10] = { 0 };
	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			int a = member[i][j].week;
			dayarr[i][j] = member[i][j].week;
		}
	}


	//赋值，得到代表周几的aa[i]有n个日程
	int aa[8] = { 0 };
	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			if (dayarr[i][j] == 1)
			{
				aa[1] += 1;
			}
			else if (dayarr[i][j] == 2)
			{
				aa[2] += 1;
			}
			else if (dayarr[i][j] == 3)
			{
				aa[3] += 1;
			}
			else if (dayarr[i][j] == 4)
			{
				aa[4] += 1;
			}
			else if (dayarr[i][j] == 5)
			{
				aa[5] += 1;
			}
			else if (dayarr[i][j] == 6)
			{
				aa[6] += 1;
			}
			else if (dayarr[i][j] == 7)
			{
				aa[7] += 1;
			}
		}
	}

	//周几有多少日程赋给ai
	int a1 = aa[1];
	int a2 = aa[2];
	int a3 = aa[3];
	int a4 = aa[4];
	int a5 = aa[5];
	int a6 = aa[6];
	int a7 = aa[7];


	//冒泡，得到日程最多的星期几
	int biggest = aa[1];
	int ccc = 0;
	for (int i = 1;i <= 7;i++)
	{
		for (int j = 1;j <= 7 - i;j++)
		{
			if (aa[j] >= aa[j + 1])
			{
				ccc = aa[j];
				aa[j] = aa[j + 1];
				aa[j + 1] = ccc;
			}
		}
	}
	int getflagbig[8] = { 0 };
	if (a1 == aa[7])
	{
		getflagbig[1] = 1;
	}
	if (a2 == aa[7])
	{
		getflagbig[2] = 2;
	}
	if (a3 == aa[7])
	{
		getflagbig[3] = 3;
	}
	if (a4 == aa[7])
	{
		getflagbig[4] = 4;
	}
	if (a5 == aa[7])
	{
		getflagbig[5] = 5;
	}
	if (a6 == aa[7])
	{
		getflagbig[6] = 6;
	}
	if (a7 == aa[7])
	{
		getflagbig[7] = 7;
	}
	for (int i = 1;i <= 7;i++)
	{
		switch (getflagbig[i])
		{
		case 1:
			cout << "周一" << " ";
			break;
		case 2:
			cout << "周二" << " ";
			break;
		case 3:
			cout << "周三" << " ";
			break;
		case 4:
			cout << "周四" << " ";
			break;
		case 5:
			cout << "周五" << " ";
			break;
		case 6:
			cout << "周六" << " ";
			break;
		case 7:
			cout << "周日" << " ";
			break;
		default:
			break;
		}
	}
	cout << endl;
}



void Team::finddaysmall()
{
	//每一个日程的日期赋给dayarr[]
	int dayarr[20][10] = { 0 };
	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			int a = member[i][j].week;
			dayarr[i][j] = member[i][j].week;
		}
	}


	//赋值，得到代表周几的aa[i]有n个日程
	int aa[8] = { 0 };
	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			if (dayarr[i][j] == 1)
			{
				aa[1] += 1;
			}
			else if (dayarr[i][j] == 2)
			{
				aa[2] += 1;
			}
			else if (dayarr[i][j] == 3)
			{
				aa[3] += 1;
			}
			else if (dayarr[i][j] == 4)
			{
				aa[4] += 1;
			}
			else if (dayarr[i][j] == 5)
			{
				aa[5] += 1;
			}
			else if (dayarr[i][j] == 6)
			{
				aa[6] += 1;
			}
			else if (dayarr[i][j] == 7)
			{
				aa[7] += 1;
			}
		}
	}

	//周几有多少日程赋给ai
	int a1 = aa[1];
	int a2 = aa[2];
	int a3 = aa[3];
	int a4 = aa[4];
	int a5 = aa[5];
	int a6 = aa[6];
	int a7 = aa[7];


	//冒泡，得到日程最多的星期几
	int biggest = aa[1];
	int ccc = 0;
	for (int i = 1;i <= 7;i++)
	{
		for (int j = 1;j <= 7 - i;j++)
		{
			if (aa[j] >= aa[j + 1])
			{
				ccc = aa[j];
				aa[j] = aa[j + 1];
				aa[j + 1] = ccc;
			}
		}
	}
	int getflagsmall[8] = { 0 };
	if (a1 == aa[1])
	{
		getflagsmall[1] = 1;
	}
	if (a2 == aa[1])
	{
		getflagsmall[2] = 2;
	}
	if (a3 == aa[1])
	{
		getflagsmall[3] = 3;
	}
	if (a4 == aa[1])
	{
		getflagsmall[4] = 4;
	}
	if (a5 == aa[1])
	{
		getflagsmall[5] = 5;
	}
	if (a6 == aa[1])
	{
		getflagsmall[6] = 6;
	}
	if (a7 == aa[1])
	{
		getflagsmall[7] = 7;
	}
	for (int i = 1;i <= 7;i++)
	{
		switch (getflagsmall[i])
		{
		case 1:
			cout << "周一" << " ";
			break;
		case 2:
			cout << "周二" << " ";
			break;
		case 3:
			cout << "周三" << " ";
			break;
		case 4:
			cout << "周四" << " ";
			break;
		case 5:
			cout << "周五" << " ";
			break;
		case 6:
			cout << "周六" << " ";
			break;
		case 7:
			cout << "周日" << " ";
			break;
		default:
			break;
		}
	}
	cout << endl;
}


void Team::searchtime()
{
	findtime searchtime[20];
	int week = 0;
	cout << "请输入你要查询的星期几" << endl;
	cin >> week;
	int flag = 0;
	for (int i = 1;i <= total;i++)
	{
		for (int j = 1;member[i][j].week;j++)
		{
			if (week == member[i][j].week)
			{
				searchtime[flag].week = week;
				searchtime[flag].begin = member[i][j].begintime;
				searchtime[flag].end = member[i][j].endtime;
				flag += 1;
				continue;
			}
		}
	}


	int bt = 0;
	int et = 0;
	cout << "输入开始时间" << endl;
	cin >> bt;
	cout << "请输入结束时间" << endl;
	cin >> et;

	int have = 0;
	for (int i = 0;i < flag;i++)
	{
		int a = 0;
		int b = 0;
		if (bt >= searchtime[i].begin && bt <= searchtime[i].end)
		{
			a += 1;
		}
		if (et >= searchtime[i].begin && bt <= searchtime[i].end)
		{
			b += 1;
		}
		if (a > 0 || b > 0)
		{
			have += 1;
		}
	}

	cout << "团队一共有" << total << "人。" << endl;
	cout << "在星期" << week << "有日程安排的一共有" << flag << "人，没有日程安排的一共有" << total - flag << "人" << endl;
	cout << "其中在该时间段内处于空闲的成员一共有" << total - have << "人" << endl;
}