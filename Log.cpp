#pragma once
#include<iostream>
#include "fstream"
using namespace std;
#include<string>
#include"Log.h"
#include"Control.h"
#include"Model.h"
#include"View.h"
#include"User.h"
#include"Team.h"

Log logs[100];
int Log::count = 1;
class User;
void Log::Setu(User* ppu)
{
	pu = ppu;
}
//void Log::Sett(Team* ppt)
//{
//	pt = ppt;
//}

void Log::get()
{
	ofstream ofile;
	ofile.open("user.txt", ios::out);

	for (int i = 0; i < count; i++)
	{
		ofile << logs[i].Name << endl;
		ofile << logs[i].Password << endl;
	}
	ofile.close();
};

void Log::set()
{
	fstream ifile;
	string temp;
	ifile.open("user.txt", ios::in);//只读
	//for (int i = 0; !ifile.eof(); i++)
	//{
	//	cout << "aaaaaaa\n";
	//	ifile >> user[i].Name;
	//	ifile >> user[i].Password;
	//	count++;
	//}
	//count--;
	//ifile.close();
	if (!ifile.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	else
	{
		cout << "文件打开成功。" << endl;
		int i = 0;
		while (getline(ifile, temp, '\n'))
		{
			i += 1;
			if (i % 2 == 1)
			{
				logs[count].Name = temp;
			}
			else if (i % 2 == 0)
			{
				logs[count].Password = temp;
				cout << logs[count].Name << " " << logs[count].Password << endl;
				count += 1;
			}
			//cout << "aaa" << " " << count << endl;

		}
	}
	ifile.close();
};

void Log::Rege()
{
	string name3;
	string pas1;
	string pas2;
	this->set();

	cout << "请输入用户名" << endl;
	cin >> name3;

	for (int i = 0;i < count;i++)
	{
		if (logs[i].Name == name3)
		{
			cout << "用户已存在" << endl;
			this->Rege();
		}
		else
		{
			continue;
		}
	}
	cout << "请输入密码" << endl;
	cin >> pas1;
	cout << "请确认密码" << endl;
	cin >> pas2;
	bool whether = Ifpassame(pas1, pas2);
	if (!whether)
	{
		cout << "密码不同，注册失败" << endl;
		this->Rege();
	}
	else
	{


		Name = name3;
		Password = pas1;

		fstream ofile;
		ofile.open("user.txt", ios::app);
		ofile << Name << endl;
		ofile << Password << endl;
		ofile.close();
		creatfile(Name);
		count += 1;
		cout << "注册成功。" << endl;
	}
}

bool Log::Ifpassame(string pas1, string pas2)
{
	return(pas1 == pas2);
}

void Log::creatfile(string filename)
{
	string ff = filename;
	string tt = ".txt";
	ff += tt;
	ofstream ofile(ff);
	ofile.close();
}

void Log::Login()
{
	string name4;
	string pas;
	string pas2;
	this->set();
	cout << "请输入用户名" << endl;
	cin >> name4;
	int flag = 0;
	for (int i = 1;i < count;i++)
	{
		if (logs[i].Name == name4)
		{
			flag = 1;
			cout << "请输入密码" << endl;
			cin >> pas;
			int j = i;
			if (logs[j].Password == pas)
			{
				cout << "登录成功！" << endl;
				break;
			}
			else
			{
				cout << "密码错误，无法登录" << endl;
			}
		}
		else
		{
			flag = 0;
		}
	};
	if (!flag)
	{
		cout << "该用户不存在,请注册后登录" << endl;
	}
	if (flag)
	{
		int choi = 0;
		do
		{
			choi = pu->menu();
			switch (choi)
			{
			case 1:
				pu->addif(name4);
				break;
			case 2:
				pu->getif(name4);
				break;
				//case 3:
				//	pt->letoutinf();
			default:
				cout << "输入错误,请重新输入" << endl;
				break;
			}
		} while (choi != 0);

	}
}