#ifndef TEST_FRAME_H
#define TEST_FRAME_H

#include <vector>
#include <iostream>                                                                
#include <memory>                                                                

using namespace std;  

typedef void(*RegisterTestFunction)();


/*
注意这个宏的参数仅仅是方法的名字使用的时候
这样做的目的是为了让宏参数能和下面的RS进行宏的##连接，形成一个变量
所以这里传入的是一个函数变量，在宏里面进行&才取的这个函数的地址，
从而变成一个函数指针，供RegisterStruct进行实例化
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
使用的时候
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