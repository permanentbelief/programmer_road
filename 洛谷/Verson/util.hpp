#pragma once

// ����ͷ�ļ�
#include <stdint.h>
#include <iostream>
#include <vector>

#include<fstream>

#ifdef _WIN32           // windows ͷ�ļ�
#include <WinSock2.h>   // hton()  ��ϵ��ת��ip��ַ�����ֽ����������ֽ����ת���ӿ�
#include <WS2tcpip.h>
#include <IPHlpApi.h>   // ��ȡ������Ϣ�ӿڵ�ͷ�ļ�

#include <sstream>
#pragma comment(lib, "Iphlpapi.lib") // ��ȡ������Ϣ�ӿڵ� ���ļ�
#pragma comment(lib, "ws2_32.lib")   // windows�µ�socket�� inet_pton

#else
//linux�µ�ͷ�ļ�
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

//�ļ����������࣬Ŀ����Ϊ�����ⲿֱ��ʹ���ļ������ӿڼ��ɡ�
//�ú����ļ������������޸ģ���ֻ��Ҫ�޸��ļ����������༴�ɣ�����Ҫ��ԭ�Ľ��иı䡣
class FileUtil
{
public:

	static int64_t GetFileSize(const std::string&name)
	{
		return boost::filesystem::file_size(name);
	}
	//Write��ָ���ļ���ָ��λ��д��ָ������
	/*
	Ѹ���еĲ����ǣ������ڲ�ͬ���������в�ͬ�����ݣ������ʵ�֣���ͬ���������Ͳ�ͬ�ֶ��������ݣ�
	��ÿһ������Ҫһ���ֶΡ� ���� A����Ҫfile�ļ�������Ҫ ��B����Ҫȡ(20-100), ��C����Ҫȡ��100-200��
	*/
	//static bool Write(const std::string& name, const std::string& body, int64_t offset = 0)
	//{
	//	std::ofstream ofs(name); //������ݵ�ʵ���������൱�ڴ��ļ�,�������򴴽�
	//	if (ofs.is_open() == false)
	//	{
	//		std::cout << "���ļ�ʧ��" << std::endl;
	//	}
	//	ofs.seekp(offset,std::ios::beg); // ��������  seekp(uint32_t offset,std::ios::beg);��ʼλ��
	//	ofs.write(&body[0],body.size()); //����������ofs.write(const char* body,size_t len);

	//	if (ofs.good() == false)
	//	{
	//		std::cout << "���ļ�д������ʧ��" << std::endl;
	//		return false;
	//	}
	//	ofs.close();
	//}

	//static bool Read(const std::string & name, std::string *body)
	//{
	//	std::ifstream ifs(name);
	//	if (ifs.is_open() == false)
	//	{
	//		std::cout << "���ļ�ʧ��" << std::endl;
	//		return false;
	//	}
	//	int64_t filesize = boost::filesystem::file_size(name);
	//	body->resize(filesize);
	//	ifs.read(&(*body)[0], filesize);
	//	/*
	//	if (ifs.good == false)
	//	{
	//		std::cout << "��ȡ�ļ�ʧ��" << std::endl;
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
	//		std::cerr << "�ļ���ʧ��\n";
	//		return false;
	//	}
	//	//fseek(fp, offset, SEEK_SET);
	//	//int dis = range_end - range_start + 1;
	//	int ret = fwrite(body.c_str(), 1, body.size() , fp);
	//	if (ret != range_end - range_start + 1);
	//	{
	//		std::cerr << "���ļ���д������ʧ��\n";
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
			std::cerr << "�ļ���ʧ��\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fwrite(body.c_str(), 1, body.size(), fp);
		if (ret != body.size())
		{
			std::cerr << "���ļ���д������ʧ��\n";
			fclose(fp);
			return false;
		}
		
