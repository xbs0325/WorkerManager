#include "manager.h"

Manager::Manager(int id, string name, int depId)
{
	m_Id = id;
	m_Name = name;
	m_DepId = depId;
}
void Manager::showInfo()
{
	cout << "���:" << m_Id << "\t����:" << m_Name << "\t���ű��:" << m_DepId << endl;
}

//�������
string Manager::getName()
{
	return m_Name;
}
//���id
int Manager::getId()
{
	return m_Id;
}

//��������
void Manager::setName(string name)
{
	m_Name = name;
}
//����id
void Manager::setId(int Id)
{
	m_Id = Id;
}
//���ò��ű��
void Manager::setDepId(int DepId)
{
	m_DepId = DepId;
}

//��ò��ű��
int Manager::getDepId()
{
	return m_DepId;
}

string Manager::getDepName()
{
	return (string)"����";
}