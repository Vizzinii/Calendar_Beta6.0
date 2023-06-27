#pragma once
#ifndef CONTROLL_H
#define CONTROLL_H

class View;
class Model;
class Log;
class Team;
class Control
{
private:
	View* ppv;
	Model* ppm;
	Log* ppl;
	Team* ppt;
public:
	Control();
	~Control();

	//传指针进来
	void SetView(View* pv);
	void SetModel(Model* pm);
	void SetLog(Log* pl);
	void SetTeam(Team* pt);

	//运行的主函数
	void Run();


	void Now();//当前月
	void NextYear();
	void PreYear();
	void NextMonth();
	void PreMonth();

	void Register();
	void Login();
	void GetTeam();
	void Getdaily();
	void Dispatch();
	void Searchtime();
};
#endif

