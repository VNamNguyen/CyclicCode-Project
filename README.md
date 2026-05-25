# BÀI TẬP LỚN MÔN LÝ THUYẾT THÔNG TIN - NHÓM 8

## 1. Thông tin sinh viên thực hiện
| STT | Họ và tên | Mã sinh viên |
|:---:|:---|:---:|
| 1 | **Nguyễn Văn Nam** | **B24DCCN411** |
| 2 | **Lê Hải Biên** | **B24DCCN064** |
| 3 | **Đặng Mạnh Đạt** | **B24DCCN104** | 

## 2. Mô tả đề tài (Part #2)
Chương trình thực hiện mô phỏng thuật toán mã hóa mã vòng tuyến tính C(n, k) với yêu cầu cụ thể:
* Xây dựng các lớp cơ sở: Lớp Bit (trường GF(2)), lớp Vector nhị phân và lớp Đa thức.
* Thực hiện **thuật toán nhân** để xác định từ mã hệ thống cho bản tin m(x) dựa trên đa thức kiểm tra h(x) cho trước.
* Đáp ứng chuẩn nhập/xuất dữ liệu của các kỳ thi lập trình quốc tế (ICPC).

## 3. Thiết kế chương trình
Chương trình được xây dựng theo hướng lập trình hướng đối tượng (OOP) gồm các thành phần chính:
* **Lớp Bit:** Đại diện phần tử trong trường GF(2), hỗ trợ các phép toán nhị phân cơ bản như XOR và AND.
* **Lớp BinaryVector:** Quản lý vector nhị phân, hỗ trợ thao tác trên từng bit và xử lý dữ liệu I/O.
* **Lớp GF2Polynomial:** Kế thừa từ BinaryVector, biểu diễn đa thức nhị phân trên trường GF(2).
* **Lớp CyclicCode:** Chứa hàm `encodeSystematic()` thực hiện thuật toán sinh từ mã hệ thống cho bản tin m(x) dựa trên đa thức kiểm tra h(x).

## 4. Các tính năng đặc biệt
* **Chế độ Tự luận (Bonus):** Khi bật biến `isVerbose = true` trong mã nguồn, chương trình sẽ xuất chi tiết từng bước tính toán các bit kiểm tra c_p để người dùng có thể đối chiếu với cách giải tay.
* **Tối ưu ICPC:** Tối ưu hóa I/O (`ios_base::sync_with_stdio(false)`), hỗ trợ đọc nhiều bộ testcases liên tục theo luồng chuẩn.

## 5. Yêu cầu môi trường
* **Hệ điều hành:** Windows hoặc Linux.
* **Trình biên dịch:** GCC/G++ hỗ trợ chuẩn C++11 trở lên.

## 6. Hướng dẫn cài đặt và chạy thử nghiệm
Mã nguồn được tối ưu hóa trong một file duy nhất `main.cpp`.

**Biên dịch chương trình:**
   ```bash
   g++ main.cpp -o CyclicCode
   ```

**Chạy chương trình (Đọc luồng I/O chuẩn):**
   ```bash
   ./CyclicCode < input.in > output.out
   ```
*(Trên Windows: `CyclicCode.exe < input.in > output.out`)*

## 7. Cấu trúc dữ liệu Kiểm thử (Testcases)
Định dạng file input (`.in`) chuẩn:
* Dòng 1: Số lượng testcase `T`.
* Dòng 2: Hai số nguyên `n` và `k`.
* Dòng 3: `k` hệ số của đa thức h(x) (cách nhau bởi khoảng trắng).
* Dòng 4: `k` bit của bản tin m(x) (cách nhau bởi khoảng trắng).

**Ví dụ Testcase:**
*Input:*
   ```text
   1
   7 4
   1 0 1 1
   1 0 1 1
   ```

*Output:*
   ```text
   => Vector tu ma: 0 0 0 1 0 1 1
   ```