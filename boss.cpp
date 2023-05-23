#include "Boss.h"

Boss::Boss(int id, string name, int depId)
{
	m_Id = id;
	m_Name = name;
	m_DepId = depId;
}
void Boss::showInfo()
{
	cout << "����:" << m_Id << "\t����:" << m_Name << "\t���ű���:" << m_DepId << endl;
}

//��������
string  Boss::getName()
{
	return m_Name;
}
//����id
int  Boss::getId()
{
	return m_Id;
}

//��������
void Boss::setName(string name)
{
	m_Name = name;
}
//����id
void Boss::setId(int Id)
{
	m_Id = Id;
}
//���ò��ű���
void Boss::setDepId(int DepId)
{
	m_DepId = DepId;
}

//���ò��ű���
int  Boss::getDepId()
{
	return m_DepId;
}


string Boss::getDepName()
{
	return (string)"�ϰ�";
}
