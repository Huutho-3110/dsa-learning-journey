# Backtracking, Branch and Bound và Traveling Salesman Problem

Tài liệu này được biên soạn nhằm cung cấp một cái nhìn hệ thống, sâu sắc và mang tính tư duy về các thuật toán tìm kiếm tổ hợp. Mục tiêu không phải là học thuộc lòng các đoạn mã, mà là hiểu rõ bản chất của không gian trạng thái, cách thiết lập các ràng buộc, và kỹ năng chuyển đổi từ ý tưởng toán học sang mã nguồn C++ thực tế.

---

## 1. Tổng quan về bài toán tìm kiếm tổ hợp

### Tìm kiếm tổ hợp là gì?

Tìm kiếm tổ hợp (Combinatorial Search) là quá trình tìm kiếm một hoặc tất cả các cấu trúc rời rạc thỏa mãn một tập hợp các điều kiện nhất định. Các cấu trúc này thường là các hoán vị, tổ hợp, tập con, hoặc các đường đi trên đồ thị.

### Vấn đề của không gian trạng thái

Các bài toán tổ hợp đặc trưng bởi sự bùng nổ tổ hợp (Combinatorial Explosion). Số lượng các cấu hình có thể có tăng theo hàm mũ (ví dụ $O(2^n)$ đối với tập con) hoặc giai thừa (ví dụ $O(n!)$ đối với hoán vị) khi kích thước đầu vào $n$ tăng lên.

### Vì sao Brute Force không khả thi?

Brute Force (Vét cạn) hoạt động theo nguyên tắc: "Sinh ra tất cả các cấu hình có thể có, sau đó kiểm tra từng cấu hình xem có thỏa mãn điều kiện không". Với $n$ lớn, việc sinh ra toàn bộ cấu hình sẽ vượt quá giới hạn thời gian tính toán của máy tính hiện đại (thường giới hạn ở mức $10^8$ phép toán/giây).

### Cây trạng thái (State-space tree)

Để tối ưu, ta không sinh toàn bộ cấu hình cùng lúc mà **xây dựng lời giải từng bước**. Quá trình này được mô hình hóa bằng một cây trạng thái:

- **Node (Nút):** Thể hiện một trạng thái cục bộ trong quá trình xây dựng lời giải.
- **State (Trạng thái):** Thông tin lưu trữ tại một nút, đại diện cho những gì đã được chọn cho đến thời điểm hiện tại.
- **Candidate/Choice (Lựa chọn):** Các bước phát triển từ trạng thái hiện tại để đi đến trạng thái tiếp theo (các nhánh con).
- **Constraint (Ràng buộc):** Điều kiện để xác định một nhánh có hợp lệ để đi tiếp hay không.
- **Solution (Lời giải):** Một nút (thường là nút lá) đại diện cho một trạng thái hoàn chỉnh và hợp lệ.

### Backtracking là DFS trên cây trạng thái

Quay lui (Backtracking) chính là thuật toán Tìm kiếm theo chiều sâu (DFS) áp dụng trên cây trạng thái. Khác với DFS trên đồ thị tĩnh (đã có sẵn các đỉnh và cạnh), DFS trong Backtracking là duyệt trên một đồ thị ẩn; các đỉnh và cạnh chỉ được sinh ra trong lúc chạy thuật toán. Nhờ việc kiểm tra ràng buộc (Constraint) tại mỗi nút, Backtracking có thể "cắt tỉa" (prune) những nhánh sai ngay lập tức mà không cần đi sâu xuống lá, khắc phục điểm yếu của Brute Force.

### Phân biệt các chiến lược giải quyết

- **Brute Force:** Sinh toàn bộ lời giải $\rightarrow$ Kiểm tra tất cả.
- **Recursion (Đệ quy):** Kỹ thuật lập trình gọi lại chính hàm đó, là công cụ để cài đặt DFS.
- **Backtracking:** Đệ quy + Cắt tỉa các nhánh sai (Pruning dựa trên tính hợp lệ).
- **Branch and Bound:** Backtracking + Cắt tỉa dựa trên hàm đánh giá (Pruning dựa trên tính tối ưu).
- **Dynamic Programming (Quy hoạch động):** Cũng duyệt qua không gian trạng thái, nhưng có bộ nhớ (Memoization/Tabulation) để không giải lại các bài toán con trùng lặp (Overlapping subproblems). Backtracking không nhớ các trạng thái đã qua.
- **Greedy (Tham lam):** Chỉ chọn nhánh tốt nhất tại thời điểm hiện tại và không bao giờ quay lui.

### Khi nào nên dùng Backtracking?

- Đề bài yêu cầu tìm **tất cả** các cấu hình thỏa mãn điều kiện.
- Kích thước đầu vào (n) rất nhỏ (thường $n \le 20$).
- Cần duyệt toàn bộ không gian để tìm nghiệm tối ưu nhưng không có cấu trúc bài toán con trùng lặp (không dùng được DP).

---

## 2. Nền tảng của Backtracking

### 2.1. Backtracking là gì?

Về mặt trực giác, Backtracking giống như việc bạn đi tìm đường trong một mê cung. Bạn chọn một hướng đi, đánh dấu lại, và cứ thế tiến tới. Nếu gặp ngõ cụt (vi phạm Constraint), bạn lùi lại (Backtrack) đúng một bước, xóa bỏ lựa chọn vừa rồi (Undo), và thử hướng đi khác.

### 2.2. Các thành phần cốt lõi

