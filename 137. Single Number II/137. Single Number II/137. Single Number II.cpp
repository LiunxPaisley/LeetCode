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
#include <numeric>

#include <cstring> 
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;
/*
�������ֽⷨ˼·Ҳʮ�������������ⷨ��˼·�����ǰ����������ֵ�ÿһλ�ۼ�������3ȡ�࣬
ʣ�µĽ�������Ǹ����������λ�ϵ����֣����������ۼӵĹ��̶�Ҫ��3ȡ�࣬��ôÿһλ���ۼ�
�Ĺ��̾���0->1->2->0�����ɶ����Ƶı�ʾΪ00->01->10->00����ô���ǿ���д����Ӧ��ϵ��
00 (+) 1 = 01
01 (+) 1 = 10
10 (+) 1 = 00 ( mod 3)

��ô������ab����ʾ��ʼ��״̬�����ڼ�1�����󣬵õ�����״̬��ab���㷨���£�
b = b xor r & ~a;
a = a xor r & ~b;
���������ab�������������״̬00��01��10��ʮλ�͸�λ���տ�ʼ��ʱ��a��b����0������ʱ
��������1��ʱ��b����Ϊ1��a����Ϊ0������01��״̬���ٴ�����1��ʱ��b����Ϊ0��a����Ϊ
1������10��״̬���ٴ�����1��ʱ��b����Ϊ0��a����Ϊ0������00��״̬���൱�������ˣ����
�Ľ��������b�С�����������ķ������̣�����д���������£�
*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int a = 0, b = 0;
		for (int i = 0; i < nums.size(); ++i) {
			b = (b ^ nums[i]) & ~a;
			a = (a ^ nums[i]) & ~b;
		}
		return b;
	}
};


int main() {
	Solution sln;
}