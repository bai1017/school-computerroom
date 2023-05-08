#pragma once
#include<iostream>
using namespace std;

class Identity//抽象身份基类
{
public:
	virtual void operMenu() = 0;//纯虚函数---操作子菜单

	string m_Name;//用户名
	string m_Pwd;//登录密码
};