1. **State (Trạng thái):** Tập hợp các biến biểu diễn trạng thái hiện tại (ví dụ: mảng kết quả tạm thời, chỉ số phần tử đang xét).
2. **Choice (Lựa chọn):** Tại trạng thái hiện tại, có những hướng đi nào tiếp theo?
3. **Constraint (Ràng buộc):** Điều kiện xác định một lựa chọn có hợp lệ không.
4. **Base case (Trạng thái dừng):** Điều kiện xác định ta đã xây dựng xong một lời giải.
5. **Undo (Hoàn tác):** Sau khi đã thử một lựa chọn và đi sâu xuống nhánh đó, khi đệ quy quay trở lại, ta phải đưa hệ thống về lại trạng thái ban đầu để có thể thử lựa chọn tiếp theo một cách độc lập.

### 2.3. Mẫu tư duy tổng quát (Template)

```cpp
void backtrack(State state)
{
    // 1. Base case: Kiểm tra xem đã đạt được lời giải chưa
    if (isSolution(state))
    {
        processSolution(state); // Lưu kết quả hoặc in ra
        return;                 // Dừng nhánh này
    }

    // 2. Duyệt qua tất cả các lựa chọn có thể có tại bước hiện tại
    for (Choice choice : getChoices(state))
    {
        // 3. Constraint: Lựa chọn này có hợp lệ không?
        if (isValid(choice, state))
        {
            // 4. Make choice: Áp dụng lựa chọn vào trạng thái
            makeChoice(choice, state);

            // 5. Recurse: Đi sâu xuống nhánh tiếp theo
            backtrack(state);

            // 6. Undo: RẤT QUAN TRỌNG - Xóa bỏ lựa chọn để thử nhánh khác
            undoChoice(choice, state);
        }
    }
}

```

**Giải thích bước Undo:**
Khi truyền dữ liệu bằng tham chiếu (reference) hoặc dùng biến toàn cục (để tiết kiệm bộ nhớ, tránh copy mảng liên tục), trạng thái bị thay đổi khi gọi đệ quy. Nếu nhánh 1 thêm giá trị `A`, sau khi nhánh 1 kết thúc, giá trị `A` vẫn nằm trong trạng thái. Nhánh 2 muốn thêm giá trị `B` vào cùng vị trí đó sẽ bị lỗi. Do đó, hàm phải lấy `A` ra (Undo) trước khi thử `B`.

### 2.4. Cách tự suy luận một bài Backtracking mới

Khi gặp bài toán mới, hãy trả lời tuần tự các câu hỏi sau:

1. **Ta đang xây dựng cái gì?** (Một mảng, một chuỗi, một ma trận?)
2. **Trạng thái được biểu diễn thế nào?** (Cần tham số gì trong hàm đệ quy? Ví dụ: `int index`, `vector<int>& current_path`).
3. **Tại mỗi bước, có những lựa chọn nào?** (Các vòng `for` sẽ chạy từ đâu đến đâu?).
4. **Điều kiện nào làm lựa chọn không hợp lệ?** (Hàm `isValid` chứa logic gì?).
5. **Khi nào kết thúc?** (Kích thước `current_path` bằng $n$?).
6. **Có cần hoàn tác không?** (Nếu dùng cấu trúc dữ liệu chung như `std::vector`, chắc chắn phải `pop_back`).

---

## 3. Quay lui trên mảng 1 chiều

Đây là lớp bài toán nền tảng nhất, thường chia làm hai nhóm chính: Tổ hợp (Combination/Subset) và Hoán vị (Permutation).

### Sự khác biệt cốt lõi

- **Tổ hợp / Tập con:** Quan tâm đến "những phần tử nào được chọn". Thứ tự không quan trọng (`[1, 2]` giống `[2, 1]`). Để tránh lặp lại, ta cần một biến `start` để ép vòng lặp chỉ xét các phần tử nằm _phía sau_ phần tử vừa chọn.
- **Hoán vị:** Quan tâm đến "thứ tự sắp xếp". `[1, 2]` khác `[2, 1]`. Tại mỗi vị trí, ta có quyền xét lại từ đầu mảng (`i = 0`). Tuy nhiên, không được dùng lại phần tử đã dùng, nên cần mảng đánh dấu `used[]`.

### 3.1. Bài toán Hoán vị (Permutations)

**Bài toán:** Cho mảng các số nguyên phân biệt từ 1 đến n. Sinh tất cả các hoán vị.

- **State:** Mảng lưu cấu hình hiện tại `path`.
- **Choice:** Chọn bất kỳ phần tử nào từ $0$ đến $n-1$.
- **Constraint:** Phần tử đó chưa được chọn (`!used[i]`).
- **Undo:** Loại bỏ phần tử khỏi `path` và đánh dấu lại là chưa sử dụng (`used[i] = false`).

```cpp
void generatePermutations(int n, vector<int>& path, vector<bool>& used)
{
    // Base case
    if (path.size() == n)
    {
        // In cấu hình path
        return;
    }

    // Choice: Vòng lặp LUÔN CHẠY TỪ 0
    for (int i = 1; i <= n; i++)
    {
        // Constraint
        if (!used[i])
        {
            path.push_back(i);      // Make choice
            used[i] = true;         // Đánh dấu đã dùng

            generatePermutations(n, path, used); // Đi sâu xuống

            used[i] = false;        // Undo đánh dấu
            path.pop_back();        // Undo lựa chọn
        }
    }
}

```

