#include "AddInclude.h"

void title()
{
	system("cls");
	printf("*************** CHUONG TRINH QUAN LY BAI GIU XE ****************\n");
}

void showMenu_QLXe()
{
	title();
	printf("*  0. Thoat                                                    *\n");
	printf("*  1. Nhap danh sach xe bang ban phim                          *\n");
	printf("*  2. Nhap danh sach xe tu file                                *\n");
	printf("*  3. Xuat danh sach xe                                        *\n");
	printf("*  4. Them 1 xe vao danh sach                                  *\n");
	printf("*  5. Xuat cac xe co nhieu xe nhat                             *\n");
	printf("*  6. Tim xe theo loai x                                       *\n");
	printf("*  7. Thong ke xe theo don gia                                 *\n");
	printf("*  8. Xuat so luong xe moi loai                                *\n");
	printf("*  9. Xoa xe X                                                 *\n");
	printf("* 10. So luong xe trong bai                                    *\n");
	printf("****************************************************************\n");
}

void showMenu_Manager_QLDoanhThu()
{
	title();
	printf("*  0. Thoat                                                    *\n");
	printf("*  1. Doanh thu theo tuan                                      *\n");
	printf("*  2. Doanh thu theo thang                                     *\n");
	printf("*  3. Doanh thu theo nam                                       *\n");
	printf("*  4. Doanh thu theo ngay                                      *\n");
	printf("*  5. Doanh thu tu ngay den ngay                               *\n");
	printf("****************************************************************\n");
}

void showMenu_Manager()
{
	title();
	printf("*  Ban la quan ly, vui long chon chuc nang:                    *\n");
	printf("*  0. Dang xuat                                                *\n");
	printf("*  1. Quan ly nhan vien                                        *\n");
	printf("*  2. Quan ly doanh thu                                        *\n");
	printf("*  3. Quan ly xe                                               *\n");
	printf("****************************************************************\n");
}

void showMenu_Manager_QLNV()
{
	title();
	printf("*  0. Tro lai                                                   *\n");
	printf("*  1. Them nhan vien                                            *\n");
	printf("*  2. Xem danh sach nhan vien                                   *\n");
	printf("*  3. Xoa nhan vien                                             *\n");
	printf("*****************************************************************\n");
}

void showMenu_QLDoanhThu()
{
	title();
	printf("*  Ban la quan ly, vui long chon chuc nang:                    *\n");
	printf("*  0. Tro lai                                                  *\n");
	printf("*  1. Doanh thu theo tuan                                      *\n");
	printf("*  2. Doanh thu theo thang                                     *\n");
	printf("*  3. Doanh thu theo nam                                       *\n");
	printf("*  4. Doanh thu theo ngay                                      *\n");
	printf("*  5. Doanh thu tu ngay den ngay                               *\n");
	printf("****************************************************************\n");
}

void showMenu_Staff()
{
	title();
	printf("*  Ban la nhan vien, vui long chon chuc nang:                  *\n");
	printf("*  0. Dang xuat                                                *\n");
	printf("*  1. Quan ly xe                                               *\n");
	printf("****************************************************************\n");
}

//----------------------------------------------------- Show --------------------------------------------
void showMenuTTXe_Top()
{
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("%-15s%-15s%-15s%-30s%-15s%-15s\n", "Ma Xe", "So Xe", "Loai Xe", "Ten Khach Hang", "Don Gia", "Ngay Giu");
}

void showMenuTTXe_Bottom()
{

	printf("--------------------------------------------------------------------------------------------------------\n");
}

void menu_TTNV()
{
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("%-15s%-30s%-15s%-15s\n", "ID", "Ten Dang Nhap", "Mat Khau", "Vai Tro");
}