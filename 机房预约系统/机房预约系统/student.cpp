#include"student.h"

Student::Student()//Ĭ�Ϲ���
{

}

Student::Student(int id, string name, string pwd)//�вι���-������ѧ�š�����������
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initComputerRoom();//��ʼ��������Ϣ
}

void Student::operMenu()//�˵�����
{
	cout << "��ӭѧ������ " << this->m_Name << " ��¼��" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t|\t 1-�� �� Ԥ Լ \t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 2-�鿴�ҵ�ԤԼ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 3-�鿴����ԤԼ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 4-ȡ��ԤԼ��Ϣ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t ����--ע����¼\t\t|" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "����������ѡ��" << endl;
}

void Student::applyOrder()//����ԤԼ
{
	int date = 0;//����
	int interval = 0;//ʱ���
	int room;//�������

	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "��ѡ����ҪԤԼ��ʱ�䣺" << endl;
	cout << "\t1-��һ" << endl;
	cout << "\t2-�ܶ�" << endl;
	cout << "\t3-����" << endl;
	cout << "\t4-����" << endl;
	cout << "\t5-����" << endl;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "���������������������룺" << endl;
	}
	cout << "��ѡ����ҪԤԼ��ʱ��Σ�" << endl;
	cout << "1-����" << endl;
	cout << "2-����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "���������������������룺" << endl;

	}
	cout << "��ѡ����ҪԤԼ�Ļ�����ţ�" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "-" << vCom[i].m_ComId << "�Ż�����������Ϊ" << vCom[i].m_MaxNum << "��" << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "���������������������룺" << endl;
	}
	cout << "ԤԼ�ɹ�����������У�" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()//�鿴�Լ���ԤԼ
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		//string => int:    string ���� .c_str() תΪC���Է����ַ��� const char *
		//Ȼ��  atoi( const char * ) => int
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			index += 1;
			cout << index << "��";
			string mydate;
			if (of.m_OrderData[i]["date"] == "1")
			{
				mydate = "��һ";
			}
			else if (of.m_OrderData[i]["date"] == "2")
			{
				mydate = "�ܶ�";
			}
			else if (of.m_OrderData[i]["date"] == "3")
			{
				mydate = "����";
			}
			else if (of.m_OrderData[i]["date"] == "4")
			{
				mydate = "����";
			}
			else
			{
				mydate = "����";
			}
			cout << "ԤԼ���ڣ�" << mydate;
			cout << "\tʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "\t������ţ�" << of.m_OrderData[i]["roomId"];
			string status = "\t״̬��";
			//1�������   2��ԤԼ�ɹ�  -1��ԤԼʧ��  0��ȡ��ԤԼ
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "ԤԼ�������������";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "���ͨ����ԤԼ�ɹ���";
			}
			else if (of.m_OrderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ�ܣ�";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()//�鿴����ԤԼ
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";

		string mydate;
		if (of.m_OrderData[i]["date"] == "1")
		{
			mydate = "��һ";
		}
		else if (of.m_OrderData[i]["date"] == "2")
		{
			mydate = "�ܶ�";
		}
		else if (of.m_OrderData[i]["date"] == "3")
		{
			mydate = "����";
		}
		else if (of.m_OrderData[i]["date"] == "4")
		{
			mydate = "����";
		}
		else
		{
			mydate = "����";
		}
		cout << "ԤԼ���ڣ�" << mydate;
		cout << "\tʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << "\tѧ�ţ�" << of.m_OrderData[i]["stuId"];
		cout << "\t������" << of.m_OrderData[i]["stuName"];
		cout << "\t������ţ�" << of.m_OrderData[i]["roomId"];
		string status = "\t״̬��";
		//1�������   2��ԤԼ�ɹ�  -1��ԤԼʧ��  0��ȡ��ԤԼ
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "ԤԼ�������������";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "���ͨ����ԤԼ�ɹ���";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ�ܣ�";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder()//ȡ��ԤԼ
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "������ȡ���Ѿ�����ɹ����������״̬��ԤԼ��" << endl;

	vector<int>v;//��Ŵ�map�������±�
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				string mydate;
				if (of.m_OrderData[i]["date"] == "1")
				{
					mydate = "��һ";
				}
				else if (of.m_OrderData[i]["date"] == "2")
				{
					mydate = "�ܶ�";
				}
				else if (of.m_OrderData[i]["date"] == "3")
				{
					mydate = "����";
				}
				else if (of.m_OrderData[i]["date"] == "4")
				{
					mydate = "����";
				}
				else
				{
					mydate = "����";
				}
				cout << "ԤԼ���ڣ�" << mydate;
				cout << "\tʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << "\t������ţ�" << of.m_OrderData[i]["roomId"];
				string status = "\t״̬��";//1�������   2��ԤԼ�ɹ�
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "ԤԼ�������������";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "���ͨ����ԤԼ�ɹ���";
				}
				cout << status << endl;
			}
		}
	}
	cout << "��������Ҫȡ����ԤԼ��Ϣ�ı��,0���Է�����һ����" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "ȡ��ԤԼ�ɹ���" << endl;
				break;
			}
		}
		cout << "���������������������룺" << endl;
	}
	system("pause");
	system("cls");
}

void Student::initComputerRoom()//��ʼ��������Ϣ
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//���ļ�

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
