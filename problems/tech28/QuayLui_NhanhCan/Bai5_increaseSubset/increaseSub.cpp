/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> input;

vector<int> kq;
void nhap()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        input.push_back(in);
    }
}

void Try(int start)
{
    if (kq.size() >= 2)
    {
        for (int i = 0; i < (int)kq.size(); i++)
        {
            cout << kq[i] << " ";
        }
        cout << '\n';
    }
    for (int j = start; j < n; j++)
    {
        if (kq.empty() || input[j] > kq.back())
        {
            kq.push_back(input[j]);
            Try(j + 1);
            kq.pop_back();
        }
    }
}
class Solution
{
public:
    void solve()
    {
        nhap();
        Try(1);
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