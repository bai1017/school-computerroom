#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
#include<vector>

class Teacher :public Identity//教师类
{
public:
	Teacher();//默认构造

	Teacher(int empId, string name, string pwd);//有参构造-参数：编号、姓名、密码

	virtual void operMenu();//菜单界面

	void showAllOrder();//查看所有预约

	void validOrder();//审核预约

	int m_EmpId;//职工编号
};

