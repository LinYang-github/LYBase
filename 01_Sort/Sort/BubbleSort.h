#ifndef BubbleSort_h__
#define BubbleSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	冒泡排序算法.  </summary>
///
/// 通过与相邻元素的比较和交换来把小的数交换到最前面
/// 过程类似于水泡向上升一样
/// 时间复杂度：O(n^2)
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class BubbleSort
{
public:

	BubbleSort(void);
	~BubbleSort(void);
public:
	
	template<typename T>
	static void bubbleSort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		for (int i = 0; i < length(arr) - 1; i++)
		{
			for (int j = length(arr) - 1; j > i; j--)
			{
				if (arr[j] < arr[j-1])
				{
					swap(arr, j-1, j);
				}
			}
		}
	}
 
};

#endif // BubbleSort_h__

