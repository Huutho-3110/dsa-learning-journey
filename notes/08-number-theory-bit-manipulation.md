---

# Các Thuật Toán Sinh (Generation Algorithms)

## Tổng quan (Overview)

Thuật toán sinh là phương pháp dùng để liệt kê tất cả các cấu hình có thể có của một bài toán tổ hợp.
Thay vì dùng đệ quy, thuật toán sinh hoạt động dựa trên một vòng lặp với logic cốt lõi:

1. Bắt đầu từ **cấu hình đầu tiên**.
2. Kiểm tra xem đã tới **cấu hình cuối cùng** chưa.
3. Nếu chưa, in ra cấu hình hiện tại và dùng thuật toán để **sinh ra cấu hình kế tiếp**.

**Khuôn mẫu chung (Mã giả tổng quát):**

```text
Khởi tạo cấu hình đầu tiên;
while (Chưa đạt cấu hình cuối cùng) {
    Xử lý/In cấu hình hiện tại;
    Sinh ra cấu hình kế tiếp;
}

```

Dưới đây là chi tiết 4 thuật toán sinh cơ bản nhất trong Khoa học Máy tính.

---

## 1. Thuật toán sinh xâu nhị phân (Binary String Generation)

### Ý nghĩa & Mục đích (Theory)

- **Dùng để làm gì:** Liệt kê tất cả các xâu (mảng) có độ dài $N$ chỉ gồm 2 ký tự `0` và `1`.
- **Dùng khi nào:** Khi bài toán yêu cầu xét tất cả các trạng thái Đúng/Sai, Có/Không. Ví dụ: Bài toán cái túi (chọn hoặc không chọn đồ vật), bài toán liệt kê tất cả tập con của một tập hợp.
- **Ý nghĩa:** Tương đương với việc đếm các số trong hệ nhị phân từ $0$ đến $2^N - 1$.

### Trạng thái điều kiện

- **Cấu hình đầu tiên:** Xâu toàn bit `0` (VD: `0000`).
- **Khi nào tiếp tục:** Khi xâu chưa phải là toàn bit `1`.
- **Khi nào dừng (Cấu hình cuối):** Xâu toàn bit `1` (VD: `1111`).

### Thuật toán cài đặt (Logic)

_Thuật toán sinh bằng mảng:_ Quét từ cuối mảng (bên phải) lên đầu. Tìm bit `0` đầu tiên gặp được.

1. Đổi bit `0` đó thành `1`.
2. Đổi toàn bộ các bit phía sau (bên phải) nó thành `0`.

_Mở rộng: Sinh bằng toán tử bit (Bitwise)_
Chỉ cần chạy một vòng lặp $i$ từ $0$ đến $2^N - 1$. Biểu diễn nhị phân của số $i$ chính là một cấu hình.

### Mã giả & C++ Code (Cách dùng mảng)

```cpp
// Độ phức tạp thời gian: O(2^N)
// Độ phức tạp không gian: O(N)
#include <iostream>
using namespace std;

int a[100], n;
bool isFinal = false; // Cờ đánh dấu cấu hình cuối

void sinh() {
    int i = n;
    // Tìm bit 0 đầu tiên từ phải sang trái
    while (i >= 1 && a[i] == 1) {
        a[i] = 0; // Đổi các bit 1 ở cuối thành 0
        i--;
    }
    if (i == 0) {
        isFinal = true; // Đã đến cấu hình 11...1
    } else {
        a[i] = 1; // Đổi bit 0 tìm được thành 1
    }
}

int main() {
    n = 4; // Ví dụ n = 4
    for(int i = 1; i <= n; i++) a[i] = 0; // Khởi tạo cấu hình đầu

    while (!isFinal) {
        for(int i = 1; i <= n; i++) cout << a[i]; // In cấu hình
        cout << endl;
        sinh(); // Sinh cấu hình tiếp theo
    }
    return 0;
}

```

---

## 2. Thuật toán sinh tập con (Subset / Combination Generation)

