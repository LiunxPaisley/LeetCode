#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <memory>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> st;
        int         size1 = nums1.size();
        int         size2 = nums2.size();
        int         ave   = (size1 + size2) / 2 + 1;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int i = 0, j = 0;
        while (true)
        {

            if (nums1[i] < nums2[j])
            {
                st.push_back(nums1[i]);
                i += 1;
            }
            else
            {
                st.push_back(nums2[j]);
                j += 1;
            }

            if (st.size() >= ave)
            {
                break;
            }
        }
        if ((size1 + size2) % 2 != 0)
        {
            return st.back() / 1.0;
        }
        else
        {
            return (st[st.size() - 1] + st[st.size() - 2]) / 2.0;
        }
    }
};

int main()
{
    vector<int> nums1 = { 1, 3 };
    vector<int> nums2 = { 2 };
    Solution    sln;
    auto        res = sln.findMedianSortedArrays(nums1, nums2);
    cout << "res = " << res << "\n";
}