#include<ctime>
#include<cstdio>
#include"Model.h"
#include"View.h"

//��ȡ��ǰʱ��
Model::Model()
{
	Getnow();
};
Model::~Model() {};


void Model::Getnow()//��ǰʱ��
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

//Ϊ������ֵ
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

//���ÿһ�����ܼ�
int Model::Getweek(int a)const   //a�Ǽ���
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

//�Ƿ�����
bool Model::ifrun()const
{
	return ((year % 4 == 0) && ((year % 100) != 0) || year % 400 == 0);
}

//�ж��·ݵ�����
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

//����
void Model::Setweek()
{
	curdaysweek = Getweek(date);
	firdaysweek = Getweek(1);
	msday = Setdays();
}

//��������
int Model::Getmsday()const
{
	return msday;
	//return Setdays();
}
//ĳ���ܼ�
int Model::Getcurweek()const
{
	return curdaysweek;
}
//��һ���ܼ�
int Model::GetFirdaysweek()const
{
	return firdaysweek;
}

//����������·�
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

//��ǰʱ��
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

//����ʾ����
void Model::SetView(View* pv)
{
	pv = pv;
}