### 3.2. Bài toán Tổ hợp / Tập con (Combinations / Subsets)

**Bài toán:** Sinh tất cả tập con của một tập hợp n phần tử.

- **State:** `path` và biến `start`.
- **Choice:** Chọn các phần tử từ chỉ số `start` đến $n-1$.
- **Constraint:** Vòng lặp từ `start` tự động đảm bảo không có thứ tự ngược, không cần mảng `used`.

```cpp
void generateSubsets(int n, int start, vector<int>& path)
{
    // Không có điều kiện dừng cứng, mọi trạng thái đều là tập con hợp lệ
    // In cấu hình path hiện tại ra

    // Choice: Chạy từ start để tránh trùng lặp thứ tự
    for (int i = start; i <= n; i++)
    {
        path.push_back(i); // Make choice

        // Gọi đệ quy, chuyển i + 1 vào tham số start tiếp theo
        // Để bước sau chỉ xét các phần tử sau i
        generateSubsets(n, i + 1, path);

        path.pop_back();   // Undo lựa chọn
    }
}

```

**Bản chất của biến `start`:** Nó cắt tỉa các nhánh tạo ra hoán vị. Ví dụ: Từ `1` có thể gọi `2`, nhưng từ `2` sẽ bị chặn (do `start = 3`), không thể gọi lại `1`.

---

## 4. Quay lui trên chuỗi

Chuỗi (`std::string` trong C++) về bản chất là mảng 1 chiều các ký tự. Các quy tắc Backtracking áp dụng hoàn toàn tương tự, điểm khác biệt là ta tác động lên `string` thông qua các phương thức của nó.

- `push_back(char c)`: Chính là thao tác Make Choice.
- `pop_back()`: Chính là thao tác Undo.

### Phân tích: Khi nào dùng phương pháp nào?

- **Cần chia chuỗi (Partitioning):** Dùng biến `start` làm điểm bắt đầu cắt, vòng `for` tìm điểm cắt tiếp theo.
- **Sinh hoán vị chuỗi:** Dùng mảng `used[]` để đánh dấu các ký tự đã ghép.

### Mẫu mã: Palindrome Partitioning (Phân hoạch chuỗi đối xứng)

**Bài toán:** Cho chuỗi $S$. Chia chuỗi thành các chuỗi con sao cho mọi chuỗi con đều là Palindrome.

- **State:** Biến `start` để biết chuỗi còn lại bắt đầu từ đâu. Mảng `path` lưu các chuỗi con đã cắt.
- **Choice:** Cắt từ `start` đến `i`.
- **Constraint:** Đoạn `S[start...i]` phải là Palindrome.

```cpp
void partitionString(int start, const string& s, vector<string>& path)
{
    // Base case: Đã cắt đến hết chuỗi
    if (start == s.length())
    {
        // In hoặc lưu path
        return;
    }

    for (int i = start; i < s.length(); i++)
    {
        // Constraint
        if (isPalindrome(s, start, i))
        {
            // Trích xuất chuỗi con từ start, độ dài i - start + 1
            path.push_back(s.substr(start, i - start + 1));

            // Recurse: Cắt tiếp phần còn lại bắt đầu từ i + 1
            partitionString(i + 1, s, path);

            // Undo
            path.pop_back();
        }
    }
}

```

---

## 5. Quay lui trên mảng 2 chiều

Đây là dạng bài tập phổ biến trong các trò chơi (Sudoku, N-Queens) và duyệt đồ thị ma trận (Maze).

### Đặc trưng

- **State:** Được biểu diễn bằng 2 biến tọa độ `(row, col)`.
- **Hướng di chuyển:** Thay vì dùng nhiều câu lệnh `if`, ta dùng mảng hằng số để định nghĩa hướng.
- `int dr[] = {-1, 1, 0, 0};`
- `int dc[] = {0, 0, -1, 1};`

- **Mảng `visited`:** Để tránh việc đi lại vào ô cũ gây lặp vô tận (infinite loop).

### Vấn đề: Phân biệt DFS và DFS + Backtracking trên Grid

- **DFS thông thường (Tìm vùng miền, loang):** Đi tới đâu đánh dấu `visited[r][c] = true` tới đó, và **không bao giờ** gỡ bỏ đánh dấu. Ô nào đã thăm là thăm vĩnh viễn.
- **Backtracking (Tìm mọi đường đi từ A đến B):** Đánh dấu `visited[r][c] = true` trước khi đi xuống nhánh con, sau khi nhánh con trả về thì **bắt buộc phải Undo** bằng cách gán `visited[r][c] = false`. Điều này cho phép một ô có thể thuộc về nhiều đường đi khác nhau.

### Mẫu mã: Rat in a Maze

```cpp
int dr[] = {-1, 1, 0, 0}; // Lên, Xuống, Trái, Phải
int dc[] = {0, 0, -1, 1};

void solveMaze(int r, int c, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited)
{
    // Base case: Tới đích
    if (r == n - 1 && c == n - 1)
    {
        // Ghi nhận tìm thấy 1 đường đi
        return;
    }

    // Đánh dấu ô hiện tại
    visited[r][c] = true;

    // Xét 4 hướng
    for (int i = 0; i < 4; i++)
    {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        // Constraint: Nằm trong biên, chưa thăm, và là đường đi được (grid = 1)
        if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n
            && !visited[next_r][next_c] && grid[next_r][next_c] == 1)
        {
            solveMaze(next_r, next_c, n, grid, visited);
        }
    }

    // Undo: Trả lại trạng thái ô trống để các đường đi khác có thể đi qua đây
    visited[r][c] = false;
}

```

