#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	//如果没有空间或者空间不足，那么我们就扩容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	}

}

void SeqListPushBack(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);

	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);
}

void SeqListPopBack(SL* ps)
{
	//温柔处理方式
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0;
	//	ps->size--;
	//}

	//暴力处理方式
	//assert(ps->size > 0);
	//ps->size--;

	SeqListErase(ps, ps->size - 1);
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);

	////挪动数据
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);

	//挪动数据
	//int begin = 0;
	//while (begin < ps->size - 1)
	//{
	//	ps->a[begin] = ps->a[begin + 1];
	//	begin++;
	//}


	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}

	//ps->size--;

	SeqListErase(ps, 0);
}

int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//温柔的处理方式
	//if (pos > ps->size || pos < 0)
	//{
	//	printf("pos invalid\n");
	//	return;
	//}

	//粗暴的方式
	assert(pos >= 0 && pos <= ps->size);

	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	//挪动数据
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}

void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}

	ps->size--;
}