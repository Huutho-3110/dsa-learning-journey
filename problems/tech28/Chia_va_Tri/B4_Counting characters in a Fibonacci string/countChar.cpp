/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, a[1000], kituA[100];
ll res(ll n, ll k)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 0;
    if (k == 0)
        return 0;
    if (k == a[n])
        return kituA[n];
    if (k > a[n - 2])
        return res(n - 1, k - a[n - 2]) + kituA[n - 2];
    return res(n - 2, k);
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        a[1] = 1;
        kituA[1] = 1;
        kituA[2] = 0;
        a[2] = 1;
        for (ll i = 3; i <= n; i++)
        {
            a[i] = a[i - 2] + a[i - 1];
            kituA[i] = kituA[i - 2] + kituA[i - 1];
        }

        cout << res(n, k);
        // Implement logic here
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