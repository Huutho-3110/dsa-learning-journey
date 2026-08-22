# Divide and Conquer, Merge Sort, Count Inversion, Quick Sort và Maximum Subarray

## 1. Tổng quan về Divide and Conquer

Divide and Conquer (Chia và trị) là một mô hình thiết kế thuật toán (algorithm design paradigm) dựa trên việc chia một bài toán lớn thành các bài toán con nhỏ hơn, giải quyết các bài toán con đó, và kết hợp kết quả lại để có được lời giải cho bài toán ban đầu.

Ba bước cốt lõi của Divide and Conquer bao gồm:

- **Divide (Chia):** Chia bài toán ban đầu thành nhiều bài toán con. Các bài toán con này phải có cùng dạng với bài toán gốc nhưng có kích thước nhỏ hơn.
- **Conquer (Trị):** Giải quyết các bài toán con một cách đệ quy. Tuy nhiên, nếu kích thước của bài toán con đủ nhỏ (đạt đến base case - trường hợp cơ sở), ta giải quyết nó trực tiếp mà không cần đệ quy.
- **Combine (Kết hợp):** Kết hợp các kết quả của các bài toán con để tạo thành kết quả của bài toán lớn ban đầu.

Ví dụ minh họa luồng xử lý:
Bài toán lớn
-> Chia thành các bài toán nhỏ (Divide)
-> Giải quyết từng bài toán nhỏ (Conquer)
-> Kết hợp kết quả (Combine)
-> Lời giải bài toán ban đầu

**Giải thích chuyên sâu:**

- **Vì sao chia bài toán lớn thành bài toán nhỏ có thể giúp giải nhanh hơn?** Các thuật toán thường có độ phức tạp phi tuyến tính (ví dụ $O(n^2)$). Khi ta chia nhỏ n, tổng thời gian để giải các phần nhỏ cộng với thời gian kết hợp lại thường nhỏ hơn đáng kể so với việc giải trực tiếp toàn bộ n (ví dụ giảm xuống $O(n \log n)$).
- **Vì sao recursion (đệ quy) thường xuất hiện?** Vì các bài toán con có bản chất giống hệt bài toán gốc, chỉ khác kích thước, nên đệ quy là công cụ tự nhiên nhất để diễn đạt quá trình này.
- **Có bắt buộc dùng recursion không?** Không. Mọi thuật toán đệ quy đều có thể khử đệ quy bằng cách sử dụng cấu trúc dữ liệu Stack. Tuy nhiên, cách viết đệ quy giúp mã nguồn gọn gàng và bám sát trực giác toán học nhất.

- **Khi nào việc chia bài toán thực sự giúp giảm complexity?** Khi chi phí (cost) của bước Divide và Combine đủ nhỏ gọn, đồng thời kích thước bài toán giảm đi theo một tỷ lệ phân số (ví dụ giảm một nửa).
- **Khi nào không đem lại lợi ích?** Khi các bài toán con bị trùng lặp (overlapping subproblems) dẫn đến việc tính toán lại nhiều lần. Lúc này, Quy hoạch động (Dynamic Programming) là lựa chọn thay thế tốt hơn. Hoặc khi chi phí Combine quá lớn, lớn hơn cả việc giải trực tiếp bài toán.

## 2. Cách nhận diện bài toán Divide and Conquer

Khi đọc một đề bài, hãy sử dụng quy trình suy luận sau bằng cách tự đặt câu hỏi:

1. **Bài toán có thể chia thành những bài toán con tương tự không?** (Nếu đang tìm tổng lớn nhất của mảng, ta có thể tìm tổng lớn nhất của nửa trái và nửa phải không?)
2. **Các bài toán con có độc lập với nhau không?** (Kết quả của nửa trái có phụ thuộc vào nửa phải không? Nếu không, đây là dấu hiệu tốt).
3. **Kích thước bài toán có giảm đáng kể sau mỗi lần chia không?** (Thường là chia đôi, chia ba. Nếu chỉ giảm 1 phần tử mỗi lần, nó giống với đệ quy thông thường hoặc duyệt tuyến tính hơn).
4. **Có thể giải bài toán nhỏ bằng cùng một phương pháp không?**
5. **Base case là gì?** (Khi mảng chỉ có 1 phần tử thì sao?)
6. **Kết quả của các bài toán con có thể kết hợp lại không (Combine)?** (Nếu biết kết quả nửa trái và nửa phải, làm sao suy ra kết quả toàn cục?)

| Dấu hiệu của đề bài                                                         | Có thể nghĩ đến Divide and Conquer? | Vì sao                                                                             |
| --------------------------------------------------------------------------- | ----------------------------------- | ---------------------------------------------------------------------------------- |
| Dữ liệu có cấu trúc tuyến tính (mảng, chuỗi) và yêu cầu tính chất toàn cục. | Có                                  | Mảng và chuỗi rất dễ chia đôi bằng chỉ số (index) `mid`.                           |
| Bài toán yêu cầu độ phức tạp $O(n \log n)$ nhưng Brute Force là $O(n^2)$.   | Có                                  | $\log n$ thường sinh ra từ việc chia đôi liên tục cấu trúc dữ liệu kích thước $n$. |
| Có tính chất tự đồng dạng (định nghĩa đệ quy).                              | Có                                  | Cây (Tree) tự bản thân nó là cấu trúc Divide and Conquer tự nhiên.                 |
| Yêu cầu tìm kiếm tất cả các cấu hình hoặc bị lặp lại các bài toán con.      | Không                               | Nên nghĩ đến Backtracking hoặc Dynamic Programming.                                |

## 3. Công thức truy hồi (Recurrence Relation)

Công thức truy hồi biểu diễn thời gian chạy của thuật toán đệ quy $T(n)$ dựa trên thời gian chạy của các bài toán con.

Ví dụ kinh điển: $T(n) = 2T(n/2) + O(n)$

- **T(n):** Tổng thời gian để giải bài toán kích thước $n$.
- **2T(n/2):** Số lượng bài toán con là 2, mỗi bài toán có kích thước $n/2$. Đây là bước Trị (Conquer).
- **O(n):** Thời gian dành cho bước Chia (Divide) và Kết hợp (Combine).

Vì sao Merge Sort có recurrence như vậy? Vì Merge Sort chia mảng thành 2 nửa (mỗi nửa $n/2$), sau đó mất $O(n)$ để trộn (merge) hai nửa đó lại.

