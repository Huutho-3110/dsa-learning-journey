/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

void print(string path)
{
    for (int i = 0; i < (int)path.size(); i++)
    {
        cout << path[i];
    }
    cout << endl;
}

void TRY(vector<vector<int>> &maze, int n, int i, int j, string &path)
{
    if (i == n && j == n)
    {
        if (!path.size())
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            print(path);
        }
    }
    if (i + 1 <= n && maze[i + 1][j] == 1)
    {
        path += "D";
        TRY(maze, n, i + 1, j, path);
        path.pop_back();
    }
    if (j + 1 <= n && maze[i][j + 1] == 1)
    {
        path += "R";
        TRY(maze, n, i, j + 1, path);
        path.pop_back();
    }
}

class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        string path = "";
        vector<vector<int>> maze(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> maze[i][j];
            }
        }
        TRY(maze, n, 1, 1, path);
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