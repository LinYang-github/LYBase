#ifndef QuickSort_h__
#define QuickSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	快速排序算法.  </summary>
///
/// 思想来源于冒泡排序
/// 比较和交换小数和大数，不仅把小数冒泡到上面同时也把大数沉到下面
/// 快速排序=冒泡+二分+递归分治
/// 不稳定的，时间平均复杂度：O(nlgn)
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class QuickSort
{
public:
	QuickSort(void);
	~QuickSort(void);
public:
	template<typename T>
	static int partition(T& arr, int left, int right)
	{
		int pivotKey = arr[left];
		int pivotPointer = left;

		while (left < right)
		{
			while (left < right && arr[right] >= pivotKey)
			{
				right--;
			}
			while (left < right && arr[left] <= pivotKey)
			{
				left++;
			}
			swap(arr, left, right);
		}
		swap(arr, pivotPointer, left);
		return left;
	}

	template<typename T>
	static int partition2(T& arr, int left, int right)
	{
		int pivotKey = arr[left];
		int pivotPointer = left;

		while (left < right)
		{
			while (left < right && arr[right] >= pivotKey)
			{
				right--;
			}
			arr[left] = arr[right];
			while (left < right && arr[left] <= pivotKey)
			{
				left++;
			}
			arr[right] = arr[left];
		}
		arr[left] = pivotKey;
		return left;
	}

	template<typename T>
	static void quickSort(T& arr, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		int pivotPos = partition(arr, left, right);
		quickSort(arr, left, pivotPos-1);
		quickSort(arr, pivotPos+1, right);
	}

	template<typename T>
	static void sort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		quickSort(arr, 0, length(arr)-1);
	}
};

#endif // QuickSort_h__
