# Đồ án Mã vòng Tuyến tính C(n, k) - Part #2

## 1. Thông tin nhóm
* Nhóm: 3 thành viên
* Ngôn ngữ thực hiện: C++
* Mục tiêu: Xây dựng chương trình mô phỏng thuật toán nhân mã vòng hệ thống C(n,k) từ đa thức kiểm tra $h(x)$.

## 2. Điểm nổi bật của chương trình
Chương trình được thiết kế với tư duy Lập trình Hướng đối tượng (OOP) và thỏa mãn 2 tiêu chí quan trọng:
* **Chuẩn ICPC:** Tối ưu hóa I/O, đọc nhiều testcase cùng lúc.
* **Tính năng Bonus (Tự luận):** Tích hợp biến `isVerbose` trong hàm `main()`. Khi set `isVerbose = true`, chương trình sẽ in ra lời giải chi tiết từng bước tính toán (phép cộng XOR, phép nhân AND trên trường GF(2)) để phục vụ việc kiểm tra và học tập.

## 3. Cấu trúc mã nguồn
Toàn bộ mã nguồn được tối ưu trong file `main.cpp` với 4 thành phần chính:
1. `class Bit`: Nạp chồng toán tử (+, *) để tự động tính toán trên trường GF(2).
2. `class BinaryVector`: Quản lý dãy bit linh hoạt.
3. `class GF2Polynomial`: Kế thừa vector nhị phân để biểu diễn đa thức.
4. `class CyclicCode`: Chứa lõi thuật toán `encodeSystematic` sinh từ mã hệ thống.

## 4. Hướng dẫn chạy Test
Bộ testcases được đặt trong thư mục `tests/` bao gồm các cặp file `*.in` và `*.out`.
Biên dịch chương trình bằng lệnh:
`g++ main.cpp -o main`
Chạy chương trình:
`./main`