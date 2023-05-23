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
		case 1://增加
			wm.add_worker();
			break;
		case 2://显示
			wm.traverse_worker();
			break;
		case 3://删除
			if (wm.delete_worker() == true)
				cout << "删除成功" << endl;
			else
				cout << "删除失败" << endl;
			break;
		case 4://修改
			if (wm.change_worker())
				cout << "修改成功" << endl;
			else
				cout << "修改失败" << endl;
			break;
		case 5://查找
			cout << "请输入要查找的编号:";
			cin >> temp_Id;
			temp2_wn = wm.IsExist(temp_Id);
			temp2_wn->data->showInfo();
			break;
		case 6://清空
			wm.fclear();
			break;
		default://退出
			quit = 1;
			break;
		}
		system("pause");
		system("cls");//clear screen
	}
	wm.exit_system();

}