**Các ví dụ phổ biến:**

- $T(n) = T(n/2) + O(1)$: Binary Search. Chỉ đi vào 1 nửa, chi phí tính điểm giữa là $O(1)$. Complexity: $O(\log n)$.
- $T(n) = 2T(n/2) + O(n)$: Merge Sort. Đi vào cả 2 nửa, chi phí trộn là $O(n)$. Complexity: $O(n \log n)$.
- $T(n) = 2T(n/2) + O(1)$: Duyệt cây nhị phân. Đi vào 2 con, chi phí tại mỗi node là $O(1)$. Complexity: $O(n)$.
- $T(n) = T(n-1) + O(n)$: Quick Sort trường hợp xấu nhất (chọn sai pivot). Giảm được 1 phần tử, tốn $O(n)$ để phân hoạch (partition). Complexity: $O(n^2)$.

## 4. Master Theorem

Master Theorem là công cụ giúp giải nhanh các công thức truy hồi có dạng tổng quát:

$$T(n) = aT(n/b) + f(n)$$

- **a:** Số lượng bài toán con được sinh ra ($a \ge 1$).
- **b:** Tỷ lệ kích thước bài toán bị chia nhỏ ($b > 1$).
- **f(n):** Chi phí thực hiện thao tác Divide và Combine ngoài việc gọi đệ quy.

Định lý so sánh hàm $f(n)$ với $n^{\log_b a}$. Về mặt trực giác, $n^{\log_b a}$ đại diện cho khối lượng công việc ở tầng lá (đáy) của quá trình đệ quy. Bạn đang cân nhắc xem phần lớn thời gian thuật toán dành cho việc: (1) chia/kết hợp ở các tầng trên, hay (2) xử lý các base case ở đáy, hay (3) phân bổ đều.

**Ba trường hợp của Master Theorem:**

1. **Trường hợp 1 (Đáy nặng hơn):** Nếu $f(n)$ nhỏ hơn $n^{\log_b a}$ (về mặt đa thức).

- Trực giác: Công việc chủ yếu nằm ở số lượng base case quá lớn.
- Kết quả: $T(n) = \Theta(n^{\log_b a})$.

2. **Trường hợp 2 (Cân bằng):** Nếu $f(n)$ và $n^{\log_b a}$ phát triển cùng tốc độ.

- Trực giác: Công việc phân bổ đều ở mọi tầng đệ quy. Ta chỉ việc lấy chi phí của 1 tầng nhân với chiều cao của cây đệ quy là $\log n$.
- Kết quả: $T(n) = \Theta(n^{\log_b a} \log n)$.

3. **Trường hợp 3 (Đỉnh nặng hơn):** Nếu $f(n)$ lớn hơn $n^{\log_b a}$ (về mặt đa thức).

- Trực giác: Chi phí Combine quá lớn, chiếm áp đảo. Thời gian chủ yếu tiêu tốn ở ngay các lệnh gọi đầu tiên.
- Kết quả: $T(n) = \Theta(f(n))$.

**Ví dụ:**

- **Ví dụ 1:** $T(n) = 2T(n/2) + O(n)$.
  Ta có $a=2, b=2 \Rightarrow n^{\log_2 2} = n^1 = n$.
  So sánh với $f(n) = O(n)$, thấy chúng bằng nhau (Trường hợp 2).
  $\Rightarrow T(n) = O(n \log n)$.
- **Ví dụ 2:** $T(n) = 2T(n/2) + O(1)$.
  Ta có $a=2, b=2 \Rightarrow n^{\log_2 2} = n$.
  So sánh với $f(n) = O(1)$, thấy $n > 1$ (Trường hợp 1).
  $\Rightarrow T(n) = O(n)$.
- **Ví dụ 3:** $T(n) = 4T(n/2) + O(n)$.
  Ta có $a=4, b=2 \Rightarrow n^{\log_2 4} = n^2$.
  So sánh với $f(n) = O(n)$, thấy $n^2 > n$ (Trường hợp 1).
  $\Rightarrow T(n) = O(n^2)$.

Nếu gặp dạng như $T(n) = T(n-1) + O(n)$, không thể dùng Master Theorem vì $b$ không phải là hằng số chia. Lúc này cần dùng Recursion Tree (Cây đệ quy) hoặc Substitution Method (Phương pháp thế).

## 5. Recursion Tree (Cây đệ quy)

Cây đệ quy là công cụ trực quan để tính tổng thời gian chạy, giúp bạn hiểu rõ bản chất thay vì học vẹt công thức.

Xét $T(n) = 2T(n/2) + cn$ (với $c$ là hằng số biểu diễn chi phí của $O(n)$).

- **Level 0 (Gốc):** Kích thước là $n$. Chi phí tại đây là $cn$. Thuật toán tách thành 2 bài toán con kích thước $n/2$.
- **Level 1:** Có 2 bài toán con, mỗi bài kích thước $n/2$. Chi phí tại mỗi node là $c(n/2)$. Tổng chi phí level 1 = $2 \times c(n/2) = cn$.
- **Level 2:** Có 4 bài toán con, mỗi bài kích thước $n/4$. Chi phí tại mỗi node là $c(n/4)$. Tổng chi phí level 2 = $4 \times c(n/4) = cn$.
- ...
- **Leaf level (Lá):** Quá trình chia kết thúc khi kích thước giảm xuống 1. Chiều cao của cây là $\log_2 n$ (vì chia đôi liên tục).

**Phân tích tổng cost:**
Nhận thấy ở mỗi tầng, tổng chi phí luôn là $cn$.
Vì cây có $\log_2 n$ tầng, tổng chi phí của toàn bộ cây là:

$$T(n) = cn \times \log_2 n = O(n \log n)$$

Phương pháp này dạy bạn cách bóc tách bài toán: đếm tổng lượng công việc theo từng cấp độ đệ quy.

## 6. Merge Sort

Thuật toán Merge Sort là một ví dụ kinh điển của Divide and Conquer.

### 6.1. Ý tưởng

1. **Chia (Divide):** Chia mảng ban đầu thành hai mảng con có kích thước gần bằng nhau. Việc này tiếp tục đệ quy cho đến khi mảng chỉ còn 1 phần tử (đã tự sắp xếp).

