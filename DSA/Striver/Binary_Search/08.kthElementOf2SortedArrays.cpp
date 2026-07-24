#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
  // assuming first array to be smaller, so that TC becomes O(log(min(n, m)))
  // we do BS on smaller array
  if (m < n)
    return kthElement(arr2, arr1, m, n, k);

  // ex: n=4, m=6 & k=7, here k>m means even if we take full arr2 we need to
  // select atleast (k-m) elements
  int low = max(0, k - m);
  // ex: n=4, m=6 & k=3, here k<n so we can't take high as k
  int high = min(n, k);

  while (low <= high) {
    int cut1 = low + (high - low) / 2;
    int cut2 = k - cut1;

    int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
    int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
    int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
    int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

    if (l1 <= r2 && l2 <= r1)
      return max(l1, l2);
    else if (r2 < l1)
      high = cut1 - 1;
    else
      low = cut1 + 1;
  }
  return -1;
}
