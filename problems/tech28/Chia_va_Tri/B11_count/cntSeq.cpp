/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
ll binpow(ll a, ll m, int mod)
{
    if (m == 0)
        return 1;
    ll half = binpow(a, m / 2, MOD);
    ll res = (half * half) % MOD;
    if (m % 2)
        res = (res * a) % MOD;
    return res;
}
class Solution
{
public:
    void solve()
    {
        ll n;
        cin >> n;
        ll res = binpow(2, n - 1, MOD);
        cout << res;
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