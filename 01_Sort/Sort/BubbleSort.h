#ifndef BubbleSort_h__
#define BubbleSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	ð�������㷨.  </summary>
///
/// ͨ��������Ԫ�صıȽϺͽ�������С������������ǰ��
/// ����������ˮ��������һ��
/// ʱ�临�Ӷȣ�O(n^2)
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

