/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
vector<ll> tmp;

ll sapxep(vector<ll> &a, ll l, ll r, vector<ll> &tmp)
{
    if (l >= r)
        return 0;
    ll m = l + (r - l) / 2;
    ll res = 0;
    res += sapxep(a, l, m, tmp);
    res += sapxep(a, m + 1, r, tmp);
    int j = m + 1;
    for (int i = l; i <= m; i++)
    {
        while (j <= r && a[i] > a[j] + k)
        {
            j++;
        }
        res += (j - (m + 1)); // Cộng dồn bằng long long
    }

    int i = l;
    j = m + 1;
    int x = l;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp[x++] = a[i++];
        }
        else
        {
            tmp[x++] = a[j++];
        }
    }

    while (i <= m)
        tmp[x++] = a[i++];
    while (j <= r)
        tmp[x++] = a[j++];

    for (int t = l; t <= r; t++)
    {
        a[t] = tmp[t];
    }

    return res;
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        tmp.resize(n);
        ll ans = sapxep(a, 0, n - 1, tmp);
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
