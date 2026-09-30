#include <bits\stdc++.h>
using namespace std;
int partition(vector<int> &nums, int low, int high) {
  int mid = low + (high - low) / 2;
  int i = low - 1;
  int j = high + 1;

  int pivot = nums[mid];
  while (true) {
    do {
      i++;
    } while (nums[i] < pivot);
    do {
      j--;
    } while (nums[j] > pivot);
    if (i >= j)
      return j;
    swap(nums[i], nums[j]);
  }
}
void quickSort(vector<int> &nums, int low, int high) {
  if (low < high) {
    int pi = partition(nums, low, high);
    quickSort(nums, low, pi);
    quickSort(nums, pi + 1, high);
  }
}
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    quickSort(nums, 0, (int)nums.size() - 1);
    return nums;
  }
};