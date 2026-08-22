/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n;
ll a[1000000];
ll tmp[1000000];
ll sum(ll a[], ll l, ll m, ll r)
{
    ll dem = 0;
    ll j = m + 1;
    for (int i = l; i <= m; i++)
    {
        while (j <= r && a[i] > 2 * a[j])
            ++j;
        dem += j - (m + 1);
    }
    return dem;
}
void merge(ll a[], ll l, ll m, ll r)
{
    ll i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= m)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (ll p = l; p <= r; ++p)
    {
        a[p] = tmp[p];
    }
}
ll devide(ll a[], ll l, ll r)
{
    ll cnt = 0;
    if (l >= r)
        return cnt;
    ll m = l + (r - l) / 2;
    cnt += devide(a, l, m);
    cnt += devide(a, m + 1, r);
    cnt += sum(a, l, m, r);
    merge(a, l, m, r);
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
            ll ans = devide(a, 0, n - 1);
            cout << ans;
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