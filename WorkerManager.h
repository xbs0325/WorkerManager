#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
using namespace std;

//ʹ��virtual�ؼ��ʽ��д��麯���̳�ʱ ������ָ��ָ���������ַ 
// ��ʱ��Ա��������д ����Ա����Ϊ���� ���Ե����û���ָ�����������ַʱ 
// ��Ա������ֱ�ӵ��� ����Ա����Ҫ��������

//c++�нṹ�嶨����Բ���struct

//WorkerManager ��91��
struct Worker_Node
{
	Worker* data;
	Worker_Node* next;
};

struct WorkerList
{
	Worker_Node* head;
	Worker_Node* tail;
};


class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//����Ա����Ϣ
	bool load();
	//�˵�
	void show_menu();
	//����Ա����Ϣ
	bool add_worker();
	//ɾ��Ա����Ϣ
	bool delete_worker();
	//����Ա����Ϣ
	bool change_worker();
	//����ְ����Ϣ
	bool save();
	//����Ա����Ϣ

	//����Ա����Ϣ
	void traverse_worker();
	//����Ա����Ϣ

	//��ȡְ��������
	int get_length();
	//ְ���Ƿ����
	Worker_Node* IsExist(int Id);
	//�˳�
	void exit_system();

	void fclear();

	~WorkerManager();

	//����
	int m_WorkerNumber;
	//ְ������
	WorkerList* workerlist;//struct ���Բ�д
};
