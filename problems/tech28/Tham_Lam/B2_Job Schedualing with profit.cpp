/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
struct job
{
    int id, deadline, profit;
};
struct CompareCost
{
    bool operator()(const job &a, const job &b)
    {
        return a.profit < b.profit;
    }
};
class Solution
{
public:
    void solve()
    {
        priority_queue<job, vector<job>, CompareCost> pq;
        int n, prof = 0;
        int maxDl = -1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            job tmp;
            cin >> tmp.id >> tmp.deadline >> tmp.profit;
            if (tmp.deadline > maxDl)
                maxDl = tmp.deadline;
            pq.push(tmp);
        }
        vector<bool> visDl(maxDl, false);
        while (!pq.empty())
        {
            job current_job = pq.top();
            pq.pop();

            for (int j = current_job.deadline - 1; j >= 0; j--)
            {
                if (!visDl[j])
                {
                    visDl[j] = true;
                    prof += current_job.profit;
                    break;
                }
            }
        }
        cout << prof;
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