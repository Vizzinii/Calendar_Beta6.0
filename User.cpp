#include<iostream>
#include<iomanip>
#include"View.h"
#include"Model.h"
#include"User.h"
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;

class User;
int User::menu()
{
	int se;
	cout << "---------------------------------------" << endl;
	cout << "----------------0.退出-----------------" << endl;
	cout << "----------------1.添加日程---------------" << endl;
	cout << "--------------2.查看已有日程-------------" << endl;
	//cout << "------------3.查看所有成员日程-----------" << endl;
	cout << "What You Wanna Do" << endl;
	cin >> se;
	return se;
}



void User::addif(string name1)
{
	//1;1700;1900;EAP4 English;1
	//周一；17-19点；上英语课；需要每周
	string txtname = name1;
	string hz = ".txt";
	txtname += hz;

	cout << "你想添加几个日程？" << endl;
	int times = 0;
	num = times;
	cin >> times;

	schedule newif;

	cin.ignore();
	fstream fl;
	fl.open(txtname, ios::out);
	for (int j = 0;j < times;j++)
	{
		cout << "按照以下格式输入：" << endl;
		cout << "(周一；17-19点；上英语课；需要每周)表示为（1;1700;1900;EAP4 English;1）" << endl;
		cout << "即（星期；起始时间；结束时间；事件；是否每周都有），1表示weekly，0相反" << endl;
		cin.clear();
		string temp;
		getline(cin, temp);
		string str1;
		string str2;
		string str3;
		string str4;
		string str5;

		int count[5] = { 0 };//4个分号
		int flag = 0;
		for (int ooo = 0; ooo < temp.size(); ooo++)
		{

			if (temp[ooo] == ';')
			{
				flag++;
				continue;
			}
			count[flag]++;
		}
		count[4] = (int)temp.size() - count[0] - count[1] - count[2] - count[3];

		str1 = temp.substr(0, count[0]);//周几
		str2 = temp.substr((size_t)(count[0] + 1), (size_t)count[1]);//开始时间
		str3 = temp.substr((size_t)(count[0] + count[1] + 2), (size_t)count[2]);//结束时间
		str4 = temp.substr((size_t)(count[0] + count[1] + count[2] + 3), (size_t)count[3]);//日程
		str5 = temp.substr((size_t)(count[0] + count[1] + count[2] + count[3] + 4), (size_t)count[4]);//是否重复

		int teb = 0;
		int tee = 0;

		//newif.username = name1;

		istringstream w(str1);
		w >> newif.week;

		istringstream b(str2);
		b >> teb;
		//b >> newif.begintime;

		istringstream e(str3);
		e >> tee;
		//e >> newif.endtime;

		if (teb >= tee)
		{
			int temp = 0;
			temp = teb;
			teb = tee;
			tee = temp;
		}

		newif.begintime = teb;
		newif.endtime = tee;

		newif.wassup = str4;

		istringstream i(str5);
		i >> newif.ifweekly;





		fl << newif.week << ";" << newif.begintime << ";" << newif.endtime << ";" << newif.wassup << ";" << newif.ifweekly << endl;
		onePerson[j] = newif;

		//saveif(txtname, week, begintime, endtime, wassup, ifweekly);
	}
	fl.close();
}

//void saveif(string txtname, int a, int b, int c, string d, int e)
//{
//	string firstname = txtname;
//	string lastname = ".txt";
//	firstname += lastname;
//	fstream ofile;
//	ofile.open(firstname, ios::app);
//	ofile << a << ";" << b << ";" << c << ";" << d << ";" << e << endl;
//	ofile.close();
//}
















void User::getif(string name2)
{
	string textname = name2;
	string hz = ".txt";
	textname += hz;
	vector<string>tt;
	//char name[256];
	string temp;
	fstream ifile;
	ifile.open(textname, ios::in);
	if (ifile.eof())
	{
		cout << "日程为空，请先添加" << endl;
		ifile.close();
		return;
	}
	while (getline(ifile, temp))
	{
		//cout << temp << endl;
		tt.push_back(temp);
		string str1;
		string str2;
		string str3;
		string str4;
		string str5;

		int count[5] = { 0 };//4个分号
		int flag = 0;
		for (int ooo = 0; ooo < temp.size(); ooo++)
		{

			if (temp[ooo] == ';')
			{
				flag++;
				continue;
			}
			count[flag]++;
		}
		count[4] = (int)temp.size() - count[0] - count[1] - count[2] - count[3];

		str1 = temp.substr(0, count[0]);//周几
		str2 = temp.substr((size_t)(count[0] + 1), (size_t)count[1]);//开始时间
		str3 = temp.substr((size_t)(count[0] + count[1] + 2), (size_t)count[2]);//结束时间
		str4 = temp.substr((size_t)(count[0] + count[1] + count[2] + 3), (size_t)count[3]);//日程
		str5 = temp.substr((size_t)(count[0] + count[1] + count[2] + count[3] + 4), (size_t)count[4]);//是否重复
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

		if (bb >= ee)
		{
			int just = bb;
			bb = ee;
			ee = just;
		}


		string www;
		switch (ww)
		{
		case 1:
			www = "周一";
			break;
		case 2:
			www = "周二";
			break;
		case 3:
			www = "周三";
			break;
		case 4:
			www = "周四";
			break;
		case 5:
			www = "周五";
			break;
		case 6:
			www = "周六";
			break;
		case 7:
			www = "周日";
			break;
		default:
			break;
		}

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

		string iii;
		switch (ii)
		{
		case 0:
			iii = "不是每周都有";
			break;
		case 1:
			iii = "每周都有";
			break;
		default:
			break;
		}

		cout << "用户" << name2 << " " << www << "  " << setw(2) << setfill('0') << bb1 << ":" << setw(2) << setfill('0') << bb2 << "-" << setw(2) << setfill('0') << ee1 << ":" << setw(2) << setfill('0') << ee2 << "  " << str4 << "  " << iii << endl;
		cin.ignore();


	}
	ifile.close();
	//for (int i = 0;i < num;i++)
	//{
	//	

	//	//schedule temp = information.back();
	//	//cout << temp.begintime << ";" << temp.endtime << endl;
	//}

}