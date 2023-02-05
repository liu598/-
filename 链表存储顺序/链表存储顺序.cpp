#include<stdio.h>
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;

void CreatList_H(LinkList& L, int n)
{
	int i;
	LNode* p;
	L = new LNode;
	L->next = NULL;
	for (i = 0; i < n; ++i)
	{
		p = new LNode;
		scanf("%d", &p->data);
		p->next = L->next; L->next = p;
	}
}

Status ListInsert(LinkList& L, int i, int e)
{
	LNode* p;
	LNode* s;
	int j;
	p = L, j = 0;
	while (p && (j < i - 1))
	{
		p = p->next; ++j;
	}
	if (!p || j > i - 1) return ERROR;
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList& L, int i)
{
	LNode* p, * q;
	int j;
	p = L; j = 0;
	while ((p->next) && (j < i - 1))
	{
		p = p->next; ++j;
	}
	if (!(p->next) || (j > i - 1)) return ERROR;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

Status GetElem(LinkList L, int i, int& e)
{
	LNode* p;
	int j;
	p = L->next; j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}

LNode* LocateElem(LinkList L, int e)
{
	LNode* p;
	p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}

void main()
{
	LinkList L;
	LNode* p;
	int n, i, j, k, e;

	printf("请输入初始状态的元素个数：\n");
	scanf("%d", &n);
	while (n < 1)
	{
		printf("元素个数n小于1，请重新输入：\n");
		scanf("%d", &n);
	}
	printf("请依次输入%d个元素（逆序）：\n", n);//前插法
	CreatList_H(L, n);
	//printf("请依次输入%d个元素：\n",n);//后插法
	//CreatList_R(L,n);
	printf("链表中的原始数据为：\n");
	p = L->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");

	printf("请输入在链表中插入数据的位置i：\n");
	scanf("%d", &i);
	printf("请输入要插入的数据：\n");
	scanf("%d", &e);
	ListInsert(L, i, e);
	printf("在链表的第%d个位置插入%d后的结果：\n", i, e);
	p = L->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");

	printf("请输入在链表中删除数据的位置j：\n");
	scanf("%d", &j);
	ListDelete(L, j);
	printf("删除链表的第%d个元素后的结果：\n", j);
	p = L->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");

	printf("请输入在链表中获取数据的位置k：\n");
	scanf("%d", &k);
	if (GetElem(L, k, e))
		printf("链表的第%d个元素是%d。\n", k, e);
	else
		printf("取值失败。\n");

	printf("请输入在链表中查找的数据e：\n");
	scanf("%d", &e);
	if (LocateElem(L, e))
		printf("查找成功。\n");
	else
		printf("查找失败。\n");
}