//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min����

//�㷨ʵ��:

//1.����һ������ջmin.ѹ���ʱ�򵱸���ջΪ�յ�ʱ�����ѹ��Ԫ��С�ڵ��ڸ���ջ��Ԫ�ص�ʱ��ѹ��
//2.pop��ʱ��ֻҪ����ȥ��Ԫ�ص���ջ��Ԫ����ô����ջ��Ԫ��Ҳ����ȥ����ʱ����ջ����СԪ�ص�һ����

class Solution {
private:
	stack<int> s;
	stack<int>  s_min;
public:
	void push(int value) {
		//�������ջΪ�ջ���ѹ���Ԫ��С�ڸ���ջ��Ԫ����ѹ��ȥ
		s.push(value);
		if (s_min.empty() || value <= s_min.top())//�������ջΪ��
		{
			s_min.push(value);
		}
	}
	void pop() {
		//������ȥ��ֵ����ջ��Ԫ�ص�ֵ�û���ô������ջ�е�Ԫ��Ҳ����ȥ
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