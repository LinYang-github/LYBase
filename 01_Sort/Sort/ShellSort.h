#ifndef ShellSort_h__
#define ShellSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	希尔排序算法.  </summary>
///
/// 是插入排序的一种高效率的实现，也叫缩小增量排序
/// 先将整个待排记录序列分割称为若干子序列分别进行直接插入排序，
/// 待整个序列中的记录基本有序时再对全体记录进行一次直接插入排序
/// 不能一步一步向前移，而是跳跃式的；最后一趟排序时做到基本有序
/// 时间复杂度：O(n^1.3)
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class ShellSort
{
public:
	ShellSort(void);
	~ShellSort(void);

	template<typename T>
	static void shellInsert(T& arr, int d)
	{
		for (int i = d; i < length(arr); i++)
		{
			int j = i - d;
			int temp = arr[i];//记录要插入的数据;
			while(j >= 0 && arr[j] > temp)
			{
				//从后向前，找到比其小的数的位置;
				arr[j + d] = arr[j];//向后挪动;
				j -= d;
			}

			if (j != i - d)//存在比其小的数;
			{
				arr[j+d] = temp;
			}
		}
	}

	template<typename T>
	static void shellSort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		int d = length(arr)/2;
		while(d >= 1)
		{
			shellInsert(arr, d);
			d /=2;
		}
	}
};


#endif // ShellSort_h__
