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
	cout << "----------------0.�˳�-----------------" << endl;
	cout << "----------------1.��һ��---------------" << endl;
	cout << "----------------2.��һ��---------------" << endl;
	cout << "----------------3.��һ��---------------" << endl;
	cout << "----------------4.��һ��---------------" << endl;
	cout << "----------------5.��ǰ��---------------" << endl;
	cout << "---------------6.�û�ע��--------------" << endl;
	cout << "---------------7.�û���¼--------------" << endl;
	cout << "-----------8.��ʾ���г�Ա�ճ�----------" << endl;
	cout << "-------------9.����ĳ���ձ�------------" << endl;
	cout << "----------10.���ҳ�Ա����ʱ��----------" << endl;
	cout << "--------11.��ѯĳ��ʱ���������--------" << endl;
	cout << "---------------------------------------" << endl;
	cout << "What You Wanna Do" << endl;
	cin >> se;
	return se;
}

void View::Get(int year, int month, int date, int firdaysweek, int msday, int ry, int rm, int rd)
{
	int n = msday + firdaysweek;
	int d = 1;
	cout << "��ǰʱ����" << ry << "��" << rm << "��" << rd << "��" << endl;
	//cout << n << endl;
	cout << "�����ʱ����" << year << "��" << month << "��" << endl;
	cout << "   ��   һ   ��   ��   ��   ��   ��" << endl;
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

//�뺯������
void View::Con(Model* pm)
{
	Get(pm->Getyear(), pm->Getmonth(), pm->Getdate(), pm->GetFirdaysweek(), pm->Getmsday(), pm->GetRealyear(), pm->GetRealmonth(), pm->GetRealdate());
}