### Ý nghĩa & Mục đích (Theory)

- **Dùng để làm gì:** Liệt kê tất cả các tổ hợp chập $K$ của $N$ phần tử.
- **Dùng khi nào:** Cần chọn ra một nhóm $K$ phần tử từ $N$ phần tử mà **không quan tâm đến thứ tự**. Ví dụ: Chọn 3 học sinh từ 10 học sinh đi thi.

### Trạng thái điều kiện

- **Giới hạn giá trị:** Tại vị trí thứ $i$, giá trị lớn nhất có thể đạt được là $N - K + i$.
- **Cấu hình đầu tiên:** `1, 2, ..., K` (Các phần tử nhỏ nhất).
- **Khi nào tiếp tục:** Khi vẫn còn ít nhất một phần tử chưa đạt giá trị lớn nhất.
- **Khi nào dừng (Cấu hình cuối):** Tất cả phần tử đều đạt giá trị lớn nhất: `N-K+1, N-K+2, ..., N`.

### Thuật toán cài đặt (Logic)

Quét mảng từ phải sang trái để tìm phần tử $a_i$ đầu tiên **chưa đạt** giá trị lớn nhất ($a_i < N - K + i$).

1. Tăng $a_i$ lên 1 đơn vị.
2. Cập nhật các phần tử đứng sau $a_i$ sao cho chúng bằng phần tử ngay trước nó cộng 1 ($a_j = a_{j-1} + 1$).

### Mã giả & C++ Code

```cpp
// Mảng a lưu trữ chỉ số từ 1 đến K
int a[100], n = 5, k = 3;
bool isFinal = false;

void sinh() {
    int i = k;
    // Tìm phần tử chưa đạt giới hạn lớn nhất (N - K + i)
    while (i >= 1 && a[i] == n - k + i) {
        i--;
    }
    if (i == 0) {
        isFinal = true;
    } else {
        a[i]++; // Tăng giá trị tại i lên 1
        // Các phần tử phía sau cập nhật tăng dần 1 đơn vị
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        }
    }
}

```

---

## 3. Thuật toán sinh hoán vị (Permutation Generation)

### Ý nghĩa & Mục đích (Theory)

- **Dùng để làm gì:** Liệt kê tất cả các cách sắp xếp thứ tự của $N$ phần tử. Số lượng cấu hình là $N!$.
- **Dùng khi nào:** Khi thứ tự sắp xếp là quan trọng. Ví dụ: Bài toán người đi du lịch (TSP), xếp lịch trực nhật, tìm đường đi.

### Trạng thái điều kiện

- **Cấu hình đầu tiên:** Mảng được sắp xếp tăng dần hoàn toàn (VD: `1, 2, 3, 4`).
- **Khi nào tiếp tục:** Khi mảng chưa phải là giảm dần hoàn toàn.
- **Khi nào dừng (Cấu hình cuối):** Mảng được sắp xếp giảm dần hoàn toàn (VD: `4, 3, 2, 1`).

### Thuật toán cài đặt (Logic)

1. Quét từ phải sang trái tìm vị trí $i$ đầu tiên sao cho $a[i] < a[i+1]$ (Tìm điểm gãy).
2. Nếu không tìm thấy (tức $i=0$), dãy đã là giảm dần $\Rightarrow$ Dừng.
3. Nếu tìm thấy, dò từ cuối mảng ngược về $i+1$, tìm phần tử $a[k]$ nhỏ nhất mà $a[k] > a[i]$.
4. Hoán vị (Swap) $a[i]$ và $a[k]$.
5. Lật ngược (Reverse) đoạn từ $i+1$ đến cuối mảng để tạo thành đoạn tăng dần (nhỏ nhất ở phần còn lại).

### Mã giả & C++ Code

