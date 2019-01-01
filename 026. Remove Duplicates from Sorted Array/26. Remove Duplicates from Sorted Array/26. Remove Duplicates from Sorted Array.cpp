#include <iostream>
#include <fstream>
#include <sstream>

#include <array>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <tuple>

#include <algorithm>
#include <utility>
#include <memory>
#include <limits>
#include <functional>

#include <cstring> 
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

        int target = nums[0];
		int count = 0;
        int nums_size = nums.size();
        for(int i = 1; i < nums_size; ++i){
            if(nums[i] == target){
                continue;
            }else{
				target = nums[i];
				count += 1;
				nums[count] = nums[i];
            }
        }
		nums.resize(count + 1);
        return count + 1;
    }
};


int main() {
    Solution sln;
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    int result = sln.removeDuplicates(nums);
    cout << result << endl;
	for (auto&& item : nums) {
		cout << item << " ";
	}
	cout << endl;
}