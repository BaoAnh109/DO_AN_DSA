#include "AddInclude.h"
#include "SNode.h"

void initStack(Stack& st)
{
	st.Top = NULL;
}

int isEmpty(Stack st)
{
	return (st.Top == NULL) ? 1 : 0;
}

StackNode* createStackNode(ItemType x)
{
	StackNode* p = new StackNode;
	if (p == NULL)
	{
		printf("Khong the cap phat node moi");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

int push(Stack& st, StackNode* p)
{
	if (p == NULL)
	{
		return 0;
	}
	if (isEmpty(st) == 1)
	{
		st.Top = p;
	}
	else
	{
		p->Next = st.Top;
		st.Top = p;
	}
	return 1;
}

int pop(Stack& st, ItemType& x)
{
	if (isEmpty(st) == 1)
		return 0;
	StackNode* p = st.Top;
	st.Top = st.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}

int deleteAfter(Stack& st, StackNode* q, ItemType& x)
{
	if (q == NULL || q->Next == NULL)
		return 0;
	StackNode* p = q->Next;
	q->Next = p->Next;
	x = p->Info;
	delete p;
	return 1;
}

int deleteStackList(Stack& st)
{
	ItemType x;
	if (isEmpty(st))
		return 0;
	while (!isEmpty(st))
		pop(st,x);
	return 1;
}

int deleteStackNode(Stack& st, StackNode* q, ItemType& x)
{
	if (q == NULL || isEmpty(st))
		return 0;
	if (q == st.Top)
		pop(st, x);
	else
	{
		StackNode* p = st.Top;
		while (p->Next != q)
			p = p->Next;
		deleteAfter(st, p, x);
	}
	return 1;
}

//------------------------------------------------- Suport --------------------------------------------

int countStack(Stack st)
{
	int count = 0;
	for (StackNode* p = st.Top; p != NULL; p = p->Next)
		count++;
	return count;
}

//------------------------------------------------- Find --------------------------------------------

Stack findSListByLoaiXe(Stack st, char loaiXe[])
{
	StackNode* p = st.Top;
	StackNode* newNode;
	Stack result;
	initStack(result);
	while (p != NULL)
	{
		if (strcmpi(p->Info.loaiXe, loaiXe) == 0)
		{
			newNode = createStackNode(p->Info);
			if (newNode == NULL)
				continue;
			push(result, newNode);
		}
		p = p->Next;
	}
	return result;
}

StackNode* findSNodeByLoaiXe(Stack st, char loaiXe[])
{
	StackNode* p = st.Top;
	while (p != NULL)
	{
		if (strcmpi(p->Info.loaiXe, loaiXe) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}

StackNode* findSNodeByMaXe(Stack st, char maXe[])
{
	StackNode* p = st.Top;
	while (p != NULL)
	{
		if (strcmpi(p->Info.maXe, maXe) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}

StackNode* findSNodeBySoXe(Stack st, char soXe[])
{
	StackNode* p = st.Top;
	while (p != NULL)
	{
		if (strcmpi(p->Info.soXe, soXe) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}

StackNode* findSNodeByTenKhachHang(Stack st, char tenKhachHang[])
{
	StackNode* p = st.Top;
	while (p != NULL)
	{
		if (strcmpi(p->Info.tenKhachHang, tenKhachHang) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}
