#pragma once
#include "TestFrame.h"

#include <iostream>
#include <cstring>
using namespace std;



char* myStrCpy(char* dest,const char* src)
{
	if (dest == nullptr || src == nullptr)
	{
		return nullptr;
	}

	if (dest == src)
	{
		return dest;
	}

	int index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return dest;
}


class String 
{
private:
	char* data;

public:
	char& operator[](int index)
	{
		return const_cast<char&>(static_cast<const String&>(*this)[index]);
	}


	const char& operator[](int index) const 
	{
		return data[index];
	}


	char* GetChars() const
	{
		return data;
	}

	~String(void)
	{
		if (data)
		{
			delete[] data;
		}
		
	}

	String():data(nullptr) {}

	String(const char* _data)
	{
		if (_data == nullptr)
		{
			data = new char[1];
			data[0] = '\0';
		}
		else 
		{
			int len = strlen(_data);
			data = new char[len + 1];
			strcpy(data, _data);
		}
	}

	String(const String& other)
	{
		if (&other)
		{
			data = new char[strlen(other.data) + 1];
			strcpy(data, other.data);
		}
	}

	String& operator=(const String& other)
	{
		if (&other)
		{
			//这里需要使用指针的方式来进行访问，不能使用引用的方式。
			if (this == &other)
			{
				return *this;
			}
			else 
			{
				if (data)
				{
					delete[] data;
				}

				data = new char[strlen(other.data) + 1];
				strcpy(data, other.data);
				return *this;
			}
		}
	}


	friend String operator+(const String& other1,const String& other2);
};

String operator+(const String& other1, const String& other2)
{
	int len = strlen(other1.data) + strlen(other2.data);
	char* data = new char[len +1];
	int index = 0;
	int DesIndex = 0;
	while (other1.data[index] != '\0')
	{
		data[DesIndex++] = other1.data[index++];
	}

	index = 0;
	while (other2.data[index] != '\0')
	{
		data[DesIndex++] = other2.data[index++];
	}
	data[DesIndex] = '\0';

	return String(data);
}


int StrToInt(string str) {
		int flag = 1;
		int num = 0;
		if (str.size() == 0) return 0;
		if (str[0] == '-') flag = -1;
		for (int i = (str[0] == '+' || str[0] == '-') ? 1 : 0; i < str.size(); i++)
		{
			if (!(str[i] >= '0' && str[i] <= '9')) return 0;
			num = num * 10 + str[i] - '0';
		}
		return num*flag;
	}


void FStringTest()
{
	
	char* p = const_cast<char*>("w3er2");
	String a(p);

	char* p2 = const_cast<char*>("w3er");
	String a2(p2);
	
	String a3;
	a3 = a + a2;

	cout << a.GetChars() << endl;
	cout << a2.GetChars() << endl;
	cout << a3.GetChars() << endl;
	

	char* des = new char[10];
	myStrCpy(des, p2);
	cout << des << endl;
}

//RegisterStruct RegisterFStringTest(&FStringTest);