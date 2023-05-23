#include "WorkerManager.h"

using namespace std;

int main()
{
	WorkerManager wm;
	Worker_Node* temp2_wn = NULL;
	int quit = 0;
	int option = 8;
	int temp_Id = 0;

	while (!quit)
	{
		wm.show_menu();

		cin >> option;
		switch (option)
		{
		case 1://����
			wm.add_worker();
			break;
		case 2://��ʾ
			wm.traverse_worker();
			break;
		case 3://ɾ��
			if (wm.delete_worker() == true)
				cout << "ɾ���ɹ�" << endl;
			else
				cout << "ɾ��ʧ��" << endl;
			break;
		case 4://�޸�
			if (wm.change_worker())
				cout << "�޸ĳɹ�" << endl;
			else
				cout << "�޸�ʧ��" << endl;
			break;
		case 5://����
			cout << "������Ҫ���ҵı��:";
			cin >> temp_Id;
			temp2_wn = wm.IsExist(temp_Id);
			temp2_wn->data->showInfo();
			break;
		case 6://���
			wm.fclear();
			break;
		default://�˳�
			quit = 1;
			break;
		}
		system("pause");
		system("cls");//clear screen
	}
	wm.exit_system();

}

