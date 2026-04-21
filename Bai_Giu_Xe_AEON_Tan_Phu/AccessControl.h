#pragma once
#include "AddInclude.h"
#include "SNode.h"


//------------------------------------------StackNode_User--------------------------------------------
enum Role
{
	Manager, Staff, Invalid
};

struct User
{
	char id[20];
	char username[20];
	char password[20];
	Role role;
};

typedef User Itemtype_User;

struct StackNode_User
{
	Itemtype_User Info;
	StackNode_User* Next;
};

struct Stack_User
{
	StackNode_User* Top;
};

void initStack_User(Stack_User& st);
int isEmpty_User(Stack_User st);
StackNode_User* createStackNode_User(Itemtype_User x);
int push_User(Stack_User& st, StackNode_User* p);
int pop_User(Stack_User& st, Itemtype_User& x);
int deleteStackList_User(Stack_User& st);
int deleteAfter_User(Stack_User& st, StackNode_User* q, Itemtype_User& x);
int deleteStackNode_User(Stack_User& st, StackNode_User* q, Itemtype_User& x);
//------------------------------------------------- Input - Output (File) -------------------------------------------
void input_Login(User& user);
int checkLogin(char username[], char password[], User& user, char inputFileName[]);
void getUserFromFile(User& user, FILE* fi);
int input_UserFromFile(Stack_User& st, char inputFileName[]);
void putUserToFile(User user, FILE* fo);
int output_UserToFile(User user, char outputFileName[]);
int deleteLine(const char* filename, char idUser[]);
//------------------------------------------------- Show -------------------------------------------------------------
void showTTNV(Itemtype_User x);
void showSList_User(Stack_User st);
//---------------------------------------- Function ------------------------------------------------
Role login(User& user, char inputFileName[]);
StackNode_User* findSNode_User_ByID(Stack_User st, char id[]);
void process_QLNV(Stack_User &st, char inputFileName[]);
//void process_User(SList st);


