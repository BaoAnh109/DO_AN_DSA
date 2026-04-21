#include "AddInclude.h"	
#include "SNode.h"
#include "Menu.h"
//------------------------------------------------- Sort --------------------------------------------

void swap(ItemType& a, ItemType& b)
{
	ItemType temp = a;
	a = b;
	b = temp;
}

int compareDate(DATE date1, DATE date2)
{
	if (date1.nam != date2.nam)
		return date1.nam - date2.nam;
	if (date1.thang != date2.thang)
		return date1.thang - date2.thang;
	return date1.ngay - date2.ngay;
}

int compare(ItemType& a, ItemType& b)
{
	if (a.donGia < b.donGia)
		return -1;
	else if (a.donGia > b.donGia)
		return 1;
	else
		return -compareDate(a.ngayGiu, b.ngayGiu);
}

void qickSort(ItemType arr[], int left, int right)
{
	if (left >= right) return;
	if (left < right)
	{
		int i = left;
		int j = right;
		ItemType pivot = arr[(left + right) / 2];
		while (i <= j)
		{
			while (compare(arr[i], pivot) < 0)
				i++;
			while (compare(arr[j], pivot) > 0)
				j--;
			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		qickSort(arr, left, j);
		qickSort(arr, i, right);
	}
}

void sortStackByDonGia(Stack& st)
{
	if (isEmpty(st))
		return;
	int n = countStack(st);
	ItemType arr[1000];
	StackNode* p = st.Top;
	for (int i = 0; i < n; i++)
	{
		arr[i] = p->Info;
		p = p->Next;
	}
	qickSort(arr, 0, n - 1);
	p = st.Top;
	for (int i = 0; i < n; i++)
	{
		p->Info = arr[i];
		p = p->Next;
	}
}

//------------------------------------------------- Input --------------------------------------------

void nhapNgay(DATE& date)
{
	printf("Nhap ngay: ");
	scanf("%d", &date.ngay);
	printf("Nhap thang: ");
	scanf("%d", &date.thang);
	printf("Nhap nam: ");
	scanf("%d", &date.nam);
}

void nhapTTXe(ItemType& x)
{
	printf("Nhap ma xe: ");	rewind(stdin); gets_s(x.maXe);
	printf("Nhap so xe: "); rewind(stdin); gets_s(x.soXe);
	printf("Nhap loai xe: "); rewind(stdin); gets_s(x.loaiXe);
	printf("Nhap ten khach hang: "); rewind(stdin); gets_s(x.tenKhachHang);
	printf("Nhap don gia: "); scanf("%d", &x.donGia);
	printf("Nhap ngay: ");	nhapNgay(x.ngayGiu);
}
void createStack_InputByHand(Stack& st)
{
	initStack(st);
	int n;
	do
	{
		printf("\nBan hay cho biet so luong phan tu cua danh sach: ");
		scanf("%d", &n);
		if (n <= 0)
		{
			printf("Ban nhap sai roi. Vui long nhap lai!");
		}
	} while (n <= 0);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		nhapTTXe(x);
		StackNode* p = createStackNode(x);
		int kq = push(st, p);
		if (kq == 1) i++;
	}
}

void loadTTXe(FILE* fi, ItemType& x)
{
	fscanf(fi, "%[^#]#", x.maXe);
	fscanf(fi, "%[^#]#", x.soXe);
	fscanf(fi, "%[^#]#", x.loaiXe);
	fscanf(fi, "%[^#]#", x.tenKhachHang);
	fscanf(fi, "%d#", &x.donGia);
	fscanf(fi, "%d/%d/%d\n", &x.ngayGiu.ngay, &x.ngayGiu.thang, &x.ngayGiu.nam);
}

void createStack_FromTextFile(Stack& st, char inputFileName[])
{
	initStack(st);
	FILE* fi = fopen(inputFileName, "rt");
	if (fi == NULL)
	{
		printf("Loi mo File: %s", inputFileName);
		return;
	}
	int n;
	fscanf(fi, "%d\n", &n);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		loadTTXe(fi, x);
		StackNode* p = createStackNode(x);
		int kq = push(st, p);
		if (kq == 1) i++;
	}
	fclose(fi);
}
//------------------------------------------------- Output --------------------------------------------


void saveTTXe(FILE* fo, ItemType x)
{
	fprintf(fo, "%s#%s#%s#%s#%d#%d/%d/%d\n", x.maXe, x.soXe, x.loaiXe, x.tenKhachHang, x.donGia,
		x.ngayGiu.ngay, x.ngayGiu.thang, x.ngayGiu.nam);
}

