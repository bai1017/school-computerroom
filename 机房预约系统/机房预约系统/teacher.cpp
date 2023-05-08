#include"teacher.h"

Teacher::Teacher()//Ĭ�Ϲ���
{

}

Teacher::Teacher(int empId, string name, string pwd)//�вι���-��������š�����������
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu()//�˵�����
{
	cout << "��ӭ��ʦ " << this->m_Name << " ��¼��" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t|\t 1-�鿴����ԤԼ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 2-�� �� Ԥ  Լ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t ����--ע����¼\t\t|" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "����������ѡ��" << endl;
}

void Teacher::showAllOrder()//�鿴����ԤԼ
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

void Teacher::validOrder()//���ԤԼ
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "����˵�ԤԼ��Ϣ��¼���£�" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";

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
			cout << "\tѧ��ѧ�ţ�" << of.m_OrderData[i]["stuId"];
			cout << "\tѧ��������" << of.m_OrderData[i]["stuName"];
			cout << "\t������ţ�" << of.m_OrderData[i]["roomId"];
			string status = "\t״̬�������";
			cout << status << endl;
		}
	}
	cout << "��������Ҫ��˵�ԤԼ��¼�ı��,0���Է�����һ����" << endl;
	int select = 0;
	int ret = 0;//��˽��

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
				cout << "��������˽����" << endl;
				cout << "1-���ͨ��" << endl;
				cout << "2-��˲�ͨ��" << endl;

				while (true)
				{
					cin >> ret;
					if (ret == 1)//���ͨ��
					{
						of.m_OrderData[v[select - 1]]["status"] = "2";
						break;
					}
					else if (ret == 2)//��˲�ͨ��
					{
						of.m_OrderData[v[select - 1]]["status"] = "-1";
						break;
					}
					cout << "���������������������룺" << endl;
				}

				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "���������������������룺" << endl;
	}
	system("pause");
	system("cls");
}
