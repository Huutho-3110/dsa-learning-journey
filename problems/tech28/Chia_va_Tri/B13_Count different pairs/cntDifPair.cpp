/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, k;
ll a[1000000];
ll tmp[1000000];
// vector<ll> tmp;
int dem(ll a[], ll l, ll m, ll r)
{

    ll j = m + 1;
    ll cnt = 0;

    return cnt;
}
void merge(ll a[], ll l, ll m, ll r)
{
    ll x = l;
    ll i = l;
    ll j = m + 1;
    ll dem;

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp[x] = a[i];
            ++i;
        }
        else
        {
            tmp[x] = a[j];
            ++j;
        }
        ++x;
    }
    while (i <= m)
    {
        tmp[x] = a[i];
        ++i;
        ++x;
    }
    while (j <= r)
    {
        tmp[x] = a[j];
        ++j;
        ++x;
    }
    for (ll t = l; t <= r; t++)
    {
        a[t] = tmp[t];
    }
}
ll sapxep(ll a[], ll l, ll r)
{
    if (l >= r)
        return 0;
    ll m = l + (r - l) / 2;
    ll res = 0;
    res += sapxep(a, l, m);
    res += sapxep(a, m + 1, r);
    res += dem(a, l, m, r);
    merge(a, l, m, r);
    return res;
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll ans = sapxep(a, 0, n - 1);
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