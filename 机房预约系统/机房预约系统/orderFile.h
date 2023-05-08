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
	OrderFile();//构造函数

	void updateOrder();//更新预约

	int m_Size;//预约的条数

	//key：第几条预约信息，value：当前这条预约的详细内容
	map<int, map<string, string>>m_OrderData;//记录所有预约的容器
};

