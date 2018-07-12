#ifndef HeapSort_h__
#define HeapSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	�������㷨.  </summary>
///
/// ��������ʵ�ֵ�ѡ������
/// ��������ʹ�ô󶥶ѣ���֮ʹ��С���ѡ�ԭ�򣺶Ѷ�Ԫ����Ҫ����������β��
/// �󶥶ѣ�arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]
/// С���ѣ�arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]
/// 1.����ֱ����������������ʾһ���ѣ��ɳ�ʼ���������н���һ���ƾ���Ҫ�Ե�����
/// �ӵ�һ����ҶԪ�ؿ�ʼ����������һ����
/// 2.���������Ѷ�Ԫ��֮�󣬵���ʣ��Ԫ�س�Ϊһ���µĶ�
/// ���Ѷ�Ԫ�غ����һ��Ԫ�ؽ�����Ȼ��Ƚϵ�ǰ�Ѷ�Ԫ�ص����Һ��ӽڵ㣬
/// ��Ϊ���˵�ǰ�ĶѶ�Ԫ�أ����Һ��ӶѾ�����������
/// ��ʱ��Ҫѡ��ǰ�Ѷ�Ԫ�������Һ��ӽڵ�Ľϴ��ߣ��󶥶ѣ�������ֱ��Ҷ�ӽڵ�
/// ����ԶѶ���Ҷ�ӵĵ�����Ϊɸѡ
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
		int maxIdx = index;//maxIdx������������������±�
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
