#ifndef MergeSort_h__
#define MergeSort_h__

#include <vector>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	�鲢�����㷨.  </summary>
///
/// ʹ�õݹ���ε�˼��
/// �ȵݹ黮�������⣬Ȼ��ϲ����
/// �ռ临�Ӷȣ�O(n)
/// ʱ�临�Ӷȣ�O(nlogn)
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class MergeSort
{
public:
	MergeSort(void);
	~MergeSort(void);

public:
	template<typename T>
	static void mergeSort(T& arr)
	{
		mSort(arr, 0, length(arr)-1);
	}

	template<typename T>
	static void mSort(T& arr, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		int mid = (left + right)/2;

		mSort(arr, left, mid);
		mSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}

	template<typename T>
	static void merge(T& arr, const int &left, const int &mid, const int &right)
	{
		std::vector<int> temp;
		int i = left;
		int j = mid + 1;
		while (i <= mid && j <= right)
		{
			if (arr[i] <= arr[j])
			{
				temp.push_back(arr[i++]);
			}
			else
			{
				temp.push_back(arr[j++]);
			}
		}

		while (i <= mid)
		{
			temp.push_back(arr[i++]);
		}

		for (size_t p = 0; p < temp.size(); p++)
		{
			arr[left+p] = temp[p];
		}
	}
};


#endif // MergeSort_h__
