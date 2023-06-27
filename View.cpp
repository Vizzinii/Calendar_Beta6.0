#include<iostream>
#include<iomanip>
#include"View.h"
#include"Model.h"
using namespace std;

View::View() {};
View::~View() {};

int View::menu()
{
	int se;
	cout << "---------------------------------------" << endl;
	cout << "----------------0.退出-----------------" << endl;
	cout << "----------------1.上一年---------------" << endl;
	cout << "----------------2.下一年---------------" << endl;
	cout << "----------------3.上一月---------------" << endl;
	cout << "----------------4.下一月---------------" << endl;
	cout << "----------------5.当前月---------------" << endl;
	cout << "---------------6.用户注册--------------" << endl;
	cout << "---------------7.用户登录--------------" << endl;
	cout << "-----------8.显示所有成员日程----------" << endl;
	cout << "-------------9.查找某天日报------------" << endl;
	cout << "----------10.查找成员空闲时间----------" << endl;
	cout << "--------11.查询某个时间空闲人数--------" << endl;
	cout << "---------------------------------------" << endl;
	cout << "What You Wanna Do" << endl;
	cin >> se;
	return se;
}

void View::Get(int year, int month, int date, int firdaysweek, int msday, int ry, int rm, int rd)
{
	int n = msday + firdaysweek;
	int d = 1;
	cout << "当前时间是" << ry << "年" << rm << "月" << rd << "日" << endl;
	//cout << n << endl;
	cout << "输出的时间是" << year << "年" << month << "月" << endl;
	cout << "   日   一   二   三   四   五   六" << endl;
	for (int i = 1; i <= n; ++i)
	{
		if (i <= firdaysweek)
		{
			cout << std::right << setw(5) << setfill(' ') << " ";
		}
		else
		{
			cout << std::right << setw(5) << setfill(' ') << d++;
		}
		if (i % 7 == 0)
			cout << endl;
	}
	cout << endl;
}

//与函数连接
void View::Con(Model* pm)
{
	Get(pm->Getyear(), pm->Getmonth(), pm->Getdate(), pm->GetFirdaysweek(), pm->Getmsday(), pm->GetRealyear(), pm->GetRealmonth(), pm->GetRealdate());
}