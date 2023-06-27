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
	int msday;//���µ�����

	//��ǰʱ��
	int realyear;
	int realmonth;
	int realdate;

	//��ͼ�����ʽ
	int curdaysweek;//ĳ��������һ��
	int firdaysweek;//���µ�һ�����ܼ�

	View* pv;

public:
	Model();
	~Model();
	int Getyear()const;
	int Getmonth()const;
	int Getdate()const;

	//��ȡ��ǰʱ��
	void Getnow();

	//��ȡĳһ���µ�����
	int Setdays()const;

	//���ĳһ�����ܼ�
	int Getweek(int)const;
	void Setweek();


	//��ͼ�����ʽ
	int Getmsday()const;
	int Getcurweek()const;
	int GetFirdaysweek()const;

	//������Ե��ж�
	bool ifrun()const;//�Ƿ�����

	//����������·�
	void NextYear();
	void PreYear();
	void NextMonth();
	void PreMonth();
	void Now();

	//��ȡ��ǰʱ��
	int GetRealyear()const;
	int GetRealmonth()const;
	int GetRealdate()const;

	//������ʾ
	void SetView(View*);
};
#endif

