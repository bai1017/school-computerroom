#pragma once
#include<iostream>
#include<cstdlib>//���Է�ֹ system����ȷ
using namespace std;
#include"identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

class Student :public Identity//ѧ����
{
public:
	Student();//Ĭ�Ϲ���

	Student(int id, string name, string pwd);//�вι���-������ѧ�š�����������

	virtual void operMenu();//�˵�����

	void applyOrder();//����ԤԼ

	void showMyOrder();//�鿴�Լ���ԤԼ

	void showAllOrder();//�鿴����ԤԼ

	void cancelOrder();//ȡ��ԤԼ

	void initComputerRoom();//��ʼ��������Ϣ

	int m_Id;//ѧ��

	vector<ComputerRoom>vCom;//��Ż�����Ϣ������
};

