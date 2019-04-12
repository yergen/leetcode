#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace::std;

class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0, current = 0;
		stack<int> st;
		while (current < height.size())
		{
			//当前bar能盛的水
			while (!st.empty() && height[current] > height[st.top()])
			{
				//栈中最后一个递减值
				int top = st.top();
				st.pop();
				if (st.empty())
					break;
				//栈中倒数第二个值
				int distance = current - st.top() - 1;
				int bounded_height = min(height[current], height[st.top()]) - height[top];
				ans += distance *bounded_height;
			}
			st.push(current++);
		}
		return ans;
	}
};

int main()
{
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	Solution sol;

	cout << sol.trap(height) << endl;

	return 0;
}