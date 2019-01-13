#include "SinglyLinkedList.h"
#include "Hashtable.h"
#include <Windows.h>
#include <cstdio>

bool Hashtable::Bucket::Insert(char * chKey, char * chValue)
{
	stSLOT* stSLOT_New = new stSLOT;
	strcpy_s(stSLOT_New->chKey, chKey);
	strcpy_s(stSLOT_New->chValue, chValue);

	if(push_front(&stSLOT_New))
		return true;
	return false;
}

bool Hashtable::Bucket::Delete(char * chKey)
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

void Hashtable::Bucket::Print()
{
	stNODE* pNode = _pHead->pNext;
	while (pNode != nullptr)
	{
		printf(" > ID : %s | Name : %s", pNode->Data->chKey, pNode->Data->chValue);
		pNode = pNode->pNext;
	}
}

bool Hashtable::Bucket::SearchKey(char * chKey, stSLOT * chOutAccount)
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


bool Hashtable::Bucket::SearchValue(char * chValue, stSLOT * chOutAccount)
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

void Hashtable::Bucket::Hashing(char * szString, int * OutHashCode)
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

Hashtable::Hashtable(int iHashTable_Cnt)
{
	_iHashTable_Cnt = iHashTable_Cnt;
	for (int i = 0; i < _iHashTable_Cnt; ++i)
	{
		_pBucket[i] = new Bucket;
	}
}

Hashtable::~Hashtable()
{
	for (int i = 0; i < _iHashTable_Cnt; ++i)
	{
		delete _pBucket[i];
	}
}

bool Hashtable::Insert(char* szInID, size_t iIDLen, char* szInName, size_t iNameLen)
{
	int iHashCode;

	if (!Trim(szInID, iIDLen))
		return false;

	if (!Trim(szInName, iNameLen))
		return false;

	Bucket::Hashing(szInID, &iHashCode);
	if (_pBucket[iHashCode]->SearchKey(szInID))
		return false;

	for (int i = 0; i < df_BUCKET_CNT; ++i)
	{
		if (_pBucket[i]->SearchValue(szInName))
			return false;
	}

	return _pBucket[iHashCode]->Insert(szInID, szInName);
}

bool Hashtable::Delete(char* szInID)
{
	int iHashCode;
	Bucket::Hashing(szInID, &iHashCode);
	return _pBucket[iHashCode]->Delete(szInID);
}

void Hashtable::Print()
{
	for (int i = 0; i < 10; ++i)
	{
		printf("\n [%02d]", i);
		_pBucket[i]->Print();
	}
	printf("\n");
}

bool Hashtable::Search(char* szInID)
{
	int iHashCode;
	Bucket::Hashing(szInID, &iHashCode);

	stSLOT pAccount;
	if (_pBucket[iHashCode]->SearchKey(szInID, &pAccount))
	{
		printf(" Name : %s\n", pAccount.chValue);
		return true;
	}

	return false;
}

bool Hashtable::Trim(char* szString, size_t iSize)
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

