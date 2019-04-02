#include<iostream>  
#include<queue>  
using namespace std;
#define Max 10000  
int n, l, p;
int A[Max], B[Max];
int solve() {
	//ans表示最后结果，即最小加油次数  
	//pos表示当前卡车位置  
	//tank表示油缸中油的数量   
	//que优先队列中存放之前能通过的各个加油站的最大加油量Bi   
	priority_queue<pair<int, int> > que;
	int ans = 0, pos = 0, tank = p;
	for (int i = 0; i < n; i++) {
		int curDist = A[i] - pos;   //curDist表示到达下一个临时终点(加油站)的距离   
		while (curDist > tank)      //当前油不够到下一个终点   
		{
			if (que.empty()) {
				//cout<<"无法到达终点~"<<endl;  
				return -1;
			}
			pair<int, int> temp = que.top();
			que.pop();
			tank += temp.first;         //不断加油,直到能到达下一个终点   
			cout << temp.second + 1 << " ";
			ans++;
		}

		tank -= curDist;          //跑到下一个终点，消耗 curDist数量的油  
		pos = A[i];               //到达下一个加油站，取得该加油站的油，放在优先队列中，以便后面使用   
		que.push(make_pair(B[i], i));

	}
	cout << endl;
	return ans;
}
int main() {
	cin >> n >> l >> p;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}
	cout << "加油的站点的编号:";
	cout << solve();
	return 0;
}