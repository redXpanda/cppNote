﻿// cppNote.cpp: 定义应用程序的入口点。
//

#include "cppNote.h"
#include <vector>

using namespace std;




vector<char> makeAllCards()
{
	vector<char> out;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			char cCard1 = getCardServerID(j, i);

			out.push_back(cCard1);
		}
	}

	return out;
}

vector<char> makeOneHandCards(vector<char> allCards)
{
	shuffle(allCards.begin(), allCards.end());

	vector<char> out;
	for (int i=0; i<13; i++)
	{
		out.push_back(allCards[i]);
	}

	return out;

}

char getCardServerID(char cVal, char cType)
{
	return  cVal | (cType << 4);
}

int getCardType(char cCard)
{
	int iType = cCard >> 4;
	//int iValue = (cCard & 0xf);
	return iType;
}


struct CardCountInfo
{
	int iType;
	int iCount;
};
bool cciSort(CardCountInfo cci1, CardCountInfo cci2)
{
	return cci1.iCount < cci2.iCount;
}

vector<char> autoGetExchangeCards(vector<char> vccCards)
{



	vector<int> vcTypeCount = { 0,0,0 };

	for (int i = 0; i < vcTypeCount.size(); i++)
	{
		vcTypeCount[getCardType(vccCards[i])] ++;
	}


	CardCountInfo cci[3];

	for (int i = 0; i < 3; i++)
	{
		cci[i].iCount = vcTypeCount[i];
		cci[i].iType = i;
	}

	vector<CardCountInfo> vccci;
	for (int i = 0; i < 3; i++)
	{
		vccci.push_back(cci[i]);
	}


	int whileCount = 0;
	do
	{
		if (vccci[whileCount].iCount < 3)
		{
			vccci.erase(vccci.begin() + whileCount);
		}
		else
		{
			whileCount++;
		}

	} while (whileCount >= vccci.size());


	sort(vccci.begin(), vccci.end(), cciSort);
	int rType = vccci[0].iType;

	vector<char> vcSelected;


	for (int i = 0; i < vcTypeCount.size(); i++)
	{
		if (getCardType(vcTypeCount[i]) == rType)
		{
			vcSelected.push_back(vcTypeCount[i]);
			if (vcSelected.size() == 3)
			{
				return vcSelected;
			}
		}
	}






	int a = 0;

	return vcSelected;
}


int main()
{
	cout << "Hello CMake。" << endl;

	vector<char> allCards = makeAllCards();


	for (int i=0; i<10000; i++)
	{
		auto handCards = makeOneHandCards(allCards);

		auto excards = autoGetExchangeCards(handCards);


		std::ostringstream oss;
		oss << "ex[" << excards[0] << excards[1] << excards[2] << "]" << endl;

	}


	return 0;
}
