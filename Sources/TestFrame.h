#ifndef TEST_FRAME_H
#define TEST_FRAME_H

#include <vector>
#include <iostream>                                                                
#include <memory>                                                                

using namespace std;  

typedef void(*RegisterTestFunction)();


/*
ע�������Ĳ��������Ƿ���������ʹ�õ�ʱ��
��������Ŀ����Ϊ���ú�����ܺ������RS���к��##���ӣ��γ�һ������
�������ﴫ�����һ�������������ں��������&��ȡ����������ĵ�ַ��
�Ӷ����һ������ָ�룬��RegisterStruct����ʵ����
void ReflectionSystemTest()
{
}
RegisterStructTestFunction2(ReflectionSystemTest)

*/
#define RegisterStructTestFunction2(RegisterTestFunction) \
	RegisterStruct RegisterTestFunction##RS(&RegisterTestFunction);


#define RegisterStructTestFunction(RegisterTestFunction) \
	RegisterStruct FunctionName##RS(RegisterTestFunction);


//#define REGISTER_TEST_FUN(funcion) gRegisterFunction()

//RegisterFunction* RegisterFunction::instace = nullptr;

class RegisterFunction
{
public:
	//static RegisterFunction* instace = nullptr;
public:
	RegisterFunction() {}

	static RegisterFunction* GetInstance()
	{

		static RegisterFunction instace;
		//if (instace == nullptr)
			//instace = new RegisterFunction();
		return &instace;
	}

	void RunAllRegisterFunction()
	{
		for (int i = 0; i < RegisterTestFunctionArray.size(); i++)
		{
			RegisterTestFunction func = RegisterTestFunctionArray[i];
			func();
		}
	}

	void RegisterFun(RegisterTestFunction inFunction)
	{
		RegisterFunction* instace = RegisterFunction::GetInstance();

		//RegisterFunction::GetInstance()->RegisterTestFunctionArray
		instace->RegisterTestFunctionArray.push_back(inFunction);
	}

	
private:

	struct FunctionNode
	{
		RegisterTestFunction fun;
		FunctionNode* next;

		FunctionNode()
		{
			fun = nullptr;
			next = nullptr;
		}
	};


	//static 
	vector<RegisterTestFunction> RegisterTestFunctionArray;
	FunctionNode RegisterTestFunctionLink;

	//shared_ptr<vector<RegisterTestFunction>> RegisterTestFunctionArray{make_shared<vector<RegisterTestFunction>>()};  
	//vector<RegisterTestFunction> RegisterTestFunctionArray;
};

struct RegisterStruct
{
	RegisterStruct(RegisterTestFunction func)
	{
		RegisterFunction::GetInstance()->RegisterFun(func);
	}
};

//RegisterFunction* gRegisterFunction = RegisterFunction::GetInstance();



/*
ʹ�õ�ʱ��
#include "TestFrame.h"

void Test()
{
	cout << "sdfsdf"<<endl;
}

RegisterStruct testRegister(&Test);

*/





/*

RegisterStruct::RegisterStruct(RegisterTestFunction func)
{
	RegisterFunction::GetInstance()->RegisterFun(func);
}
*/


//RegisterFunction* RegisterFunction::instace = RegisterFunction::GetInstance();

//vector<RegisterTestFunction> RegisterFunction::RegisterTestFunctionArray;
/*

RegisterFunction::RegisterFunction()
{
	
}



void RegisterFunction::RegisterFun(RegisterTestFunction inFunction)
{
	RegisterFunction* instace = RegisterFunction::GetInstance();

	//RegisterFunction::GetInstance()->RegisterTestFunctionArray
	instace->RegisterTestFunctionArray.push_back(inFunction);
}




void RegisterFunction::RunAllRegisterFunction()
{
	
	for (int i = 0; i < RegisterTestFunctionArray.size(); i++)
	{
		RegisterTestFunction func = RegisterTestFunctionArray[i];
		func();
	}
	
}
*/


#endif//end TEST_FRAME_H