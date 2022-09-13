#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define N 1000
//typedef int SLDataType;
//
//// ��̬˳���
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;// ��ʾ�����д洢�˶��ٸ�����
//}SL;
//
//// �ӿں��� -- ��������Ǹ���STL�ߵģ��������ѧϰSTL
//void SeqListInit(SL* ps, SLDataType x);
//
//// ��̬�ص㣺������˾Ͳ��ò��� ȱ�㣺�����Ŀռ�����أ��������ȷ��
//// N��С�˲����ã�N�������˷�
//void SeqListPushBack(SL* ps, SLDataType x);
//void SeqListPopBack(SL* ps);
//void SeqListPushFront(SL* ps, SLDataType x);
//void SeqListPopFront(SL* ps);
//// ...


typedef int SLDataType;

// ��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;// ��ʾ�����д洢�˶��ٸ�����
	int capacity;// ����ʵ���ܴ����ݵĿռ������Ƕ��
}SL;


// �ӿں��� -- ��������Ǹ���STL�ߵģ��������ѧϰSTL
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
// ...

//�ҵ��˷���xλ���±꣬û���ҵ�����-1
int SeqListFind(SL* ps, SLDataType x);
//ָ��pos�±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos);