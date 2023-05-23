#include "manager.h"

Manager::Manager(int id, string name, int depId)
{
	m_Id = id;
	m_Name = name;
	m_DepId = depId;
}
void Manager::showInfo()
{
	cout << "编号:" << m_Id << "\t姓名:" << m_Name << "\t部门编号:" << m_DepId << endl;
}

//获得名字
string Manager::getName()
{
	return m_Name;
}
//获得id
int Manager::getId()
{
	return m_Id;
}

//设置名字
void Manager::setName(string name)
{
	m_Name = name;
}
//设置id
void Manager::setId(int Id)
{
	m_Id = Id;
}
//设置部门编号
void Manager::setDepId(int DepId)
{
	m_DepId = DepId;
}

//获得部门编号
int Manager::getDepId()
{
	return m_DepId;
}

string Manager::getDepName()
{
	return (string)"经理";
}