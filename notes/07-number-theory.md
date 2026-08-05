# Lesson 07: Number Theory & Combinatorics
## 1. Đồng dư (Modular Arithmetic)

- **Tính chất phép cộng:**
  $$
  (a+b)\bmod m=((a\bmod m)+(b\bmod m))\bmod m
  $$

- **Tính chất phép trừ:**
  $$
  (a-b)\bmod m=((a\bmod m)-(b\bmod m)+m)\bmod m
  $$

  - _Lưu ý: Trong C++, nên cộng thêm `m` trước khi `% m` để tránh kết quả âm._

- **Tính chất phép nhân:**
  $$
  (a\times b)\bmod m=((a\bmod m)\times(b\bmod m))\bmod m
  $$

---

## 2. Lũy thừa nhị phân (Binary Exponentiation)

- **Mục đích:** Tính

  $$
  A^B \pmod M
  $$

  với độ phức tạp **$O(\log B)$**.

### Tư duy đệ quy (Chia để trị)

- **Trường hợp cơ sở (Base case):**
  Khi số mũ bằng `0` thì

  $$
  A^0=1
  $$

  nên trả về `1`.

- **Nếu số mũ chẵn:**

  Chia bài toán thành

  $$
  A^B=(A^{B/2})^2
  $$

  rồi lấy modulo.

- **Nếu số mũ lẻ:**

  Tách ra

  $$
  A^B=A\times A^{B-1}
  $$

  hoặc

  $$
  A^B=A\times(A^{B/2})^2
  $$

  rồi lấy modulo.

### Code Implementation

```cpp
// Tự gõ lại hàm:
//
// long long binpow(long long a, long long b, long long m)
//
// Lưu ý:
// - Sử dụng kiểu long long.
// - Không nhìn lời giải.
// - Sau khi hoàn thành hãy tự phân tích độ phức tạp.
```

---

## 3. Phân tích thừa số nguyên tố & Số lượng ước

- **Định lý cơ bản:** Một số nguyên dương $N$ luôn phân tích được thành

$$
N=p_1^{x_1}\cdot p_2^{x_2}\cdots p_k^{x_k}
$$

- **Công thức đếm tổng số ước:**

$$
(x_1+1)(x_2+1)\cdots(x_k+1)
$$

Trong đó $x_i$ là số mũ của từng thừa số nguyên tố.

### Code Implementation

```cpp
// Tự gõ lại hàm:
//
// int countDivisors(long long n)
//
// Gợi nhớ:
// - Điều kiện dừng tối ưu của vòng for là i * i <= n.
// - Vì sao chỉ cần duyệt đến sqrt(n)?
// - Đừng quên xử lý trường hợp còn lại khi n > 1.
```

---

## 4. Công thức Legendre (Bậc của thừa số nguyên tố)

- **Mục đích:** Tìm số mũ lớn nhất $X$ sao cho

$$
P^X\mid N!
$$

- **Công thức Toán học:**

$$
X=\left\lfloor\frac{N}{P}\right\rfloor+
\left\lfloor\frac{N}{P^2}\right\rfloor+
\left\lfloor\frac{N}{P^3}\right\rfloor+\cdots
$$

### Tương quan với C++

**Câu hỏi**

Tại sao phép chia số nguyên (`/`) trong C++ lại phản ánh chính xác công thức trên mà không cần dùng `floor()`?

**Trả lời**

Trong C++, khi chia hai số nguyên, kết quả tự động lấy phần nguyên (integer division), tức là:

```cpp
7 / 2 = 3
9 / 4 = 2
```

Điều này đúng với toán tử

$$
\left\lfloor\frac{a}{b}\right\rfloor
$$

nên không cần gọi `floor()`.

### Code Implementation

```cpp
// Tự gõ lại:
//
// long long legendre(long long n, long long p)
//
// Sau khi viết xong hãy tự giải thích:
// - Vì sao n /= p sau mỗi vòng lặp?
// - Vì sao thuật toán chạy rất nhanh?
```

---

## 5. Sàng số nguyên tố (Sieve of Eratosthenes)

- **Độ phức tạp thuật toán:**

$$
O(N\log\log N)
$$

### Base Cases

- Số **0** không phải số nguyên tố.
- Số **1** không phải số nguyên tố.

### Sàng phân đoạn (Segmented Sieve)

**Khi nào sử dụng?**

Khi:

- $N$ rất lớn.
- Nhưng độ dài đoạn

$$
|A-B|
$$

nhỏ (ví dụ $\le10^7$).

**Công thức tìm bội đầu tiên của $i$ không nhỏ hơn $A$:**

$$
\max(i^2,\left\lceil\frac{A}{i}\right\rceil\times i)
$$

Trong C++ thường viết:

```cpp
max(i * i, ((A + i - 1) / i) * i)
```

### Code Implementation

```cpp
// Tự gõ lại:
//
// void segmentedSieve(long long A, long long B)
//
// Gợi nhớ:
//
// - Tạo 2 vector<bool>
// - Một vector cho prime.
// - Một vector cho đoạn [A, B].
// - Tự nhớ cách đánh dấu các bội.
```

---

## 6. Bài toán chia kẹo Euler (Stars and Bars)

### Trường hợp 1

Có:

- $N$ viên kẹo
- $K$ đứa trẻ
- Mỗi đứa nhận **ít nhất 1 viên**

**Công thức tổ hợp**

$$
\boxed{\binom{N-1}{K-1}}
$$

---

### Trường hợp 2

Có:

- $N$ viên kẹo
- $K$ đứa trẻ
- Có thể có đứa **không nhận viên nào**

**Kỹ thuật quy đổi**

Thêm **$K-1$ thanh ngăn (bars)** vào giữa các viên kẹo hoặc quy đổi bằng cách thêm **$K$ viên kẹo giả** để biến bài toán thành trường hợp mỗi nhóm có ít nhất một phần tử.

> Gợi nhớ: Sau phép quy đổi, bài toán trở thành chia **$N+K$** đối tượng với điều kiện mỗi nhóm đều có ít nhất một phần tử.

**Công thức tổ hợp**

$$
\boxed{\binom{N+K-1}{K-1}}
$$đ
# ✅ Self-Check

- [ ] Vì sao Binary Exponentiation có độ phức tạp $O(\log n)$?
- [ ] Vì sao khi phân tích thừa số nguyên tố chỉ cần duyệt đến $\sqrt{N}$?
- [ ] Tại sao công thức Legendre lại cộng các giá trị $\left\lfloor \frac{N}{P^i} \right\rfloor$?
- [ ] Sieve thường khác Segmented Sieve ở điểm nào?
- [ ] Khi nào nên dùng Stars and Bars?
- [ ] Công thức chia kẹo có điều kiện "ít nhất một viên" khác "có thể không nhận viên nào" ở đâu?

---

# 📝 Reflection

- Phần khó nhớ nhất:
  - `[...]`

- Thuật toán cần luyện lại:
  - `[...]`

- Sai lầm mình từng mắc:
  - `[...]`

- Mức độ nhớ bài (0–10):
  - `[...]`

- Ngày ôn lại tiếp theo:
  - `[...]`
