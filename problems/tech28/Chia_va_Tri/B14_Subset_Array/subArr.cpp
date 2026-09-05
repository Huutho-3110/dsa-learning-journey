/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, x;
vector<ll> a;
vector<ll> fA;
vector<ll> tmp;
ll merge(ll l, ll m, ll r)
{
    ll k = l;
    ll i = l;
    ll j = m + 1;
    ll cnt = 0;
    for (int i = l; i <= m; i++)
    {
        while (j <= r && fA[j] - fA[i] < x)
        {
            j++;
        }
        cnt += (j - (m + 1));
    }
    j = m + 1;
    while (i <= m && j <= r)
    {

        if (fA[i] <= fA[j])
        {
            tmp[k++] = fA[i++];
        }
        else
        {
            tmp[k++] = fA[j++];
        }
    }
    while (i <= m)
    {
        tmp[k++] = fA[i++];
    }
    while (j <= r)
    {
        tmp[k++] = fA[j++];
    }

    for (int t = l; t <= r; t++)
    {
        fA[t] = tmp[t];
    }
    return cnt;
}

ll mergeSort(ll l, ll r)
{
    if (l >= r)
        return 0;
    ll m = l + (r - l) / 2;
    ll res = 0;
    res += mergeSort(l, m);
    res += mergeSort(m + 1, r);
    res += merge(l, m, r);
    return res;
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> x;
        a.resize(n + 1);
        fA.resize(n + 1);
        fA[0] = 0;
        tmp.resize(n);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {

            fA[i] = fA[i - 1] + a[i];
        }
        ll ans = mergeSort(0, n);
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