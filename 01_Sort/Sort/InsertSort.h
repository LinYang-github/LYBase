#ifndef InsertSort_h__
#define InsertSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	���������㷨.  </summary>
///
/// ����ͨ������λ�ö���ͨ���Ƚ��ҵ����ʵ�λ�ò���Ԫ�����ﵽ�����Ŀ��
/// ���ȼ����һ������λ������ȷ��
/// �������ƴ��˿�ʱ�Ĳ���
/// ʱ�临�Ӷȣ�O(n^2)
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
