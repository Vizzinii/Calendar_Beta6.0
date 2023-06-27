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

	//��ָ�����
	void SetView(View* pv);
	void SetModel(Model* pm);
	void SetLog(Log* pl);
	void SetTeam(Team* pt);

	//���е�������
	void Run();


	void Now();//��ǰ��
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

