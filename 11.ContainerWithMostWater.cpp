#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int h_size = height.size();
        std::vector<int> maxsize(h_size, 0);
        for(int i = 1; i < h_size; ++i)
        {
            for(int j = 0; j < i; j++)
            {
                int temp1 = std::min(height[i], height[j])*(i-j);
                int temp2 = std::max(maxsize[i - 1], temp1);
                maxsize[i] = std::max(maxsize[i], temp2);
                //cout << "j = " << j << ", temp = " << temp2 << ", maxsize["<<i<<"] = "<<maxsize[i] << endl;
            }
            //cout << endl;
        }
        // for(auto item: maxsize)
        // {
        //     cout << item << " ";
        // }
        // cout << endl;
        return maxsize[h_size - 1];
    }
};

int main()
{
    std::vector<int> height{ 2, 7, 4, 5, 6, 2, 4, 3};
    Solution s;
    int max = s.maxArea(height);
    cout << "max: " << max << endl;
}