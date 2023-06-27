#include<iostream>
#include"Control.h"
#include "View.h"
#include "Model.h"
#include"Log.h"
#include"Team.h"
using namespace std;

Control::Control() :ppv(NULL), ppm(NULL), ppl(NULL) {};
Control::~Control() {};
void Control::SetView(View* pv)
{
	ppv = pv;
}
void Control::SetModel(Model* pm)
{
	ppm = pm;
}
void Control::SetLog(Log* pl)
{
	ppl = pl;
}
void Control::SetTeam(Team* pt)
{
	ppt = pt;
}



void Control::Now()
{
	ppm->Now();
}
void Control::PreMonth()
{
	ppm->PreMonth();
}
void Control::PreYear()
{
	ppm->PreYear();
}
void Control::NextMonth()
{
	ppm->NextMonth();
}
void Control::NextYear()
{
	ppm->NextYear();
}



void Control::Run()
{
	ppt->getmember();
	int cho = 0;
	do
	{
		cho = ppv->menu();
		switch (cho)
		{
		case 1:
			PreYear();
			break;
		case 2:
			NextYear();
			break;
		case 3:
			PreMonth();
			break;
		case 4:
			NextMonth();
			break;
		case 5:
			Now();
			break;
		case 6:
			Register();
			break;
		case 7:
			Login();
			break;
		case 8:
			GetTeam();
			break;
		case 9:
			Getdaily();
			break;
		case 10:
			Dispatch();
			break;
		case 11:
			Searchtime();
			break;
		default:
			cout << "ERROR!" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (cho != 0);
}
//cout << "----------------1.上一年---------------" << endl;
//cout << "----------------2.下一年---------------" << endl;
//cout << "----------------3.上一月---------------" << endl;
//cout << "----------------4.下一月---------------" << endl;

void Control::Register()
{
	ppl->Rege();
}
void Control::Login()
{
	ppl->Login();
}
void Control::GetTeam()
{
	ppt->getmember();
	ppt->letoutinf();
}
void Control::Getdaily()
{
	ppt->daily();
}

void Control::Dispatch()
{
	ppt->dispatch();
}
void Control::Searchtime()
{
	ppt->searchtime();
}