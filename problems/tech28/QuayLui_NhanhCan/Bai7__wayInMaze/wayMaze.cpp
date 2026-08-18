/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void TRY(vector<vector<int>> &maze, int n, int m, int i, int j)
{
    if (i == n && j == m)
    {

        ++cnt;
    }
    if (i + 1 <= n && maze[i + 1][j] != 0)
    {
        TRY(maze, n, m, i + 1, j);
    }
    if (j + 1 <= m && maze[i][j + 1] != 0)
    {
        TRY(maze, n, m, i, j + 1);
    }
}

class Solution
{
public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        string path = "";
        vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> maze[i][j];
            }
        }
        TRY(maze, n, m, 1, 1);
        cout << cnt << '\n';
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