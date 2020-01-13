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
	检查一组牌的type是否相等
	ps:没有牌返回false
	一张牌返回true
	存在类型错误返回false
	*/
	static bool isTypeEqual(const std::vector<char> &vcCards);

	/*
	是否是序数牌（万条筒）
	*/
	static bool isXUSHUPAI(char cCard);

	/*
	是否是一九牌
	*/
	static bool isYIJIUPAI(char cCard);

	//把手牌给放到二维数组里面去
	static int settle_cards(const std::vector<char>& hand_card, int all_cards[6][10]);

	//从二维数组转化为牌组
	//static std::vector<char> convertBackVcc(int all_cards[6][10]);


	//std::vector<int> judge_if_hu(int allPai[6][10], ResultTypeDef &resultType, int sendNum, std::map<int, int>& mapRule);

	static std::string getCardName(char cCard);
	static std::string getCardTypeName(char cType);

	static std::string getCardsName(std::vector<char> vcCards);
	
protected:
private:
};