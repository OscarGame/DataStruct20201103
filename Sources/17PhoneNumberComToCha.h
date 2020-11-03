#pragma once
#include "TestFrame.h"


vector<string> res;     //�洢���յķ��ؽ��
const string letterMap[10]{
    "",     //0 ���������й����в�����ʵ������������Ϊ�˷���letterMap��ʱ����̵��������ö�Ӧ�����е������ţ�
    " ",    //1 ��ͬ�ϣ�
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
        //������
        res.push_back(s);
        return;
    }
    char c = digits[index]; //��ȡ�ַ����е�ָ��λ�õ�����
    string letters = letterMap[c -'0']; //��ȡ�������ֶ�Ӧ����ĸ
    for(int i =0; i < letters.size(); i++){ //�����������ֶ�Ӧ��ĸ��ÿ�ֿ����ԣ�Ȼ���֮��������ַ����ݹ���������
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