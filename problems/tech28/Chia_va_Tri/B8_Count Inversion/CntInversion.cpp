/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n;
ll a[10000000];
ll tmp[10000000];
ll merge(ll a[], ll l, ll m, ll r)
{
    ll i = l;
    ll j = m + 1;
    ll k = l;
    ll total = 0;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp[k] = a[i];
            ++i;
        }
        else
        {
            total += (m - i + 1);
            tmp[k] = a[j];
            j++;
        }
        ++k;
    }
    while (i <= m)
    {
        tmp[k] = a[i];
        ++i;
        ++k;
    }
    while (j <= r)
    {
        tmp[k] = a[j];
        ++j;
        ++k;
    }
    for (ll p = l; p <= r; ++p)
    {
        a[p] = tmp[p];
    }
    return total;
}
ll mergesort(ll a[], ll l, ll r)
{
    ll cnt = 0;
    if (l >= r)
        return 0;

    else
    {
        ll m = l + (r - l) / 2;
        cnt += mergesort(a, l, m);
        cnt += mergesort(a, m + 1, r);
        cnt += merge(a, l, m, r);
    }
    return cnt;
}
class Solution
{
public:
    void solve()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll ans = mergesort(a, 0, n - 1);
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