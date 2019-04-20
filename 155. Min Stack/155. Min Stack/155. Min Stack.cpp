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
#include <cctype>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		min = INT_MAX;
	}
	// 遇到新的最小值时，把当前的最小值先压栈，新的最小值再压栈
	// 下次弹出的是最小值时，再弹栈，即为第二小值，就变成了当前的最小值。
	void push(int x) {
		if (x <= min) {
			s1.push(min);
			min = x;
		}
		s1.push(x);
	}

	void pop() {
		if (s1.top() == min) {
			s1.pop();
			min = s1.top();
		}
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return min;
	}
private:
	stack<int> s1;
	int min;
};


int main() {
	MinStack* obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-1);
	obj->pop();
	cout << obj->top() << endl;
	cout << obj->getMin() << endl;
}