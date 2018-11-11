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
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size(), k = 0;
        for(;i < j;){
            if(nums[i]+nums[j]<0){
                k = j-1;
                while(nums[k]>0){

                }
            }else if(nums[i]+nums[j]>0) {
                k = i+1;
                while(nums[k]<0){

                }
            }else{
                k = i+1;
                while(nums[k] != 0){

                }
            }
        }
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

