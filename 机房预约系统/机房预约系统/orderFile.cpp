#include"orderFile.h"


OrderFile::OrderFile()//构造函数
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;//日期
	string interval;//时间段
	string stuId;//学生学号
	string stuName;//学生姓名
	string roomId;//机房编号
	string status;//预约状态

	this->m_Size = 0;//初始化预约的条数

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		string key;
		string value;

		map<string, string>m;

		int pos = date.find(":");//date
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - (pos + 1));
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");//interval
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - (pos + 1));
			m.insert(make_pair(key, value));
		}
		pos = stuId.find(":");//stuId
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - (pos + 1));
			m.insert(make_pair(key, value));
		}
		pos = stuName.find(":");//stuName
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - (pos + 1));
			m.insert(make_pair(key, value));
		}
		pos = roomId.find(":");//roomId
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - (pos + 1));
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");//status
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - (pos + 1));
			m.insert(make_pair(key, value));
		}
		//将小map容器放到大map容器中
		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}
	ifs.close();

	//测试大map容器
	/*for (map<int, map<string, string>>::iterator it = m_OrderData.begin(); it != m_OrderData.end(); it++)
	{
		cout << "条数为：" << it->first << "value = " << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		{
			cout << "key = " << mit->first << " value = " << mit->second << "  ";
		}
		cout << endl;
	}*/
}

void OrderFile::updateOrder()//更新预约
{
	if (this->m_Size == 0)//预约记录为0
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << endl;
	}
	ofs.close();
}
