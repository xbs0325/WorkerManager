#include "WorkerManager.h" 
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#define path "worker.txt"

WorkerManager::WorkerManager()
{
	//ְ������
	m_WorkerNumber = 0;
	       
	workerlist = new WorkerList;
	//ͷ�ڵ��ʼ��    
	workerlist->head = new Worker_Node;
	workerlist->head->next = NULL;

	//β�ڵ��ʼ��
	workerlist->tail = workerlist->head;
	workerlist->tail->next = NULL;
	
	if (!load())
	{
		cout << "���ļ������ڣ�" << endl;
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
	
		cout << "	      ְ������ϵͳ    " << endl;
		cout << "	---------------------  " << endl;
		cout << "	    1.����ְ����Ϣ     " << endl;
		cout << "	    2.��ʾְ����Ϣ     " << endl;
		cout << "	    3.ɾ����ְԱ��     " << endl;
		cout << "	    4.�޸�ְ����Ϣ     " << endl;
		cout << "	    5.����ְ����Ϣ     " << endl;
		cout << "	    6.��������ĵ�     " << endl;
		cout << "		7.�˳�			   " << endl;
		cout << "	---------------------  " << endl;

}

bool WorkerManager::add_worker()
{
	int num;
	int i;

	cout << "����������Ա���ĸ���:" << endl;
	cin >> num;
	//������������
	Worker* temp = NULL;
	for (i = 0; i < num; i++)
	{
		int types = 0;
		int Id = 0;
		int DepId = 0;
		string Name = { 0 };
		//�����½ڵ�
		Worker_Node* wk = new Worker_Node;
		wk->data = NULL;
		wk->next = NULL;
		
		//��λȷ��
		cout << "������ְ����λ:(1.Ա��/2.����/3.�ϰ�)";
		cin >> types;
		//������ʱ����
		cout << "������Ա�����:" << endl;
		cin >> Id;
		cout << "������Ա������:" << endl;
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
		//temp���ݴ����½ڵ�
		wk->data = temp;
		//�½ڵ��������
		workerlist->tail->next = wk;
		workerlist->tail = wk;
	}
	//delete temp;  ָ��ֱ��ָ��ڵ㲻��Ҫ�ͷſռ�  Ϊ�ṹ��ָ�����ռ���nextָ��ڵ�ʱ ָ��Ӧ���ͷ�
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
		//cout << temp_wk->data->m_Id << endl;      //?:ͨ��������ó�Ա������ַ���ᷢ��ƫ��
		cout << index << ". ";
		temp_wk->data->showInfo();
		temp_wk = temp_wk->next;
	}
}
bool WorkerManager::delete_worker()
{
	int temp_Id = 0;
	cout << "������ְ�����:" << endl;
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
		cout << "��������" << endl;
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

	cout << "�����ְ����ţ�";
	cin >> temp_Id;
	
	if (wn == NULL)
		return false;
	cout << "��������ĵĸ�λ���:";
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
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::fclear()
{
	delete workerlist;
	workerlist = new WorkerList;
	//ͷ�ڵ��ʼ��    
	workerlist->head = new Worker_Node;
	workerlist->head->next = NULL;

	//β�ڵ��ʼ��
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