/**
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.empty() || nums.back() < 0 || nums.front() > 0){ return {};}
        int k = 0;
        for(;k < nums.size(); ++k){
            if(nums[k] > 0){
                break;
            }
            if(k > 0 && nums[k]==nums[k-1]) {
                continue;
            }
            int target = 0 - nums[k];
            int i = k+1;
            int j = nums.size() - 1;
            while(i<j){
                if(nums[i]+nums[j]==target){
                    res.insert({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i+1]){i++;}
                    while(i < j && nums[j] == nums[j-1]){j--;}
                    ++i;
                    --j;
                }else if(nums[i]+nums[j]< target){
                    ++i;
                }else{
                    --j;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

int main(){
    Solution sln;
    vector<int> nums{};
    vector<vector<int>> res = sln.threeSum(nums);
    for(auto& item:res){
        for(auto& elem:item){
            printf("%d ", elem);
        }
        printf("\n");
    }
}