void saveStack_ToTextFile(Stack st, char inputFileName[])
{
	FILE* fo = fopen(inputFileName, "wt");
	if (fo == NULL)
	{
		printf("Loi mo File: %s", inputFileName);
		return;
	}
	int n = countStack(st);
	fprintf(fo, "%d\n", n);
	for (StackNode* p = st.Top; p != NULL; p = p->Next)
	{
		saveTTXe(fo, p->Info);
	}
	fclose(fo);
}

//------------------------------------------Process-------------------------------------------------


void showTTXe(ItemType x)
{
	printf("%-15s%-15s%-15s%-30s%-15d%d/%d/%d\n", x.maXe, x.soXe, x.loaiXe, x.tenKhachHang, x.donGia,
		x.ngayGiu.ngay, x.ngayGiu.thang, x.ngayGiu.nam);
}

void showStack(Stack st)
{
	if (isEmpty(st))
	{
		printf("Danh sach rong\n");
		return;
	}
	StackNode* p = st.Top;
	showMenuTTXe_Top();
	while (p != NULL)
	{
		showTTXe(p->Info);
		p = p->Next;
	}
	showMenuTTXe_Bottom();
}

std::unordered_map<std::string, int> countByLoaiXe(Stack st)
{
	std::unordered_map<std::string, int> loaiXeCount;
	StackNode* p = st.Top;
	while (p != NULL)
	{
		loaiXeCount[p->Info.loaiXe]++;
		p = p->Next;
	}
	return loaiXeCount;
}

void showLoaiXeMax(Stack st)
{
	std::unordered_map<std::string, int> loaiXeCount = countByLoaiXe(st);
	if (loaiXeCount.empty())
	{
		printf("Danh sach rong\n");
		return;
	}
	int countMax = loaiXeCount.begin()->second;
	for (auto it = loaiXeCount.begin(); it != loaiXeCount.end(); it++)
	{
		if (it->second > countMax)
		{
			countMax = it->second;
		}
	}
	for (auto it = loaiXeCount.begin(); it != loaiXeCount.end(); it++)
	{
		if (it->second == countMax)
		{
			char loaiXe[16];
			strcpy_s(loaiXe, it->first.c_str());
			printf("Loai xe co so luong nhieu nhat: %s, so luong: %d\n", loaiXe, it->second);
			showStack(findSListByLoaiXe(st, loaiXe));
		}
	}

}

void showDSSLXe(Stack st)
{
	std::unordered_map<std::string, int> loaiXeCount = countByLoaiXe(st);
	char loaiXe[16];
	if (loaiXeCount.empty())
	{
		printf("Danh sach rong\n");
		return;
	}
	for (auto it = loaiXeCount.begin(); it != loaiXeCount.end(); it++)
	{
		strcpy(loaiXe, it->first.c_str());
		printf("Loai xe: %s, so luong: %d\n", loaiXe, it->second);
	}
}

void deleteXe(Stack& st)
{
	ItemType dataDelete;
	printf("Ban muon xoa xe theo phuong thuc nao?\n");
	printf("1. Xoa theo ma xe\n");
	printf("2. Xoa theo so xe\n");
	printf("3. Xoa theo loai xe\n");
	int choice;
	char tenFile_dsxe[] = "xe.txt";
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		char maXe[16];
		printf("Nhap ma xe can xoa: ");
		rewind(stdin);
		gets_s(maXe);
		StackNode* p = findSNodeByMaXe(st, maXe);
		if (!deleteStackNode(st, p, dataDelete)) printf("Co loi xay ra!\n");
		else
		{
			printf("Da xoa xe co ma %s thanh cong!\n", maXe);
			saveStack_ToTextFile(st, tenFile_dsxe);
		}
		break;
	}
	case 2:
	{
		char soXe[16];
		printf("Nhap so xe can xoa: ");
		rewind(stdin);
		gets_s(soXe);
		StackNode* p = findSNodeBySoXe(st, soXe);
		if (!deleteStackNode(st, p, dataDelete)) printf("Co loi xay ra!\n");
		else
		{
			printf("Da xoa xe co so %s thanh cong!\n", soXe);
			saveStack_ToTextFile(st, tenFile_dsxe);
		}
		break;
	}
	case 3:
	{
		char loaiXe[16];
		printf("Nhap loai xe can xoa: ");
		rewind(stdin);
		gets_s(loaiXe);
		StackNode* p = findSNodeByLoaiXe(st, loaiXe);
		if (!deleteStackNode(st, p, dataDelete)) printf("Co loi xay ra!\n");
		else
		{
			printf("Da xoa xe co loai %s thanh cong!\n", loaiXe);
			saveStack_ToTextFile(st, tenFile_dsxe);
		}
		break;
	}
	default:
		printf("Lua chon khong hop le!\n");
		break;
	}
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && isLeapYear(year)) return 29;
	return days[month - 1];
}

