# MILLIONAIRE GAME 
---
# I. GIỚI THIỆU
---
## 1. Tác giả

- Họ và tên: Nguyễn Thanh Phong

## 2. Thông tin chung

Mục tiêu của trò chơi là trả lời đúng một loạt câu hỏi trắc nghiệm để giành được số tiền thưởng ngày càng tăng, 
với mục tiêu cuối cùng là giành giải thưởng cao nhất trị giá một triệu đô la.

---
## 3. Xây dựng bởi 

- Công cụ: Visual Studio 2022
- Ngôn ngữ: C++;
- Hệ điều hành: Window 10 

# II. CHI TIẾT VỀ DỰ ÁN

## 1. Thư mục dự án 

Thư mục ***millionaireGame*** sẽ chứa tập tin `README.md`, thư mục ảnh minh hoạ cho dự án,
mã nguồn chính và tập tin `millionaireGame.sln` để mở toàn bộ dự án.

## 2. Mã nguồn dự án

- `README.md` để ghi tất cả thông tin về dự án, cách cài đặt, build chương trình cùng một số
lưu ý khác.
- `functions.h` dùng để khai báo các các thư viện cần sử dụng cho dự án, định nghĩa các mã 
***ANSI ESCAPE CODE*** to màu sắc cho các đối tượng trong dự án. Bên cạnh đó còn khai báo và xây dựng
cấu trúc cho gamePlayer (người chơi) cùng một số hàm liên quan đến gamePlayer.
- Thư mục ***millionaireGame*** sẽ chứa các mã nguồn `.cpp` tương ứng với từng hàm trong dự án và
tập tin văn bản `questions.txt` để lưu trữ thông tin bộ câu hỏi dùng trong trò chơi.

## 3. Các giao diện trò chơi 

> ***Lưu ý khi chọn các chỉ mục*** 
- Người quản lý sẽ thực hiện các thao tác nhấn mũi tên ***"lên, xuống, trái, phải"*** ứng
với mã ASCII ***'72, 80, 75, 77'*** để di chuyển giữa các chỉ mục.
và nhấn ***'Enter'*** để biểu thị mình đã chọn chỉ mục đó. Sau khi hoàn thành các thao tác
trong chỉ mục đã chọn, thì chỉ cần nhấn ***'Enter'*** một lần nữa để quay lại màn hình chính.
### 3.1. Màn hình chính

<div align="center">
  <img src="image/a1.png" alt="a1">
</div>

### 3.2. Màn hình đăng nhập 

<div align="center">
  <img src="image/a9.png" alt="a9">
</div>

### 3.3. Giao diện tổng quan trò chơi
<div align="center">
  <img src="image/a2.png" alt="a2">
</div>

### 3.4. Các lựa chọn hỗ trợ

<div align="center">
  <img src="image/a3.png" alt="a3">
</div>

> *Trợ giúp 50-50*

- Người chơi sẽ được ban tổ chức loại đi 2 đáp án không chính xác.
<div align="center">
  <img src="image/a4.png" alt="a4">
</div>

> *Gọi điện cho bạn bè*

- Người chơi sẽ được ban tổ chức liên lạc với người bạn ở đường dây
bên kia để nhờ sự trợ giúp.

<div align="center">
  <img src="image/a5.png" alt="a5">
</div>

> *Tham khảo ý kiến khán giả*
- Ban tổ chức sẽ khảo sát đáp án từ khán giả và cho ra thống kê về 
các đáp án lựa chọn. Người chơi sẽ quyết định dựa vào kết quả đó.
<div align="center">
  <img src="image/a6.png" alt="a6">
</div>

### 3.5. Đúng/ Sai
> *Khi người chơi trả lời đúng thì được đi tiếp câu hỏi tiếp theo*

<div align="center">
  <img src="image/a7.png" alt="a7">
</div>


> *Khi người chơi trả lời sai thì buộc dừng cuộc chơi*

<div align="center">
  <img src="image/a8.png" alt="a8">
</div>

## 4. Lưu trữ thông tin

Danh sách các phòng và khách hàng sẽ được lưu lần lượt tại các tệp văn bản 
`questions.txt` trong thư mục ***millionaireGame***, nằm cùng thư mục với các mã nguồn
`.cpp`.

---

# III. PHỤ LỤC

---
## 1. Các thư viện sử dụng

- `iostream` để xử lý nhập xuất dữ liệu.
- `conio.h` để đọc phím bấm, xử lý dữ liệu không đồng bộ.
- `iomanip` giúp việc định dạng dữ liệu rõ ràng và dễ nhìn hơn
- `fstream` để xử lý nhập xuất file.
- `string` để có thể sử dụng chuỗi và các hàm đã cài đặt sẵn cho chuỗi.
- `windows.h`để có thể sử dụng các hàm chỉ riêng cho hệ điều hành Window.
- `mmsystem.h` để xử lý âm thanh
- `chrono` để tính toán thời gian

## 2. Tài liệu tham khảo

- https://downloads.khinsider.com/game-soundtracks/album/who-wants-to-be-a-millionaire-the-album
- https://github.com/TamasPetii/Who-wants-to-be-a-millionaire
---



