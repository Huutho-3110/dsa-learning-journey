# Lesson 07: Number Theory & Combinatorics (Lý thuyết số - Toán học)

# 1. Đồng dư (Modular Arithmetic)

Đồng dư cho phép thực hiện các phép toán trên số rất lớn bằng cách chỉ quan tâm đến phần dư khi chia cho `MOD`.

## Các tính chất

### Phép cộng

```text
(a + b) % MOD = ((a % MOD) + (b % MOD)) % MOD
```

### Phép trừ

```text
(a - b) % MOD = ((a % MOD) - (b % MOD) + MOD) % MOD
```

> **Lưu ý:** Trong C++, toán tử `%` có thể trả về số âm. Vì vậy nên cộng thêm `MOD` trước khi `% MOD`.

Ví dụ

```cpp
int x = (a - b + MOD) % MOD;
```

### Phép nhân

```text
(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD
```

---

# 2. Binary Exponentiation

## Mục đích

Tính

```text
A^B mod M
```

với độ phức tạp

```text
O(log B)
```

thay vì

```text
O(B)
```

## Ý tưởng

### Base Case

```text
A^0 = 1
```

### Nếu số mũ chẵn

```text
A^B = (A^(B/2))²
```

### Nếu số mũ lẻ

```text
A^B = A × A^(B-1)
```

---

## Recursive Implementation

```cpp
long long binpow(long long a, long long b, long long mod) {
    if (b == 0) return 1;

    long long half = binpow(a, b / 2, mod);
    long long result = (half * half) % mod;

    if (b % 2)
        result = (result * a) % mod;

    return result;
}
```

---

## Iterative Implementation (Khuyên dùng)

```cpp
long long binpow(long long a, long long b, long long mod) {
    a %= mod;
    long long res = 1;

    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}
```

**Complexity**

- Time: `O(log B)`
- Memory: `O(1)` (iterative)

---

# 3. Prime Factorization & Number of Divisors

## Định lý

Mọi số nguyên dương đều có thể phân tích duy nhất thành tích các lũy thừa của số nguyên tố.

```text
N = p1^x1 × p2^x2 × ... × pk^xk
```

## Công thức số lượng ước

```text
(x1 + 1)(x2 + 1)...(xk + 1)
```

Trong đó `xi` là số mũ của từng thừa số nguyên tố.

---

## Implementation

```cpp
int countDivisors(long long n) {
    int ans = 1;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int exponent = 0;

            while (n % i == 0) {
                exponent++;
                n /= i;
            }

            ans *= (exponent + 1);
        }
    }

    if (n > 1)
        ans *= 2;

    return ans;
}
```

**Complexity**

```text
O(√N)
```

---

# 4. Legendre Formula

## Mục đích

Tìm số mũ lớn nhất của số nguyên tố `p` trong `N!`.

Ví dụ

```text
10! chia hết cho 2^8
```

thì đáp án là

```text
8
```

## Công thức

```text
floor(N / P)
+ floor(N / P²)
+ floor(N / P³)
+ ...
```

---

## Vì sao C++ không cần floor()?

Trong C++, phép chia số nguyên luôn lấy phần nguyên.

Ví dụ

```cpp
7 / 2 = 3
15 / 4 = 3
20 / 6 = 3
```

Do đó

```cpp
n / p
```

đã chính là

```text
floor(n / p)
```

---

## Implementation

```cpp
long long legendre(long long n, long long p) {
    long long ans = 0;

    while (n) {
        n /= p;
        ans += n;
    }

    return ans;
}
```

**Complexity**

```text
O(logₚ N)
```

---

# 5. Sieve of Eratosthenes

## Complexity

```text
O(N log log N)
```

## Base Cases

```text
0 không phải số nguyên tố.

1 không phải số nguyên tố.
```

---

## Sieve Implementation

```cpp
vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!prime[i]) continue;

        for (int j = i * i; j <= n; j += i)
            prime[j] = false;
    }

    return prime;
}
```

---

# Segmented Sieve

## Khi nào dùng?

Khi

- N rất lớn (10¹², 10¹⁸...)
- nhưng chỉ cần prime trong đoạn `[L, R]`
- với `R - L ≤ 10⁷`

---

## Tìm bội đầu tiên

```cpp
long long start = max(i * i, ((L + i - 1) / i) * i);
```

---

## Implementation

```cpp
vector<long long> segmentedSieve(long long L, long long R) {

    long long limit = sqrt(R);

    vector<bool> prime(limit + 1, true);

    vector<bool> isPrime(R - L + 1, true);

    for (long long i = 2; i * i <= limit; i++) {
        if (!prime[i]) continue;

        for (long long j = i * i; j <= limit; j += i)
            prime[j] = false;
    }

    for (long long i = 2; i <= limit; i++) {

        if (!prime[i]) continue;

        long long start = max(i * i, ((L + i - 1) / i) * i);

        for (long long j = start; j <= R; j += i)
            isPrime[j - L] = false;
    }

    if (L == 1)
        isPrime[0] = false;

    vector<long long> ans;

    for (long long i = L; i <= R; i++)
        if (isPrime[i - L])
            ans.push_back(i);

    return ans;
}
```

---

# 6. Stars and Bars

