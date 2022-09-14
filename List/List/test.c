#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	//SListPopBack(&plist);

	SListPrint(plist);
}

void TestSList3()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
}

void TestSList4()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	//找
	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while(pos)
	{
		printf("第%d个pos节点：%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	//修改 3->30
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(plist);
}

void TestSList5()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);

	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	SListPrint(plist);

	pos = SListFind(plist, 4);
	if (pos)
	{
		SListInsert(&plist, pos, 40);
	}
	SListPrint(plist);
}

void TestSList6()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListDestroy(&plist);
}

//int main()
//{
//	//TestSList1();
//	//TestSList2();
//	//TestSList3();
//	//TestSList4();
//	//TestSList5();
//	TestSList6();
//	return 0;
//}

#include "List.h"

void TestList1()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	//ListPopBack(plist);
	ListPrint(plist);

}

void TestList2()
{
	LTNode* plist = ListInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListDestroy(plist);
	plist = NULL;
}

int main()
{
	//TestList1();
	TestList2();
	return 0;
}