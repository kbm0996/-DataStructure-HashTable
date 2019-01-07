#ifndef __SINGLYLINKEDLIST_H__
#define __SINGLYLINKEDLIST_H__

template <class DATA>
class Linkedlist {
public:
	struct stNODE
	{
		DATA Data;
		stNODE* pNext = nullptr;
	};

	Linkedlist();
	virtual ~Linkedlist();

	bool push_front(DATA* pData);
	bool pop_front();
	DATA front();

protected:
	stNODE* _pHead;
};

template <class DATA>
inline Linkedlist<DATA>::Linkedlist()
{
	_pHead = new stNODE;
}

template <class DATA>
inline Linkedlist<DATA>::~Linkedlist()
{
	while (1)
	{
		if (!pop_front())
			break;
	}

	delete _pHead;
}

template <class DATA>
bool inline Linkedlist<DATA>::push_front(DATA* pData)
{
	stNODE* pNode = new stNODE();

	///memcpy(pNode->Data, pData, sizeof(DATA));
	pNode->Data = *pData;

	pNode->pNext = _pHead->pNext;
	_pHead->pNext = pNode;

	return true;
}

template <class DATA>
bool inline Linkedlist<DATA>::pop_front()
{
	if (_pHead->pNext == nullptr)
		return false;

	stNODE* pFreeNode = _pHead->pNext;
	_pHead->pNext = pFreeNode->pNext;
	delete pFreeNode;
	return true;
}

template <class DATA>
DATA inline Linkedlist<DATA>::front()
{
	if (_pHead->pNext == nullptr)
		return NULL;
	return _pHead->pNext->Data;
}

#endif