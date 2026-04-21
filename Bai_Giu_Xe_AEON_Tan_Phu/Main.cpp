#include "SNode.h"
#include "AccessControl.h"
#include "Xe.h"
#include "Menu.h"
#include "AddInclude.h"


// Chuong trinh quan ly bai giu xe AEON Tan Phu



void process()
{
	Stack slXe;
	Stack_User slStaff;
	initStack(slXe);
	initStack_User(slStaff);
	char tenFile_dsxe[] = "xe.txt";
	char tenFile_user[] = "user.txt";
	while (1)
	{
		User user;
		Role role = login(user, tenFile_user);
		if (role == Manager)
		{
			input_UserFromFile(slStaff, tenFile_user);
			int choice;
			do
			{
				showMenu_Manager();
				printf("Nhap lua chon: ");
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:
					showMenu_Manager_QLNV();
					process_QLNV(slStaff, tenFile_user);
					break;
				case 2:
					process_QLDoanhThu(slXe);
					break;
				case 3:
					showMenu_QLXe();
					process_QLXe(slXe, tenFile_dsxe);
					break;
				case 0:
					printf("Ban chon dang xuat.\n");
					getch();
					break;
				default:
					printf("Lua chon khong hop le. Vui long chon lai.\n");
					getch();
					break;
				}
			} while (choice != 0);
		}
		else if (role == Staff)
		{
			int choice;
			do
			{
				showMenu_Staff();
				printf("Nhap lua chon: ");
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:
					showMenu_QLXe();
					process_QLXe(slXe, tenFile_dsxe);
					break;
				case 0:
					printf("Ban chon dang xuat.\n");
					getch();
					break;
				default:
					printf("Lua chon khong hop le. Vui long chon lai.\n");
					getch();
					break;
				}

			} while (choice != 0);
		}
	}
}


int main()
{
	
	process();
	return 0;
}





//Stack sl;
//initStack(sl);
//ItemType x;
//SNode* P;
//int choice, kq;
//char tenFile_dsxe[] = "xe.txt";
//do
//{
//	system("cls");
//	showMenu();
//	printf("Ban hay lua chon mot chuc nang: ");
//	scanf("%d", &choice);
//	switch (choice)
//	{
//	case 1:
//		createSList_InputByHand(sl);
//		printf("\nNOI DUNG CUA DANH SACH LA: ");
//		showSList(sl);
//		break;
//	case 2:
//		createSList_FromTextFile(sl, tenFile_dsxe);
//		printf("NOI DUNG CUA DANH SACH VUA TAO TU FILE TEXT LA:\n");
//		showSList(sl);
//		break;
//	case 3:
//		showSList(sl);
//		break;
//	case 4:
//		printf("Ban hay nhap thong tin mot chiec xe moi:\n ");
//		nhapTTXe(x);
//		P = createSNode(x);
//		kq = insertTail(sl, P);
//		if (kq == 0)
//			printf("Khong the them chiec xe moi.");
//		else
//		{
//			printf("\nNOI DUNG CUA DANH SACH SAU KHI THEM 1 CHIEC XE (VAO CUOI) LA:\n ");
//			showSList(sl);
//			saveSList_ToTextFile(sl, tenFile_dsxe);
//		}
//		break;
//	case 5:
//		showLoaiXeMax(sl);
//		break;
//	case 6:
//	{
//		if (isEmpty(sl))
//		{
//			printf("Danh sach rong\n");
//			break;
//		}
//		printf("Nhap loai xe can tim: ");
//		char loaiXe[16];
//		rewind(stdin);
//		gets_s(loaiXe);
//		Stack* result = findSListByLoaiXe(sl, loaiXe);
//		if (result == NULL)
//		{
//			printf("Khong tim thay xe co loai %s\n", loaiXe);
//		}
//		else
//		{
//			printf("Cac xe co loai %s:\n", loaiXe);
//			showSList(*result);
//		}
//		break;
//	}
//	case 7:
//		if (isEmpty(sl))
//		{
//			printf("Danh sach rong\n");
//			break;
//		}
//		printf("Danh sach khi chua thong ke:\n");
//		showSList(sl);
//		printf("Danh sach xe theo don gia:\n");
//		thongKeTheoDonGia(sl);
//		//sortSListByDonGia(sl);
//		//showSList(sl);
//		break;
//	case 8:
//		showDSSLXe(sl);
//		break;
//	case 9:
//		if (isEmpty(sl))
//		{
//			printf("Danh sach rong\n");
//			break;
//		}
//		deleteXe(sl);
//		break;
//	case 10:
//		printf("Tong so luong xe co trong bai giu xe la: %d\n", countSList(sl));
//		break;
//	case 11:
//		showDoanhThu(sl);
//		break;
//	case 0:
//		printf("Thoat chuong trinh\n");
//		break;
//	default:
//		printf("Lua chon khong hop le. Vui long chon lai.\n");
//		break;
//	}
//	getch();
//} while (choice != 0);