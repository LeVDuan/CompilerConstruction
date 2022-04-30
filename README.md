# CompilerConstruction
+ Tạo chương trình dịch cho ngôn ngữ ```KPL``` bằng ngôn ngữ ```C```
+ Thông qua bài tập hàng tuần trong các folder theo bài
# Description

+ Repositorie bao gồm: các thư mục chứa các bài tập hàng tuần
+ Biên dịch bằng công cụ makefile với ngôn ngữ ```C```
+ Hệ điều hành: Ubuntu, windows, ...

# Command to compiler code
- Bên dịch code trong thư mục \bai1:
```
cd bai1
make
bin/bai1
```
- Bên dịch code trong thư mục \bai2: -> Pha 1: Phân tích từ vựng
```
cd bai2/completed
make
./mytest.sh
```
Cách biên dịch trên đã bao gồm các đoạn mã để so sánh kết quả và các test. Để xem kết quả trên terminal của từng ví dụ, thực thi lệnh dưới đây sau khi đã biên dịch ```make```:
```
./scanner ../test/example1.kpl
```
- Bên dịch code trong thư mục \bai3: -> Pha 2: Phân tích cú pháp
```
cd bai3/completed
make
./mytest.sh
```
Cách biên dịch trên đã bao gồm các đoạn mã để so sánh kết quả và các test. Để xem kết quả trên terminal của từng ví dụ, thực thi lệnh dưới đây sau khi đã biên dịch ```make```:
```
./parser ../test/example1.kpl
```
- Bên dịch code trong thư mục \bai4: -> Pha 3: Phân tích ngữ nghĩa
  + \day1: -> Xây dựng bảng kí hiệu
  ```
  cd bai4/day1/completed
  make
  ./symtab
  ```
  Xây dựng và in bảng kí hiệu cho 1 đoạn mã cụ thể  trong file main.c
