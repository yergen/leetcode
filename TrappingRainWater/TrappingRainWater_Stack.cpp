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
			//��ǰbar��ʢ��ˮ
			while (!st.empty() && height[current] > height[st.top()])
			{
				//ջ�����һ���ݼ�ֵ
				int top = st.top();
				st.pop();
				if (st.empty())
					break;
				//ջ�е����ڶ���ֵ
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