#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
#include<vector>

class Teacher :public Identity//��ʦ��
{
public:
	Teacher();//Ĭ�Ϲ���

	Teacher(int empId, string name, string pwd);//�вι���-��������š�����������

	virtual void operMenu();//�˵�����

	void showAllOrder();//�鿴����ԤԼ

	void validOrder();//���ԤԼ

	int m_EmpId;//ְ�����
};

