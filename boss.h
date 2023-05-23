#pragma once
#include "worker.h"
using namespace std;

class Boss :public Worker
{
public:
	Boss(int id, string name, int depId);
	//获取个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDepName();
	//获得名字
	virtual string getName();
	//获得id
	virtual int getId();
	//获得部门编号
	virtual int getDepId();
	//设置名字
	virtual void setName(string name);
	//设置id
	virtual void setId(int id);
	//设置部门编号
	virtual void setDepId(int DepId);


	string m_Name;
	int m_Id;
	int m_DepId;

};