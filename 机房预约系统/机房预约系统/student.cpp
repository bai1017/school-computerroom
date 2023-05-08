#include"student.h"

Student::Student()//默认构造
{

}

Student::Student(int id, string name, string pwd)//有参构造-参数：学号、姓名、密码
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initComputerRoom();//初始化机房信息
}

void Student::operMenu()//菜单界面
{
	cout << "欢迎学生代表 " << this->m_Name << " 登录！" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t|\t 1-申 请 预 约 \t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 2-查看我的预约\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 3-查看所有预约\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 4-取消预约信息\t\t|" << endl;
	cout << "\t|\t               \t\t|" << endl;
	cout << "\t|\t 其它--注销登录\t\t|" << endl;
	cout << "\t---------------------------------" << endl;
	cout << "请输入您的选择：" << endl;
}

void Student::applyOrder()//申请预约
{
	int date = 0;//哪天
	int interval = 0;//时间段
	int room;//机房编号

	cout << "机房开放时间为周一至周五" << endl;
	cout << "请选择您要预约的时间：" << endl;
	cout << "\t1-周一" << endl;
	cout << "\t2-周二" << endl;
	cout << "\t3-周三" << endl;
	cout << "\t4-周四" << endl;
	cout << "\t5-周五" << endl;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "您的输入有误！请重新输入：" << endl;
	}
	cout << "请选择您要预约的时间段：" << endl;
	cout << "1-上午" << endl;
	cout << "2-下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "您的输入有误！请重新输入：" << endl;

	}
	cout << "请选择您要预约的机房编号：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "-" << vCom[i].m_ComId << "号机房，其容量为" << vCom[i].m_MaxNum << "人" << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "您的输入有误！请重新输入：" << endl;
	}
	cout << "预约成功！正在审核中！" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()//查看自己的预约
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		//string => int:    string 利用 .c_str() 转为C语言风格的字符串 const char *
		//然后：  atoi( const char * ) => int
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			index += 1;
			cout << index << "、";
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
			cout << "\t机房编号：" << of.m_OrderData[i]["roomId"];
			string status = "\t状态：";
			//1：审核中   2：预约成功  -1：预约失败  0：取消预约
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
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()//查看所有预约
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
		//1：审核中   2：预约成功  -1：预约失败  0：取消预约
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

void Student::cancelOrder()//取消预约
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "您可以取消已经申请成功或正在审核状态的预约！" << endl;

	vector<int>v;//存放大map容器的下标
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
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
				cout << "\t机房编号：" << of.m_OrderData[i]["roomId"];
				string status = "\t状态：";//1：审核中   2：预约成功
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "预约申请正在审核中";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "审核通过，预约成功！";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入您要取消的预约信息的编号,0可以返回上一级：" << endl;
	int select = 0;
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
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "取消预约成功！" << endl;
				break;
			}
		}
		cout << "您的输入有误！请重新输入：" << endl;
	}
	system("pause");
	system("cls");
}

void Student::initComputerRoom()//初始化机房信息
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//读文件

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
