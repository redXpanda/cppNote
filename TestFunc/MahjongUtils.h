#pragma once

#include <string>
#include <vector>
#include <map>

#include <stdio.h>
#include <string.h>

class MahjongUtils
{
public:

	

	static int getThisTypeCardsCountInVec(int iType,std::vector<char> cards);

	static int getCardValue(char cCard);
	static int getCardType(char cCard);

	static char getCardServerID(char cVal, char cType);


	static bool isCardID_Valid(char cCard);

	/*
	���һ���Ƶ�type�Ƿ����
	ps:û���Ʒ���false
	һ���Ʒ���true
	�������ʹ��󷵻�false
	*/
	static bool isTypeEqual(const std::vector<char> &vcCards);

	/*
	�Ƿ��������ƣ�����Ͳ��
	*/
	static bool isXUSHUPAI(char cCard);

	/*
	�Ƿ���һ����
	*/
	static bool isYIJIUPAI(char cCard);

	//�����Ƹ��ŵ���ά��������ȥ
	static int settle_cards(const std::vector<char>& hand_card, int all_cards[6][10]);

	//�Ӷ�ά����ת��Ϊ����
	//static std::vector<char> convertBackVcc(int all_cards[6][10]);


	//std::vector<int> judge_if_hu(int allPai[6][10], ResultTypeDef &resultType, int sendNum, std::map<int, int>& mapRule);

	static std::string getCardName(char cCard);
	static std::string getCardTypeName(char cType);

	static std::string getCardsName(std::vector<char> vcCards);
	
protected:
private:
};