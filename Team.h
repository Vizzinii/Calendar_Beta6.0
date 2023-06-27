#pragma once
#include<iostream>
#include<vector>
#include"Control.h"
#include"Model.h"
#include"View.h"
#include"Log.h"
#include"User.h"
using namespace std;
class User;

class Team
{
private:
	User::schedule member[100][100];
	int total = 0;
	string username[100];
	/*User* pu;*/
	struct findtime
	{
		int week;
		int begin;
		int end;
	};



public:
	void getmember();
	void letoutinf();
	void daily();
	void dispatch();
	void finddaybig();
	void finddaysmall();
	void searchtime();
	/*void setu(User*);*/

};