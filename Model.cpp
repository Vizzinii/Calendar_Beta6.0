#include<ctime>
#include<cstdio>
#include"Model.h"
#include"View.h"

//获取当前时间
Model::Model()
{
	Getnow();
};
Model::~Model() {};


void Model::Getnow()//当前时间
{
	struct tm now;
	time_t timecur;
	time(&timecur);
	localtime_s(&now, &timecur);

	year = 1900 + now.tm_year;
	month = 1 + now.tm_mon;
	date = now.tm_mday;

	realyear = year;
	realmonth = month;
	realdate = date;
}

//为变量赋值
int Model::Getyear()const
{
	return year;
}
int Model::Getmonth()const
{
	return month;
}
int Model::Getdate()const
{
	return date;
}

//获得每一天是周几
int Model::Getweek(int a)const   //a是几号
{
	int c = year / 100;
	int y = year % 100;
	int m = month;
	if (m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	return ((y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + a - 1) % 7) > 0 ? (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + a - 1) % 7 : (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + a - 1) % 7 + 7;
}

//是否闰年
bool Model::ifrun()const
{
	return ((year % 4 == 0) && ((year % 100) != 0) || year % 400 == 0);
}

//判断月份的天数
int Model::Setdays()const
{
	static int days[]{ 29,31,28,31,30,31,30,31,31,30,31,30,31 };
	int  m = month;
	if (ifrun() && m == 2)
	{
		m = 0;
	}
	return days[m];
}

//重置
void Model::Setweek()
{
	curdaysweek = Getweek(date);
	firdaysweek = Getweek(1);
	msday = Setdays();
}

//该月天数
int Model::Getmsday()const
{
	return msday;
	//return Setdays();
}
//某天周几
int Model::Getcurweek()const
{
	return curdaysweek;
}
//第一天周几
int Model::GetFirdaysweek()const
{
	return firdaysweek;
}

//控制年份与月份
void Model::NextYear()
{
	year += 1;
	Setweek();
	pv->Con(this);
}
void Model::NextMonth()
{
	if (++month > 12)
	{
		month = 1;
		year += 1;
	}
	Setweek();
	pv->Con(this);
}
void Model::PreYear()
{
	if (year > 1)
	{
		year -= 1;
	}
	Setweek();
	pv->Con(this);
}
void Model::PreMonth()
{
	if (--month < 1)
	{
		if (year > 1)
		{
			year -= 1;
			month = 12;
		}
	}
	Setweek();
	pv->Con(this);
}
void Model::Now()
{
	month = realmonth;
	year = realyear;
	Setweek();
	pv->Con(this);
}

//当前时间
int Model::GetRealyear()const
{
	return realyear;
}
int Model::GetRealmonth()const
{
	return realmonth;
}
int Model::GetRealdate()const
{
	return realdate;
}

//与显示连接
void Model::SetView(View* pv)
{
	pv = pv;
}