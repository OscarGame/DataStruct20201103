#pragma once
#include "TestFrame.h"


vector<string> res;     //存储最终的返回结果
const string letterMap[10]{
    "",     //0 （程序运行过程中不会访问到，这里添加是为了访问letterMap的时候键盘的数字正好对应数组中的索引号）
    " ",    //1 （同上）
    "abc",  //2
    "def",  //3
    "ghi",  //4
    "jkl",  //5
    "mno",  //6
    "pqrs", //7
    "tuv",  //8
    "wxyz"  //9
};

void findCombination(const string& digits, int index, const string& s){
    if(index == digits.size()){
        //保存结果
        res.push_back(s);
        return;
    }
    char c = digits[index]; //获取字符串中的指定位置的数字
    string letters = letterMap[c -'0']; //获取上述数字对应的字母
    for(int i =0; i < letters.size(); i++){ //遍历上述数字对应字母的每种可能性，然后对之后的数字字符串递归上述操作
        findCombination(digits, index + 1, s + letters[i]);
    }

}

vector<string> letterCombinations(string digits) {
    res.clear();
    if(digits == "")
        return res;
    findCombination(digits, 0, "");
    return res;
}


void Test17()
{
	string aa = "23";
	letterCombinations(aa);
}

//RegisterStruct T17(&Test17);