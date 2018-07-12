#ifndef InsertSort_h__
#define InsertSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	插入排序算法.  </summary>
///
/// 不是通过交换位置而是通过比较找到合适的位置插入元素来达到排序的目的
/// 首先假设第一个数的位置是正确的
/// 过程类似打扑克时的插牌
/// 时间复杂度：O(n^2)
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class InsertSort
{
public:
	InsertSort(void);
	~InsertSort(void);
public:
	template<typename T>
	static void insertSort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		for (int i = 1; i < length(arr); i++)
		{
			int j = i;
			int target = arr[i];

			while (j > 0 && target < arr[j - 1])
			{
				arr[j] = arr[j - 1];
				j--;
			}

			arr[j] = target;
		}
	}
};


#endif // InsertSort_h__
