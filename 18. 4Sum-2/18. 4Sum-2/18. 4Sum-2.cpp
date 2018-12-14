#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        typedef pair<int, int> pii;

        size_t nums_size = nums.size();
        if(nums_size < 4){
            return {};
        }


        unordered_map<int, vector<pii>> mark;

        set<vector<int>> result_set;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums_size;++i){
            for(int j  = i+1; j < nums_size;++j){
                mark[nums[i]+nums[j]].push_back(make_pair(i, j));
            }
        }

        typedef unordered_map<int, vector<pii>>::iterator iter_type;
        for(int i = 0; i < nums_size - 3; ++i){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target){
                break;
            }
            for(int j=i+1; j < nums_size - 2; ++j){
                if(mark.find(target - (nums[i]+nums[j]))!= mark.end()){
                    vector<pii>& v = mark[target - (nums[i]+nums[j])];
                    for(int k =0; k < v.size();++k){ //auto&& x: mark[target - (nums[i]+nums[j])]
                        pii& x = v[k];
                        if(x.first > j){
                            vector<int> temp{nums[i], nums[j], nums[x.first], nums[x.second]};
                            result_set.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> result(result_set.begin(), result_set.end());


        return result;
//        unordered_map<int,vector<pii>> mark;
//        set<vector<int>> res;
//        vector<vector<int>> res2;
//        if(nums.size()<4)
//            return res2;
////这个地方也可以不用排序的，排序是因为减少一些计算量，方便下面的循环判定提前跳出条件
//        sort(nums.begin(),nums.end());
//        for(int i=0; i<nums.size(); i++)
//            for(int j=i+1; j<nums.size(); j++)
//                mark[nums[i]+nums[j]].push_back(make_pair(i,j));
//
////注意注意这个地方有一个巨大的坑，中间的判断条件： i<nums.size()-3，会陷入到死循环中
////因为nums.size()是一个unsigned的类型，其与int相运算，得到的还是unsigned！！！！！
////所以如果nums.size()<3的话就会出现死循环，切记切记
//        for(int i=0; i<nums.size()-3; i++)
//        {
//            //先判定，提前跳出的情况
//            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
//                break;
//            for(int j=i+1; j<nums.size()-2; j++)
//            {
//                if(mark.find(target-(nums[i]+nums[j])) != mark.end())
//                {
//                    for(auto &&x:mark[target-(nums[i]+nums[j])])
//                    {
//                        if(x.first>j)
//                        {
//                            vector<int> tmp{nums[i],nums[j],nums[x.first],nums[x.second]};
//                            res.insert(tmp);
//                        }
//                    }
//                }
//            }
//        }
//
//        for(auto &&x:res)
//        {
//            res2.push_back(x);
//        }
//        return res2;

    }

};

int main()
{
    Solution sln;
    vector<int> nums{1, 0, -1, 0, -2, 2};

    int target = 0;
    vector<vector<int>> res = sln.fourSum(nums, target);

    for(auto& item:res)
    {
        for(auto& elem:item)
        {
            printf("%d ", elem);
        }
        printf("\n");
    }
}

