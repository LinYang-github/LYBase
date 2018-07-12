#ifndef HeapSort_h__
#define HeapSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	堆排序算法.  </summary>
///
/// 借助堆来实现的选择排序
/// 升序排序：使用大顶堆；反之使用小顶堆。原因：堆顶元素需要交换到序列尾部
/// 大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]
/// 小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]
/// 1.可以直接用线性数组来表示一个堆，由初始的无序序列建成一个推就需要自底向上
/// 从第一个非叶元素开始挨个调整成一个堆
/// 2.如何在输出堆顶元素之后，调整剩余元素成为一个新的堆
/// 将堆顶元素和最后一个元素交换。然后比较当前堆顶元素的左右孩子节点，
/// 因为除了当前的堆顶元素，左右孩子堆均满足条件，
/// 这时需要选择当前堆顶元素与左右孩子节点的较大者（大顶堆）交换，直至叶子节点
/// 这个自堆顶至叶子的调整称为筛选
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class HeapSort
{
public:
	HeapSort(void);
	~HeapSort(void);

public:
	template<typename T>
	static void heapAdjust(T& arr, int len, int index)
	{
		int left = 2*index + 1;
		int right = 2*index + 2;
		int maxIdx = index;//maxIdx是三个数中最大数的下标
		if (left < len && arr[left] > arr[maxIdx])
		{
			maxIdx = left;
		}
		if (right < len && arr[right] > arr[maxIdx])
		{
			maxIdx = right;
		}
		if (maxIdx != index)
		{
			swap(arr[maxIdx], arr[index]);
			heapAdjust(arr, len, maxIdx);
		}
	}

	template<typename T>
	static void heapSort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		int size = length(arr);
		for (int i = size/2 - 1; i >= 0; i--)
		{
			heapAdjust(arr, size, i);
		}
		for (int i = size - 1; i >= 1; i--)
		{
			swap(arr[0], arr[i]);
			heapAdjust(arr, i, 0);
		}
	}
};


#endif // HeapSort_h__
