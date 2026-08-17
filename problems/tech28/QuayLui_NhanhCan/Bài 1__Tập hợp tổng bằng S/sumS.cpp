/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
int n, k, s;
int cnt = 0;
void Try(int i, int lasValue, int sum)
{
    if (sum > s)
        return;
    if (i == k + 1)
    {
        if (sum == s)
            cnt++;
        return;
    }
    for (int j = lasValue + 1; j <= n - k + i; j++)
    {
        if (sum + j <= s)
        {
            Try(i + 1, j, sum + j);
        }
        else
        {
            break;
        }
    }
}

class Solution
{
public:
    void solve()
    {
        cin >> n >> k >> s;
        Try(1, 0, 0);
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