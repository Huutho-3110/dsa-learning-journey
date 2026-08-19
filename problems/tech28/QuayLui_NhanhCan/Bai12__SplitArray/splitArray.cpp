/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

int n, k, final = 0, sum = 0, target = 0;
/*
n: so phan tu
k: so tap con
final: check ket qua co ton tai hay khong
sum: tong tat ca cac phan tu cua day
target: muc tieu cua tong cac day con
*/
int a[1000]; // mang chua cac so input
int visited[1000]; // mang danh dau da tham hay chua

void Try(int start, int curSum, int cnt)
{
    if (final == 1) // neu da hoan thanh thuat toan va co ton tai cac tap con co tong bang nhau
        return;
    if (cnt == k) // neu da du 3 tap con (mac ke dung hay sai thi van phai dung lai)
    {
        final = 1;
        return;
    }
    if (curSum == target)
    {
        Try(1, 0, cnt + 1);
    }
    for (int j = start; j <= n; j++)
    {
        if (!visited[j] && curSum + a[j] <= target)
        {
            visited[j] = 1;
            Try(start + 1, curSum + a[j], cnt);
            visited[j] = 0;
            if (curSum == 0)
                return;
            while (j < n && a[j] == a[j + 1])
                j++;
        }
    }
}

class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        if (k == 0 || sum % k != 0 || n < k)
        {
            cout << 0 << "\n";
            return;
        }
        sort(a + 1, a + n + 1, greater<int>());
        target = sum / k;
        Try(1, 0, 0);
        cout << final << endl;
    }
};

int main()
{
    // Tối ưu hóa chuẩn I/O cho hiệu năng cao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Mẹo đọc file cục bộ, không ảnh hưởng đến GitHub Actions workflow
#ifndef ONLINE_JUDGE
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        // Bỏ comment dòng dưới nếu bạn muốn kết quả in thẳng ra file output.txt
        // freopen("output.txt", "w", stdout);
    }
#endif

    Solution solution;
    solution.solve();

    return 0;
}