/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll binpow(ll n, ll m, ll mod)
{
    if (m == 0)
        return 1;
    ll half = binpow(n, m / 2, mod);
    ll res = (half * half) % mod;
    if (m % 2)
        res = (res * n) % mod;
    return res;
}
ll dao(ll n)
{

    ll ni = 0;
    while (n != 0)
    {
        ni = ni * 10 + n % 10;
        n /= 10;
    }
    return ni;
}
class Solution
{
public:
    void solve()
    {
        ll n, m;
        cin >> n;
        m = dao(n);
        ll ans = binpow(n, m, MOD);
        cout << ans;
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