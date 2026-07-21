#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // take first array as smaller one
    if (nums2.size() < nums1.size())
      return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0;   // we can take no element
    int high = n1; // or all elements

    while (low <= high) {
      int cut1 = low + (high - low) / 2; // on nums1
      // on nums2, total elements in left - elements in cut1
      int cut2 = (n1 + n2 + 1) / 2 - cut1;

      int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
      int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
      int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
      int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

      // when Entire left half is Less than Entire righ half, then we can
      // figure out correct ans that means l1, l2 is less than r1, r2 both
      // but bcz array are sorted, hence l1 <= r1 and l2 <= r2 already
      // satisfies So we need to check at cross, i.e., is l1 <= r2
      // and l2 <= r1 satisfies ?
      if (l1 <= r2 && l2 <= r1) {
        if ((n1 + n2) % 2 == 0) // total even numbers
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        else // total odd numbers
          return max(l1, l2);
      } else if (l1 > r2)
        high = cut1 - 1; // reduce cut1 -> reduce high
      else               // l2 > r1
        low = cut1 + 1;  // reduce cut2 -> increase cut1 -> increase low
    }
    return 0.0;
  }
};
