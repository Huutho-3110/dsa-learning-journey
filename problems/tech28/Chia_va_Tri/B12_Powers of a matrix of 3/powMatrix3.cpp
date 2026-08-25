/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
const ll MOD = 1e9 + 7;

struct matran
{
    vector<vector<ll>> x;
    matran()
    {
        x.assign(n, vector<ll>(n, 0));
    }
    friend matran operator*(matran a, matran b)
    {
        matran kq;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                for (ll k = 0; k < n; k++)
                {
                    kq.x[i][j] = (kq.x[i][j] + (a.x[i][k] * b.x[k][j]) % MOD) % MOD;
                }
            }
        }
        return kq;
    }
};

matran maxpow(matran &tmp, ll k)
{
    if (k == 1)
        return tmp;
    matran res = maxpow(tmp, k / 2);
    if (k % 2 == 0)
        return res * res;
    return res * res * tmp;
}

ll tong(matran res)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum = (sum + res.x[i][i]) % MOD;
    }
    return sum;
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        matran tmp;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> tmp.x[i][j];
            }
        }
        matran res = maxpow(tmp, k);
        cout << tong(res);
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