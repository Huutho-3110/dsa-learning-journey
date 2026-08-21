/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
int t;

long long F[100];
string ans(int n, long long k)
{
    if (n == 1)
        return "28tech";
    if (n == 2)
        return "C++";
    if (n == 3)
    {
        if (k == 1)
            return "DSA";
        if (k == 2)
            return "JAVA";
    }
    if (k <= F[n - 3])
        return ans(n - 3, k);
    else if (F[n - 3] < k && k <= F[n - 3] + F[n - 2])
        return ans(n - 2, k - F[n - 3]);
    else
    {
        return ans(n - 1, k - F[n - 2] - F[n - 3]);
    }
}
class Solution
{
public:
    void solve()
    {
        F[1] = 1;
        F[2] = 1;
        F[3] = 2;
        for (int i = 4; i < 100; i++)
        {
            F[i] = F[i - 1] + F[i - 2] + F[i - 3];
        }
        cin >> t;
        while (t--)
        {
            int n;
            long long k;
            cin >> n >> k;
            cout << ans(n, k) << endl;
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