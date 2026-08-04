# C++ Data Structures & Algorithms Journey

> A structured repository documenting my long-term journey of learning Data Structures and Algorithms using C++.  
> This repository emphasizes consistency, engineering discipline, documentation, and continuous improvement rather than simply collecting accepted solutions.

---

# Developer's Note

This repository begins tracking my learning journey from **Lesson 7**.

Lessons 1–6 were completed before I established a proper Git and GitHub workflow. Instead of recreating commit history or uploading old, unorganized source code, I chose to start tracking my progress transparently from my current stage.

I believe a Git repository should represent the real development process—not an artificially reconstructed history.

Every commit, note, refactoring, and solution in this repository reflects my actual learning progress.

The absence of earlier lessons serves as a reminder that maintaining a disciplined engineering workflow is just as important as writing code.

---

# Repository Architecture

```text
DSA-Journey/
├── .github/
│   └── workflows/             # CI/CD Pipeline (Tự động biên dịch mã nguồn C++)
├── assets/                    # Hình ảnh, sơ đồ minh họa (Ví dụ: Đồ thị, Cây nhị phân)
├── docs/                      # Meta-data: Quản lý tiến độ và chất lượng
│   ├── mistakes.md            # Nhật ký bắt Bug (Segmentation Fault, Memory Leak...)
│   ├── progress.md            # Theo dõi lộ trình hoàn thành các bài học
│   └── study-log.md           # Nhật ký thời gian code hằng ngày
├── notes/                     # Knowledge Base: Không gian lý thuyết độc lập
│   ├── 07-arrays-strings.md   # Ghi chép lý thuyết và phân tích độ phức tạp
│   └── 08-linked-lists.md
├── problems/                  # Workspace: Nơi chứa toàn bộ mã nguồn C++
│   ├── lesson_07/
│   │   └── two_sum.cpp
│   └── lesson_08/
├── templates/                 # Boilerplates: Khuôn mẫu chuẩn hóa
│   ├── cpp-boilerplate.cpp    # Khung code C++ tối ưu I/O, khai báo class chuẩn
│   ├── problem-template.md    # Khung trình bày bài giải (Intuition, $O(N)$ Complexity)
│   └── theory-template.md     # Khung ghi chép lý thuyết cấu trúc dữ liệu
├── .gitignore                 # Cổng an ninh: Chặn tệp tin nhị phân (.exe, .o, build/)
└── README.md                  # Landing page & Tuyên ngôn minh bạch của kỹ sư
```

---

# Study Workflow

Every lesson follows the same engineering workflow.

```text
Study Theory
      ↓
Write Personal Notes
      ↓
Design Algorithm
      ↓
Implement in C++
      ↓
Test & Debug
      ↓
Review Mistakes
      ↓
Refactor
      ↓
Commit to GitHub
```

This workflow encourages understanding, documentation, iterative improvement, and long-term consistency instead of focusing only on solving problems.

---

# Commit Convention

| Prefix      | Description                            |
| ----------- | -------------------------------------- |
| `algo:`     | Add a new algorithm or solve a problem |
| `docs:`     | Update documentation or study notes    |
| `refactor:` | Improve existing implementation        |
| `fix:`      | Fix bugs or incorrect logic            |
| `test:`     | Add or improve test cases              |
| `style:`    | Code formatting or style changes       |
| `chore:`    | Repository maintenance                 |

### Examples

```text
algo: implement binary search
docs: add notes for graph traversal
fix: correct BFS implementation
refactor: optimize merge sort
test: add edge cases for linked list
```

---

# Project Goals

- Build a solid foundation in Data Structures and Algorithms.
- Develop disciplined software engineering habits.
- Document every important concept learned.
- Maintain transparent progress through Git history.
- Continuously improve problem-solving ability and code quality.

---

# Engineering Principles

- Learn before memorizing.
- Understand before optimizing.
- Document before forgetting.
- Refactor before moving forward.
- Prioritize consistency over speed.

---

> "This repository is not a collection of solved problems. It is a transparent record of how I learn, make mistakes, improve, and grow as a future software engineer."

---

# Hành trình học Cấu trúc Dữ liệu & Giải thuật bằng C++

> Repository này ghi lại quá trình học Data Structures & Algorithms bằng C++ một cách có hệ thống, tập trung vào tính kỷ luật, tài liệu hóa, khả năng giải quyết vấn đề và sự tiến bộ liên tục, thay vì chỉ lưu trữ lời giải.

---

# Ghi chú từ người phát triển

Repository này bắt đầu ghi nhận quá trình học từ **Lesson 7**.

