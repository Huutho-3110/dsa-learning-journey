/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

int n = 8;
int cnt = 0;
int MAX = -1;
vector<bool> nguoc, xuoi, cot;
vector<vector<int>> grid;
void Try(int rows, int curSum)
{
    if (rows > n)
    {
        ++cnt;
        if (curSum > MAX)
            MAX = curSum;

        return;
    }
    for (int cols = 1; cols <= n; cols++)
    {
        if (!cot[cols] && !nguoc[rows + cols - 1] && !xuoi[rows - cols + n])
        {
            cot[cols] = nguoc[rows + cols - 1] = xuoi[rows - cols + n] = true;
            Try(rows + 1, curSum + grid[rows][cols]);
            cot[cols] = nguoc[rows + cols - 1] = xuoi[rows - cols + n] = false;
        }
    }
}
class Solution
{
public:
    void solve()
    {
        grid.assign(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> grid[i][j];
            }
        }
        xuoi.assign(n + 1, false);
        nguoc.assign(n + 1, false);
        cot.assign(n + 1, false);
        Try(1, 0);
        cout << MAX << endl;
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
