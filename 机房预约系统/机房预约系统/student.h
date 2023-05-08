#pragma once
#include<iostream>
#include<cstdlib>//可以防止 system不明确
using namespace std;
#include"identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

class Student :public Identity//学生类
{
public:
	Student();//默认构造

	Student(int id, string name, string pwd);//有参构造-参数：学号、姓名、密码

	virtual void operMenu();//菜单界面

	void applyOrder();//申请预约

	void showMyOrder();//查看自己的预约

	void showAllOrder();//查看所有预约

	void cancelOrder();//取消预约

	void initComputerRoom();//初始化机房信息

	int m_Id;//学号

	vector<ComputerRoom>vCom;//存放机房信息的容器
};

