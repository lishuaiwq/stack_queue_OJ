������ջʵ��һ������

�㷨������ֻ��stack1��stac2

��ôѹ���ʱ��ֻ��Ҫ��stack1��ѹ��Ϳ���

��ô������ʱ�������ж�stack2�Ƿ�Ϊ�գ����Ϊ�վͽ�stack1�е�����Ԫ��ѹ��stack2Ȼ��stack2.pop�Ϳ����ˡ�
����ĵ���ֻҪstack2��Ϊ��֤��֮ǰ��ѹ��Ԫ�ػ�û��ȫ������ȥ����ô������stack2��������Ԫ�ؾͿ�����

����

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