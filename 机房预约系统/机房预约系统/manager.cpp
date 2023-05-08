#include"manager.h"

Manager::Manager()//Ĭ�Ϲ���
{

}

Manager::Manager(string name, string pwd)//�вι���  ����������������
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();//��ʼ����������ȡ�ļ���ѧ������ʦ����Ϣ

	this->initComputerRoom();//��ʼ��������Ϣ
}

void Manager::operMenu()//�˵�����
{
	cout << "��ӭ����Ա " << this->m_Name << " ��¼��" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t|\t 1-����˺���Ϣ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 2-�鿴�˺���Ϣ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 3-�鿴������Ϣ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 4-���ԤԼ��Ϣ\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t ����--ע����¼\t\t|" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "����������ѡ��" << endl;
}

void Manager::addPerson()//����˺�
{
	cout << "��ѡ����Ҫ��ӵ��˺����ͣ�" << endl;
	cout << "1-���ѧ��" << endl;
	cout << "2-��ӽ�ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;//�ظ��Ĵ�����ʾ

	ofstream ofs;

	int select = 0;//�û���ѡ��

	while (true)
	{
		cin >> select;

		if (select == 1)//���ѧ��
		{
			fileName = STUDENT_FILE;
			tip = "��������Ҫ��ӵ�ѧ��ѧ�ţ�";
			errorTip = "ѧ���ظ������������룺";
			break;
		}
		else if (select == 2)//��ӽ�ʦ
		{
			fileName = TEACHER_FILE;
			tip = "��������Ҫ��ӵĽ�ʦ��ţ�";
			errorTip = "ְ������ظ������������룺";
			break;
		}
		else
		{
			cout << "���������������������룺" << endl;
		}
	}
	ofs.open(fileName, ios::out | ios::app);//д�ļ�(׷�ӵķ�ʽ)

	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "��������Ҫ��ӵ�������" << endl;
	cin >> name;
	cout << "��������Ҫ��ӵ����룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;//������д�뵽�ļ���
	cout << "�����Ϣ�ɹ���" << endl;

	system("pause");
	system("cls");
	ofs.close();

	this->initVector();//���£��൱��ÿ��һ���˾����¶�ȡ�ļ��е���Ϣ
}

void printStudent(Student& s)
{
	cout << "ѧ��ѧ�ţ�" << s.m_Id << "\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ����ţ�" << t.m_EmpId << "\t������" << t.m_Name << "\t���룺" << t.m_Pwd << endl;
}

void Manager::showPerson()//�鿴�˺�
{
	cout << "��ѡ����Ҫ�鿴����Ϣ���ͣ�" << endl;
	cout << "1-�鿴����ѧ����Ϣ" << endl;
	cout << "2-�鿴���н�ʦ��Ϣ" << endl;

	int select = 0;

	while (true)
	{
		cin >> select;
		if (select == 1)//�鿴ѧ����Ϣ
		{
			cout << "����ѧ����Ϣ���£�" << endl;

			for_each(vStu.begin(), vStu.end(), printStudent);

			break;
		}
		else if (select == 2)//�鿴��ʦ��Ϣ
		{
			cout << "���н�ʦ��Ϣ���£�" << endl;

			for_each(vTea.begin(), vTea.end(), printTeacher);

			break;
		}
		else
		{
			cout << "���������������������룺" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()//�鿴������Ϣ
{
	cout << "���л�����Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << "\t�������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearFile()//���ԤԼ��Ϣ
{
	cout << "��ȷ��Ҫ������е�ԤԼ��Ϣ��" << endl;
	cout << "1-ȷ��" << endl;
	cout << "2-����" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			ofstream ofs;
			ofs.open(ORDER_FILE, ios::trunc);
			ofs.close();

			cout << "���ԤԼ��Ϣ�ɹ���" << endl;
			break;
		}
		else if (select == 2)
		{
			break;
		}
		else
		{
			cout << "���������������������룺" << endl;
		}
	}
	system("pause");
	system("cls");
}

void  Manager::initVector()//��ʼ������
{
	vStu.clear();
	vTea.clear();

	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		cout << "'�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)//����ظ�-������ѧ�Ż�ְ���ţ��������
{
	if (type == 1)//ѧ��
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else//��ʦ
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::initComputerRoom()//��ʼ��������Ϣ
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//���ļ�

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	ifs.close();
}