---

## 6. Bài toán N-Queens

Bài toán kinh điển nhất để minh họa khả năng cắt tỉa (pruning) của Backtracking.

### 6.1. Phát biểu và Tư duy xây dựng

Đặt $N$ quân hậu lên bàn cờ $N \times N$ sao cho không có 2 quân hậu nào ăn nhau (không cùng hàng, không cùng cột, không cùng đường chéo).

- **Tại sao đặt theo hàng?** Nếu xét từng ô trên bàn cờ, không gian trạng thái là $2^{N^2}$. Nhưng vì mỗi hàng chỉ có thể có đúng 1 quân hậu, ta duyệt theo hàng: Hàng 0 đặt 1 quân, hàng 1 đặt 1 quân,... Không gian trạng thái giảm mạnh xuống còn $N^N$.

### 6.2. Biểu diễn State

Không cần lưu mảng 2 chiều. Chỉ cần mảng 1 chiều `board`, trong đó `board[r] = c` nghĩa là tại hàng `r`, quân hậu được đặt ở cột `c`.

### 6.3. Constraints (Kiểm tra mâu thuẫn)

Cần đảm bảo không có quân hậu nào trước đó ở hàng `i` mâu thuẫn với quân hậu định đặt ở tọa độ `(r, c)`.
Thay vì dùng 2 vòng `for` kiểm tra, ta có một tính chất toán học trên lưới tọa độ vuông:

1. **Cột:** Các ô cùng cột có giá trị `col` bằng nhau. Ta dùng mảng `usedCol[c]`.
2. **Đường chéo chính ():** Các ô trên cùng đường chéo chính có hiệu số `row - col` là một hằng số. (VD: $(0,0), (1,1), (2,2) \rightarrow row-col=0$). Do $row - col$ có thể âm, ta cộng thêm $N$ để dùng làm chỉ số mảng: `row - col + N`.
3. **Đường chéo phụ (/):** Các ô trên cùng đường chéo phụ có tổng `row + col` là một hằng số.

### 6.4. Code C++ (Bản tối ưu $O(1)$ cho kiểm tra)

```cpp
void solveNQueens(int r, int n, vector<bool>& usedCol,
                  vector<bool>& diag1, vector<bool>& diag2)
{
    // Base case: Đã đặt thành công quân hậu ở n hàng (từ 0 đến n-1)
    if (r == n)
    {
        // Ghi nhận 1 cấu hình hợp lệ
        return;
    }

    // Thử đặt quân hậu vào từng cột ở hàng r hiện tại
    for (int c = 0; c < n; c++)
    {
        // Constraint: Kiểm tra O(1) nhờ mảng đánh dấu
        if (!usedCol[c] && !diag1[r - c + n] && !diag2[r + c])
        {
            // Make choice
            usedCol[c] = diag1[r - c + n] = diag2[r + c] = true;

            // Recurse: Xuống hàng tiếp theo
            solveNQueens(r + 1, n, usedCol, diag1, diag2);

            // Undo
            usedCol[c] = diag1[r - c + n] = diag2[r + c] = false;
        }
    }
}

```

### 6.5. Phân tích độ phức tạp

Ở hàng đầu tiên, có $N$ lựa chọn. Hàng tiếp theo có không quá $N-1$ lựa chọn (do ràng buộc cột)... Do đó, cây trạng thái có worst-case Big-O là $O(N!)$. Tuy nhiên, nhờ ràng buộc đường chéo (pruning), số nhánh bị cắt xén rất sớm, thực tế chạy nhanh hơn nhiều so với $O(N!)$.

---

## 7. Branch and Bound (Kỹ thuật Nhánh và Cận)

Nếu Backtracking là kỹ thuật tìm kiếm "Lời giải hợp lệ", thì Branch and Bound (B&B) là kỹ thuật tìm kiếm "Lời giải tối ưu".

### 7.1. Định nghĩa

- **Branch (Nhánh):** Quá trình phân rã cây trạng thái (như Backtracking).
- **Bound (Cận):** Một hàm ước lượng giá trị tốt nhất (tối ưu nhất) mà từ nút hiện tại đi xuống các lá có thể đạt được.
- **Pruning (Cắt tỉa):** Nếu một nhánh có giá trị Bound _tệ hơn_ một lời giải hoàn chỉnh mà ta đã từng tìm được (Best Known Solution), ta khẳng định chắc chắn đi xuống nhánh đó không mang lại nghiệm tốt hơn, và lập tức loại bỏ nó.

### 7.2. So sánh Backtracking và Branch & Bound

| Đặc điểm         | Backtracking                        | Branch and Bound                      |
| ---------------- | ----------------------------------- | ------------------------------------- |
| **Mục tiêu**     | Tìm TẤT CẢ các cấu hình hợp lệ.     | Tìm MỘT nghiệm TỐI ƯU nhất (Max/Min). |
| **Cách cắt tỉa** | Dựa trên tính hợp lệ của bài toán.  | Dựa trên tính tối ưu tiềm năng.       |
| **Khi nào tỉa?** | Khi vi phạm ràng buộc (Constraint). | Khi Bound $\ge$ Best (bài toán Min).  |
| **Bài toán**     | N-Queens, Sudoku, Sinh hoán vị...   | TSP, Knapsack, Cắt vật liệu...        |

### 7.3. Cách xây dựng một Bound tốt

