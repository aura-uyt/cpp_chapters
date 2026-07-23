#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int optimain(vector<int> &arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int missing = arr[mid] - mid - 1;
      if (missing < k)
        low = mid + 1;
      else
        high = mid - 1;
    }
    // return arr[high] + k - (arr[high] - high - 1);
    // return k + high + 1; // low = high + 1 bcz that's when loop ends
    return k + low;
  }
  int bruteForce(vector<int> &arr, int k) {
    for (int i : arr)
      if (k >= i)
        k++;

    return k;
  }
};
