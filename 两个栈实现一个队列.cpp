用两个栈实现一个队列

算法：假设只有stack1和stac2

那么压入的时候只需要往stack1中压入就可以

那么弹出的时候，首先判断stack2是否为空，如果为空就将stack1中的所有元素压入stack2然后stack2.pop就可以了。
后面的弹出只要stack2不为空证明之前的压入元素还没有全部弹出去，那么继续从stack2中往出弹元素就可以了

代码

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};