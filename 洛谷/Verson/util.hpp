#pragma once

// 公共头文件
#include <stdint.h>
#include <iostream>
#include <vector>

#include<fstream>

#ifdef _WIN32           // windows 头文件
#include <WinSock2.h>   // hton()  等系列转换ip地址网络字节序与主机字节序的转换接口
#include <WS2tcpip.h>
#include <IPHlpApi.h>   // 获取网卡信息接口的头文件

#include <sstream>
#pragma comment(lib, "Iphlpapi.lib") // 获取网卡信息接口的 库文件
#pragma comment(lib, "ws2_32.lib")   // windows下的socket库 inet_pton

#else
//linux下的头文件
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#endif


class StringUtil
{
public:
	static int64_t Str2Dig(const std::string& num)
	{
		std::stringstream tmp;
		tmp << num;
		int64_t res;
		tmp >> res;
		return res;
	}
};

//文件操作工具类，目的是为了让外部直接使用文件操作接口即可。
//让后期文件操作有其它修改，则只需要修改文件操作工具类即可，不需要对原文进行改变。
class FileUtil
{
public:

	static int64_t GetFileSize(const std::string&name)
	{
		return boost::filesystem::file_size(name);
	}
	//Write向指定文件的指定位置写入指定数据
	/*
	迅雷中的操作是，若相邻不同的主机上有不同的数据，则可以实现，向不同的主机发送不同字段请求数据，
	向每一个主机要一个字段。 比如 A主机要file文件，所以要 向B主机要取(20-100), 向C主机要取（100-200）
	*/
	//static bool Write(const std::string& name, const std::string& body, int64_t offset = 0)
	//{
	//	std::ofstream ofs(name); //输出数据的实例化对象，相当于打开文件,不存在则创建
	//	if (ofs.is_open() == false)
	//	{
	//		std::cout << "打开文件失败" << std::endl;
	//	}
	//	ofs.seekp(offset,std::ios::beg); // 两个参数  seekp(uint32_t offset,std::ios::beg);起始位置
	//	ofs.write(&body[0],body.size()); //两个参数，ofs.write(const char* body,size_t len);

	//	if (ofs.good() == false)
	//	{
	//		std::cout << "向文件写入数据失败" << std::endl;
	//		return false;
	//	}
	//	ofs.close();
	//}

	//static bool Read(const std::string & name, std::string *body)
	//{
	//	std::ifstream ifs(name);
	//	if (ifs.is_open() == false)
	//	{
	//		std::cout << "打开文件失败" << std::endl;
	//		return false;
	//	}
	//	int64_t filesize = boost::filesystem::file_size(name);
	//	body->resize(filesize);
	//	ifs.read(&(*body)[0], filesize);
	//	/*
	//	if (ifs.good == false)
	//	{
	//		std::cout << "读取文件失败" << std::endl;
	//		ifs.close();
	//		return false;
	//	}
	//	*/
	//	ifs.close();
	//	return true;
	//}

