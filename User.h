#pragma once
#include<iostream>
#include<vector>
using namespace std;

class User
{
public:
	User* pu;
	int num;
	struct schedule
	{
		//string username;
		int week;
		int begintime;
		int b1;
		int b2;
		int endtime;
		int e1;
		int e2;
		string wassup;
		int ifweekly;
	};
	schedule onePerson[100];

	struct Monmon//һ
	{
		string thing;
		bool delay;//�ܷ����ڻ�ȡ��������Ϊ1������Ϊ0��1������Ҫ��0�������Ҫ��
	};
	struct Monaft
	{
		string thing;
		bool delay;
	};
	struct Tuesmon//��
	{
		string thing;
		bool delay;
	};
	struct Tuesaft
	{
		string thing;
		bool delay;
	};
	struct Wedmon//��
	{
		string thing;
		bool delay;
	};
	struct Wedaft
	{
		string thing;
		bool delay;
	};
	struct Thumon//��
	{
		string thing;
		bool delay;
	};
	struct Thuaft
	{
		string thing;
		bool delay;
	};
	struct Frimon//��
	{
		string thing;
		bool delay;
	};
	struct Friaft
	{
		string thing;
		bool delay;
	};
	struct Satmon//��
	{
		string thing;
		bool delay;
	};
	struct Sataft
	{
		string thing;
		bool delay;
	};
	struct Sunmon//��
	{
		string thing;
		bool delay;
	};
	struct Sunaft
	{
		string thing;
		bool delay;
	};

public:
	void addif(string);
	//void saveif(string, int, int, int, string, int);
	void getif(string);
	int menu();
	void setMonmor();
	void setMonaft();
	void setTuemor();
	void setTueaft();
	void setWedmor();
	void setWedaft();
	void setThumor();
	void setThuaft();
	void setFrimor();
	void setFriaft();
	void setSatmor();
	void setSataft();
	void setSunmor();
	void setSunaft();

};