int dayOfYear(DATE d) {
	int sum = d.ngay;
	for (int i = 1; i < d.thang; ++i)
		sum += daysInMonth(i, d.nam);
	return sum;
}

int getWeekOfYear(DATE date)
{
	int dayOfYearValue = dayOfYear(date);
	return (dayOfYearValue - 1) / 7 + 1;
}

void doanhThuTuan(Stack st, int nam)
{
	std::map<int, int> doanhThu;
	StackNode* p = st.Top;
	while (p != NULL)
	{
		if (p->Info.ngayGiu.nam != nam)
		{
			p = p->Next;
			continue;
		}
		int week = getWeekOfYear(p->Info.ngayGiu);
		doanhThu[week] += p->Info.donGia;
		p = p->Next;
	}
	if (doanhThu.empty())
	{
		printf("Khong co doanh thu trong tuan cua nam %d\n", nam);
		return;
	}
	printf("Doanh thu theo tuan cua nam %d:\n", nam);
	for (auto it = doanhThu.begin(); it != doanhThu.end(); it++)
	{
		printf("Tuan %d: %d\n", it->first, it->second);
	}
}

void doanhThuThang(Stack st, int nam)
{
	std::map<int, int> doanhThu;
	StackNode* p = st.Top;
	while (p != NULL)
	{
		if (p->Info.ngayGiu.nam != nam)
		{
			p = p->Next;
			continue;
		}
		int month = p->Info.ngayGiu.thang;
		doanhThu[month] += p->Info.donGia;
		p = p->Next;
	}
	if (doanhThu.empty())
	{
		printf("Khong co doanh thu trong thang cua nam %d\n", nam);
		return;
	}
	printf("Doanh thu theo thang cua nam %d:\n", nam);
	for (auto it = doanhThu.begin(); it != doanhThu.end(); it++)
	{
		printf("Thang %d: %d\n", it->first, it->second);
	}
}

void doanhThuNam(Stack st)
{
	std::map<int, int> doanhThu;
	StackNode* p = st.Top;
	while (p != NULL)
	{
		int year = p->Info.ngayGiu.nam;
		doanhThu[year] += p->Info.donGia;
		p = p->Next;
	}
	if (doanhThu.empty())
	{
		printf("Chua nam nao co doanh thu\n");
		return;
	}
	printf("Doanh thu theo nam:\n");
	for (auto it = doanhThu.begin(); it != doanhThu.end(); it++)
	{
		printf("Nam %d: %d\n", it->first, it->second);
	}
}

void doanhThuDay(Stack st, DATE date)
{
	StackNode* p = st.Top;
	int doanhthu = 0;
	while (p != NULL)
	{
		if (p->Info.ngayGiu.ngay == date.ngay && p->Info.ngayGiu.thang == date.thang && p->Info.ngayGiu.nam == date.nam)
		{
			doanhthu += p->Info.donGia;
		}
		p = p->Next;
	}
	printf("Doanh thu cua ngay %d/%d/%d la: %d\n", date.ngay, date.thang, date.nam, doanhthu);
}

void thongKeTheoDonGia(Stack st)
{
	std::map <int, Stack> dsThongKe;
	printf("\nThong ke theo don gia gui:");
	StackNode* p = st.Top;
	while (p != NULL)
	{
		int donGia = p->Info.donGia;
		if (dsThongKe.find(donGia) == dsThongKe.end())
		{
			Stack temp;
			initStack(temp);
			dsThongKe[donGia] = temp;
		}
		StackNode* newNode = createStackNode(p->Info);
		if (newNode == NULL)
		{
			printf("Khong the cap phat node moi");
			getch();
			return;
		}
		push(dsThongKe[donGia], newNode);
		p = p->Next;
	}

	for (auto it = dsThongKe.begin(); it != dsThongKe.end(); it++)
	{
		printf("\nDon gia: %d\n", it->first);
		showStack(it->second);
	}
}

