#define _CRT_SECURE_NO_WARNINGS 1

//#define MAX 1000

#define DEFAULT_SZ 3

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

enum Option
{
	EXIT,//0
	ADD,//1
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//通讯录类型
struct Contact
{
	struct PeoInfo* data;//一个管理动态开辟内存的指针
	int size;//记录当前已经有的元素个数
	int capacity;//当前通讯录的最大容量
};

//声明函数
//初始化通讯录的函数
void InitContact(struct Contact* ps);

//增加一个信息到通讯录
void AddContact(struct Contact* ps);

//打印通讯录中的信息
void ShowContact(const struct Contact* ps);

//删除指定的联系人
void DelContact(struct Contact* ps);

//查找指定的人的信息
void SearchContact(const struct Contact* ps);

//修改指定联系人
void ModifyContact(struct Contact* ps);

//排序通讯录内容
void SortContact(struct Contact *ps);

//销毁通讯录 - 释放动态开辟的内存
void DestroyContact(struct Contact* ps);

//保存文件
void SaveContact(struct Contact* ps);

//加载文件中的信息到通讯录
void LoadContact(struct Contact* ps);