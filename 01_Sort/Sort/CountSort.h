#ifndef CountSort_h__
#define CountSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	���������㷨.  </summary>
///
/// ��Ҫ�Ƚ϶�ĸ����ռ�
/// �ô����������Ϊ����������±꣬ͳ��ÿ�����ֵĸ���
/// 
/// <remarks>	liny, 2018/7/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class CountSort
{
public:
	CountSort(void);
	~CountSort(void);

	template<typename T>
	static void countSort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		int max = maxCount(arr);

		std::vector<int> count;

		for (int i = 0;i < length(arr); ++i)
		{
			count[arr[i]]++;
		}

		int k = 0;
		for (int i = 0; i <= max; i++)
		{
			for (int j = 0;j < count[i];j++)
			{
				arr[k++] = i;
			}
		}
	}

	template<typename T>
	static int maxCount(T& arr)
	{
		int max = -1;
		for (int i = 0;i < length(arr); i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}
};


#endif // CountSort_h__