Giả sử ta giải bài toán **Tìm Min**.

- Ta cần một biến toàn cục `best_answer = +INFINITY`.
- Tại trạng thái $S$ đang xét, chi phí đã trả là `current_cost`.
- Ta phải tính `lower_bound` (cận dưới) cho phần công việc chưa hoàn thành. Điều kiện là: $lower\_bound \le actual\_future\_cost$.
- Tổng chi phí ước lượng tối thiểu: `estimated = current_cost + lower_bound`.
- **Logic Pruning:** Nếu `estimated >= best_answer`, ta cắt nhánh.

Nếu cận được thiết kế quá lỏng (ví dụ `lower_bound = 0`), B&B sẽ thoái hóa thành Backtracking duyệt toàn bộ. Cận càng chặt (gần thực tế), thuật toán chạy càng nhanh.

---

## 8. Traveling Salesman Problem - TSP

### 8.1. Phát biểu bài toán

Có $N$ thành phố. Một người giao hàng xuất phát từ thành phố 0, cần đi qua tất cả $N-1$ thành phố còn lại, mỗi thành phố đúng 1 lần, và quay về thành phố 0. Ma trận chi phí `cost[i][j]` cho biết khoảng cách. Tìm đường đi có tổng chi phí nhỏ nhất (Minimization).

### 8.2. Mô hình hóa trạng thái

- **Cấu trúc:** Một mảng hoán vị bắt đầu bằng `0`.
- **State:**
- `curr_city`: Thành phố đang đứng.
- `visited_count`: Số lượng thành phố đã thăm.
- `current_cost`: Tổng chi phí đã tiêu tốn.

### 8.3. B&B để giải TSP

Ta sẽ thiết kế một hàm `Bound` đơn giản:

- Gọi `cmin` là chi phí của cạnh nhỏ nhất trong toàn bộ đồ thị (tính một lần ở đầu chương trình).
- Nếu ta còn $N - visited\_count$ thành phố phải đi qua, và 1 bước quay về điểm xuất phát (tổng cộng $N - visited\_count + 1$ cạnh cần đi).
- `lower_bound = (N - visited_count + 1) * cmin`.
- `estimated_cost = current_cost + lower_bound`.
- Nếu `estimated_cost >= best_cost`, cắt nhánh.

### 8.4. Mã nguồn C++ cho TSP

```cpp
int best_cost = INT_MAX;
int cmin; // Gán giá trị nhỏ nhất của mảng cost ở hàm main

void TSP(int curr_city, int visited_count, int current_cost,
         int n, vector<vector<int>>& cost, vector<bool>& visited)
{
    // Cắt tỉa (Pruning) bằng Branch and Bound
    int estimated_cost = current_cost + (n - visited_count + 1) * cmin;
    if (estimated_cost >= best_cost) return; // Nhánh này vô vọng

    // Base case: Đã thăm đủ n thành phố
    if (visited_count == n)
    {
        // Cộng thêm chi phí quay về thành phố xuất phát (thành phố 0)
        int total_cost = current_cost + cost[curr_city][0];
        if (total_cost < best_cost)
        {
            best_cost = total_cost; // Cập nhật kỷ lục mới
        }
        return;
    }

    // Duyệt qua các thành phố tiếp theo
    for (int next_city = 1; next_city < n; next_city++)
    {
        if (!visited[next_city] && cost[curr_city][next_city] > 0)
        {
            visited[next_city] = true; // Make choice

            TSP(next_city, visited_count + 1,
                current_cost + cost[curr_city][next_city],
                n, cost, visited);     // Đi sâu xuống nhánh

            visited[next_city] = false; // Undo
        }
    }
}

```

**Tại sao pruning này an toàn?** Vì `cmin` là cạnh rẻ nhất đồ thị, phần đoạn đường chưa đi KHÔNG THỂ NÀO có giá rẻ hơn `cmin * số đoạn`. Do đó, `estimated_cost` chắc chắn nhỏ hơn hoặc bằng chi phí thực tế. Nếu ngay cả cái ước lượng lạc quan nhất này còn lớn hơn `best_cost`, thì chi phí thực tế đi nhánh này chắc chắn sẽ lớn hơn, không thể làm kỷ lục giảm xuống được.

---

## 9. Cách suy luận từ đề bài để chọn thuật toán

Kỹ năng quan trọng nhất không phải là code, mà là nhìn đề và biết dùng "bài" gì.

| Dấu hiệu trong đề                              | Thuật toán nên nghĩ đến      | Lý do                                                        |
| ---------------------------------------------- | ---------------------------- | ------------------------------------------------------------ |
| Tìm TẤT CẢ tổ hợp, cấu hình. $N \le 20$.       | Backtracking                 | Vấn đề duyệt toàn không gian, không có trạng thái trùng lặp. |
| Tìm TẤT CẢ các hoán vị, thứ tự.                | Backtracking + mảng `used[]` | Cần duyệt mọi nhánh nhưng không lặp phần tử.                 |
| Tập con, chọn K phần tử, không xét thứ tự.     | Backtracking + biến `start`  | Ép chiều tăng dần của chỉ số để khử trùng lặp hoán vị.       |
| Tìm kết quả TỐI ƯU trên không gian hoán vị.    | Branch and Bound             | Cần duyệt nhưng có thể tỉa bớt các nhánh kém tối ưu.         |
| Đi trên lưới/ma trận, tìm đường, giải mê cung. | Backtracking (Grid)          | Loang với 4 hướng, cần Undo để thử đường khác.               |

