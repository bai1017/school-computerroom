#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public Identity//管理员类
{
public:
	Manager();//默认构造

	Manager(string name, string pwd);//有参构造  参数：姓名、密码

	virtual void operMenu();//菜单界面

	void addPerson();//添加账号

	void showPerson();//查看账号

	void showComputer();//查看机房信息

	void clearFile();//清空预约信息

	void initVector();//初始化容器

	void initComputerRoom();//初始化机房信息

	bool checkRepeat(int id, int type);//检测重复-参数：学号或职工号，身份类型

	vector<Student>vStu;//存放学生信息的容器

	vector<Teacher>vTea;//存放老师信息的容器

	vector<ComputerRoom>vCom;//存放机房信息的容器
};
