#include "employee.h"
Employee::Employee(int id, string name, int depId)
{
	m_Id = id;
	m_Name = name;
	m_DepId = depId;
}
void Employee::showInfo()
{
	cout << "���:" << m_Id << "\t����:" << m_Name << "\t���ű��:" << m_DepId << endl;
}
//�������
string Employee::getName()
{
	return m_Name;
}
//���id
int Employee::getId()
{
	return m_Id;
}

//��������
void  Employee::setName(string name)
{
	m_Name = name;
}
//����id
void  Employee::setId(int Id)
{
	m_Id = Id;
}
//���ò��ű��
void  Employee::setDepId(int DepId)
{
	m_DepId = DepId;
}

//��ò��ű��
int Employee::getDepId()
{
	return m_DepId;
}


string Employee::getDepName()
{
	return (string)"Ա��";
}