```cpp
int a[100], n = 4;
bool isFinal = false;

void sinh() {
    int i = n - 1;
    // 1. Tìm điểm gãy (phần tử đứng trước nhỏ hơn phần tử đứng sau)
    while (i >= 1 && a[i] > a[i + 1]) {
        i--;
    }
    if (i == 0) {
        isFinal = true;
    } else {
        // 2. Tìm phần tử > a[i] nằm cuối cùng (vì đoạn sau đang giảm dần)
        int k = n;
        while (a[k] < a[i]) k--;

        // 3. Đổi chỗ
        swap(a[i], a[k]);

        // 4. Lật ngược đoạn từ i+1 đến n
        int l = i + 1, r = n;
        while (l < r) {
            swap(a[l], a[r]);
            l++; r--;
        }
    }
}

```

_(Ghi chú: Trong C++, bạn có thể dùng trực tiếp hàm `next_permutation()` trong thư viện `<algorithm>` để thay thế logic này khi đi làm thực tế)._

---

## 4. Thuật toán sinh phân hoạch (Partition Generation)

### Ý nghĩa & Mục đích (Theory)

- **Dùng để làm gì:** Tìm tất cả các cách phân tích số nguyên dương $N$ thành tổng của các số nguyên dương $\le N$.
- **Dùng khi nào:** Trong các bài toán chia tài nguyên, đổi tiền, chia kẹo (khi các phần tử có thể lặp lại và không phân biệt thứ tự).

### Trạng thái điều kiện

- **Cấu hình đầu tiên:** Chỉ có đúng 1 phần tử mang giá trị $N$ (VD: $N=5 \Rightarrow$ `[5]`).
- **Khi nào tiếp tục:** Khi mảng chưa phải là mảng toàn số 1.
- **Khi nào dừng (Cấu hình cuối):** Mảng gồm $N$ số 1 (VD: $N=5 \Rightarrow$ `[1, 1, 1, 1, 1]`).

### Thuật toán cài đặt (Logic)

Do mảng thay đổi độ dài liên tục, ta cần biến `cnt` để lưu số lượng phần tử hiện tại.

1. Quét từ phải sang trái tìm phần tử $a_i$ đầu tiên khác 1.
2. Giảm $a_i$ đi 1 đơn vị. Lấy lượng vừa giảm đó cộng vào phần "dư thừa" (lượng bù đắp = các phần tử số 1 phía sau gộp lại + 1 đơn vị vừa giảm).
3. Đem lượng "dư thừa" này chia đều ra phía sau sao cho các phần tử sau lớn nhất có thể (chỉ được tối đa bằng $a_i$ mới cập nhật).
4. Nếu còn lẻ, nhét nốt vào phần tử cuối cùng.

### Mã giả & C++ Code

```cpp
int a[100], n = 5, cnt;
bool isFinal = false;

// Khởi tạo
// a[1] = n; cnt = 1;

void sinh() {
    int i = cnt;
    // 1. Tìm phần tử đầu tiên từ cuối lên khác 1
    while (i >= 1 && a[i] == 1) {
        i--;
    }
    if (i == 0) {
        isFinal = true;
    } else {
        a[i]--; // 2. Giảm phần tử đó đi 1

        // 3. Tính toán lượng giá trị đang bị thiếu hụt
        // Lượng khuyết = (số lượng số 1 ở cuối) + 1 (vừa bị trừ)
        int missing_val = cnt - i + 1;

        cnt = i; // Tạm thời cắt bỏ các số 1 ở cuối

        // 4. Bù đắp lượng thiếu hụt theo tham lam (chia đều theo kích thước a[i])
        int q = missing_val / a[i]; // Số lượng phần tử có thể tạo ra bằng a[i]
        int r = missing_val % a[i]; // Phần dư còn lại

        if (q > 0) {
            for (int j = 1; j <= q; j++) {
                cnt++;
                a[cnt] = a[i];
            }
        }
        if (r > 0) {
            cnt++;
            a[cnt] = r;
        }
    }
}

```

---

_Tài liệu được soạn thảo dùng cho mục đích ôn tập cấu trúc dữ liệu và giải thuật (Data Structures & Algorithms)._

---
