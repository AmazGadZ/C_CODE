#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinarytTreeNode
{
	struct BinarytTreeNode* left;
	struct BinarytTreeNode* right;
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
//void TreeSize(BTNode* root, int* psize);
int TreeSize(BTNode* root);
int TreeLeafSize(BTNode* root);
void LebelOrder(BTNode* root);
void DestroyTree(BTNode* root);