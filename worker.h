#pragma once
#include <iostream>
#include <string>


using namespace std;

class Worker
{
public:
	//获取个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDepName() = 0;
	//获得名字
	virtual string getName() = 0;
	//获得id
	virtual int getId() = 0;
	//获得部门编号
	virtual int getDepId() = 0;
	//设置名字
	virtual void setName(string name) = 0;
	//设置id
	virtual void setId(int id)= 0;
	//设置部门编号
	virtual void setDepId(int DepId) = 0;


	string m_Name;
	int m_Id;
	int m_DepId;
};

