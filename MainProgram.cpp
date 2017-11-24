// DataStructureForCPP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include <memory>
#include <vector>
#include <map>

#include "DataStructure.h"
#include "BSTInplementation.h"

using namespace std;


class MainProgramNeed
{
public:
	void function1(int& targetNum, string& str)
	{
		char buff[4];
		memcpy(buff, &targetNum, sizeof(int));

		for (int i = 0; i < 4; i++)
		{
			str.push_back(buff[i]);
			cout << "we push a number into char[4] ,this number is ";
			cout << targetNum << endl;
		}
		int len = str.length();
		for (int i = 0; i << len; i++)
		{
			cout << str[i] << " " << endl;
		}
	}
};

int main(void)
{
	string mystr;
	int targetNum;
	MainProgramNeed* mfn = new MainProgramNeed();
	while (true)
	{
		cin >> targetNum;

		mfn->function1(targetNum, mystr);
	}

	system("pause");
	return 0;
}

 