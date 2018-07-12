#ifndef SelectSort_h__
#define SelectSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	选择排序算法.  </summary>
///
/// 与冒泡排序类似，在一次排序后把最小的元素放在最前面
/// 非相邻的比较和交换，而是通过对整体的选择
/// 确定了最小数的前提下才进行交换，大大减少了交换的次数
/// 时间复杂度：O(n^2)
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class SelectSort
{
public:
	SelectSort(void);
	~SelectSort(void);

public:
	
	template<typename T>
	static void selectSort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		int minIndex = 0;
		for (int i = 0; i < length(arr) - 1; i++)
		{
			minIndex = i;
			for (int j = i + 1; j < length(arr); j++)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}
			if (minIndex != i)
			{
				swap(arr, i, minIndex);
			}
		}
	}

};

#endif // SelectSort_h__
