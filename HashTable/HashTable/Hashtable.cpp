#include "SinglyLinkedList.h"
#include "Hashtable.h"
#include <Windows.h>
#include <cstdio>

bool Accountlist::Hashtable::Insert(char * chKey, char * chValue)
{
	stACCOUNT* stAccount_New = new stACCOUNT;
	strcpy_s(stAccount_New->chKey, chKey);
	strcpy_s(stAccount_New->chValue, chValue);

	if(push_front(&stAccount_New))
		return true;
	return false;
}

bool Accountlist::Hashtable::Delete(char * chKey)
{
	stNODE *pPrev = _pHead;
	stNODE *pNode = _pHead->pNext;
	
	while (pNode != nullptr)
	{
		if (strcmp(chKey, pNode->Data->chKey) == 0)
		{
			pPrev->pNext = pNode->pNext;
			delete pNode;
	
			return true;
		}
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	return false;
}

void Accountlist::Hashtable::Print()
{
	stNODE* pNode = _pHead->pNext;
	while (pNode != nullptr)
	{
		printf(" > ID : %s | Name : %s", pNode->Data->chKey, pNode->Data->chValue);
		pNode = pNode->pNext;
	}
}

bool Accountlist::Hashtable::SearchKey(char * chKey, stACCOUNT * chOutAccount)
{
	stNODE *pNode = _pHead->pNext;

	while (pNode != nullptr)
	{
		if (strcmp(pNode->Data->chKey, chKey) == 0)
		{
			if (chOutAccount != nullptr)
				*chOutAccount = *pNode->Data;
			return true;
		}
		pNode = pNode->pNext;
	}

	return false;
}


bool Accountlist::Hashtable::SearchValue(char * chValue, stACCOUNT * chOutAccount)
{
	stNODE *pNode = _pHead->pNext;

	while (pNode != nullptr)
	{
		if (strcmp(pNode->Data->chValue, chValue) == 0)
		{
			if (chOutAccount != nullptr)
				*chOutAccount = *pNode->Data;
			return true;
		}
		pNode = pNode->pNext;
	}

	return false;
}

void Accountlist::Hashtable::Hashing(char * szString, int * OutHashCode)
{
	int i = 0;
	unsigned int iHashCode = 0;

	while (szString[i] != '\0')
	{
		iHashCode += szString[i];
		++i;
	}

	*OutHashCode = iHashCode % 10;
}

Accountlist::Accountlist(int iHashTable_Cnt)
{
	_iHashTable_Cnt = iHashTable_Cnt;
	for (int i = 0; i < _iHashTable_Cnt; ++i)
	{
		_Index[i] = new Hashtable;
	}
}

Accountlist::~Accountlist()
{
	for (int i = 0; i < _iHashTable_Cnt; ++i)
	{
		delete _Index[i];
	}
}

bool Accountlist::Insert(char* szInID, size_t iIDLen, char* szInName, size_t iNameLen)
{
	int iHashCode;

	if (!Trim(szInID, iIDLen))
		return false;

	if (!Trim(szInName, iNameLen))
		return false;

	Hashtable::Hashing(szInID, &iHashCode);
	if (_Index[iHashCode]->SearchKey(szInID))
		return false;

	for (int i = 0; i < df_HASHTABLE_CNT; ++i)
	{
		if (_Index[i]->SearchValue(szInName))
			return false;
	}

	return _Index[iHashCode]->Insert(szInID, szInName);
}

bool Accountlist::Delete(char* szInID)
{
	int iHashCode;
	Hashtable::Hashing(szInID, &iHashCode);
	return _Index[iHashCode]->Delete(szInID);
}

void Accountlist::Print()
{
	for (int i = 0; i < 10; ++i)
	{
		printf("\n [%02d]", i);
		_Index[i]->Print();
	}
	printf("\n");
}

bool Accountlist::Search(char* szInID)
{
	int iHashCode;
	Hashtable::Hashing(szInID, &iHashCode);

	stACCOUNT pAccount;
	if (_Index[iHashCode]->SearchKey(szInID, &pAccount))
	{
		printf(" Name : %s\n", pAccount.chValue);
		return true;
	}

	return false;
}

bool Accountlist::Trim(char* szString, size_t iSize)
{
	if (iSize == 0)
		return false;

	for (int i = 0; i < iSize; ++i)
	{
		if (szString[i] == 9 || szString[i] == 10 || szString[i] ==  11 || szString[i] ==  12 || szString[i] == 13 || szString[i] == 32)
			return false;
	}
	return true;
}

