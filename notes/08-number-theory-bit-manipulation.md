# Lesson 8 - Number Theory & Bit Manipulation

## 1. Định lý Euclid mở rộng (Extended Euclidean Algorithm)

- **Mục đích:** Tìm Ước chung lớn nhất $\gcd(a,b)$ và hai hệ số nguyên $x, y$ (hệ số Bézout) thỏa mãn phương trình Diophantine tuyến tính:

$$a \cdot x + b \cdot y = \gcd(a,b)$$

- **Công thức quy nạp:** Dựa vào $\gcd(a, b) = \gcd(b, a \pmod b)$, giả sử lớp đệ quy dưới giải xong và trả về $x_1, y_1$ sao cho:

$$b \cdot x_1 + (a \pmod b) \cdot y_1 = \gcd(a, b)$$

Bằng cách thay $a \pmod b = a - \lfloor \frac{a}{b} \rfloor \cdot b$, ta rút gọn được công thức cập nhật ngược lên cho lớp hiện tại:

- $x = y_1$
- $y = x_1 - \lfloor \frac{a}{b} \rfloor \cdot y_1$

- **Độ phức tạp thời gian (Time Complexity):** $\mathcal{O}(\log(\min(a,b)))$

**Pseudocode:**

```plaintext
Function Extended_GCD(a, b):
    // Trường hợp cơ sở
    If b == 0:
        Return (a, 1, 0)  // Trả về (gcd, x, y)

    // Đệ quy đi xuống
    (g, x1, y1) = Extended_GCD(b, a % b)

    // Tính toán hệ số x, y khi đi lên
    x = y1
    y = x1 - floor(a / b) * y1

    Return (g, x, y)

```

## 2. Nghịch đảo Modulo & Định lý Fermat nhỏ

- **Nghịch đảo Modulo:** Tìm số $x$ sao cho $a \cdot x \equiv 1 \pmod m$. Điều kiện bắt buộc để $x$ tồn tại là $\gcd(a, m) = 1$ (hai số phải nguyên tố cùng nhau).

### Cách 1: Dùng Euclid mở rộng

Biến đổi quan hệ đồng dư thành phương trình:

$$a \cdot x + m \cdot y = 1$$

Áp dụng thuật toán ở mục 1 để tìm $x$.

### Cách 2: Dùng Định lý Fermat nhỏ

_(Chỉ áp dụng khi $m$ là số nguyên tố)_

Nếu $m$ là số nguyên tố và $a$ không chia hết cho $m$, định lý phát biểu:

$$a^{m-1} \equiv 1 \pmod m$$

Tách số mũ ra, ta được $a \cdot a^{m-2} \equiv 1 \pmod m$. Vậy nghịch đảo modulo của $a$ chính là $a^{m-2} \pmod m$.

> **Nhận xét:** Cách này cài đặt rất đơn giản, chỉ cần dùng thuật toán Lũy thừa nhị phân (Binary Exponentiation) để tính $a^{m-2} \pmod m$ trong thời gian $\mathcal{O}(\log m)$.

## Ghi chú: Cách tiếp cận Bài 7 - Ex 2

Ban đầu, khi phân tích đề bài, mình xác định được công thức tổng quát để giải quyết bài toán là:

$$\frac{n!}{k_1! \cdot k_2! \cdot k_3! \dots} \pmod{\text{MOD}}$$

Với $\text{MOD} = 10^9 + 7$. Tuy nhiên, cách triển khai thuật toán ban đầu của mình lại khá dài dòng và phức tạp.

### 1. Hướng tiếp cận ban đầu (Chưa tối ưu)

- Trước tiên, mình đếm tần số xuất hiện của các ký tự trong chuỗi $s$ có độ dài $n$ để xác định các giá trị $k$.
- Sử dụng thuật toán Sàng nguyên tố (Sieve) để tìm các số nguyên tố nhỏ hơn hoặc bằng $n$.
- Sử dụng Lũy thừa nhị phân (Binary Exponentiation) để xác định số mũ lớn nhất của từng số nguyên tố trong $n!$. Nói cách khác, mình phân tích $n!$ thành tích các thừa số nguyên tố kèm theo số mũ tương ứng.
- Áp dụng quy trình tương tự cho các dãy $k$. Việc phải duyệt qua từng $k_i$ và lặp lại thao tác phân tích như với $n$ khiến toàn bộ quá trình trở nên cực kỳ dài dòng, chưa tính đến độ phức tạp của việc tính kết quả modulo cuối cùng.

