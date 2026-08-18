/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> maze;
int dx[] = {1, 0, 0, -1}; // i - rows

int dy[] = {0, -1, 1, 0}; // j - cols
bool isFound = false;
string direction = "DLRU";
void Try(int i, int j, int (&visit)[10][10], string path)
{

    if (i == n && j == n)
    {
        isFound = true;
        cout << path << '\n';
        return;
    }

    for (int t = 0; t < 4; t++)
    {
        int i1 = i + dx[t];
        int j1 = j + dy[t];
        if (j1 >= 1 && j1 <= n && i1 >= 1 && i1 <= n && visit[i1][j1] == 0 && maze[i1][j1] == 1)
        {
            path += direction[t];
            visit[i1][j1] = 1;
            Try(i1, j1, visit, path);
            visit[i1][j1] = 0;
            path.pop_back();
        }
    }
}

class Solution
{
public:
    void solve()
    {
        cin >> n;
        string path = "";
        maze.assign(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> maze[i][j];
        }
        int visit[10][10] = {0};
        visit[1][1] = 1;
        Try(1, 1, visit, path);
        if (!isFound)
        {
            cout << -1 << '\n';
        }
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