Cho `N` vật giống nhau chia cho `K` nhóm.

---

## Trường hợp 1

Mỗi nhóm có **ít nhất 1 phần tử**

```text
C(N - 1, K - 1)
```

Ví dụ

```text
7 viên kẹo

3 đứa trẻ

=> C(6,2)
```

---

## Trường hợp 2

Có thể có nhóm rỗng

Quy đổi:

Thêm `K` viên kẹo giả (hoặc tương đương chuyển điều kiện về mỗi nhóm có ít nhất một phần tử).

Công thức

```text
C(N + K - 1, K - 1)
```

Ví dụ

```text
7 viên kẹo

3 đứa trẻ

=> C(9,2)
```

---

## Khi nào sử dụng?

- Chia kẹo
- Chia bi
- Phân phối tài nguyên
- Chọn nghiệm nguyên không âm
- Tổ hợp có lặp

**Complexity**

```text
O(1)
```

(khi đã tiền xử lý giai thừa và nghịch đảo modulo)

---

# 7. Định lý Euclid mở rộng (Extended Euclidean Algorithm)

---

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

---

# 8. Nghịch đảo Modulo & Định lý Fermat nhỏ

---

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

```

```

---

# 9. Nguyên lý bù trừ (Inclusion-Exclusion Principle)

---

- **Mục đích:** Được sử dụng trong toán học tổ hợp để đếm chính xác số lượng phần tử của hợp nhiều tập hợp. Nguyên lý này hoạt động bằng cách cộng tổng số phần tử của các tập hợp đơn lẻ, sau đó "trừ đi" các phần giao nhau (để loại bỏ việc đếm trùng), và tiếp tục "bù lại" phần giao của nhiều tập hợp hơn.
- **Công thức với 2 tập hợp ($A$ và $B$):**

$$\vert{}A \cup B\vert{} = \vert{}A\vert{} + \vert{}B\vert{} - \vert{}A \cap B\vert{}$$

- **Công thức với 3 tập hợp ($A$, $B$ và $C$):**

$$\vert{}A \cup B \cup C\vert{} = \vert{}A\vert{} + \vert{}B\vert{} + \vert{}C\vert{} - \vert{}A \cap B\vert{} - \vert{}A \cap C\vert{} - \vert{}B \cap C\vert{} + \vert{}A \cap B \cap C\vert{}$$

# ✅ Self-Check

- [ ] Vì sao Binary Exponentiation có độ phức tạp $O(\log n)$?
- [ ] Vì sao khi phân tích thừa số nguyên tố chỉ cần duyệt đến $\sqrt{N}$?
- [ ] Tại sao công thức Legendre lại cộng các giá trị $\left\lfloor \frac{N}{P^i} \right\rfloor$?
- [ ] Sieve thường khác Segmented Sieve ở điểm nào?
- [ ] Khi nào nên dùng Stars and Bars?
- [ ] Công thức chia kẹo có điều kiện "ít nhất một viên" khác "có thể không nhận viên nào" ở đâu?

---

# 📝 Answers

1. Về cơ bản, thuật toán Binary Exponentiation (lũy thừa nhị phân) sẽ chia đôi liên tục số mũ. Với mỗi lần chia cho $2$, số bước thực hiện tương đương với cơ số $2$ của số mũ, dẫn đến độ phức tạp thời gian (Time Complexity) là $\mathcal{O}(\log N)$.
2. Khi phân tích thừa số nguyên tố, ta chỉ cần duyệt đến $N$ vì không có số nguyên $N$ nào có thể chứa một thừa số nguyên tố lớn hơn chính nó.
3. Công thức Legendre được sử dụng để tính số mũ cao nhất $x$ của một số nguyên tố $p$ sao cho $N!$ chia hết cho $p^x$. Với mỗi lần chia cho $p$, ta tính được số lượng các số chia hết cho $p$ trong khoảng từ $1$ đến $N$. Mỗi số như vậy được coi là $p$ đóng góp $1$ lần. Do đó, ta cộng các giá trị $\lfloor \frac{N}{p} \rfloor$ (và các bậc cao hơn) để tính tổng số lần $p$ đóng góp, từ đó xác định được số mũ $x$.
4. Sự khác biệt giữa Sieve và Segmented Sieve:

- **Sieve of Eratosthenes** được dùng để tìm tất cả các số nguyên tố nằm trong đoạn từ $1$ đến $N$ với $N$ có giới hạn vừa đủ.
- **Segmented Sieve** được dùng để tìm tất cả các số nguyên tố trong một khoảng $[L, R]$ với giới hạn rất lớn.

5. Phương pháp Stars and Bars (bài toán chia kẹo) được áp dụng khi cần phân chia một số lượng $P$ cho $N$ đối tượng sao cho mỗi đối tượng nhận được ít nhất $1$ phần tử.
6. Sự khác biệt trong các điều kiện của bài toán chia kẹo:

- **Điều kiện "ít nhất một viên":** Ta chỉ cần đặt các vách ngăn nằm ở các khoảng trống ở giữa $2$ viên kẹo.
- **Điều kiện "có thể không nhận viên nào":** Ta có thể đặt các vách ngăn ở những vị trí ngoài rìa (tức là có thể đặt liền kề với một viên kẹo hoặc sát mép ngoài).
