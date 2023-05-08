#include"manager.h"

Manager::Manager()//默认构造
{

}

Manager::Manager(string name, string pwd)//有参构造  参数：姓名、密码
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();//初始化容器，获取文件中学生、老师的信息

	this->initComputerRoom();//初始化机房信息
}

void Manager::operMenu()//菜单界面
{
	cout << "欢迎管理员 " << this->m_Name << " 登录！" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t|\t 1-添加账号信息\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 2-查看账号信息\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 3-查看机房信息\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 4-清空预约信息\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 其它--注销登录\t\t|" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "请输入您的选择：" << endl;
}

void Manager::addPerson()//添加账号
{
	cout << "请选择您要添加的账号类型：" << endl;
	cout << "1-添加学生" << endl;
	cout << "2-添加教师" << endl;

	string fileName;
	string tip;
	string errorTip;//重复的错误提示

	ofstream ofs;

	int select = 0;//用户的选择

	while (true)
	{
		cin >> select;

		if (select == 1)//添加学生
		{
			fileName = STUDENT_FILE;
			tip = "请输入您要添加的学生学号：";
			errorTip = "学号重复！请重新输入：";
			break;
		}
		else if (select == 2)//添加教师
		{
			fileName = TEACHER_FILE;
			tip = "请输入您要添加的教师编号：";
			errorTip = "职工编号重复！请重新输入：";
			break;
		}
		else
		{
			cout << "您的输入有误！请重新输入：" << endl;
		}
	}
	ofs.open(fileName, ios::out | ios::app);//写文件(追加的方式)

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
	cout << "请输入您要添加的姓名：" << endl;
	cin >> name;
	cout << "请输入您要添加的密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;//将数据写入到文件中
	cout << "添加信息成功！" << endl;

	system("pause");
	system("cls");
	ofs.close();

	this->initVector();//更新，相当于每加一个人就重新读取文件中的信息
}

void printStudent(Student& s)
{
	cout << "学生学号：" << s.m_Id << "\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工编号：" << t.m_EmpId << "\t姓名：" << t.m_Name << "\t密码：" << t.m_Pwd << endl;
}

void Manager::showPerson()//查看账号
{
	cout << "请选择您要查看的信息类型：" << endl;
	cout << "1-查看所有学生信息" << endl;
	cout << "2-查看所有教师信息" << endl;

	int select = 0;

	while (true)
	{
		cin >> select;
		if (select == 1)//查看学生信息
		{
			cout << "所有学生信息如下：" << endl;

			for_each(vStu.begin(), vStu.end(), printStudent);

			break;
		}
		else if (select == 2)//查看老师信息
		{
			cout << "所有教师信息如下：" << endl;

			for_each(vTea.begin(), vTea.end(), printTeacher);

			break;
		}
		else
		{
			cout << "您的输入有误！请重新输入：" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()//查看机房信息
{
	cout << "所有机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << "\t机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearFile()//清空预约信息
{
	cout << "您确定要清空所有的预约信息吗？" << endl;
	cout << "1-确定" << endl;
	cout << "2-返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			ofstream ofs;
			ofs.open(ORDER_FILE, ios::trunc);
			ofs.close();

			cout << "清空预约信息成功！" << endl;
			break;
		}
		else if (select == 2)
		{
			break;
		}
		else
		{
			cout << "您的输入有误！请重新输入：" << endl;
		}
	}
	system("pause");
	system("cls");
}

void  Manager::initVector()//初始化容器
{
	vStu.clear();
	vTea.clear();

	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "'文件读取失败！" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取教师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为：" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)//检测重复-参数：学号或职工号，身份类型
{
	if (type == 1)//学生
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else//老师
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

void Manager::initComputerRoom()//初始化机房信息
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//读文件

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
	ifs.close();
}
