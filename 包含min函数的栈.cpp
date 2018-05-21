//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数

//算法实现:

//1.设置一个辅助栈min.压入的时候当辅助栈为空的时候或者压入元素小于等于辅助栈顶元素的时候压入
//2.pop的时候只要弹出去的元素等于栈顶元素那么辅助栈的元素也弹出去，随时保持栈中最小元素的一致性

class Solution {
private:
	stack<int> s;
	stack<int>  s_min;
public:
	void push(int value) {
		//如果辅助栈为空或者压入的元素小于辅助栈的元素则压进去
		s.push(value);
		if (s_min.empty() || value <= s_min.top())//如果辅助栈为空
		{
			s_min.push(value);
		}
	}
	void pop() {
		//当弹出去的值等于栈顶元素的值得话那么将辅助栈中的元素也弹出去
		if (s.top() == s_min.top())
			s_min.pop();
		s.pop();
	}
	int top() {
		return s.top();
	}
	int min() {
		return s_min.top();
	}
};