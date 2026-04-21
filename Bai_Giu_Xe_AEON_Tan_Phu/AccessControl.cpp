#include "AddInclude.h"
#include "Menu.h"
#include "AccessControl.h"
#include "SNode.h"
#include "Xe.h"

//------------------------------------------StackNode_User--------------------------------------------

void initStack_User(Stack_User& st)
{
	st.Top = NULL;
}

int isEmpty_User(Stack_User st)
{
	return (st.Top == NULL) ? 1 : 0;
}

StackNode_User *createStackNode_User(Itemtype_User x)
{
	StackNode_User *p = new StackNode_User;
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

int push_User(Stack_User& st, StackNode_User* p)
{
	if (p == NULL)
	{
		return 0;
	}
	if (isEmpty_User(st) == 1)
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

int pop_User(Stack_User& st, Itemtype_User& x)
{
	if (isEmpty_User(st) == 1)
		return 0;
	StackNode_User* p = st.Top;
	st.Top = st.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}

int deleteStackList_User(Stack_User& st)
{
	Itemtype_User x;
	if (isEmpty_User(st))
		return 0;
	while (!isEmpty_User(st))
		pop_User(st, x);
	return 1;
}

int deleteStackNode_User(Stack_User& st, StackNode_User* q, Itemtype_User& x)
{
	if (q == NULL || isEmpty_User(st))
		return 0;
	if (q == st.Top)
		pop_User(st, x);
	else
	{
		StackNode_User* p = st.Top;
		while (p->Next != q)
			p = p->Next;
		deleteAfter_User(st, p, x);
	}
	return 1;
}

int deleteAfter_User(Stack_User& st, StackNode_User* q, Itemtype_User& x)
{
	if (q == NULL || q->Next == NULL)
		return 0;
	StackNode_User* p = q->Next;
	q->Next = p->Next;
	x = p->Info;
	delete p;
	return 1;
}


//---------------------------------------- Input - Output (File) -------------------------------------------

void input_Login(User& user)
{
	printf("Nhap ten dang nhap: ");
	rewind(stdin);
	gets_s(user.username);
	printf("Nhap mat khau: ");
	rewind(stdin);
	gets_s(user.password);
}

void getUserFromFile(User& user, FILE* fi)
{
	fscanf(fi, "%[^#]#%[^#]#%[^#]#%d\n", user.id, user.username, user.password, &user.role);
}

int checkLogin(char username[], char password[], User& user, char inputFileName[])
{
	FILE* f;
	fopen_s(&f, inputFileName, "r");
	if (f == NULL)
	{
		printf("Khong mo duoc file user.txt\n");
		fclose(f);
		return 0;
	}
	while (!feof(f))
	{
		getUserFromFile(user, f);
		if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0)
		{
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}

int input_UserFromFile(Stack_User& st, char inputFileName[])
{
	initStack_User(st);
	User user;
	FILE* fi;
	fopen_s(&fi, inputFileName, "rt");
	if (fi == NULL)
	{
		printf("Loi mo File: %s", inputFileName);
		return 0;
	}
	while (!feof(fi))
	{
		getUserFromFile(user, fi);
		if (user.role == Staff)
		{
			if (!push_User(st, createStackNode_User(user)))
			{
				printf("Khong the them nhan vien moi.");
				fclose(fi);
				return 0;
			}
		}
	}
	fclose(fi);
	return 1;
}

void putUserToFile(User user, FILE* fo)
{
	fprintf(fo, "%s#%s#%s#%d\n", user.id, user.username, user.password, user.role);
}


int output_UserToFile(User user, char outputFileName[])
{
	FILE* fo;
	fopen_s(&fo, outputFileName, "a");
	if (fo == NULL)
	{
		printf("Loi mo File: %s", outputFileName);
		return 0;
	}
	putUserToFile(user, fo);
	fclose(fo);
	return 1;
}

int deleteLine(const char* filename, char idUser[]) {
	FILE* file = fopen(filename, "r");
	FILE* temp = fopen("temp.txt", "w");
	User user;
	if (file == NULL || temp == NULL) {
		printf("Error opening file.\n");
		return 0;
	}
	while (!feof(file)) {
		getUserFromFile(user, file);
		if (strcmp(user.id, idUser) == 0) {
			continue;
		}
		else {
			putUserToFile(user, temp);
		}
	}
	fclose(file);
	fclose(temp);

	remove(filename);
	rename("temp.txt", filename);
	return 1;
}
//----------------------------------------- Show ------------------------------------------------
void showTTNV(User user)
{
	printf("%-15s%-30s%-15s%-15d\n", user.id, user.username, user.password, user.role);
}

void showStack_User(Stack_User st)
{
	if (isEmpty_User(st))
	{
		printf("Danh sach rong\n");
		return;
	}
	menu_TTNV();
	for (StackNode_User* p = st.Top; p != NULL; p = p->Next)
	{
		showTTNV(p->Info);
	}
}


//---------------------------------------- Function ------------------------------------------------



Role login(User& user, char inputFileName[])
{
	Role role = Invalid;
	char username[20];
	char password[20];
	do
	{
		system("cls");
		title();
		printf("Vui long dang nhap tai khoang de su dung chuong trinh.\n");
		printf("Nhap ten dang nhap: ");
		rewind(stdin);
		gets_s(username);
		printf("Nhap mat khau: ");
		rewind(stdin);
		gets_s(password);
		if (!checkLogin(username, password, user, inputFileName))
		{
			printf("Dang nhap khong thanh cong. Vui long kiem tra lai ten dang nhap va mat khau.\n");
			printf("Nhan phim bat ky de tiep tuc dang nhap.\n");
			getch();
		}
		else
		{
			printf("Dang nhap thanh cong. Chao mung %s\n", user.username);
			role = user.role;
		}
	} while (role == Invalid);
	return role;
}

StackNode_User* findSNode_User_ByID(Stack_User st, char id[])
{
	if (isEmpty_User(st))
	{
		printf("Danh sach rong\n");
		return NULL;
	}
	StackNode_User* p = st.Top;
	while (p != NULL)
	{
		if (strcmp(p->Info.id, id) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}



void process_QLNV(Stack_User &st,char inputFileName[])
{
	int choice;
	do
	{
		showMenu_Manager_QLNV();
		printf("Nhap lua chon: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Them nhan vien\n");
			User user;
			printf("Nhap id: ");
			rewind(stdin);
			gets_s(user.id);
			input_Login(user);
			user.role = Staff;
			if (!push_User(st, createStackNode_User(user)))
			{
				printf("Khong the them nhan vien moi.");
			}
			else
			{
				printf("Them nhan vien thanh cong.\n");
				if (output_UserToFile(user, inputFileName))
				{
					printf("Luu thong tin nhan vien vao file user.txt thanh cong.\n");
				}
				else
				{
					printf("Khong the luu thong tin nhan vien vao file user.txt.\n");
				}
			}
			break;
		case 2:
			printf("Xem danh sach nhan vien\n");
			if (isEmpty_User(st))
			{
				printf("Danh sach rong\n");
				break;
			}
			else showStack_User(st);
			break;
		case 3:
			printf("Danh sach nhan vien hien tai:\n");
			showStack_User(st);
			printf("Xoa nhan vien\n");
			User dataDelete;
			char id[20];
			printf("Nhap id nhan vien can xoa: ");
			rewind(stdin);
			gets_s(id);
			if (!deleteStackNode_User(st,findSNode_User_ByID(st,id), dataDelete))
			{
				printf("Khong the xoa nhan vien.\n");
			}
			else
			{
				printf("Da xoa nhan vien co id %s thanh cong!\n", id);
				if (deleteLine(inputFileName, id))
				{
					printf("Xoa nhan vien trong file user.txt thanh cong.\n");
				}
				else
				{
					printf("Khong the xoa nhan vien trong file user.txt.\n");
				}
			}
			break;
		case 0:
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
		if (choice != 0)
		{
			getch();
		}
	} while (choice != 0);
}