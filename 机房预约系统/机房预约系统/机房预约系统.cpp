#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

void studentMenu(Identity*& student)//学生子菜单
{
	while (true)
	{
		student->operMenu();//调用学生子菜单
		Student* stu = (Student*)student;//将父类指针转换为子类指针，调用其他接口

		int select = 0;//记录用户的选择
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else//注销登录
		{
			delete student;//销毁堆区的对象
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}

void teacherMenu(Identity*& teacher)//教师子菜单
{
	while (true)
	{
		teacher->operMenu();//调用教师子菜单
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)//查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else//注销登录
		{
			delete teacher;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity*& manager)//管理员子菜单
{
	while (true)
	{
		manager->operMenu();//调用管理员子菜单
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房信息
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->clearFile();
		}
		else//注销登录
		{
			delete manager;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能   参数：操作的文件名、登录人员的身份类型
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//父类指针，用于指向子类的对象

	ifstream ifs;
	ifs.open(fileName, ios::in);//读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//接收用户的信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)//判断身份类型-学生
	{
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//判断身份类型-教师
	{
		cout << "请输入职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入登录密码：" << endl;
	cin >> pwd;

	if (type == 1)//学生身份验证
	{
		int fId;//从文件中读出的学号
		string fName;//从文件中读出的姓名
		string fPwd;//从文件中读出的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd )
		{
			if (fId == id && fName == name && fPwd == pwd)//与用户的输入对比
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);//进入学生子菜单
				return;
			}
		}
	}
	else if (type == 2)//教师身份验证
	{
		int fId;//从文件中读出的职工编号
		string fName;//从文件中读出的姓名
		string fPwd;//从文件中读出的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				teacherMenu(person);//进入教师子菜单
				return;
			}
		}
	}
	else if (type == 3)//管理员身份验证
	{
		string fName;//从文件中读出的姓名
		string fPwd;//从文件中读出的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				managerMenu(person);//进入管理员子菜单
				return;
			}
		}
	}
	cout << "您的输入有误！登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;//记录用户的选择

	while (true)
	{
		cout << "**********************欢迎使用机房预约系统**********************" << endl;
		cout << "请选择身份：" << endl;
		cout << "\t\t--------------------------------" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|         1-学生代表           |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|         2-老    师           |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|         3-管 理 员          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|         0-退出系统           |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t--------------------------------" << endl;
		cout << "请输入您的选择：";

		cin >> select;

		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);//学生
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);//老师
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);//管理员
			break;
		case 0:
			cout << "欢迎下次使用!" << endl;//退出系统
			system("pause");
			return 0;
			break;
		default:
			cout << "您的输入有误!请重新选择!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

