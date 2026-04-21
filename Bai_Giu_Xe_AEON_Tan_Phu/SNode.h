#pragma once

#include "AddInclude.h"
#include "Menu.h"
// Bai Giu Xe AEON Tan Phu

struct DATE
{
	int ngay, thang, nam;
};

struct TT_XE
{
	char maXe[16];
	char soXe[16];
	char loaiXe[16];
	char tenKhachHang[31];
	int donGia;
	DATE ngayGiu;
};

typedef TT_XE ItemType;

//------------------------------------------------- StackNODE --------------------------------------------

struct StackNode
{
	ItemType Info;
	StackNode* Next;
};

struct Stack
{
	StackNode* Top;
};

void initStack(Stack& st);
int isEmpty(Stack st);
StackNode* createStackNode(ItemType x);
int push(Stack& st, StackNode* p);
int pop(Stack& st, ItemType& x);
int deleteAfter(Stack& st, StackNode* q, ItemType& x);
int deleteStackList(Stack& st);
int deleteStackNode(Stack& st, StackNode* q, ItemType& x);
//------------------------------------------------- FUNCTION --------------------------------------------

//int deleteSList(Stack& st);
//int deleteSNode(Stack& st, StackNode* q, ItemType& x);
//int deleteAfter(Stack& st, StackNode* q, ItemType& x);
// 
//int deleteSList(Stack& st);
//int deleteSNode(Stack& st, StackNode* q, ItemType& x);
//int deleteAfter(Stack& st, StackNode* q, ItemType& x);

//int deleteSList(Stack& st);
//int deleteSNode(Stack& st, StackNode* q, ItemType& x);
//int deleteAfter(Stack& st, StackNode* q, ItemType& x);

//int deleteSList(Stack& st);
//int deleteSNode(Stack& st, StackNode* q, ItemType& x);
int countStack(Stack st);
Stack findSListByLoaiXe(Stack st, char loaiXe[]);
StackNode* findSNodeByLoaiXe(Stack st, char loaiXe[]);
StackNode* findSNodeByMaXe(Stack st, char soXe[]);
StackNode* findSNodeBySoXe(Stack st, char soXe[]);
StackNode* findSNodeByTenKhachHang(Stack st, char tenKhachHang[]);
