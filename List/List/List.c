#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

LTNode* ListInit()
{
	//哨兵位头节点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* tail = phead->prev;
	//LTNode* newnode = BuyListNode(x);


	////phead               tail  newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	ListInsert(phead, x);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	//LTNode* tail = phead->prev->prev;
	//free(phead->prev);
	//tail->next = phead;
	//phead->prev = tail;

	ListErase(phead->prev);
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->next;

	//phead->next = newnode;
	//newnode->prev = phead;

	//newnode->next = next;
	//next->prev = newnode;

	ListInsert(phead->next, x);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	//LTNode* next = phead->next->next;
	//free(phead->next);
	//phead->next = next;
	//next->prev = phead;

	ListErase(phead->next);
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

//pos位置之前插入
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	// posPrev  newnode  pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;

}

//删除pos位置
void ListErase(LTNode* pos)
{
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}