2. **Trị (Conquer):** Đệ quy sắp xếp hai mảng con.

3. **Kết hợp (Combine):** Trộn (Merge) hai mảng con đã được sắp xếp thành một mảng lớn cũng được sắp xếp.

### 6.2. Tại sao Merge Sort đúng?

Tính đúng đắn được chứng minh bằng quy nạp toán học.

- **Base case:** Mảng 1 phần tử luôn có thứ tự đúng.
- **Giả thiết quy nạp:** Giả sử thuật toán hoạt động đúng với mảng kích thước $< n$.
- **Bước quy nạp:** Với mảng kích thước $n$, ta chia làm 2 nửa $< n$. Theo giả thiết quy nạp, cả hai nửa này sẽ được sắp xếp đúng. Cuối cùng, hàm Merge sẽ duyệt tuyến tính hai mảng con đã có thứ tự để ghép thành mảng lớn có thứ tự. Do đó, toàn bộ mảng n phần tử được sắp xếp đúng.

### 6.3. Merge (Trộn)

Đây là trái tim của thuật toán. Bài toán: Có hai mảng đã sắp xếp `Left` và `Right`, ghép chúng thành mảng `Result` có thứ tự.

Ví dụ:
`Left`: [1, 4, 7]
`Right`: [2, 3, 8]

Dùng 2 con trỏ `i` cho `Left` và `j` cho `Right`. Một con trỏ `k` cho `Result`.

- Bước 1: So sánh `Left[0]` (1) và `Right[0]` (2). $1 \le 2$, đưa 1 vào `Result`, tăng `i`.
- Bước 2: So sánh `Left[1]` (4) và `Right[0]` (2). $2 < 4$, đưa 2 vào `Result`, tăng `j`.
- Bước 3: So sánh `Left[1]` (4) và `Right[1]` (3). $3 < 4$, đưa 3 vào `Result`, tăng `j`.
- Bước 4: So sánh `Left[1]` (4) và `Right[2]` (8). $4 \le 8$, đưa 4 vào `Result`, tăng `i`.
- Bước 5: So sánh `Left[2]` (7) và `Right[2]` (8). $7 \le 8$, đưa 7 vào `Result`, tăng `i`.
  Lúc này `Left` đã hết phần tử. Khi một bên hết phần tử, ta chỉ cần chép toàn bộ các phần tử còn sót lại của bên kia vào `Result`. Đưa nốt số 8 vào.

Quy tắc:

- Lấy phần tử bên trái khi `Left[i] <= Right[j]`. Điều kiện `<=` rất quan trọng để giữ tính Stable.
- Lấy phần tử bên phải khi `Left[i] > Right[j]`.

### 6.4. Cài đặt Merge Sort bằng C++

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Hàm trộn hai mảng con đã sắp xếp
void merge(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo mảng tạm
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Gộp hai mảng
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng L (nếu có)
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng R (nếu có)
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

// Hàm chia để trị
void mergeSort(vector<int>& a, int left, int right) {
    if (left >= right) return; // Base case: mảng có 1 hoặc 0 phần tử

    int mid = left + (right - left) / 2; // Tránh tràn số int

    mergeSort(a, left, mid);      // Sắp xếp nửa trái
    mergeSort(a, mid + 1, right); // Sắp xếp nửa phải

    merge(a, left, mid, right);   // Kết hợp hai nửa
}

```

Giải thích code:

- `left + (right - left) / 2` được dùng thay vì `(left + right) / 2` để tránh hiện tượng Integer Overflow khi `left` và `right` là các số rất lớn.
- Hàm `merge` yêu cầu bộ nhớ phụ để lưu mảng `L` và `R` trước khi ghi đè lại vào mảng `a`.

### 6.5. Complexity

- **Time complexity:** Bước chia mảng làm đôi sinh ra 2 mảng con, quy trình này chiếm chiều cao đệ quy là $\log_2 n$. Tại mỗi tầng của quá trình đệ quy, hàm `merge` duyệt qua tổng cộng $n$ phần tử. Do đó ta có công thức $T(n) = 2T(n/2) + O(n)$. Master Theorem (Trường hợp 2) hoặc Recursion Tree chỉ ra độ phức tạp là $O(n \log n)$.
- **Best, Average, Worst case:** Thuật toán luôn chia đôi mảng một cách cơ học bất chấp trạng thái ban đầu của dữ liệu, do đó cả 3 trường hợp đều là $\Theta(n \log n)$.
- **Space complexity:** Bước `merge` sinh ra 2 mảng tạm `L` và `R` có tổng kích thước $n$. Do đó không gian bộ nhớ thêm là $O(n)$. Call stack đệ quy tốn thêm không gian $O(\log n)$, nhưng $O(n)$ vẫn là độ phức tạp không gian bao trùm.

### 6.6. Stable Sort

Stable sort (sắp xếp ổn định) là tính chất mà các phần tử có giá trị bằng nhau sẽ giữ nguyên thứ tự tương đối như mảng ban đầu.
Merge Sort **có tính stable**. Tại sao? Vì trong hàm `merge`, ta sử dụng điều kiện `if (L[i] <= R[j])`. Khi hai phần tử bằng nhau, phần tử thuộc mảng `L` (mảng nằm bên trái trong cấu trúc ban đầu) sẽ được chọn trước, ưu tiên ghi vào mảng kết quả, do đó thứ tự tương đối không bị đảo lộn.

### 6.7. In-place

Merge Sort cài đặt cơ bản như trên **không phải** là thuật toán in-place (tại chỗ) vì nó cần một lượng bộ nhớ phụ $O(n)$ cho thao tác trộn. Mặc dù tồn tại In-place Merge Sort (sử dụng dịch vị trí và hoán vị), độ phức tạp thời gian thường bị đẩy lên rất lớn hoặc cấu trúc code trở nên vô cùng phức tạp, không phù hợp cho ứng dụng phổ thông.

## 7. Đếm nghịch thế (Count Inversion)

Đây là ứng dụng xuất sắc nhất chứng minh sức mạnh của Divide and Conquer được "nhúng" vào cấu trúc của Merge Sort.

### 7.1. Inversion là gì?

Cho mảng: `[2, 4, 1, 3, 5]`
Nghịch thế (Inversion) là một cặp hai phần tử đảo lộn thứ tự tăng dần.
Định nghĩa toán học: Cặp chỉ số $(i, j)$ gọi là một nghịch thế nếu $i < j$ nhưng $a[i] > a[j]$.

Liệt kê toàn bộ inversion của mảng trên:

- (2, 1) vì index $0 < 2$ nhưng $2 > 1$.
- (4, 1) vì index $1 < 2$ nhưng $4 > 1$.
- (4, 3) vì index $1 < 3$ nhưng $4 > 3$.
  Tổng cộng có 3 nghịch thế.

### 7.2. Brute Force

```cpp
int count = 0;
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j])
            count++;
    }
}

