/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> ans;
vector<int> kq;

void Try(int start, int curSum, int &k, int &n, int a[])
{
    if (curSum > k)
        return;
    if (curSum == k)
    {
        ans.push_back(kq);
    }
    for (int j = start; j < n; j++)
    {
        if (curSum + a[j] > k)
            break;
        kq.push_back(a[j]);
        Try(j + 1, curSum + a[j], k, n, a);
        kq.pop_back();
    }
}
class Solution
{
public:
    void solve()
    {
        int n, k;
        int a[10000];
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        Try(0, 0, k, n, a);
        if (ans.size() == 0)
        {
            cout << -1;
            return;
        }
        for (auto x : ans)
        {
            cout << "[";
            for (int i = 0; i < (int)x.size(); ++i)
            {
                cout << x[i];
                if (i + 1 < (int)x.size())
                    cout << " ";
            }
            cout << "]" << '\n';
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