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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    kq.x[i][j] += a.x[i][k] * b.x[k][j];
                    kq.x[i][j] %= MOD;
                }
            }
        }
        return kq;
    }
};

matran binpow(matran &tmp, ll k)
{
    if (k == 1)
        return tmp;
    matran X = binpow(tmp, k / 2);
    if (k % 2 == 0)
        return X * X;
    else
    {
        return tmp * X * X;
    }
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        matran a;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> a.x[i][j];
            }
        }
        matran res = binpow(a, k);

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cout << res.x[i][j] << " ";
            }
            cout << "\n";
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