```

- **Tại sao đúng?** Duyệt vét cạn mọi cặp phần tử đứng trước và đứng sau.
- **Complexity:** $O(n^2)$ vì có hai vòng lặp lồng nhau.
- **Vì sao không phù hợp?** Khi $n$ lớn (vd $n = 10^5$), $n^2 = 10^{10}$ phép toán, sẽ vượt quá giới hạn thời gian (thường là 1 giây cho $10^8$ phép tính trong thi đấu lập trình).

### 7.3. Tối ưu bằng Merge Sort

Tư duy Divide and Conquer:
Nếu ta chia mảng làm 2 nửa trái và phải. Một nghịch thế có thể rơi vào 1 trong 3 trường hợp:

1. Cả 2 phần tử đều nằm trong nửa trái (Left inversion).
2. Cả 2 phần tử đều nằm trong nửa phải (Right inversion).
3. Một phần tử nằm ở nửa trái, phần tử kia nằm ở nửa phải (Cross inversion).

**Mô hình:** `Total inversion = Left inversion + Right inversion + Cross inversion`
Việc đếm _Left_ và _Right_ có thể giao cho đệ quy giải quyết. Việc đếm _Cross_ sẽ thực hiện ngay trong bước `merge`.

Tại sao Merge Sort lại đếm được Cross Inversion?
Giả sử ta đang có hai mảng con **đã được sắp xếp**:
`Left`: [2, 4, 7]
`Right`: [1, 3, 5]
Con trỏ `i` trỏ vào `Left`, `j` trỏ vào `Right`.

- So sánh `Left[0]` (2) và `Right[0]` (1). Vì $2 > 1$, đây là một nghịch thế!
- **ĐIỂM TƯ DUY CỐT LÕI:** Vì mảng `Left` đã được sắp xếp tăng dần, nếu `Left[i] > Right[j]`, thì **MỌI PHẦN TỬ ĐỨNG SAU `Left[i]` TRONG MẢNG LEFT CŨNG SẼ LỚN HƠN `Right[j]**`.
- Thay vì đếm từng cái một, ta có thể cộng hàng loạt: Số lượng nghịch thế tạo với `Right[j]` là toàn bộ phần tử từ `i` đến cuối mảng `Left`.
- Số lượng đó chính là: `n1 - i` (hoặc `mid - (left + i) + 1` tùy cách bạn quản lý index).
- Trong ví dụ: `2 > 1`, số 1 tạo nghịch thế với 2, 4, 7. Ta cộng 3 vào tổng. Tăng `j`.

### 7.4. Code C++

```cpp
#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long crossInversions = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
            // Dòng code ăn tiền của cả thuật toán
            crossInversions += (n1 - i);
        }
        k++;
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    return crossInversions;
}

long long mergeSortAndCount(vector<int>& a, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(a, left, mid);
        count += mergeSortAndCount(a, mid + 1, right);
        count += mergeAndCount(a, left, mid, right);
    }
    return count;
}