### Checklist Suy Luận (11 bước)

1. **Tôi đang xây dựng cái gì?** $\rightarrow$ Dạng kết quả cần trả về.
2. **Tại mỗi bước có những lựa chọn nào?** $\rightarrow$ Xác định vòng `for`.
3. **Biểu diễn State thế nào?** $\rightarrow$ Xác định tham số hàm.
4. **Constraint là gì?** $\rightarrow$ Lệnh `if` bọc ngoài nhánh đệ quy.
5. **Khi nào đạt Solution?** $\rightarrow$ Điệu kiện dừng (Base case).
6. **Cần hoàn tác (Undo) cái gì?** $\rightarrow$ Lệnh đằng sau đệ quy.
7. **Có bị trùng nghiệm không?** $\rightarrow$ Suy nghĩ xem có cần biến `start`.
8. **Bài toán có yêu cầu Tối ưu (Max/Min) không?** $\rightarrow$ Đưa thêm B&B vào.
9. **Bound tính bằng cách nào?** $\rightarrow$ Dùng một logic đơn giản hóa bài toán.
10. **Độ sâu cây là bao nhiêu?** $\rightarrow$ Kích thước tối đa của đáp án.
11. **Worst-case Complexity?** $\rightarrow$ Kiểm tra xem thuật toán có bị Time Limit Exceeded không.

---

## 10. Những template C++ cần ghi nhớ

_Lưu ý: Đừng học vẹt, hãy hiểu cấu trúc "Cơ sở $\rightarrow$ Lựa chọn $\rightarrow$ Hợp lệ $\rightarrow$ Hành động $\rightarrow$ Đệ quy $\rightarrow$ Hoàn tác"._

### Template 1: Backtracking Cơ Bản / Hoán Vị

**Khi nào dùng:** Sắp xếp đối tượng có thứ tự.
**Đặc điểm:** Vòng `for` chạy từ 0, dùng `used[]`.

### Template 2: Tổ Hợp / Tập Con

**Khi nào dùng:** Bốc K phần tử từ N phần tử, không quan tâm thứ tự.
**Đặc điểm:** Vòng `for` chạy từ biến `start`. Truyền `i + 1` vào đệ quy tiếp theo.

### Template 3: Grid / Maze

**Khi nào dùng:** Bài toán di chuyển trên đồ thị mảng 2 chiều.
**Đặc điểm:** Dùng mảng hướng `dr`, `dc`. Kiểm tra biên `0 <= r < R`. Dùng `visited[][]`.

### Template 4: Branch and Bound Tối Ưu Hóa

**Khi nào dùng:** Bài toán Min/Max với không gian nhỏ.
**Đặc điểm:** Giống Backtracking nhưng dòng đầu tiên kiểm tra hàm Bound và `return` sớm.

---

## 11. Phân tích độ phức tạp

Complexity của Backtracking ít khi là một đa thức.
Công thức tổng quát tính số lượng Node trên cây: **Số Node $\approx b^d$**

- **$b$ (Branching factor):** Số lượng trung bình các nhánh con tỏa ra từ một nút.
- **$d$ (Depth):** Độ sâu lớn nhất của cây trạng thái.

**Ví dụ:**

- **Sinh hoán vị $N$ phần tử:** Cấp 1 có $N$ nhánh, cấp 2 có $N-1$ nhánh... Số nút lá là $N!$. Tổng số nút là $\approx e \cdot N!$. Độ phức tạp $O(N!)$.
- **Sinh tập con:** Tại mỗi phần tử, ta có 2 quyết định (Chọn hoặc Không chọn). Độ sâu là $N$. Độ phức tạp: $O(2^N)$.
- **N-Queens:** Worst case là $O(N!)$, nhưng do Constraint rất mạnh (cột, 2 đường chéo), hằng số $b$ giảm liên tục, số lượng node thực tế sinh ra nhỏ hơn nhiều so với $N!$. Không có công thức Big-O chính xác chặt chẽ nào ngoài $O(N!)$.

**Độ phức tạp bộ nhớ (Space Complexity):**
Backtracking dùng đệ quy. Bộ nhớ tiêu tốn chính là kích thước của ngăn xếp gọi hàm (Call Stack). Do thuật toán duyệt theo chiều sâu, độ sâu call stack tối đa chính là $d$. Vậy độ phức tạp không gian (chưa tính lưu trữ kết quả) thường là $O(d)$. (Ví dụ $O(N)$ cho hoán vị).

---

## 12. Những lỗi tư duy và lỗi code phổ biến

1. **Quên thao tác Undo (Hoàn tác):**

- _Biểu hiện:_ Kết quả chỉ in ra 1 nhánh đầu tiên, các nhánh sau rác hoặc văng lỗi.
- _Sửa:_ Luôn có cặp đối xứng `push_back` - đệ quy - `pop_back`, hoặc `visited[i]=true` - đệ quy - `visited[i]=false`.

2. **Truyền tham trị (Pass-by-value) cho chuỗi/mảng lớn:**

- _Lỗi:_ Dùng `void backtrack(vector<int> path)` thay vì `vector<int>& path`.
- _Hậu quả:_ Code chạy rất chậm, Time Limit Exceeded do C++ copy toàn bộ mảng ra vùng nhớ mới ở mỗi tầng đệ quy.

3. **Kiểm tra Constraint quá muộn:**

