#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>


class OrderFile
{
public:
	OrderFile();//���캯��

	void updateOrder();//����ԤԼ

	int m_Size;//ԤԼ������

	//key���ڼ���ԤԼ��Ϣ��value����ǰ����ԤԼ����ϸ����
	map<int, map<string, string>>m_OrderData;//��¼����ԤԼ������
};