```

### 7.5. Complexity

Bởi vì cấu trúc thuật toán hoàn toàn giống Merge Sort, chỉ chèn thêm đúng một phép cộng vô hướng $O(1)$ trong vòng lặp `while`, độ phức tạp thời gian vẫn được duy trì ở $O(n \log n)$. Ta đã giải quyết thành công bài toán $O(n^2)$ chỉ bằng cách lợi dụng quá trình xếp thứ tự.

### 7.6. Những lỗi thường gặp

- **Đếm sai khi hai phần tử bằng nhau:** Chỉ đếm nghịch thế khi `L[i] > R[j]`. Nếu ghi nhầm `L[i] >= R[j]` thì các phần tử bằng nhau cũng sẽ bị tính sai thành nghịch thế.
- **Integer overflow (Tràn số):** Trong trường hợp mảng xếp ngược hoàn toàn, số lượng nghịch thế là $n(n-1)/2$. Nếu $n = 10^6$, kết quả lên tới $5 \times 10^{11}$, vượt quá giới hạn của kiểu `int` 32-bit (chỉ lưu tối đa khoảng $2 \times 10^9$). Luôn dùng kiểu `long long` để lưu biến `count`.
- **Sai index khi cộng:** Không dùng biến `mid` và index tổng thể lẫn lộn nếu đang trỏ trên mảng tạm `L` và `R`. Hãy dùng công thức `n1 - i` thay cho logic index phức tạp.

## 8. Quick Sort

### 8.1. Ý tưởng

Quick Sort cũng là thuật toán Divide and Conquer, nhưng thay vì chú trọng vào việc chia đôi cơ học và gộp lại vất vả, nó dồn sức mạnh vào bước chia (phân hoạch):

1. **Divide (Chia):** Chọn một phần tử làm chốt (pivot). Sắp xếp lại mảng sao cho mọi phần tử nhỏ hơn hoặc bằng pivot đứng bên trái, và mọi phần tử lớn hơn hoặc bằng pivot đứng bên phải.

2. **Conquer (Trị):** Gọi đệ quy Quick Sort cho hai mảng con.

3. **Combine (Kết hợp):** Không làm gì cả, vì sau khi phân hoạch và đệ quy, mảng đã tự động vào đúng vị trí.

### 8.2. Pivot

Pivot là phần tử chốt dùng để so sánh các phần tử khác. Cách chọn pivot ảnh hưởng cực lớn đến thời gian chạy:

- **First / Last element:** Dễ cài đặt, nhưng nếu mảng ban đầu đã được sắp xếp tăng hoặc giảm, thuật toán sẽ rơi vào trường hợp xấu nhất $O(n^2)$.
- **Middle:** Chọn phần tử ở giữa `(left+right)/2` làm pivot. Giảm thiểu nguy cơ worst case trên các mảng đã có thứ tự một phần.
- **Random pivot:** Chọn một chỉ số ngẫu nhiên. Tránh hoàn toàn việc người ra đề cố tình tạo test case tiêu diệt thuật toán (Trường hợp tối ưu trong thực tế).

### 8.3. Partition

Đây là trái tim của Quick Sort. Có 2 cách tiếp cận phổ biến:

#### 8.4. Lomuto Partition

- **Ý tưởng:** Chọn phần tử cuối cùng `A[r]` làm pivot. Dùng một con trỏ `i` để lưu vết vị trí giới hạn cuối cùng của khu vực "các phần tử nhỏ hơn pivot". Con trỏ `j` duyệt tìm các phần tử nhỏ hơn, nếu thấy thì ném nó về khu vực của `i` thông qua hoán vị.

- **Mô phỏng với mảng:** `[5, 2, 8, 1, 7, 3]`
- Pivot là 3. `i` bắt đầu ở vị trí ảo trước mảng (-1). `j` chạy từ 0.
- `j=0`, giá trị 5. Không $\le 3$.
- `j=1`, giá trị 2. $2 \le 3$, tăng `i` thành 0, swap `A[0]`(5) và `A[1]`(2) $\Rightarrow [2, 5, 8, 1, 7, 3]$.
- `j=2`, giá trị 8. Không $\le 3$.
- `j=3`, giá trị 1. $1 \le 3$, tăng `i` thành 1, swap `A[1]`(5) và `A[3]`(1) $\Rightarrow [2, 1, 8, 5, 7, 3]$.
- `j=4`, giá trị 7. Không $\le 3$.
- Kết thúc vòng lặp. Swap Pivot vào giữa: Swap `A[i+1]` tức là `A[2]`(8) với `A[5]`(3) $\Rightarrow [2, 1, 3, 5, 7, 8]$. Trả về index của số 3 là 2.

- Code C++ (Dựa trên mô hình chuẩn):

```cpp
int lomutoPartition(vector<int>& a, int p, int r) {
    int pivot = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

```

#### 8.5. Hoare Partition

- **Ý tưởng:** Dùng hai con trỏ `left` bắt đầu từ đầu mảng tiến tới, và `right` từ cuối mảng lùi lại. `left` sẽ dừng lại khi gặp phần tử $\ge pivot$. `right` sẽ dừng lại khi gặp phần tử $\le pivot$. Khi cả hai cùng dừng, ta swap chúng. Liên tục cho đến khi 2 con trỏ giao nhau.
- **So sánh với Lomuto:** Hoare xử lý hoán đổi ít hơn tới 3 lần trung bình, hiệu suất thực tế cực cao. Tuy nhiên index trả về của Hoare không phải là vị trí chính xác của pivot.

### 8.6. Complexity

- **Best case:** Khi pivot luôn chia mảng thành 2 nửa cân bằng. Ta có $T(n) = 2T(n/2) + O(n)$. Theo Master Theorem, độ phức tạp là $O(n \log n)$.
- **Worst case:** Khi mảng đã sắp xếp và chọn phần tử cuối làm pivot, mỗi lần phân hoạch ta tách được 1 mảng $n-1$ phần tử và 1 mảng rỗng. $T(n) = T(n-1) + O(n)$. Giải đệ quy ta ra chuỗi tổng cấp số cộng: $n + (n-1) + (n-2) + ... + 1 = O(n^2)$.
  Pivot quá lệch (lớn nhất hoặc nhỏ nhất) tạo ra cây đệ quy cực kỳ mất cân bằng.

### 8.7. Randomized Quick Sort

Để tránh worst-case, ta chọn một chỉ số $k$ ngẫu nhiên từ `left` tới `right`, swap `A[k]` với `A[right]` (đưa vào vị trí Lomuto chờ). Do pivot là ngẫu nhiên, xác suất liên tiếp bốc trúng các pivot cực đoan trong mọi đợt gọi đệ quy là cực kỳ nhỏ. Do đó, Average case luôn được đảm bảo duy trì quanh mức $O(n \log n)$ một cách an toàn.

### 8.8. Quick Sort vs Merge Sort

| Tiêu chí           | Merge Sort                                                                                               | Quick Sort                                                                                                                            |
| ------------------ | -------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| **Average time**   | $O(n \log n)$                                                                                            | $O(n \log n)$                                                                                                                         |
| **Worst time**     | $O(n \log n)$                                                                                            | $O(n^2)$                                                                                                                              |
| **Extra memory**   | $O(n)$                                                                                                   | $O(\log n)$ (call stack)                                                                                                              |
| **Stable**         | Có                                                                                                       | Không                                                                                                                                 |
| **In-place**       | Không                                                                                                    | Có                                                                                                                                    |
| **Cache locality** | Tốt                                                                                                      | Rất xuất sắc                                                                                                                          |
| **Khi nên dùng**   | Cần sắp xếp stable (ví dụ: chuỗi). Hoặc sort các đối tượng như Linked List (vì merge list $O(1)$ space). | Sắp xếp mảng số chung chung trên thực tế, hiệu suất cao, tiết kiệm RAM. Đa số thư viện `std::sort` nhúng biến thể của nó (Introsort). |

_Giải thích bổ sung:_ Quick Sort in-place nên các thao tác đọc ghi diễn ra liên tục trên các vùng nhớ gần nhau. Kiến trúc CPU tận dụng rất tốt phần cứng (Cache L1/L2 locality). Đó là lý do dù worst-case của Quick Sort là $O(n^2)$, nó vẫn là "vua" trong thực tế.

## 9. Maximum Sum Subarray (Đoạn con liên tiếp có tổng lớn nhất)

**Bài toán:** Cho mảng số nguyên, tìm đoạn con liên tiếp có tổng lớn nhất.
Ví dụ: `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`
Kết quả: `[4, -1, 2, 1]` với tổng là `6`.

### 9.1. Brute Force

Thử mọi tổ hợp điểm bắt đầu `i` và điểm kết thúc `j`. Tính tổng các phần tử bên trong.
Complexity: $O(n^3)$ (nếu dùng vòng lặp phụ tính tổng) hoặc $O(n^2)$ (cộng dồn từng phần tử khi `j` chạy). Không đạt yêu cầu khi $n \ge 10^5$.

### 9.2. Prefix Sum

Tính mảng tổng tiền tố `P[i] = a[0] + ... + a[i]`. Tổng đoạn từ `i` đến `j` là `P[j] - P[i-1]`. Vẫn mất 2 vòng lặp để duyệt `i` và `j`, độ phức tạp là $O(n^2)$. Có thể kết hợp Prefix Sum và mảng tối thiểu để đưa về $O(n)$, nhưng về tư duy thì cách dưới đây hệ thống hơn.

### 9.3. Divide and Conquer

Chia mảng làm hai nửa. Một mảng con có tổng lớn nhất chỉ có thể nằm ở 1 trong 3 trường hợp:

1. **Nằm hoàn toàn ở mảng trái** (Left answer).
2. **Nằm hoàn toàn ở mảng phải** (Right answer).
3. **Đi qua dải phân cách giữa (midpoint)** (Cross answer).

Logic: Lời giải sẽ là `answer = max(leftAnswer, rightAnswer, crossAnswer)`.
`leftAnswer` và `rightAnswer` tiếp tục gọi đệ quy. Ta chỉ cần viết hàm tìm `crossAnswer`.
Để tìm `crossAnswer` đi qua `mid`, ta chia làm hai phần độc lập:

- Bắt đầu từ `mid` lan sang trái để tìm đoạn có tổng lớn nhất chạm lề trái.
- Bắt đầu từ `mid+1` lan sang phải để tìm đoạn có tổng lớn nhất chạm lề phải.
  Cộng hai mảng này lại, ta có `crossAnswer` lớn nhất.

### 9.4. Code C++ (Divide and Conquer)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCrossingSum(const vector<int>& a, int left, int mid, int right) {
    int leftSum = -1e9, rightSum = -1e9;
    int sum = 0;

    // Quét từ mid sang trái
    for (int i = mid; i >= left; i--) {
        sum += a[i];
        if (sum > leftSum) leftSum = sum;
    }

    sum = 0;
    // Quét từ mid+1 sang phải
    for (int i = mid + 1; i <= right; i++) {
        sum += a[i];
        if (sum > rightSum) rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArrayDAC(const vector<int>& a, int left, int right) {
    if (left == right) return a[left]; // Base case

    int mid = left + (right - left) / 2;

    int leftAnswer = maxSubArrayDAC(a, left, mid);
    int rightAnswer = maxSubArrayDAC(a, mid + 1, right);
    int crossAnswer = maxCrossingSum(a, left, mid, right);

    return max({leftAnswer, rightAnswer, crossAnswer});
}

```

### 9.5. Kadane's Algorithm

Tư duy Động (Dynamic Programming) thu gọn.
Tại mỗi vị trí `i`, ta phải ra một quyết định:

1. Mở rộng đoạn con trước đó đang chạy: Kéo dài nó để thu thập `a[i]`. `currentSum = currentSum + a[i]`.
2. Cắt đứt đoạn con trước đó: Đoạn trước đó bị âm nặng, cộng vào chỉ làm giảm giá trị `a[i]`. Tốt nhất là đoạn con khởi động lại điểm xuất phát ngay tại `a[i]`. `currentSum = a[i]`.

Ta có công thức:
`currentSum = max(a[i], currentSum + a[i])`
Giữ lưu giá trị toàn cục lớn nhất trong suốt quá trình:
`bestSum = max(bestSum, currentSum)`

**Tại sao đúng?** Bản chất Kadane là tính Maximum Suffix Sum (Tổng đoạn con tận cùng tại i lớn nhất). Tổng lớn nhất của mảng sẽ là Maximum Suffix Sum của một điểm `j` nào đó trong mảng.

```cpp
int kadane(const vector<int>& a) {
    int currentSum = a[0];
    int bestSum = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        currentSum = max(a[i], currentSum + a[i]);
        bestSum = max(bestSum, currentSum);
    }
    return bestSum;
}

```

### 9.6. So sánh các phương pháp

| Phương pháp            | Time          | Space       | Ý tưởng                                                     |
| ---------------------- | ------------- | ----------- | ----------------------------------------------------------- |
| **Brute Force**        | $O(n^2)$      | $O(1)$      | Thử mọi giới hạn `i`, `j`.                                  |
| **Prefix Sum**         | $O(n^2)$      | $O(n)$      | Tính nhanh tổng `[i..j]` qua mảng cộng dồn.                 |
| **Divide and Conquer** | $O(n \log n)$ | $O(\log n)$ | Đệ quy tìm nửa trái, nửa phải, và đoạn vắt ngang giữa mảng. |
| **Kadane**             | $O(n)$        | $O(1)$      | Khởi động lại currentSum nếu nó cộng dồn mang lại số âm.    |

_D&C chạy chậm hơn Kadane, tại sao phải học?_ Vì bài toán Maximum Sum Subarray D&C là nền tảng để giải quyết truy vấn biến thể trên Cấu trúc dữ liệu Segment Tree, nơi Kadane không thể hoạt động khi mảng bị thay đổi (update).

## 10. Mối quan hệ giữa các thuật toán

Cây phả hệ của Divide and Conquer:

```text
Divide and Conquer
        |
        +---- Merge Sort (Chia làm 2 nửa an toàn, kết hợp bằng O(n))
        |       |
        |       +---- Count Inversion (Nhúng logic đếm vào vòng lặp kết hợp)
        |
        +---- Quick Sort (Trị mảng bằng cách chia nó thành dạng > và <, không cần combine)
        |
        +---- Maximum Subarray (Trị mảng bằng cách khảo sát tính chất biên: trái, phải, giữa)

```

Một thuật toán có thể được "nhúng" (embedded) vào một thuật toán khác. Count Inversion không dùng để sắp xếp, nhưng bản chất cấu trúc "hai mảng con đã sắp xếp" của bước Trị trong Merge Sort tạo điều kiện vàng để ta khảo sát sự hoán đổi chéo. Sự sáng tạo nằm ở chỗ ta mượn quy trình chạy của Divide and Conquer để xử lý một bài toán hoàn toàn không phải sắp xếp.

## 11. Cách suy luận một bài Divide and Conquer

Framework thực tế với 10 bước tự hỏi:

1. **Bài toán có thể chia thành các bài toán con không?** Có, bằng index.
2. **Các bài toán con có cùng dạng với bài toán ban đầu không?** Có, thao tác tương tự, input nhỏ hơn.
3. **Kích thước có giảm theo một tỷ lệ nào đó không?** Chia 2 ($n/2$).
4. **Base case là gì?** Khi kích thước mảng là 1 (hoặc 0).
5. **Tôi giải bài toán con như thế nào?** Trả kết quả của base case và đệ quy lặp lại.
6. **Tôi cần kết hợp (Combine) các kết quả như thế nào?** Tùy thuộc vào yêu cầu bài toán (Trộn lại, Tính tổng vắt chéo, Cập nhật biến).
7. **Cost của bước Combine là bao nhiêu?** Đếm số phép toán vòng lặp ở bước Combine.
8. **Recurrence là gì?** Dựa vào số nhánh chia và cost Combine.
9. **Complexity là bao nhiêu?** Giải bằng Master Theorem.
10. **Có cách chia khác tốt hơn không?** (Thường chia 2 là phổ biến và tốt nhất).

## 12. Cách phân tích Complexity của Divide and Conquer

Framework bóc tách phương trình:
`T(n) = (Số bài toán con) x T(Kích thước mỗi bài toán con) + (Cost của Divide) + (Cost của Combine)`

- **Merge Sort:** Chia thành 2 nửa (mỗi bài $n/2$). Cost chia bằng index là $O(1)$. Cost trộn là vòng lặp duyệt $n$ phần tử ($O(n)$).
  $\Rightarrow T(n) = 2T(n/2) + O(n) \Rightarrow O(n \log n)$
- **Quick Sort (Average):** Chia thành 2 nửa (mỗi bài $n/2$). Cost chia (Partition) tốn $O(n)$ để quét mảng. Cost trộn bằng $O(1)$.
  $\Rightarrow T(n) = 2T(n/2) + O(n) \Rightarrow O(n \log n)$

- **Maximum Subarray:** Tính `left` và `right` tạo 2 nhánh $n/2$. Tính `cross` duyệt ra hai phía từ giữa, tốn $O(n)$.
  $\Rightarrow T(n) = 2T(n/2) + O(n) \Rightarrow O(n \log n)$
- **Count Inversion:** Hoàn toàn kế thừa Merge Sort, chỉ tính toán thêm phép tính vô hướng $O(1)$.
  $\Rightarrow T(n) = 2T(n/2) + O(n) \Rightarrow O(n \log n)$

Từ mã nguồn, bạn đếm số lượng lệnh gọi hàm đệ quy sinh ra nhánh $a$. Kích thước đối số được gửi vào hàm sinh ra $b$. Vòng lặp For/While nằm bên ngoài đệ quy sinh ra $f(n)$.

## 13. Những lỗi tư duy phổ biến

- **Chia bài toán nhưng không biết combine:** (VD: Đệ quy tìm tổng con bên trái, bên phải nhưng quên không viết hàm tìm Cross Max).
- **Combine quá tốn thời gian:** Nếu bước đếm Inversion mà bạn vẫn dùng 2 vòng lặp lồng nhau $O(n^2)$ thay vì tích hợp vào `while` của Merge Sort, độ phức tạp sẽ trở thành $T(n) = 2T(n/2) + O(n^2) = O(n^2)$. Toàn bộ nỗ lực Divide đổ sông đổ biển.
- **Chọn midpoint sai:** `mid = (left + right) / 2` bị tràn số (overflow) ở C++ khi `left` và `right` là mốc index cỡ 2 tỷ.
- **Sai boundary (ranh giới):** Đệ quy `f(left, mid)` và `f(mid, right)` dẫn đến infinite recursion vì `mid` không được loại ra rạch ròi. Cách chia chuẩn: `[left, mid]` và `[mid+1, right]`.
- **Infinite recursion (Đệ quy vô hạn):** Quên base case `if (left >= right) return;`
- **Dùng Quick Sort nhưng không hiểu partition:** Ghi nhầm hoán đổi (swap) ngoài biến, hoặc mất số chốt.
- **Không xử lý số âm trong Maximum Subarray:** Khởi tạo `leftSum = 0` thay vì `leftSum = -1e9`. Nếu mảng toàn số âm, đáp án sẽ ra 0 (sai bét, phải ra số âm nhỏ nhất).

## 14. Debug Divide and Conquer

Kỹ năng gỡ lỗi:

1. **Chọn input nhỏ:** Đừng thử mảng 100 phần tử. Hãy dùng mảng 4 phần tử (ví dụ: `[3, 1, 4, 2]`).
2. **Vẽ cây recursion (Trasing):** Lấy giấy bút, ghi nhận đợt gọi đệ quy `f(0, 3)` -> tách ra `f(0, 1)` và `f(2, 3)`.
3. **Theo dõi `left`, `mid`, `right`:** Đặt lệnh in màn hình: `cout << "D&C: left=" << left << " mid=" << mid << " right=" << right << endl;`. Bạn sẽ thấy cách cây chẻ nhánh.
4. **Kiểm tra base case:** Xem thuật toán có dừng khi `left == right` không?
5. **Kiểm tra kết quả của từng subproblem:** In ra biến `leftAnswer` và `rightAnswer` xem có đúng bằng tính tay không.
6. **Kiểm tra boundary (Biên):** Test thử mảng lẻ phần tử (5 phần tử) và mảng chẵn (4 phần tử).

## 15. Template C++

### Template Divide and Conquer Khung chuẩn

```cpp
ReturnType solve(vector<int>& a, int left, int right) {
    // 1. Base case
    if (left >= right) {
        return BaseState;
    }

    // 2. Pattern chia
    int mid = left + (right - left) / 2;

    // 3. Recursive call
    ReturnType leftRes = solve(a, left, mid);
    ReturnType rightRes = solve(a, mid + 1, right);

    // 4. Combine
    ReturnType finalRes = combineLogic(leftRes, rightRes, crossRes(a, left, mid, right));

    return finalRes;
}

```

- **Điểm cần sửa khi gặp bài mới:** Logic trong bước 4 (Combine) là thứ thay đổi nhiều nhất, cần dành hàm riêng để xử lý.

### Quick Sort - Lomuto Partition Template

```cpp
void quickSort(vector<int>& a, int p, int r) {
    if (p < r) {
        // Phân hoạch[cite: 9]
        int pivot = a[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; j++) {
            if (a[j] <= pivot) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        int q = i + 1; // Pivot index

        // Đệ quy 2 nửa[cite: 9]
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

```

## 16. So sánh tổng thể

| Thuật toán           | Paradigm            | Average       | Worst         | Extra Space | Stable | In-place | Ứng dụng                                          |
| -------------------- | ------------------- | ------------- | ------------- | ----------- | ------ | -------- | ------------------------------------------------- |
| **Merge Sort**       | Divide & Conquer    | $O(n \log n)$ | $O(n \log n)$ | $O(n)$      | Có     | Không    | Linked lists, Stable Sort, Inversions.            |
| **Quick Sort**       | Divide & Conquer    | $O(n \log n)$ | $O(n^2)$      | $O(\log n)$ | Không  | Có       | Tối ưu hóa cache, hệ thống thực tế.               |
| **Count Inversion**  | D&C (Nhúng)         | $O(n \log n)$ | $O(n \log n)$ | $O(n)$      | -      | -        | Đo lường độ tương đồng (Collaborative Filtering). |
| **Max Subarray D&C** | Divide & Conquer    | $O(n \log n)$ | $O(n \log n)$ | $O(\log n)$ | -      | -        | Mở rộng qua cấu trúc Segment Tree.                |
| **Kadane**           | Dynamic Programming | $O(n)$        | $O(n)$        | $O(1)$      | -      | -        | Tìm chuỗi biến động giá tài chính (Stock Span).   |

## 17. Các bài tập tự luyện

- **Level 1 - Nhận biết Divide and Conquer**
- _Tên bài:_ Tìm phần tử lớn nhất trong mảng bằng chia để trị.
- _Gợi ý:_ `max(findMax(left, mid), findMax(mid+1, right))`.

- **Level 2 - Merge Sort và Quick Sort**
- _Tên bài:_ Sort an Array (Leetcode 912).
- _Mục tiêu:_ Tự code lại 2 thuật toán không copy.

- **Level 3 - Count Inversion và các biến thể**
- _Tên bài:_ Reverse Pairs (Leetcode 493).
- _Điểm cần suy luận:_ Đếm cặp `i < j` sao cho `nums[i] > 2 * nums[j]`. Tương tự Count Inversion nhưng phải quét điều kiện trước khi trộn.

- **Level 4 - Maximum Subarray và các biến thể**
- _Tên bài:_ Maximum Subarray (Leetcode 53).
- _Kỹ thuật:_ Code 2 cách (D&C và Kadane).

- **Level 5 - Nâng cao**
- _Tên bài:_ K-th Largest Element in an Array.
- _Mục tiêu:_ Dùng Quick Select (Bỏ đi một nửa phân hoạch của Quick Sort), độ phức tạp trung bình $O(n)$.

## 18. Active Recall (Tự kiểm tra)

Hãy che tài liệu và tự trả lời:

1. Divide and Conquer là gì? Ba bước cốt lõi?
2. Recurrence là gì? Cấu trúc của Master Theorem?
3. a, b, f(n) trong Master Theorem là gì?
4. Vì sao Merge Sort là $O(n \log n)$? (Hãy thử chứng minh bằng mồm).
5. Điều kiện cốt lõi làm nên tính Stable trong bước Trộn là gì?
6. Cross inversion là gì?
7. Vì sao `crossInversions += (n1 - i)` lại đúng?
8. Quick Sort khác Merge Sort như thế nào trong tư duy Divide và Conquer?
9. Lomuto partition duyệt con trỏ như thế nào?
10. Vì sao Quick Sort có worst-case $O(n^2)$ và Randomized bẻ gãy nó ra sao?
11. Khái niệm Cross Sum trong Maximum Subarray.
12. Vì sao thuật toán Kadane lại đạt tốc độ $O(n)$?

## 19. Cheat Sheet

- **D&C Pattern:** (1) Chia đôi bằng `mid`, (2) Trị bằng đệ quy, (3) Hợp lại.
- **Master Theorem:** So sánh tốc độ phát triển $f(n)$ với $n^{\log_b a}$.
- **Merge Sort:** `T(n) = 2T(n/2) + O(n)`. Trộn bằng 2 con trỏ. Stable. Tốn thêm mảng phụ $O(n)$.
- **Quick Sort:** `T(n) = 2T(n/2) + O(n)`. Chia trị bằng Pivot. In-place. Không stable. Tốc độ thực tế siêu việt.

- **Lomuto Partition:** Chọn r làm pivot. Cắm cọc `i` cho phần nhỏ. Quét `j`. Lớn bỏ qua, nhỏ ném về `i`.

- **Count Inversion:** Lợi dụng mảng phụ bên trái đã sắp xếp. Khi `L[i] > R[j]`, số lượng đảo với `R[j]` chính là toàn bộ đoạn chót của `L` tính từ `i`.
- **Maximum Subarray D&C:** Lấy `Max(Bên trái, Bên phải, Đoạn vắt ngang)`.
- **Kadane:** `current = max(A[i], current + A[i]); global_max = max(global_max, current);`

## 20. Kết luận

Mục tiêu học cấu trúc dữ liệu không phải học thuộc mã nguồn:
`Merge Sort = O(n log n)`
mà là để trả lời tại sao:

- Vì sao chia làm 2 rồi merge nó lại lòi ra con số $\log n$? (Vì chiều cao cây).
- Vì sao Quick Sort gọi là "Quick" dù worst case cực tệ? (Vì phân hoạch in-place và cơ chế chốt tốt).
- Làm thế nào để ứng dụng D&C vào đếm nghịch thế mà không cần vòng lặp 2 lớp?

Tư duy cốt lõi luôn là:
**Problem** $\rightarrow$ **Can I divide it?** $\rightarrow$ **Subproblems** $\rightarrow$ **Solve recursively** $\rightarrow$ **Combine** $\rightarrow$ **Recurrence** $\rightarrow$ **Complexity.**
Khi bạn nắm vững Framework 10 bước ở trên, mọi bài toán Chia và Trị (dù là trên Mảng, Đồ thị hay Hình học không gian) đều có thể được phẫu thuật một cách gọn gàng. Dữ liệu là để Cấu trúc, Thuật toán là để Tư duy. Chúc bạn code khỏe!
