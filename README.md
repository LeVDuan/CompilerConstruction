# CompilerConstruction
+ Tạo chương trình dịch cho ngôn ngữ ```KPL``` bằng ngôn ngữ ```C```
+ Thông qua bài tập hàng tuần trong các folder theo bài
# Description

+ Repositorie bao gồm: các thư mục chứa các bài tập hàng tuần
+ Biên dịch bằng công cụ makefile với ngôn ngữ ```C```
+ Hệ điều hành: Ubuntu, windows, ...

# Command to compiler code
- Chú ý: Nếu trong các thư mục có chứa file mytest.sh mà không thể thực thi thì bạn cần cấp quyền cho nó với lệnh sau: 
```
chmod +x mytest.sh
```
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
  + \day2: -> Sử dụng bảng kí hiệu để hoàn thiện file paser.c
  ```
  cd bai4/day2/completed
  make
  ```
  Bạn có thể test từng ví dụ trong thư mục ./tests như sau:
  ```
  ./kplc ../tests/example1.kpl
  ```
  Hoặc có thể test tất cả các ví dụ và so sánh với các result bằng cách thực thi file mytest.sh:
  ```
  ./mytest.sh
  ```
  + \day3: -> Xây dựng các hàm kiểm tra sự trùng lặp khi khai báo đối tượng, Kiểm tra tham chiếu tới các đối tượng được định nghĩa và triển khai trong các file semantic.h, semantic.c -> tiếp tục hoàn thiện file paser.c
  ```
  cd bai4/day3/completed
  make
  ```
  Bạn có thể test từng ví dụ trong thư mục ./tests như sau:
  ```
  ./kplc ../tests/example1.kpl
  ```
  Hoặc có thể test tất cả các ví dụ và so sánh với các result bằng cách thực thi file mytest.sh:
  ```
  ./mytest.sh
  ```
  + \day4: -> Xây dựng các hàm kiểm tra sự nhất quán về kiểu trong các cấu trúc của chương trình như định nghĩa biến mảng, hàm, thủ tục, tham số và triển khai trong các file semantic.h, semantic.c -> tiếp tục hoàn thiện file paser.c
  ```
  cd bai4/day4/completed
  make
  ```
  Bạn có thể test từng ví dụ trong thư mục ./tests như sau:
  ```
  ./kplc ../tests/example1.kpl
  ```
  Hoặc có thể test tất cả các ví dụ và so sánh với các result bằng cách thực thi file mytest.sh:
  ```
  ./mytest.sh
  ```