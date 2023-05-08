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

class Manager :public Identity//����Ա��
{
public:
	Manager();//Ĭ�Ϲ���

	Manager(string name, string pwd);//�вι���  ����������������

	virtual void operMenu();//�˵�����

	void addPerson();//����˺�

	void showPerson();//�鿴�˺�

	void showComputer();//�鿴������Ϣ

	void clearFile();//���ԤԼ��Ϣ

	void initVector();//��ʼ������

	void initComputerRoom();//��ʼ��������Ϣ

	bool checkRepeat(int id, int type);//����ظ�-������ѧ�Ż�ְ���ţ��������

	vector<Student>vStu;//���ѧ����Ϣ������

	vector<Teacher>vTea;//�����ʦ��Ϣ������

	vector<ComputerRoom>vCom;//��Ż�����Ϣ������
};
