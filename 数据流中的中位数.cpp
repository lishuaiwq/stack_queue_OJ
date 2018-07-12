如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值

算法：在这里采用优先级队列，其实其本质就是堆，在本质就是一个数组。


因为要求求中位数，所以这里如果总数是奇数位那么中间的那个就是中位数，如果总是是偶数位的话那么中间两个数的和就是中位数，所以我们将这串数字分为两组，前面的数据构建一个大堆来处理，后面的元素构建一个小堆来处理。当总数是偶数的时候插入大堆。但是插入之前要保证插入的元素比小堆中的堆顶元素小，否则需要将其插入到小堆里面，取出堆顶的元素，在放入大堆中。如果是奇数的话，插入小堆，则需要检测插入小堆的元素必须大于大堆中的元素，和上述处理方法一样。

//
class Solution {
public:
public:
	priority_queue<int, vector<int>, greater<int> >  min;//小堆
	priority_queue<int, vector<int>> max;//大堆
	void Insert(int num)
	{
		if (min.empty())
		{
			min.push(num);
			return;
		}
		if (max.empty())
		{
			max.push(num);
			return;
		}
		if ((max.size() + min.size()) % 2 == 0)//偶数的时候给大堆方
		{
			//放入大堆之前首先要判断他是不是比小堆中最小的元素还要大，如果是则将其插入小堆
			//然后取出小堆的堆顶元素，插入到大堆,因为插入的元素一定比小堆最小的元素要小
			if (num > min.top())
			{
				min.push(num);
				num = min.top();
				min.pop();
			}
			max.push(num);
		}
		else//是奇数的话给小堆
		{
			if (num < max.top())
			{
				max.push(num);
				num = max.top();
				max.pop();
			}
			min.push(num);
		}
	}


	double GetMedian()
	{
		if (max.size() + min.size() % 2 == 0)
		{
			int a = max.top();
			int b = min.top();
			return (a + b) / 2.0;
		}
		else
		{
			return max.top();
		}
	}
};