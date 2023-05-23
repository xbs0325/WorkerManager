#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
using namespace std;

//使用virtual关键词进行纯虚函数继承时 将基类指针指向派生类地址 
// 此时成员函数是重写 而成员变量为重名 所以当调用基类指针找派生类地址时 
// 成员函数可直接调用 而成员变量要加作用域

//c++中结构体定义可以不加struct

//WorkerManager 第91行
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
	//构造函数
	WorkerManager();
	//加载员工信息
	bool load();
	//菜单
	void show_menu();
	//增加员工信息
	bool add_worker();
	//删除员工信息
	bool delete_worker();
	//更改员工信息
	bool change_worker();
	//保存职工信息
	bool save();
	//查找员工信息

	//遍历员工信息
	void traverse_worker();
	//排序员工信息

	//获取职工链表长度
	int get_length();
	//职工是否存在
	Worker_Node* IsExist(int Id);
	//退出
	void exit_system();

	void fclear();

	~WorkerManager();

	//人数
	int m_WorkerNumber;
	//职工链表
	WorkerList* workerlist;//struct 可以不写
};
