/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n;
const ll MOD = 1e9 + 7;
struct matrix
{
    ll x[3][3];
    friend matrix operator*(matrix a, matrix b)
    {
        matrix kq;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                kq.x[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {

                    kq.x[i][j] += (a.x[i][k] * b.x[k][j]) % MOD;
                    kq.x[i][j] %= MOD;
                }
            }
        }
        return kq;
    };
};

matrix binpow(matrix &a, ll k)
{
    if (k == 0)
    {
        matrix id;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                id.x[i][j] = (i == j) ? 1 : 0;
            }
        }
        return id;
    }
    if (k == 1)
        return a;
    matrix tmp = binpow(a, k / 2);

    if (k % 2 == 0)
    {
        return tmp * tmp;
    }
    else
    {
        return tmp * tmp * a;
    }
}

class Solution
{
public:
    void solve()
    {
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            return;
        }

        matrix base = {{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}};
        matrix add = {{{1, 0, 0}, {1, 0, 0}, {0, 0, 0}}};
        matrix res = binpow(base, n - 2) * add;
        cout << res.x[0][0];
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