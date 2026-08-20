/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>
using namespace std;
int n, k;
bool final = false;
int a[100];
vector<string> nhieuhon;
vector<string> noitiep;
void checkLientiep(string tmp)
{
    int dayK = 0;
    int cnt = 0;

    for (int i = 0; i <= (int)tmp.size(); i++)
    {
        if (i < (int)tmp.size() && tmp[i] == '1')
        {
            cnt++;
        }
        else
        {
            if (cnt == k)
            {
                dayK++;
            }
            if (cnt > k)
            {
                return;
            }

            cnt = 0;
        }
    }
    if (dayK == 1)
    {
        noitiep.push_back(tmp);
    }
}
void checkNhieuhon(string tmp)
{
    int cnt = 0;
    for (int i = 0; i < (int)tmp.size(); i++)
    {
        if (tmp[i] == '1')
            cnt++;
        if (cnt > k)
            return;
    }
    if (cnt == k)
        nhieuhon.push_back(tmp);
}
void sinh()
{
    int i = n;
    while (i > 0 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i == 0)
    {
        final = true;
    }
    else
    {
        a[i] = 1;
    }
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
        }
        while (!final)
        {
            string tmp = "";
            for (int i = 1; i <= n; i++)
            {
                tmp += to_string(a[i]);
            }
            if (k != 1)
                checkLientiep(tmp);
            checkNhieuhon(tmp);
            sinh();
        }
        for (int i = 0; i < (int)nhieuhon.size(); i++)
        {
            cout << nhieuhon[i] << " ";
        }
        cout << endl;
        if (k != 1)
            for (int i = 0; i < (int)noitiep.size(); i++)
            {
                cout << noitiep[i] << " ";
            }
        else
        {
            for (int i = 0; i < (int)nhieuhon.size(); i++)
            {
                cout << nhieuhon[i] << " ";
            }
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