- _Lỗi:_ Đẩy giá trị sai vào `path`, gọi đệ quy, sang hàm con mới kiểm tra và return.
- _Hậu quả:_ Cây trạng thái phình to không cần thiết. Hãy kiểm tra Constraint bằng lệnh `if` TRƯỚC khi gọi đệ quy (Look-ahead).

4. **Thiết kế Bound sai lệch (Over-pruning):**

- _Lỗi:_ Trong Branch & Bound, ước tính `lower_bound` lớn hơn chi phí thực tế có thể xảy ra.
- _Hậu quả:_ Thuật toán cắt bỏ nhầm cái nhánh chứa nghiệm tối ưu, trả về đáp án sai. (Quy tắc vàng: `lower_bound` phải luôn LẠC QUAN hơn hoặc BẰNG thực tế).

---

## 13. Cách debug Backtracking

Vì hệ thống tự động nhảy qua lại giữa các hàm, việc đọc mã sẽ rất rối. Cách debug tốt nhất là in ra log dạng cây.

Sử dụng tham số `depth` để thụt lề:

```cpp
void debug_print(int depth, const string& msg) {
    for (int i = 0; i < depth; i++) cerr << "  "; // Thụt lề
    cerr << msg << endl;
}

void backtrack(int depth, ...) {
    debug_print(depth, "Enter state");
    // ...
    if (isValid()) {
        debug_print(depth, "Try branch X");
        backtrack(depth + 1, ...);
        debug_print(depth, "Backtrack from X");
    }
}

```

Khi chạy, console sẽ in ra quá trình thuật toán đi xuống các nhánh và dội ngược lên, giống hệt cấu trúc của cây trạng thái. Rất dễ phát hiện lỗi.

---

## 14. So sánh tổng thể

| Thuật toán         | Cơ chế duyệt                 | Bộ nhớ            | Ứng dụng tiêu biểu                      | Độ phức tạp đặc trưng                 |
| ------------------ | ---------------------------- | ----------------- | --------------------------------------- | ------------------------------------- |
| **Brute Force**    | Không có (For lồng nhau).    | Thấp              | Vấn đề cực nhỏ.                         | $O(N!), O(2^N)$                       |
| **DFS**            | Ngăn xếp (LIFO).             | $O(V)$            | Tìm miền liên thông, chu trình đồ thị.  | $O(V + E)$                            |
| **Backtracking**   | DFS + Constraint Pruning.    | $O(\text{Depth})$ | Sinh tổ hợp, N-Queens.                  | $O(N!), O(2^N)$ (xấp xỉ)              |
| **Branch & Bound** | BT + Optimality Pruning.     | $O(\text{Depth})$ | TSP, Knapsack, Min/Max.                 | Giống BT nhưng thực tế chạy nhanh hơn |
| **Quy hoạch động** | Memozation (Lưu trạng thái). | Cao               | Vấn đề có chuỗi bài toán con lồng nhau. | Đa thức $O(N^2), O(N^3)$              |

---

## 15. Quy trình giải bài Backtracking thực tế (End-to-End)

**Bài toán:** Trích xuất mảng Tổ hợp.

1. **Xác định đối tượng:** Mảng các số nguyên chiều dài $K$.
2. **Xác định State:** `(int depth, int start, vector<int>& path)`.
3. **Xác định Choice:** `for(int i = start; i < N; i++)`.
4. **Xác định Constraint:** Ở bài này không có, mọi số từ `start` đều hợp lệ.
5. **Xác định Base Case:** `if (path.size() == K) { in ra; return; }`.
6. **Viết Recursion & Backtrack:**

```cpp
path.push_back(arr[i]);
backtrack(depth + 1, i + 1, path);
path.pop_back();

```

7. **Phân tích:** Số nút tối đa là hệ số nhị thức $C_N^K$.
8. **Cơ hội Pruning:** Nếu độ dài `path` cộng với số phần tử còn lại trong mảng gốc `< K` thì không đủ để tạo ra kết quả, có thể `return` sớm nhánh này (đây là một dạng Bound về kích thước).

---

## 16. Ví dụ minh họa bằng cách suy luận thủ công

**Bài toán 4-Queens ($N=4$)**

- **State:** Xét hàng $r=0$.
- **Choice:** Cột $c=0$.
- **Valid:** Yes.
- **Recurse:** Tới $r=1$.
- **Choice:** Cột $c=0$ $\rightarrow$ Invalid (cùng cột).
- **Choice:** Cột $c=1$ $\rightarrow$ Invalid (đường chéo).
- **Choice:** Cột $c=2$ $\rightarrow$ Valid.
- **Recurse:** Tới $r=2$.
- Thử $c=0,1,2,3$ $\rightarrow$ Tất cả Invalid (bị 2 quân trước chiếu).
- **Prune & Backtrack:** Quay lại $r=1$, tháo quân ở $c=2$ ra.

- **Choice:** Cột $c=3$ $\rightarrow$ Valid.
- **Recurse:** Tới $r=2$.
- **Choice:** Cột $c=1$ $\rightarrow$ Valid.
- **Recurse:** Tới $r=3$.
- Thử $c=0,1,2,3$ $\rightarrow$ Tất cả Invalid.
- **Prune & Backtrack.**

- **Backtrack gốc:** Tháo quân ở $r=0, c=0$ ra.
- **Choice mới:** Cột $c=1$. (Nhánh này sẽ sinh ra đáp án thực sự).

---

## 17. Các bài tập tự luyện

_Gợi ý từ vựng cho sinh viên ngành khoa học máy tính khi tìm kiếm trên LeetCode/Hackerrank:_

