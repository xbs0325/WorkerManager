#include "employee.h"
Employee::Employee(int id, string name, int depId)
{
	m_Id = id;
	m_Name = name;
	m_DepId = depId;
}
void Employee::showInfo()
{
	cout << "编号:" << m_Id << "\t姓名:" << m_Name << "\t部门编号:" << m_DepId << endl;
}
//获得名字
string Employee::getName()
{
	return m_Name;
}
//获得id
int Employee::getId()
{
	return m_Id;
}

//设置名字
void  Employee::setName(string name)
{
	m_Name = name;
}
//设置id
void  Employee::setId(int Id)
{
	m_Id = Id;
}
//设置部门编号
void  Employee::setDepId(int DepId)
{
	m_DepId = DepId;
}

//获得部门编号
int Employee::getDepId()
{
	return m_DepId;
}


string Employee::getDepName()
{
	return (string)"员工";
}