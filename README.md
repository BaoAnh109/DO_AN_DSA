# DO_AN_DSA - Quản Lý Bãi Giữ Xe AEON Tân Phú

## 1) Giới thiệu

Đây là đồ án cấu trúc dữ liệu và giải thuật (DSA) xây dựng ứng dụng **console C++** để quản lý bãi giữ xe AEON Tân Phú.  
Chương trình hỗ trợ:

- Đăng nhập theo vai trò (**Quản lý** / **Nhân viên**)
- Quản lý thông tin xe trong bãi
- Quản lý nhân viên (đối với quản lý)
- Thống kê doanh thu theo nhiều mốc thời gian

---

## 2) Công nghệ và môi trường

- Ngôn ngữ: **C++**
- Kiểu ứng dụng: **Console**
- IDE/Build chính: **Microsoft Visual Studio 2022** (toolset v143)
- Nền tảng phù hợp: **Windows**

> Repo dùng file project `.vcxproj`, vì vậy build thuận tiện nhất bằng Visual Studio/MSBuild trên Windows.

---

## 3) Cấu trúc repository

```text
DO_AN_DSA/
├── DO_AN_CK.sln
└── Bai_Giu_Xe_AEON_Tan_Phu/
    ├── Main.cpp              # Điểm vào chương trình
    ├── Menu.h / Menu.cpp     # Giao diện menu console
    ├── SNode.h / SNode.cpp   # Cấu trúc Stack và thao tác cơ bản cho xe
    ├── Xe.h / Xe.cpp         # Nghiệp vụ quản lý xe + thống kê doanh thu
    ├── AccessControl.h/.cpp  # Đăng nhập, phân quyền, quản lý nhân viên
    ├── AddInclude.h          # Các thư viện dùng chung
    ├── xe.txt                # Dữ liệu xe
    ├── user.txt              # Dữ liệu tài khoản
    └── ZuPhong.txt           # File dữ liệu phụ
```

---

## 4) Chức năng chính

## 4.1 Đăng nhập và phân quyền

- Người dùng đăng nhập bằng `username` + `password`
- Quyền:
  - `Manager` (0): quản lý nhân viên, doanh thu, xe
  - `Staff` (1): quản lý xe

## 4.2 Quản lý xe

- Nhập danh sách xe từ bàn phím
- Đọc danh sách xe từ file
- Hiển thị danh sách xe
- Thêm xe mới
- Tìm xe theo loại
- Xóa xe (theo mã xe / số xe / loại xe)
- Đếm số lượng xe trong bãi
- Thống kê số lượng theo loại xe
- Hiển thị loại xe có số lượng nhiều nhất

## 4.3 Quản lý nhân viên (Manager)

- Thêm nhân viên
- Xem danh sách nhân viên
- Xóa nhân viên
- Đồng bộ thay đổi vào file `user.txt`

## 4.4 Quản lý doanh thu (Manager)

- Doanh thu theo tuần
- Doanh thu theo tháng
- Doanh thu theo năm
- Doanh thu theo ngày
- Doanh thu từ ngày đến ngày

---

## 5) Cấu trúc dữ liệu

- **Stack (danh sách liên kết đơn)** cho danh sách xe
- **Stack (danh sách liên kết đơn)** cho danh sách nhân viên
- `std::unordered_map` để thống kê số lượng theo loại xe
- `std::map` để gom doanh thu theo tuần/tháng/năm
- Sắp xếp theo đơn giá dùng quick sort trên mảng tạm

---

## 6) Định dạng dữ liệu file

## 6.1 `user.txt`

Mỗi dòng:

```text
id#username#password#role
```

Ví dụ:

```text
A001#admin001#1111#0
s001#staff001#1111#1
```

Trong đó:

- `role = 0`: Manager
- `role = 1`: Staff

## 6.2 `xe.txt`

Dòng đầu là số lượng bản ghi `n`, các dòng sau:

```text
maXe#soXe#loaiXe#tenKhachHang#donGia#ngay/thang/nam
```

Ví dụ:

```text
8
XK0003#52AC-13123#Xe Khach#TranBaoThan#10000#1/5/2025
...
```

---

## 7) Hướng dẫn chạy dự án

## Cách 1: Dùng Visual Studio (khuyến nghị)

1. Mở `DO_AN_CK.sln` bằng Visual Studio 2022.
2. Chọn cấu hình `Debug` hoặc `Release` (Win32/x64).
3. Build solution.
4. Đặt project `Bai_Giu_Xe_AEON_Tan_Phu` làm Startup Project.
5. Chạy chương trình.

## Cách 2: Dùng MSBuild (Windows Developer Command Prompt)

```bat
msbuild DO_AN_CK.sln /p:Configuration=Debug /p:Platform=x64
```

> Lưu ý: Chương trình đọc/ghi `xe.txt`, `user.txt` bằng đường dẫn tương đối, nên hãy chạy đúng thư mục làm việc của project để tránh lỗi không tìm thấy file.

---

## 8) Tài khoản mẫu

- Manager: `admin001 / 1111`
- Staff: `staff001 / 1111`

---

## 9) Một số lưu ý hiện tại

- Ứng dụng mang tính đồ án học thuật, dữ liệu lưu dạng text, chưa dùng CSDL.
- Chưa có bộ test tự động.
- Chưa mã hóa mật khẩu (đang lưu plain text trong `user.txt`).

---

## 10) Định hướng cải tiến

- Chuyển sang lưu trữ CSDL (SQLite/MySQL)
- Mã hóa mật khẩu và tăng cường bảo mật đăng nhập
- Tách lớp (OOP) rõ ràng hơn theo module/domain
- Bổ sung unit test và kiểm thử tự động
- Cải thiện xử lý lỗi nhập liệu và chuẩn hóa giao diện

---

## 11) Tác giả

Repo: **BaoAnh109/DO_AN_DSA**