### 2. Vấn đề của phương pháp cũ

Sau khi nghiên cứu kỹ hơn, mình nhận ra hướng đi trước đó mắc phải hai nhược điểm lớn:

- **Sai lầm về toán học trong xử lý modulo:** Trong số học modulo, ta không thể thực hiện phép chia trực tiếp. Để chia dư, bắt buộc phải tìm **Nghịch đảo Modulo (Modular Multiplicative Inverse)** của mẫu số trước khi thực hiện phép nhân.
- **Dư thừa vòng lặp và tốn kém thời gian:** Việc phân tích từng giai thừa ra thừa số nguyên tố là không cần thiết.

### 3. Giải pháp tối ưu hóa

Thay vì xử lý và phân tích từng giai thừa một cách thủ công, cách tiếp cận chuẩn xác và ngắn gọn hơn là:

- Tiền tính (precompute) mảng giai thừa bằng cách tạo một `vector` (ví dụ: `frac`) để lưu trữ giá trị của từng giai thừa sau khi đã chia dư cho $\text{MOD}$.
- Khi tính toán, chỉ cần lấy các giá trị từ `vector` này kết hợp với thuật toán Nghịch đảo Modulo. Chi tiết triển khai cấu trúc này có thể tham khảo trong mã nguồn của Bài 7 - Ex 2.

Việc sửa đổi và tự mày mò lại thuật toán không chỉ giúp tối ưu hóa mã nguồn mà còn giúp mình củng cố và hiểu sâu sắc hơn về bản chất của tổ hợp toán học và xử lý modulo.

## 3. Nguyên lý bù trừ (Inclusion-Exclusion Principle)

- **Mục đích:** Được sử dụng trong toán học tổ hợp để đếm chính xác số lượng phần tử của hợp nhiều tập hợp. Nguyên lý này hoạt động bằng cách cộng tổng số phần tử của các tập hợp đơn lẻ, sau đó "trừ đi" các phần giao nhau (để loại bỏ việc đếm trùng), và tiếp tục "bù lại" phần giao của nhiều tập hợp hơn.
- **Công thức với 2 tập hợp ($A$ và $B$):**

$$\vert{}A \cup B\vert{} = \vert{}A\vert{} + \vert{}B\vert{} - \vert{}A \cap B\vert{}$$

- **Công thức với 3 tập hợp ($A$, $B$ và $C$):**

$$\vert{}A \cup B \cup C\vert{} = \vert{}A\vert{} + \vert{}B\vert{} + \vert{}C\vert{} - \vert{}A \cap B\vert{} - \vert{}A \cap C\vert{} - \vert{}B \cap C\vert{} + \vert{}A \cap B \cap C\vert{}$$

## 4. Thuật toán sinh (Generation Algorithm)

- **Mục đích:** Xử lý các bài toán yêu cầu duyệt qua toàn bộ các trường hợp có thể xảy ra (Kỹ thuật vét cạn - Brute-force).
- **Điều kiện bắt buộc để áp dụng:**

1. Xác định được rõ ràng cấu hình đầu tiên của bài toán.
2. Xác định được dấu hiệu nhận biết cấu hình cuối cùng.
3. Thiết lập được quy tắc/thuật toán để từ một cấu hình hiện tại, ta có thể sinh ra được cấu hình kế tiếp theo một thứ tự từ điển hoặc quy luật nhất định.

- **Mã giả (Pseudocode):**

```plaintext
Bước 1: Khởi tạo <Cấu hình đầu tiên>
Bước 2: While (Chưa gặp <Cấu hình cuối cùng>) {
            In ra / Xử lý <Cấu hình hiện tại>
            Sinh ra <Cấu hình kế tiếp>
        }
Bước 3: In ra / Xử lý <Cấu hình cuối cùng>

```

> **Lưu ý tối ưu code:** Trong thực tế khi lập trình C/C++, người ta thường dùng một vòng lặp `while(true)` hoặc `do...while` kết hợp với một cờ (flag) đánh dấu `is_final` để gộp Bước 3 vào bên trong vòng lặp, giúp code gọn gàng hơn và tránh bị lặp lại thao tác xử lý cấu hình cuối.
