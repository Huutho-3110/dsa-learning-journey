/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, k, a[100];
int res(ll n, ll k)
{
    if (n == 1)
        return 1;
    if (k == a[n] / 2 + 1)
        return n;
    if (k <= a[n - 1])
        return res(n - 1, k);
    return res(n - 1, k - a[n - 1] - 1);
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        a[1] = 1;
        a[0] = 0;
        for (int i = 2; i <= n; i++)
        {
            a[i] = a[i - 1] * 2 + 1;
        }
        cout << res(n, k);
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