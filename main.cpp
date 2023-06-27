#include<iostream>
#include<ctime>
#include <windows.h>
//#include <conio.h>
#include<Mmsystem.h>
#include<winddi.h>
#pragma comment (lib,"Winmm.lib")
using namespace std;
#include"Control.h"
#include"Model.h"
#include"View.h"
#include"Log.h"
#include"User.h"
#include"Team.h"



class Action
{
private:
	Control c;
	Model m;
	View v;
	Log l;
	User u;
	Team t;
public:
	Action()
	{
		c.SetModel(&m);
		c.SetView(&v);
		c.SetLog(&l);
		m.SetView(&v);
		l.Setu(&u);
		c.SetTeam(&t);
		//t.setu(&u);
		/*v.Con(&m);*/
	}
	void st()
	{
		c.Run();
	}
	~Action() {};
};



int main()
{
	//mciSendString(TEXT("play C:\\Users\\10951\\Desktop\\大一\\Beta6.0\\x64\Debug\\88rising _ Rich Brian _ NIKI _ Warren Hue - California(feat_ Warren Hue).wav repeat"), NULL, 0, NULL);

	Action aka;
	PlaySound(TEXT("Oturans - DJ Okawari - Flower Dance (钢琴原版).wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	aka.st();
	PlaySound(NULL, NULL, SND_FILENAME);
	//mciSendString(TEXT("close C:\\Users\\10951\\Desktop\\大一\\Beta6.0\\x64\Debug\\88rising _ Rich Brian _ NIKI _ Warren Hue - California(feat_ Warren Hue).wav"), NULL, 0, NULL);
	return 0;
}