		fclose(fp);
		return true;
		//std::ofstream ofs(name);
		//if (ofs.is_open() == false)
		//{
		//	std::cerr << "���ļ�ʧ��\n";
		//	return false;
		//}
		//ofs.seekp(offset, std::ios::beg);//��дλ����ת������ļ���ʼλ�ÿ�ʼƫ����Ϊoffset��ƫ����
		//ofs.write(&body[0], body.size());
		//if (ofs.good() == false)
		//{
		//	std::cerr << "���ļ���д������ʧ��\n";
		//	ofs.close();
		//	return false;
		//}
		//ofs.close();
		//return true;
	}
	//ָ���Ͳ�����ʾ��һ������Ͳ���(�޸ĵĲ���)
	//const& ����һ�������͵Ĳ���(�����޸ĵĲ���)
	//& ��ʾ����һ����������͵Ĳ���(�����޸�Ҳ���Բ��޸�)
	static bool Read(const std::string& name, std::string* body)
	{
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		std::cout << "��ȡ�ļ����ݣ�" << name << "size" << filesize << "\n";
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "rb");
		if (fp == NULL)
		{
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		int ret = fread(&(*body)[0], 1, filesize, fp);
		if (ret != filesize)
		{
			std::cerr << "���ļ���ȡ����ʧ��\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return  true;
		//std::ifstream ifs(name);                                      //ifstream��ofstream�඼�Ƕ��ļ����в������࣬ifstream��������read�ӿڣ�ofstream��������write�ӿڣ�
		//															  //Ϊʲôifstream��������࣬������read�������𣿣� 
		//if (ifs.is_open() == false)
		//{
		//	std::cerr << "���ļ�ʧ��\n";
		//	return false;
		//}
		//int64_t filesize = boost::filesystem::file_size(name);//��ȡ�ļ���С
		//body->resize(filesize);
		//ifs.read(&(*body)[0], filesize);
		//if (ifs.good() == false)
		//{
		//	std::cerr << "��ȡ�ļ�ʧ��" << std::endl;
		//	ifs.close();
		//	return false;
		//}
		//ifs.close();
		//return true;
	}
	static bool ReadRange(const std::string& name, std::string* body, int len, int offset)//�ļ���������ģ����ݳ��ȣ������￪ʼ��ȡ����
	{
		body->resize(len);
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(),"rb");
		if (fp == NULL)
		{
			std::cerr << "���������ļ�ʧ��\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fread(&(*body)[0], 1, len, fp);
		if (ret != len)
		{
			std::cerr << "���ļ��ж�ȡ����ʧ��\n" << std::endl;
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
class Adapter  // ������������һ����    
{
public:
	uint32_t _ip_addr;   // �����ϵ�IP��ַ               �����ֽ����
	uint32_t _mask_addr; // �����ϵ���������             �����ֽ����
};

class AdapterUtil //������ ����������
{
public:
#ifdef _WIN32
	//windows�µĻ�ȡ������Ϣʵ��
	static bool GetAllAdapter(std::vector<Adapter>* list) //Ϊ���ⲿ��ʹ�ã�ʹ�þ�̬ȫ��
	{
		//IP_ADAPTER_INFO windows�´��������Ϣ�Ľṹ��
		// PIP_ADAPTER_INFO ˵������һ��ָ��ṹ
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();           //new��һ��������Ϣ����ֻ�ڶ��ϻ�ȡһ������ռ�
		//  GetAdaptersinfo win�»�ȡ������Ϣ�Ľӿ�--������Ϣ�����ж����
		// ��˴���һ��ָ�롣���������Ϣ���������ռ䣬����������Ϣ

		// ��ȡ������Ϣ�п��ܻ�ʧ�ܣ���Ϊ�ռ䲻�㣬�����һ������Ͳ���,
		// �������û����ص����ж��ٸ�������Ϣ�����ڻ�ȡʵ�����еĵ�������Ϣ��ռ�ռ��С
		uint64_t all_adapter_size = sizeof(PIP_ADAPTER_INFO);//����������Ϣ�Ĵ�С��������ֻ��һ�����ռ䡣
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);  //�޷���32λ  �� �����翨��Ϣ������p_apdoter�ռ���    
		if (ret == ERROR_BUFFER_OVERFLOW)//�����������һ������ռ䲻���ţ�����newһ�ζ���ռ�
		{
			//���¸�ָ������ռ�

			delete p_adapters;//���ͷ�ԭ�еĶ���ռ�

			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];//��������ռ�
			// BYTE : unsigned char 
			// ����
			GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);//���»�ȡ������Ϣ
		}
		while (p_adapters) // ����
		{
			Adapter adapter; //ʵ��������  ip��ַ,��������

			//inet_addr ֻ��ת��ipv4��ַ�ṹ�ĵ�ַ �����ﲻ��ȫ�� Ҫ��inet_pton
			//inet_pton ��һ���ַ������ʮ���Ƶ�ip��ַת��Ϊ�����ֽ���ip��ַ
			// inet_pton(int family, char* string, void* buf)
			// family: AF_INET ʹ��ipv4��ַ�ṹ AF_INET6��ipv6
			// string: �ַ������ʮ���Ƶ�ip��ַ
			// buf: һ�黺����,���ڽ���ת����������ֽ���ip��ַ


			// inet_addr ֻ��ת��ipV4������ӿ� ����ȫ������Ҫ��inet_pton
			//adapter._ip_addr = inet_addr(p_adapters->IpAddressList.IpAddress.String); //char���͵�
			//adapter._mask_addr = inet_addr(p_adapters->IpAddressList.IpMask.String);

			inet_pton(AF_INET, p_adapters->IpAddressList.IpAddress.String, &adapter._ip_addr); //char���͵�              //������ΪʲôҪת���ɴ�ˣ�
			inet_pton(AF_INET, p_adapters->IpAddressList.IpMask.String, &adapter._mask_addr);
			if (adapter._ip_addr != 0) //��Ϊ��Щ������û�����ã�����ip��ַΪ0
			{
				list->push_back(adapter); //��������Ϣ��ӵ�vector�з��ظ��û�

			    std::cout << "��������" << p_adapters->AdapterName << std::endl;
				std::cout << "��������" << p_adapters->Description << std::endl;
				std::cout << "IP��ַ"  << p_adapters-> IpAddressList.IpAddress.String << std::endl;
				std::cout << "��������" << p_adapters->IpAddressList.IpMask.String << std::endl;
				std::cout << std::endl;
			}
			p_adapters = p_adapters->Next;	 
		}
		delete p_adapters;
		return true;
	}
#else
	//linux�»�ȡ������Ϣ�Ľӿ�
	bool GetAllAdater(std::vector<Adapter>* list)
	{
		return true;
	}
#endif



};