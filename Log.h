#pragma once
#include<iostream>
#include "fstream"
using namespace std;
#include<string>
#include"Control.h"
#include"Model.h"
#include"View.h"

class View;
class Model;
class Control;
class Team;
class Log
{
private:
	string Name;
	string Password;
	User* pu;
	Team* pt;

public:
	static int count;//������
	void get();//�����д
	void set();//���룬��
	void Rege();
	void Login();
	bool Ifpassame(string, string);
	void creatfile(string);
	void Setu(User*);
	void Sett(Team*);




};