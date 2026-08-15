
/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
bool sinhRe(vector<int> &base, int n)
{
    int i = n - 1;
    while (i > 0 && base[i] < base[i + 1])
    {
        --i;
    }
    if (i == 0)
        return false;
    int j = n;
    while (base[i] < base[j])
        --j;
    swap(base[i], base[j]);
    reverse(base.begin() + i + 1, base.begin() + n + 1);
    return true;
}
class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        vector<int> base(n + 1);
        for (int i = 1; i <= n; i++)
        {
            base[i] = n - i + 1;
        }
        do
        {
            for (int t = 1; t <= n; t++)
            {
                cout << base[t];
            }
            cout << '\n';

        } while (sinhRe(base, n));
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