	//static bool Write1(const std::string& name, const std::string& body, int64_t range_start, int64_t range_end) // 0 - 99
	//{
	//	FILE* fp = NULL;
	//	fopen_s(&fp, name.c_str(), "wb+");
	//	if (fp == NULL)
	//	{
	//		std::cerr << "文件打开失败\n";
	//		return false;
	//	}
	//	//fseek(fp, offset, SEEK_SET);
	//	//int dis = range_end - range_start + 1;
	//	int ret = fwrite(body.c_str(), 1, body.size() , fp);
	//	if (ret != range_end - range_start + 1);
	//	{
	//		std::cerr << "向文件中写入数据失败\n";
	//		fclose(fp);
	//		return false;
	//	}
	//	fclose(fp);
	//	return true;
	//}
	static bool Write(const std::string& name, const std::string& body, int offset = 0)
	{
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "ab+");
		if (fp == NULL)
		{
			std::cerr << "文件打开失败\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fwrite(body.c_str(), 1, body.size(), fp);
		if (ret != body.size())
		{
			std::cerr << "向文件中写入数据失败\n";
			fclose(fp);
			return false;
		}
		
		fclose(fp);
		return true;
		//std::ofstream ofs(name);
		//if (ofs.is_open() == false)
		//{
		//	std::cerr << "打开文件失败\n";
		//	return false;
		//}
		//ofs.seekp(offset, std::ios::beg);//读写位置跳转到相对文件起始位置开始偏移量为offset的偏移量
		//ofs.write(&body[0], body.size());
		//if (ofs.good() == false)
		//{
		//	std::cerr << "向文件中写入数据失败\n";
		//	ofs.close();
		//	return false;
		//}
		//ofs.close();
		//return true;
	}
	//指针型参数表示是一个输出型参数(修改的参数)
	//const& 这是一个输入型的参数(不可修改的参数)
	//& 表示这是一个输入输出型的参数(可以修改也可以不修改)
	static bool Read(const std::string& name, std::string* body)
	{
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		std::cout << "读取文件数据：" << name << "size" << filesize << "\n";
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "rb");
		if (fp == NULL)
		{
			std::cerr << "打开文件失败\n";
			return false;
		}
		int ret = fread(&(*body)[0], 1, filesize, fp);
		if (ret != filesize)
		{
			std::cerr << "从文件读取数据失败\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return  true;
		//std::ifstream ifs(name);                                      //ifstream和ofstream类都是对文件进行操作的类，ifstream类里面有read接口，ofstream类里面有write接口，
		//															  //为什么ifstream类叫输入类，它不是read读数据吗？？ 
		//if (ifs.is_open() == false)
		//{
		//	std::cerr << "打开文件失败\n";
		//	return false;
		//}
		//int64_t filesize = boost::filesystem::file_size(name);//获取文件大小
		//body->resize(filesize);
		//ifs.read(&(*body)[0], filesize);
		//if (ifs.good() == false)
		//{
		//	std::cerr << "读取文件失败" << std::endl;
		//	ifs.close();
		//	return false;
		//}
		//ifs.close();
		//return true;
	}
	static bool ReadRange(const std::string& name, std::string* body, int len, int offset)//文件名，输出的，数据长度，从哪里开始读取数据
	{
		body->resize(len);
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(),"rb");
		if (fp == NULL)
		{
			std::cerr << "！！！打开文件失败\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fread(&(*body)[0], 1, len, fp);
		if (ret != len)
		{
			std::cerr << "从文件中读取数据失败\n" << std::endl;
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
	}
	static bool GetRange(const std::string& range_str, int* start, int *end)
	{
		size_t pos1 = range_str.find('-');
		size_t pos2 = range_str.find('=');
		*start = std::atol(range_str.substr(pos2 + 1, pos1 - pos2 - 1).c_str());
		std::cout << "range_str.substr(pos1 + 1, pos1 - pos2 - 1):" << range_str.substr(pos1 + 1, pos1 - pos2 - 1) << std::endl;
		*end = std::atol(range_str.substr(pos1 + 1).c_str());
		std::cout << "range_str.substr(pos1 + 1):" << range_str.substr(pos1 + 1) << std::endl;
		return true;
	}

};
class Adapter  // 网络适配器的一个类    
{
public:
	uint32_t _ip_addr;   // 网卡上的IP地址               网络字节序的
	uint32_t _mask_addr; // 网卡上的子网掩码             网络字节序的
};

class AdapterUtil //工具类 网络适配器
{
public:
#ifdef _WIN32
	//windows下的获取网卡信息实现
	static bool GetAllAdapter(std::vector<Adapter>* list) //为了外部的使用，使用静态全局
	{
		//IP_ADAPTER_INFO windows下存放网卡信息的结构体
		// PIP_ADAPTER_INFO 说明它是一个指针结构
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();           //new了一个网卡信息对象，只在堆上获取一个对象空间
		//  GetAdaptersinfo win下获取网卡信息的接口--网卡信息可能有多个，
		// 因此传入一个指针。针对网卡信息，来创建空间，填入网卡信息

		// 获取网卡信息有可能会失败，因为空间不足，因此有一个输出型参数,
		// 用于向用户返回到底有多少个网卡信息，用于获取实际所有的的网卡信息所占空间大小
		uint64_t all_adapter_size = sizeof(PIP_ADAPTER_INFO);//所有网卡信息的大小，现在是只有一块对象空间。
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);  //无符号32位  ， 将网络卡信息拷贝到p_apdoter空间中    
		if (ret == ERROR_BUFFER_OVERFLOW)//缓冲区溢出，一个对象空间不够放，重新new一段对象空间
		{
			//重新给指针申请空间

			delete p_adapters;//先释放原有的对象空间

			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];//重新申请空间
			// BYTE : unsigned char 
			// 就是
			GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);//重新获取网卡信息
		}
		while (p_adapters) // 链表
		{
			Adapter adapter; //实例化对象  ip地址,子网掩码

			//inet_addr 只能转换ipv4地址结构的地址 在这里不完全， 要用inet_pton
			//inet_pton 将一个字符串点分十进制的ip地址转换为网络字节序ip地址
			// inet_pton(int family, char* string, void* buf)
			// family: AF_INET 使用ipv4地址结构 AF_INET6是ipv6
			// string: 字符串点分十进制的ip地址
			// buf: 一块缓冲区,用于接收转换后的网络字节序ip地址


			// inet_addr 只能转换ipV4的网络接口 不安全，所以要用inet_pton
			//adapter._ip_addr = inet_addr(p_adapters->IpAddressList.IpAddress.String); //char类型的
			//adapter._mask_addr = inet_addr(p_adapters->IpAddressList.IpMask.String);

			inet_pton(AF_INET, p_adapters->IpAddressList.IpAddress.String, &adapter._ip_addr); //char类型的              //在这里为什么要转换成大端？
			inet_pton(AF_INET, p_adapters->IpAddressList.IpMask.String, &adapter._mask_addr);
			if (adapter._ip_addr != 0) //因为有些网卡并没有启用，导致ip地址为0
			{
				list->push_back(adapter); //将网卡信息添加到vector中返回给用户

			    std::cout << "网卡名称" << p_adapters->AdapterName << std::endl;
				std::cout << "网卡描述" << p_adapters->Description << std::endl;
				std::cout << "IP地址"  << p_adapters-> IpAddressList.IpAddress.String << std::endl;
				std::cout << "子网掩码" << p_adapters->IpAddressList.IpMask.String << std::endl;
				std::cout << std::endl;
			}
			p_adapters = p_adapters->Next;	 
		}
		delete p_adapters;
		return true;
	}
#else
	//linux下获取网卡信息的接口
	bool GetAllAdater(std::vector<Adapter>* list)
	{
		return true;
	}
#endif



};