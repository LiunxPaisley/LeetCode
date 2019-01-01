#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        size_t nums_size = nums.size();
        if(nums_size < 4){
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<int> selector(nums_size, 0);

        for(int i = 0; i < 4; ++i){
            selector[i] = 1;
        }

//        for(auto item : selector){
//            cout << item << " ";
//        }
//        cout << endl;

        vector<int> store;
        set<vector<int>> result_set;
        vector<int> temp(nums_size, 0);
        do{
            for(size_t i = 0; i < nums_size; ++i){
                if(selector[i] == 1){
                    store.push_back(nums[i]);
                }
            }
            // cout << "store.size() = " << store.size() << endl;
            int sum = accumulate(store.begin(), store.end(), 0);
            if(sum == target){
                //sort(store.begin(), store.end());
                result_set.insert(store);
            }
            store.clear();
        }while(prev_permutation(selector.begin(), selector.end()));
        vector<vector<int>> result(result_set.begin(), result_set.end());
        return result;
    }

};

int main(){
    Solution sln;
    vector<int> nums{1, 0, -1, 0, -2, 2};

    int target = 0;
    vector<vector<int>> res = sln.fourSum(nums, target);

    for(auto& item:res){
        for(auto& elem:item){
            printf("%d ", elem);
        }
        printf("\n");
    }
}
