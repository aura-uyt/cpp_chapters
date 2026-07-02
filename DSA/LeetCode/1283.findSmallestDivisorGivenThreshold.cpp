#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());

    while (low <= high) {
      int mid = low + (high - low) / 2;
      long long sum = 0;
      for (int i : nums)
        sum += (i + mid - 1) / mid;
      if (sum <= threshold)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return low;
  }
};
