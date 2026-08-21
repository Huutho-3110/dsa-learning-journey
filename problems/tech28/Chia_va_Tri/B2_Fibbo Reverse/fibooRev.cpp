/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
long long n, k, a[100];

char ans(long long n, long long k)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (k <= a[n - 1])
        return ans(n - 1, k);
    return ans(n - 2, a[n - 2] - (k - a[n - 1]) + 1);
}

class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        a[1] = 1;
        a[2] = 1;
        for (long long i = 3; i <= n; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        cout << ans(n, k);
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