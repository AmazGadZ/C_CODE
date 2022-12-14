#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 20);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 2, 30);
	SeqListPrint(&sl);

	int pos = SeqListFind(&sl, 4);
	if (pos != -1)
	{
		SeqListInsert(&sl, pos, 40);
	}
	SeqListPrint(&sl);

	SeqListInsert(&sl, 0, -1);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 8, 80);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList4()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListErase(&sl, 1);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);


	int pos = SeqListFind(&sl, 3);
	if (pos != -1)
	{
		SeqListErase(&sl, pos);
	}
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

//??????????????????????
void Menu()
{
	printf("******************************************\n");
	printf("??????????????:>\n");
	printf("1. ????  2. ????\n");
	printf("3. ????  4. ????\n");
	printf("5. ????  -1. ????\n");
	//...
	printf("******************************************\n");
	
}

//????????????????????????????????????????
//????????????????????????????????????????????????????????
void MenuTest()
{
	SL sl;
	SeqListInit(&sl);
	int x;
	int input = 0;
	while (input != -1)
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("????????????????????????-1??????");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushFront(&sl, x);
				scanf("%d", &x);
			}
			break;
		case 2:
			SeqListPopFront(&sl);
			break;
		case 3:
			printf("????????????????????????-1??????");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushBack(&sl, x);
				scanf("%d", &x);
			}
			break;
		case 4:
			SeqListPopBack(&sl);
			break;
		case 5:
			SeqListPrint(&sl);
			break;
		case -1:
			break;
		default:
			printf("????????????????????\n");
			break;
		}
	}

	SeqListDestroy(&sl);
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	MenuTest();

	return 0;
}