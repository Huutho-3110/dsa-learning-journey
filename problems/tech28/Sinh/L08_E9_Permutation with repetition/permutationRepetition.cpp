/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

void sinh(int &n, int a[], bool &final, int &k)
{
    int i = k;
    while (a[i] == n & i > 0)
    {
        a[i] = 1;
        i--;
    }
    if (i == 0)
    {
        final = true;
    }
    else
    {
        a[i]++;
    }
}
class Solution
{
public:
    void solve()
    {
        int n, k;
        int a[20];

        bool final = false;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            a[i] = 1;
        }
        while (!final)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << a[i];
            }
            cout << '\n';
            sinh(n, a, final, k);
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