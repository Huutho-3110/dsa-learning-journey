/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

void Try(int start, vector<int> &v, vector<bool> &used, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            if (start == 1 || abs(i - v[start - 1]) != 1)
            {
                v[start] = i;
                used[i] = true;
                if (start == n)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        cout << v[j];
                    }
                    cout << endl;
                }
                else
                {
                    Try(start + 1, v, used, n);
                }
                used[i] = false;
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
        vector<int> v;
        vector<bool> used;
        cin >> n;
        v.resize(n + 1);
        used.assign(n + 1, false);
        Try(1, v, used, n);
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