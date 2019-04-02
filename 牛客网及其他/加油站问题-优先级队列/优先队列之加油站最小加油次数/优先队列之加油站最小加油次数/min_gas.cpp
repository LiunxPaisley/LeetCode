#include<iostream>  
#include<queue>  
using namespace std;
#define Max 10000  
int n, l, p;
int A[Max], B[Max];
int solve() {
	//ans��ʾ�����������С���ʹ���  
	//pos��ʾ��ǰ����λ��  
	//tank��ʾ�͸����͵�����   
	//que���ȶ����д��֮ǰ��ͨ���ĸ�������վ����������Bi   
	priority_queue<pair<int, int> > que;
	int ans = 0, pos = 0, tank = p;
	for (int i = 0; i < n; i++) {
		int curDist = A[i] - pos;   //curDist��ʾ������һ����ʱ�յ�(����վ)�ľ���   
		while (curDist > tank)      //��ǰ�Ͳ�������һ���յ�   
		{
			if (que.empty()) {
				//cout<<"�޷������յ�~"<<endl;  
				return -1;
			}
			pair<int, int> temp = que.top();
			que.pop();
			tank += temp.first;         //���ϼ���,ֱ���ܵ�����һ���յ�   
			cout << temp.second + 1 << " ";
			ans++;
		}

		tank -= curDist;          //�ܵ���һ���յ㣬���� curDist��������  
		pos = A[i];               //������һ������վ��ȡ�øü���վ���ͣ��������ȶ����У��Ա����ʹ��   
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
	cout << "���͵�վ��ı��:";
	cout << solve();
	return 0;
}