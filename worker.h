#pragma once
#include <iostream>
#include <string>


using namespace std;

class Worker
{
public:
	//��ȡ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDepName() = 0;
	//�������
	virtual string getName() = 0;
	//���id
	virtual int getId() = 0;
	//��ò��ű��
	virtual int getDepId() = 0;
	//��������
	virtual void setName(string name) = 0;
	//����id
	virtual void setId(int id)= 0;
	//���ò��ű��
	virtual void setDepId(int DepId) = 0;


	string m_Name;
	int m_Id;
	int m_DepId;
};

