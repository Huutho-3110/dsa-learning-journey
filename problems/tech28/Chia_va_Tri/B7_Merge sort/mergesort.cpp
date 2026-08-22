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
void merge(ll a[], ll l, ll m, ll r)
{
    ll i = l;
    ll j = m + 1;
    ll k = l;
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
        {
            tmp[k] = a[i];
            ++i;
        }
        else
        {
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
}
void mergesort(ll a[], ll l, ll r)
{
    if (l >= r)
        return;

    else
    {
        ll m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
class Solution
{
public:
    void solve()
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        mergesort(a, 0, n - 1);
        for (ll i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
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