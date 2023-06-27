#pragma once
#ifndef VIEW_H
#define VIEW_H
class Model;
class User;
class View
{
public:
	View();
	~View();

	int menu();
	void Get(int y, int m, int d, int mw, int mt, int ry, int rm, int rd);
	void Con(Model* pm);
};
#endif
