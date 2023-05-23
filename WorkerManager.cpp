#include "WorkerManager.h" 
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#define path "worker.txt"

WorkerManager::WorkerManager()
{
	//职工数量
	m_WorkerNumber = 0;
	       
	workerlist = new WorkerList;
	//头节点初始化    
	workerlist->head = new Worker_Node;
	workerlist->head->next = NULL;

	//尾节点初始化
	workerlist->tail = workerlist->head;
	workerlist->tail->next = NULL;
	
	if (!load())
	{
		cout << "此文件不存在！" << endl;
	}
}
bool WorkerManager::load()
{
	ifstream ifs(path, ios::in);
	if (!ifs.is_open())
		return false;
	string temp_Name = { 0 };
	int temp_Id = 0;
	int temp_DepId = 0;

	while (ifs >> temp_Id && ifs >> temp_Name && ifs >> temp_DepId )
	{
		Worker_Node* wn = new Worker_Node;

		wn->data = NULL;
		
		if (temp_DepId == 1)
		{
			wn->data = new Employee(temp_Id, temp_Name, 1);
		}
		else if (temp_DepId == 2)
		{
			wn->data = new Manager(temp_Id, temp_Name, 2);
		}
		else if (temp_DepId == 3)
		{
			wn->data = new Boss(temp_Id, temp_Name, 3);
		}
		workerlist->tail->next = wn;
		workerlist->tail = wn;
		wn->next = NULL;
		
	}
	ifs.close();
	return true;
}

void WorkerManager::show_menu()
{
	
		cout << "	      职工管理系统    " << endl;
		cout << "	---------------------  " << endl;
		cout << "	    1.增加职工信息     " << endl;
		cout << "	    2.显示职工信息     " << endl;
		cout << "	    3.删除离职员工     " << endl;
		cout << "	    4.修改职工信息     " << endl;
		cout << "	    5.查找职工信息     " << endl;
		cout << "	    6.清空所有文档     " << endl;
		cout << "		7.退出			   " << endl;
		cout << "	---------------------  " << endl;

}

bool WorkerManager::add_worker()
{
	int num;
	int i;

	cout << "请输入增加员工的个数:" << endl;
	cin >> num;
	//创建新数据域
	Worker* temp = NULL;
	for (i = 0; i < num; i++)
	{
		int types = 0;
		int Id = 0;
		int DepId = 0;
		string Name = { 0 };
		//创建新节点
		Worker_Node* wk = new Worker_Node;
		wk->data = NULL;
		wk->next = NULL;
		
		//岗位确认
		cout << "请输入职工岗位:(1.员工/2.经理/3.老板)";
		cin >> types;
		//存入临时数据
		cout << "请输入员工编号:" << endl;
		cin >> Id;
		cout << "请输入员工姓名:" << endl;
		cin >> Name;
		if (types == 1)
		{
			temp = new Employee(Id,Name,1);
		}
		else if (types == 2)
		{
			temp = new Manager(Id, Name, 2);
		}
		else if (types == 3)
		{
			temp = new Boss(Id, Name, 3);
		}
		else
		{
			return false;
		}
		//temp数据存入新节点
		wk->data = temp;
		//新节点接入链表
		workerlist->tail->next = wk;
		workerlist->tail = wk;
	}
	//delete temp;  指针直接指向节点不需要释放空间  为结构体指针分配空间且next指向节点时 指针应被释放
	//temp = NULL;
	save();
	return true;
}
void WorkerManager::traverse_worker()
{
	Worker_Node* temp_wk = workerlist->head->next;
	int index = 0;

	while (temp_wk != NULL)
	{
		index++;
		//cout << temp_wk->data->m_Id << endl;      //?:通过基类调用成员变量地址不会发生偏移
		cout << index << ". ";
		temp_wk->data->showInfo();
		temp_wk = temp_wk->next;
	}
}
bool WorkerManager::delete_worker()
{
	int temp_Id = 0;
	cout << "请输入职工编号:" << endl;
	cin >> temp_Id;
	Worker_Node* temp_node = workerlist->head;
	if (temp_node->next == NULL)
		return false;
	Worker_Node* rubbish_node = NULL;
	while (temp_node != NULL)
	{
		if (temp_node->next->data->getId() == temp_Id)
		{
			rubbish_node = temp_node->next;
			temp_node->next = rubbish_node->next;
			rubbish_node->next = NULL;
			delete rubbish_node;
			return true;
		}
		temp_node = temp_node->next;
	}
	save();
	return false;
}
int WorkerManager::get_length()
{
	if (workerlist == NULL)
	{
		cout << "链表不存在" << endl;
		return 0;
	}

	Worker_Node* temp_wn = workerlist->head->next;
	int count = 0;

	while (temp_wn != NULL)
	{
		count++;
		temp_wn = temp_wn->next;
	}
	return count;
}

Worker_Node* WorkerManager::IsExist(int Id)
{
	
	if (workerlist->head == NULL)
	{
		return NULL;
	}
	Worker_Node* temp_node = this->workerlist->head->next;
	while (temp_node != NULL)
	{
		if (temp_node->data->getId() == Id)
			return temp_node;
		temp_node = temp_node->next;
	}
}
bool WorkerManager::change_worker()
{
	int temp_Id = 0;
	Worker_Node* wn = IsExist(temp_Id);
	int temp_DepId;

	cout << "请输出职工编号：";
	cin >> temp_Id;
	
	if (wn == NULL)
		return false;
	cout << "请输入更改的岗位编号:";
	cin >> temp_DepId;
	wn->data->setDepId(temp_DepId);
	save();
	return true;
}

bool WorkerManager::save()
{
	Worker_Node* temp_wn = workerlist->head->next;
	fstream ofs(path, ios::out);

	if (workerlist == NULL)
	{
		return false;
	}

	for (int i = 0; i < get_length(); i++)
	{
		ofs << temp_wn->data->getId() << " ";
		ofs << temp_wn->data->getName() << " ";
		ofs << temp_wn->data->getDepId() << " ";
		temp_wn = temp_wn->next;
	}
	ofs.close();
	return true;
}


void WorkerManager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::fclear()
{
	delete workerlist;
	workerlist = new WorkerList;
	//头节点初始化    
	workerlist->head = new Worker_Node;
	workerlist->head->next = NULL;

	//尾节点初始化
	workerlist->tail = workerlist->head;
	workerlist->tail->next = NULL;
	fstream ofs(path, ios::out);
	ofs << " ";
	ofs.close();
}

WorkerManager::~WorkerManager()
{
	delete workerlist;
	workerlist = NULL;
}