int isDateInRange(DATE ngay, DATE from, DATE to)
{
	return (compareDate(ngay, from) >= 0 && compareDate(ngay, to) <= 0);
}

void doanhThuTuNgayDenNgay(Stack st, DATE date1, DATE date2)
{
	StackNode* p = st.Top;
	int doanhthu = 0;
	while (p != NULL)
	{
		if (isDateInRange(p->Info.ngayGiu, date1, date2))
		{
			doanhthu += p->Info.donGia;
		}
		p = p->Next;
	}
	printf("Doanh thu tu ngay %d/%d/%d den ngay %d/%d/%d la: %d\n", date1.ngay, date1.thang, date1.nam, date2.ngay, date2.thang, date2.nam, doanhthu);
}

void process_QLDoanhThu(Stack st)
{
	if (isEmpty(st))
	{
		printf("Danh sach rong\n");
		getch();
		return;
	}
	int choice, nam;
	DATE date;
	do
	{
		showMenu_QLDoanhThu();
		printf("Nhap lua chon: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Nhap nam can thong ke theo tuan: ");
			scanf("%d", &nam);
			doanhThuTuan(st, nam);
			break;
		case 2:
			printf("Nhap nam can thong ke theo thang: ");
			scanf("%d", &nam);
			doanhThuThang(st, nam);
			break;
		case 3:
			doanhThuNam(st);
			break;
		case 4:
			printf("Nhap ngay can thong ke: \n");
			nhapNgay(date);
			doanhThuDay(st, date);
			break;
		case 5:
			DATE date1;
			printf("Nhap ngay bat dau:\n");
			nhapNgay(date);
			printf("Nhap ngay ket thuc:\n");
			nhapNgay(date1);
			doanhThuTuNgayDenNgay(st, date, date1);
			break;
		case 0:
			printf("Tro lai\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
		if(choice != 0) getch();
	} while (choice != 0);
}


void process_QLXe(Stack &st,char tenFile_dsxe[])
{
	initStack(st);
	ItemType x;
	StackNode* P;
	int choice, kq;
	do
	{
		title();
		showMenu_QLXe();
		printf("Ban hay lua chon mot chuc nang: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			createStack_InputByHand(st);
			printf("\nNOI DUNG CUA DANH SACH LA: ");
			showStack(st);
			break;
		case 2:
			createStack_FromTextFile(st, tenFile_dsxe);
			printf("NOI DUNG CUA DANH SACH VUA TAO TU FILE TEXT LA:\n");
			showStack(st);
			break;
		case 3:
			showStack(st);
			break;
		case 4:
			printf("Ban hay nhap thong tin mot chiec xe moi:\n ");
			nhapTTXe(x);
			P = createStackNode(x);
			kq  = push(st, P);
			if (kq == 0)
				printf("Khong the them chiec xe moi.");
			else
			{
				printf("\nNOI DUNG CUA DANH SACH SAU KHI THEM 1 CHIEC XE (VAO CUOI) LA:\n ");
				showStack(st);
				saveStack_ToTextFile(st, tenFile_dsxe);
			}
			break;
		case 5:
			showLoaiXeMax(st);
			break;
		case 6:
		{
			if (isEmpty(st))
			{
				printf("Danh sach rong\n");
				break;
			}
			printf("Nhap loai xe can tim: ");
			char loaiXe[16];
			rewind(stdin);
			gets_s(loaiXe);
			Stack result = findSListByLoaiXe(st, loaiXe);
			if (isEmpty(result))
			{
				printf("Khong tim thay xe co loai %s\n", loaiXe);
			}
			else
			{
				printf("Cac xe co loai %s:\n", loaiXe);
				showStack(result);
			}
			break;
		}
		case 7:
			if (isEmpty(st))
			{
				printf("Danh sach rong\n");
				break;
			}
			printf("Danh sach khi chua thong ke:\n");
			showStack(st);
			printf("Danh sach xe theo don gia:\n");
			thongKeTheoDonGia(st);
			break;
		case 8:
			showDSSLXe(st);
			break;
		case 9:
			if (isEmpty(st))
			{
				printf("Danh sach rong\n");
				break;
			}
			deleteXe(st);
			break;
		case 10:
			printf("Tong so luong xe co trong bai giu xe la: %d\n", countStack(st));
			break;
		case 0:
			printf("Tro lai\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
		if(choice != 0)	getch();
		}while (choice != 0);
}