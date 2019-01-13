#ifndef __HASH_H__
#define __HASH_H__
#include "SinglyLinkedlist.h"
#include "Config.h"

class Hashtable
{
protected:
	struct stSLOT
	{
		char chKey[df_LEN_MAX];		// ID
		char chValue[df_LEN_MAX];	// NAME
	};

	class Bucket : protected Linkedlist<stSLOT*>
	{
	public:
		Bucket() {}
		virtual ~Bucket() {}

		bool Insert(char* chKey, char* chValue);
		bool Delete(char* chKey);

		void Print();
		bool SearchKey(char* chKey, stSLOT * chOutAccount = nullptr);
		bool SearchValue(char* chValue, stSLOT * chOutAccount = nullptr);

	private:
		friend class Hashtable;
		// TODO: ID의 ASCII의 총합을 시드값으로 사용. 출력값을 리스트의 인덱스로 사용
		static void Hashing(char* szString, int *OutHashCode);
	};

public:
	Hashtable(int iHashTable_Cnt = df_HASHTABLE_CNT);
	virtual ~Hashtable();

	bool Insert(char* szInID, size_t iIDLen, char* szInName, size_t iNameLen);
	bool Delete(char* szInID);
	void Print();
	bool Search(char* szInID);

private:
	bool Trim(char* szString, size_t iSize);

	int _iHashTable_Cnt;
	Bucket* _pBucket[df_HASHTABLE_CNT];

};

#endif

