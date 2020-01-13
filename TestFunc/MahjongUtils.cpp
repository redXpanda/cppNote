
#include <algorithm>
#include "MahjongUtils.h"
using namespace std;



int MahjongUtils::getThisTypeCardsCountInVec(int iType, std::vector<char> cards)
{
	int iOut = 0;
	for (int i=0; i<cards.size(); i++)
	{
		if (iType == getCardType(cards[i]))
		{
			iOut++;
		}
		
	}
	
	return iOut;
}

bool MahjongUtils::isTypeEqual(const std::vector<char> &vcCards)
{
	if (vcCards.empty())
	{
		return false;
	}
	if (vcCards.size() == 1)
	{
		return true;
	}


	vector<int> vcType;
	for (int i = 0; i < vcCards.size(); i++)
	{
		int iType = getCardType(vcCards[i]);
		if (iType < 0)
		{
			return false;
		}
		else
		{
			vcType.push_back(iType);
		}

	}

	for (int i = 0; i < vcType.size() - 1; i++)
	{
		if (vcType[i] != vcType[i + 1])
		{
			return false;
		}
	}

	return true;
}

int MahjongUtils::getCardValue(char cCard)
{
	//int iType = cCard >> 4;
	//int iValue = (cCard & 0xf) - 1;
	int iValue = (cCard & 0xf);
	return iValue;
}

int MahjongUtils::getCardType(char cCard)
{
	int iType = cCard >> 4;
	//int iValue = (cCard & 0xf);
	return iType;
}

char MahjongUtils::getCardServerID(char cVal, char cType)
{
	return  cVal | (cType << 4);
}



bool MahjongUtils::isCardID_Valid(char cCard)
{
	int iVal = getCardValue(cCard);
	int iType = getCardType(cCard);

	if (iVal >=1 && iVal <= 9 && iType >= 0 && iType <= 5)
	{
		return true;
	}
	return false;
}

bool MahjongUtils::isXUSHUPAI(char cCard)
{
	int iType = getCardType(cCard);
	if (iType >=0 && iType <= 2)
	{
		return true;
	}
	return false;
}

bool MahjongUtils::isYIJIUPAI(char cCard)
{
	int iVal = getCardValue(cCard);

	if (isXUSHUPAI(cCard))
	{
		if (iVal == 1 || iVal == 9)
		{
			return true;
		}
	}


	return false;
}

int MahjongUtils::settle_cards(const std::vector<char>& hand_card, int all_cards[6][10])
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			all_cards[i][j] = 0;
		}
	}
	for (int i = 0; i < hand_card.size(); ++i)
	{
		int iType = hand_card[i] >> 4;
		int iValue = hand_card[i] & 0xf;
		all_cards[iType][0]++;
		all_cards[iType][iValue]++;
	}
	return 0;
}
//
//std::vector<char> MahjongUtils::convertBackVcc(int all_cards[6][10])
//{
//	std::vector<char> vccOut;
//	if (all_cards)
//	{
//		for (int i=0; i<6;i++)
//		{
//			if (all_cards[i][0] > 0)
//			{
//				for (int j = 1; j <= 9; j++)
//				{
//					if (all_cards[i][j] > 0)
//					{
//						int iCount = all_cards[i][j];
//						char cCard = MahjongUtils::getCardServerID(j, i);
//						vector<char> vccSameCards = UtilsMarcus::makeVecAllEqual(iCount,cCard);
//						vccOut.insert(vccOut.end(), vccSameCards.begin(), vccSameCards.end());
//					}
//				}
//			}
//			
//		}
//	}
//
//
//	return vccOut;
//}

std::string MahjongUtils::getCardName(char cCard)
{

	if (cCard <= 0)
	{
		return "INVALID_CARD";
	}

	int iType = MahjongUtils::getCardType(cCard);
	int iVal = MahjongUtils::getCardValue(cCard);

	//printf("cCard[%d], val=%d, type=%d\n", cCard, iVal, iType);

	std::string strType = "[ERROR_TYPE]";
	switch (iType)
	{
	case 0:
		strType = "WAN";
		break;
	case 1:
		strType = "TIAO";
		break;
	case 2:
		strType = "TONG";
		break;
	default:
		strType = "[ERROR_TYPE]";
		break;
	}

	//printf("strType=%s\n", strType.c_str());
	//printf("strOut=%s\n", out.c_str());
	return std::to_string(iVal) + strType;
}

std::string MahjongUtils::getCardTypeName(char cType)
{
	int iType = cType;

	std::string strType = "[ERROR_TYPE]";
	switch (iType)
	{
	case 0:
		strType = "WAN";
		break;
	case 1:
		strType = "TIAO";
		break;
	case 2:
		strType = "TONG";
		break;
	default:
		strType = "[ERROR_TYPE]";
		break;
	}
	return strType;
}

std::string MahjongUtils::getCardsName(std::vector<char> vcCards)
{
	std::string out;
	if (!vcCards.empty())
	{
		sort(vcCards.begin(), vcCards.end());
		for (int i=0; i<vcCards.size(); i++)
		{
			out += MahjongUtils::getCardName(vcCards[i]) + " ";
		}
	}

	return out;
}

