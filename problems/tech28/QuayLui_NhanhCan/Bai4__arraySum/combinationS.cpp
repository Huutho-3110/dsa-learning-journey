/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
int n, x;
int a[1000];
int hientai[1000];
vector<vector<int>> kq(1000);
int cnt = 0;
void nhap()
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
}

void Try(int i, int start, int sum)
{
    if (sum > x)
    {
        return;
    }
    if (sum == x)
    {
        for (int j = 1; j < i; j++)
        {
            kq[cnt].push_back(hientai[j]);
        }
        ++cnt;  
        return;
    }
    for (int j = start; j < n; j++)
    {
        if (sum + a[j] > x)
            break;
        hientai[i] = a[j];
        sum += a[j];
        Try(i + 1, j, sum);
        sum -= a[j];
    }
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> x;
        nhap();
        Try(1, 0, 0);
        if (cnt == 0)
        {
            cout << -1 << endl;
            return;
        }
        cout << cnt << '\n';
        for (int j = 0; j < cnt; j++)
        {
            cout << "{";
            for (int h = 0; h < kq[j].size(); h++)
            {
                cout << kq[j][h];
                if (h != kq[j].size() - 1)
                {
                    cout << " ";
                }
            }
            cout << "}" << '\n';
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