#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int s, m;
	
	typedef vector<pair<int, int>> rec_type;
	rec_type	rec;
	
	for (int i = 0; i < k; i++)
	{
		vector<int>::iterator max = max_element(v.begin(), v.end());
		vector<int>::iterator min = min_element(v.begin(), v.end());
		if ((*max - *min) != 0)
		{
			(*max)--;
			(*min)++;
			rec.push_back(make_pair(distance(v.begin(), max)+1,distance(v.begin(), min)+1));
		}
		else
		{
			break;
		}
	}
	vector<int>::iterator max = max_element(v.begin(), v.end());
	vector<int>::iterator min = min_element(v.begin(), v.end());
	s = *max - *min;
	m = rec.size();
	cout << s << " " << m << "\n";
	rec_type::iterator iter = rec.begin();
	rec_type::iterator end = rec.end();
	for (; iter != end; iter++)
	{
		cout << (*iter).first << " " << (*iter).second << "\n";
	}
}
//#include <iostream>
//#include<algorithm>
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//using namespace std;
//
//int main() {
//	int num = 0;
//	int k = 0;
//
//	cin >> num >> k;
//	int* height = new int[num];
//	for (int i = 0; i<num; i++) {
//		cin >> height[i];
//	}
//	sort(height, height + num);
//	int wen = height[num - 1] - height[0];
//	for (int i = 0; i<k; i++) {
//		if (height[num - 1] - height[0]>wen) break;
//		height[num - 1]--;
//		height[0]++;
//		sort(height, height + num);
//		wen = height[num - 1] - height[0];
//	}
//	cout << wen << ' ' << k;
//
//	return 0;
//}