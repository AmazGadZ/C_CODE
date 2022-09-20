#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "BTree.h"

typedef BTNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

 typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	//size_t _size;
}Queue;

 void QueueInit(Queue* pq);
 void QueueDestroy(Queue* pq);
 void QueuePush(Queue* pq, QDataType x);
 void QueuePop(Queue* pq);
 QDataType QueueFront(Queue* pq);
 QDataType QueueBack(Queue* pq);
 int QueueSize(Queue* pq);
 bool QueueEmpty(Queue* pq);