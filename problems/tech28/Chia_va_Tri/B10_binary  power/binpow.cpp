/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
long long binpow(long long a, long long b, long long mod)
{
    if (b == 0)
        return 1;

    long long half = binpow(a, b / 2, mod);
    long long result = (half * half) % mod;

    if (b % 2)
        result = (result * a) % mod;

    return result;
}

class Solution
{
public:
    void solve()
    {
        ll n, k;
        cin >> n >> k;
        ll ans = binpow(n, k, MOD);
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