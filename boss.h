#pragma once
#include "worker.h"
using namespace std;

class Boss :public Worker
{
public:
	Boss(int id, string name, int depId);
	//��ȡ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDepName();
	//�������
	virtual string getName();
	//���id
	virtual int getId();
	//��ò��ű��
	virtual int getDepId();
	//��������
	virtual void setName(string name);
	//����id
	virtual void setId(int id);
	//���ò��ű��
	virtual void setDepId(int DepId);


	string m_Name;
	int m_Id;
	int m_DepId;

};