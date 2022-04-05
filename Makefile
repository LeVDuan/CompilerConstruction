CC=gcc
CFLAGS=-I.
DEPS = lib/lib.h
OBJ = main.o lib/lib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

#	CC: là compiler C được sử dụng
#	CFLAGS: là danh sách các flag của compiler
#	DEPS để chỉ ra file .h mà các file .c phụ thuộc vào
#	-c là tạo ra các object file
#	-o $@ là tạo ra output của quá trình biên dịch trong tập tin bên trái dấu :
#	$< là thành phần đàu tiên trong danh sách của dependency và CFLAGS là macro đã được định nghĩa ở dòng 2
#	$@ và $^ để lấy thông tin bên trái và bên phải của dấu : để làm cho quá trình biên dịch được tổng quát hơn,