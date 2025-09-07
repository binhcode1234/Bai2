#  BÀI TẬP GPIO STM32  (Keil C)

2 project demo cơ bản trên vi điều khiển **STM32F103C8T6 (Blue Pill)**, lập trình bằng **Keil C**, nhằm làm quen với GPIO, LED và nút nhấn.

---

## 📝 Nội dung

### 🔹 Bài 1: Nhấp nháy LED nhiều chân GPIO (500 ms)
- **File code:** `bai2-1.c`  
- **Mô tả:** 
  - Sử dụng **GPIOA (PA0, PA1, PA2)** và **GPIOB (PB0, PB1, PB10)**.  
  - Các LED trên **GPIOA** và **GPIOB** nhấp nháy **luân phiên** với chu kỳ 500 ms.  
- **Nguyên lý:**  
  - Bật clock cho Port A và B.  
  - Cấu hình các chân ở chế độ **Output Push-Pull**, tốc độ 2 MHz.  
  - Vòng lặp chính:  
    - Bật LED trên Port A, tắt LED trên Port B.  
    - Delay 500 ms.  
    - Ngược lại, tắt LED trên Port A, bật LED trên Port B.  

---

### 🔹 Bài 2: Điều khiển LED bằng nút nhấn (toggle)
- **File code:** `bai2-2.c`  
- **Mô tả:**  
  - Sử dụng **GPIOA (PA0)** làm LED output.  
  - Sử dụng **GPIOC (PC14)** làm input (nút nhấn).  
  - Mỗi lần nhấn nút, LED sẽ **đổi trạng thái (bật/tắt)**.  
- **Nguyên lý:**  
  - Bật clock cho Port A và C.  
  - PA0 cấu hình Output Push-Pull, PC14 cấu hình Input Pull-Up.  
  - Khi nút nhấn (PC14 = 0):  
    - Chống dội phím bằng delay 20 ms.  
    - Đọc lại trạng thái → nếu vẫn = 0, thì đổi trạng thái biến `LED`.  
    - LED = 1 → bật PA0.  
    - LED = 0 → tắt PA0.  
    - Giữ cho đến khi nhả nút (tránh lặp liên tục).  

---

## ⚙️ Yêu cầu phần cứng
- **Board:** STM32F103C8T6 ("Blue Pill")  
- **Nguồn:** 3.3V hoặc USB + ST-Link  
- **Ngoại vi:**
  - Bài 1: LED nối vào PA0, PA1, PA2, PB0, PB1, PB10.  
  - Bài 2: LED nối vào PA0, nút nhấn nối PC14 (kéo lên bằng điện trở).  

---

## 🖥️ Yêu cầu phần mềm
- **Keil µVision IDE**  
- **STM32 Standard Peripheral Library**  
- **ST-Link Utility** để nạp code  

