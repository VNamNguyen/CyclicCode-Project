# BÀI TẬP LỚN MÔN LÝ THUYẾT THÔNG TIN - NHÓM 8

## 1. Thông tin sinh viên thực hiện
Dưới đây là danh sách thành viên nhóm tham gia xây dựng chương trình cho Part #2:

| STT | Họ và tên | Mã sinh viên |
|:---:|:---|:---:|
| 1 | **Nguyễn Văn Nam** | **B24DCCN411** |
| 2 | **Lê Hải Biên** | **B24DCCN064** |
| 3 | **Đặng Mạnh Đạt** | **B24DCCN104** | 

## 2. Mô tả đề tài (Part #2)
Chương trình thực hiện mô phỏng thuật toán mã hóa mã vòng tuyến tính $C(n, k)$ với yêu cầu cụ thể:
* Xây dựng các lớp cơ sở: Lớp Bit (trường GF(2)), lớp Vector nhị phân và lớp Đa thức.
* Thực hiện **thuật toán nhân** để xác định từ mã hệ thống cho bản tin $m(x)$ dựa trên đa thức kiểm tra $h(x)$ cho trước.
* Đáp ứng chuẩn nhập/xuất dữ liệu của các kỳ thi lập trình quốc tế (ICPC).

## 3. Các tính năng đặc biệt
Nhóm đã tích hợp thêm các tính năng phục vụ mục đích học tập và kiểm thử:
* **Chế độ Tự luận (Bonus):** Khi bật chế độ `isVerbose`, chương trình sẽ xuất chi tiết từng bước tính toán các bit kiểm tra $c_p$ để người dùng có thể đối chiếu với cách giải tay.
* **Hỗ trợ Testcase:** Hệ thống có khả năng đọc dữ liệu từ file `.in` và xuất kết quả ra file `.out` phục vụ việc chấm tự động.

## 4. Cấu trúc mã nguồn & Cài đặt
Toàn bộ mã nguồn được tối ưu hóa trong file `main.cpp` để thuận tiện cho việc trình bày và chấm bài nhanh.

### Cách biên dịch và chạy:
1. Sử dụng trình biên dịch GCC/G++:
   ```bash
   g++ main.cpp -o CyclicCode