Các bài học từ **Lesson 1 đến Lesson 6** đã được hoàn thành trước khi tôi xây dựng quy trình làm việc với Git và GitHub.

Thay vì tạo lại lịch sử commit hoặc tải lên những đoạn mã cũ thiếu tổ chức, tôi quyết định bắt đầu theo dõi quá trình học của mình một cách trung thực từ thời điểm hiện tại.

Tôi tin rằng một repository nên phản ánh đúng quá trình phát triển thực tế, thay vì mô phỏng một lịch sử hoàn hảo.

Mỗi commit, mỗi ghi chú, mỗi lần sửa lỗi và cải tiến trong repository này đều phản ánh đúng quá trình học tập của tôi.

Việc thiếu các bài học đầu tiên là lời nhắc nhở rằng xây dựng quy trình làm việc chuyên nghiệp cũng quan trọng không kém việc viết được chương trình.

---

# Kiến trúc Repository

```text
DSA-Journey/
├── .github/
│   └── workflows/             # CI/CD Pipeline (Tự động biên dịch mã nguồn C++)
├── assets/                    # Hình ảnh, sơ đồ minh họa (Ví dụ: Đồ thị, Cây nhị phân)
├── docs/                      # Meta-data: Quản lý tiến độ và chất lượng
│   ├── mistakes.md            # Nhật ký bắt Bug (Segmentation Fault, Memory Leak...)
│   ├── progress.md            # Theo dõi lộ trình hoàn thành các bài học
│   └── study-log.md           # Nhật ký thời gian code hằng ngày
├── notes/                     # Knowledge Base: Không gian lý thuyết độc lập
│   ├── 07-arrays-strings.md   # Ghi chép lý thuyết và phân tích độ phức tạp
│   └── 08-linked-lists.md
├── problems/                  # Workspace: Nơi chứa toàn bộ mã nguồn C++
│   ├── lesson_07/
│   │   └── two_sum.cpp
│   └── lesson_08/
├── templates/                 # Boilerplates: Khuôn mẫu chuẩn hóa
│   ├── cpp-boilerplate.cpp    # Khung code C++ tối ưu I/O, khai báo class chuẩn
│   ├── problem-template.md    # Khung trình bày bài giải (Intuition, $O(N)$ Complexity)
│   └── theory-template.md     # Khung ghi chép lý thuyết cấu trúc dữ liệu
├── .gitignore                 # Cổng an ninh: Chặn tệp tin nhị phân (.exe, .o, build/)
└── README.md                  # Landing page & Tuyên ngôn minh bạch của kỹ sư
```

---

# Quy trình học tập

Mỗi bài học đều được thực hiện theo cùng một quy trình.

```text
Học lý thuyết
      ↓
Ghi chú
      ↓
Thiết kế thuật toán
      ↓
Hiện thực bằng C++
      ↓
Kiểm thử và sửa lỗi
      ↓
Ghi lại bài học
      ↓
Refactor
      ↓
Commit lên GitHub
```

Quy trình này giúp tôi không chỉ giải được bài toán mà còn hiểu bản chất, ghi nhớ lâu dài và liên tục cải thiện chất lượng mã nguồn.

---

# Quy ước Commit

| Tiền tố     | Ý nghĩa                           |
| ----------- | --------------------------------- |
| `algo:`     | Thêm thuật toán hoặc lời giải mới |
| `docs:`     | Cập nhật tài liệu hoặc ghi chú    |
| `refactor:` | Cải thiện mã nguồn                |
| `fix:`      | Sửa lỗi                           |
| `test:`     | Bổ sung hoặc cải thiện kiểm thử   |
| `style:`    | Định dạng mã nguồn                |
| `chore:`    | Bảo trì repository                |

---

# Mục tiêu của dự án

- Xây dựng nền tảng vững chắc về Cấu trúc Dữ liệu và Giải thuật.
- Hình thành tác phong làm việc của một kỹ sư phần mềm.
- Ghi chép đầy đủ những kiến thức đã học.
- Theo dõi quá trình phát triển thông qua Git.
- Không ngừng cải thiện tư duy giải quyết vấn đề và chất lượng mã nguồn.

---

# Nguyên tắc

- Hiểu trước khi ghi nhớ.
- Hiểu bản chất trước khi tối ưu.
- Ghi chép trước khi quên.
- Refactor trước khi chuyển sang bài tiếp theo.
- Ưu tiên sự bền bỉ hơn tốc độ.

---

> "Repository này không đơn thuần là tập hợp các bài đã giải, mà là bản ghi trung thực về quá trình học tập, mắc lỗi, cải thiện và trưởng thành trên con đường trở thành một kỹ sư phần mềm."
