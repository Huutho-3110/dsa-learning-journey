#include <bits\stdc++.h>
using namespace std;
void findFirst(vector<int> &nums, int l, int r, int &target, vector<int> &ans) {

  int minL = 1e9;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) {
      minL = m;
      r = m - 1;
    } else if (nums[m] < target) {
      l = m + 1;
    } else if (nums[m] > target) {
      r = m - 1;
    }
  }
  if (minL != 1e9) {
    ans.push_back(minL);
  }
}
void findLast(vector<int> &nums, int l, int r, int &target, vector<int> &ans) {
  int maxR = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) {
      maxR = m;
      l = m + 1;
    } else if (nums[m] < target) {
      l = m + 1;
    } else if (nums[m] > target) {
      r = m - 1;
    }
  }
  if (maxR != -1) {
    ans.push_back(maxR);
  }
}
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if ((int)nums.size() == 0)
      return {{-1, -1}};
    vector<int> ans;
    int n = nums.size() - 1;
    findFirst(nums, 0, n, target, ans);
    findLast(nums, 0, n, target, ans);
    if ((int)ans.size() != 2)
      return {{-1, -1}};
    return ans;
  }
};