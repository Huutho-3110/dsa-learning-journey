/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

int cmin = 1e9;
int chip = 1e9;
void Try(int i, int curCost, int C[][100], int visit[], int n, int keep[])
{
    if (i > n)
    {
        int total = curCost + C[keep[n]][keep[1]];
        if (total < chip)
        {
            chip = total;
        }
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if (!visit[j])
        {

            int temp = curCost + C[keep[i - 1]][j] + (n - i + 1) * cmin;
            if (temp < chip)
            {
                keep[i] = j;
                visit[j] = 1;
                Try(i + 1, curCost + C[keep[i - 1]][j], C, visit, n, keep);
                visit[j] = 0;
            }
        }
    }
}
class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        int C[100][100], visit[100], keep[100];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> C[i][j];
                if (C[i][j] != 0 && C[i][j] < cmin)
                {
                    cmin = C[i][j];
                }
            }
        }
        keep[1] = 1;
        visit[1] = 1;
        Try(2, 0, C, visit, n, keep);
        cout << chip << '\n';
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