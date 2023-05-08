#include"teacher.h"

Teacher::Teacher()//默认构造
{

}

Teacher::Teacher(int empId, string name, string pwd)//有参构造-参数：编号、姓名、密码
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu()//菜单界面
{
	cout << "欢迎教师 " << this->m_Name << " 登录！" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t|\t 1-查看所有预约\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 2-审 核 预  约\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 其它--注销登录\t\t|" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "请输入您的选择：" << endl;
}

void Teacher::showAllOrder()//查看所有预约
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";

		string mydate;
		if (of.m_OrderData[i]["date"] == "1")
		{
			mydate = "周一";
		}
		else if (of.m_OrderData[i]["date"] == "2")
		{
			mydate = "周二";
		}
		else if (of.m_OrderData[i]["date"] == "3")
		{
			mydate = "周三";
		}
		else if (of.m_OrderData[i]["date"] == "4")
		{
			mydate = "周四";
		}
		else
		{
			mydate = "周五";
		}
		cout << "预约日期：" << mydate;
		cout << "\t时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "\t学号：" << of.m_OrderData[i]["stuId"];
		cout << "\t姓名：" << of.m_OrderData[i]["stuName"];
		cout << "\t机房编号：" << of.m_OrderData[i]["roomId"];
		string status = "\t状态：";
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "预约申请正在审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "审核通过，预约成功！";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败！";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()//审核预约
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "待审核的预约信息记录如下：" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";

			string mydate;
			if (of.m_OrderData[i]["date"] == "1")
			{
				mydate = "周一";
			}
			else if (of.m_OrderData[i]["date"] == "2")
			{
				mydate = "周二";
			}
			else if (of.m_OrderData[i]["date"] == "3")
			{
				mydate = "周三";
			}
			else if (of.m_OrderData[i]["date"] == "4")
			{
				mydate = "周四";
			}
			else
			{
				mydate = "周五";
			}
			cout << "预约日期：" << mydate;
			cout << "\t时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "\t学生学号：" << of.m_OrderData[i]["stuId"];
			cout << "\t学生姓名：" << of.m_OrderData[i]["stuName"];
			cout << "\t机房编号：" << of.m_OrderData[i]["roomId"];
			string status = "\t状态：审核中";
			cout << status << endl;
		}
	}
	cout << "请输入您要审核的预约记录的编号,0可以返回上一级：" << endl;
	int select = 0;
	int ret = 0;//审核结果

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果：" << endl;
				cout << "1-审核通过" << endl;
				cout << "2-审核不通过" << endl;

				while (true)
				{
					cin >> ret;
					if (ret == 1)//审核通过
					{
						of.m_OrderData[v[select - 1]]["status"] = "2";
						break;
					}
					else if (ret == 2)//审核不通过
					{
						of.m_OrderData[v[select - 1]]["status"] = "-1";
						break;
					}
					cout << "您的输入有误！请重新输入：" << endl;
				}

				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "您的输入有误！请重新输入：" << endl;
	}
	system("pause");
	system("cls");
}