**Level 1 - Cơ bản (Hiểu cơ chế Recursion/Undo)**

- _Bài 1:_ In dãy nhị phân độ dài N. (Kỹ thuật: Choice là 0 hoặc 1, không cần vòng `for`).
- _Bài 2:_ Tìm đường đi trong mê cung chỉ cho phép đi Xuống và Phải. (Kỹ thuật: Grid Backtracking cơ bản).

**Level 2 - Trung bình (Master các Template)**

- _Subsets / Subsets II:_ Sinh tập con, có và không có phần tử trùng lặp. (Kỹ thuật: Xử lý trùng lặp bằng cách bỏ qua số giống nhau sau khi sort).
- _Permutations / Permutations II:_ Hoán vị. (Kỹ thuật: Mảng `used`).
- _Combination Sum:_ (Kỹ thuật: Pruning khi tổng vượt quá target).

**Level 3 - Khá (State phức tạp, Grid logic)**

- _N-Queens / N-Queens II:_ Đã phân tích kỹ trong tài liệu.
- _Word Search:_ Tìm từ trong bảng chữ cái 2D. (Kỹ thuật: Backtracking trên ma trận kết hợp đối chiếu chuỗi).

**Level 4 - Nâng cao (Branch and Bound, Optimization)**

- _Traveling Salesman Problem (TSP):_ Đã giải trong phần 8.
- _0/1 Knapsack Problem (Dùng B&B):_ Tính mật độ value/weight để làm Cận (Bound).

---

## 18. Active Recall (Tự kiểm tra trí nhớ)

Hãy tự trả lời các câu hỏi sau để củng cố kiến thức:

1. Backtracking là gì? Vì sao gọi nó là DFS trên cây trạng thái?
2. State là gì? Choice là gì? Constraint là gì?
3. Nếu không có bước `pop_back` (Undo), cây đệ quy sẽ bị lỗi như thế nào?
4. Tại sao sinh hoán vị cần mảng `used[]` còn sinh tổ hợp lại cần biến `start`?
5. Làm sao kiểm tra 2 vị trí `(r1, c1)` và `(r2, c2)` có nằm trên cùng 1 đường chéo chính trong O(1)?
6. Kỹ thuật Branch and Bound khác Backtracking thông thường ở điểm cốt lõi nào?
7. "Cận" (Bound) là gì? Tại sao trong bài toán tìm Min, nếu Bound $\ge$ Kỷ lục hiện tại thì ta có thể chặt nhánh?
8. Tại sao TSP lại là bài toán thuộc loại siêu khó (NP-Hard)?
9. Công thức xấp xỉ số node của một cây đệ quy là gì? Phụ thuộc vào yếu tố nào?

---

## 19. Cheat Sheet cuối tài liệu

- **Template Tổng Quát:** `if (base_case) return; for (choices) if (isValid) { make_choice; recurse; undo_choice; }`
- **Permutation (Hoán vị):** Vòng lặp luôn bắt đầu `for(i=0)`. Bắt buộc phải có cờ `used[i]` để loại bỏ phần tử đã dùng.
- **Combination (Tổ hợp):** Vòng lặp phải bắt đầu từ `for(i=start)`. Hàm đệ quy tiếp theo gọi `recurse(i + 1)`. Không cần cờ `used`.
- **Grid DFS:** Khởi tạo `dr[]={-1,1,0,0}`, `dc[]={0,0,-1,1}`. Luôn kiểm tra biên trước tiên `(0 <= r < R)`. Nhớ gỡ cờ `visited` sau khi đệ quy.
- **N-Queens (Trick):** 3 mảng bool kiểm tra cột, chéo chính (`row - col + N`), chéo phụ (`row + col`).
- **Branch and Bound:** Dùng cho bài toán tối ưu. Thêm điều kiện `if (current + bound >= best) return;` ngay sau Base Case. Luôn thiết kế Bound sao cho lạc quan hơn giá trị thực tế.
- **Lỗi 90% sinh viên mắc phải:** Thiếu tham chiếu `&` trong hàm (`vector<int>& path`), dẫn đến Time Limit Exceeded do copy bộ nhớ quá nhiều.

---

## Kết luận

Con đường đi từ Đệ quy cơ bản (Recursion) đến Tìm kiếm theo chiều sâu (DFS), phát triển lên thành Quay lui (Backtracking) với khả năng cắt tỉa tính hợp lệ (Pruning), và đạt đến đỉnh cao của tìm kiếm tổ hợp là Nhánh và Cận (Branch and Bound) dựa trên tính tối ưu, là một chuỗi phát triển tư duy rất tuyến tính và đẹp mắt.

Là một lập trình viên Computer Science, mục tiêu cuối cùng của bạn **không phải là học thuộc các template**. Giá trị thực sự nằm ở khả năng nhìn vào một bài toán mới, xác định được đâu là không gian trạng thái, lựa chọn cách biểu diễn trạng thái (state) đó gọn gàng nhất, đặt ra các ràng buộc (constraint) chặt chẽ nhất để loại bỏ triệt để các nhánh dư thừa. Khi bạn làm chủ được cách thiết kế hàm Bound trong TSP, việc đối mặt với bài toán tối ưu trên không gian rời rạc sẽ không còn là rào cản. Tương tự như việc gỡ rỗi các lỗi trong dự án thực tế, mọi thứ đều bắt đầu bằng việc hiểu cấu trúc "cây quyết định" của nó.
