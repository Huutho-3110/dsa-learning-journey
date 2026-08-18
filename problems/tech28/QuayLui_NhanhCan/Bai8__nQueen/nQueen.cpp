/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;
vector<bool> nguoc, xuoi, cot;
void Try(int rows)
{
    if (rows > n)
    {
        ++cnt;
        return;
    }
    for (int cols = 1; cols <= n; cols++)
    {
        if (!cot[cols] && !nguoc[rows + cols - 1] && !xuoi[rows - cols + n])
        {
            cot[cols] = nguoc[rows + cols - 1] = xuoi[rows - cols + n] = true;
            Try(rows + 1);
            cot[cols] = nguoc[rows + cols - 1] = xuoi[rows - cols + n] = false;
        }
    }
}
class Solution
{
public:
    void solve()
    {
        cin >> n;
        xuoi.assign(n + 1, false);
        nguoc.assign(n + 1, false);
        cot.assign(n + 1, false);
        Try(1);
        cout << cnt << endl;
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