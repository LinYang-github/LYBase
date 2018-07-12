#ifndef SelectSort_h__
#define SelectSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	ѡ�������㷨.  </summary>
///
/// ��ð���������ƣ���һ����������С��Ԫ�ط�����ǰ��
/// �����ڵıȽϺͽ���������ͨ���������ѡ��
/// ȷ������С����ǰ���²Ž��н������������˽����Ĵ���
/// ʱ�临�Ӷȣ�O(n^2)
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
