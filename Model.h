#pragma once
#ifndef MODEL_H
#define MODEL_H

class View;
class Model
{
private:
	int year;
	int month;
	int date;
	int msday;//该月的天数

	//当前时间
	int realyear;
	int realmonth;
	int realdate;

	//视图输出格式
	int curdaysweek;//某天属于哪一周
	int firdaysweek;//该月第一天是周几

	View* pv;

public:
	Model();
	~Model();
	int Getyear()const;
	int Getmonth()const;
	int Getdate()const;

	//获取当前时间
	void Getnow();

	//获取某一个月的天数
	int Setdays()const;

	//获得某一天是周几
	int Getweek(int)const;
	void Setweek();


	//视图输出格式
	int Getmsday()const;
	int Getcurweek()const;
	int GetFirdaysweek()const;

	//年份属性的判断
	bool ifrun()const;//是否闰年

	//控制年份与月份
	void NextYear();
	void PreYear();
	void NextMonth();
	void PreMonth();
	void Now();

	//获取当前时间
	int GetRealyear()const;
	int GetRealmonth()const;
	int GetRealdate()const;

	//连接显示
	void SetView(View*);
};
#endif

