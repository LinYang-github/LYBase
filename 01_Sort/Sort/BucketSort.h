#ifndef BucketSort_h__
#define BucketSort_h__

#include <list>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Ͱ�����㷨.  </summary>
///
/// ���ú�����ӳ���ϵ�������˼������еıȽϹ���
/// Ͱ�����f(k)ֵ���������=�����л��֡�ϣ�������е������С��鲢�����е�������
/// �Ѵ������ݷָ���˻�����������ݿ飨Ͱ����Ȼ��ֻ���Ͱ�е������������Ƚ��ıȽ����򼴿�
/// 
/// ѭ������ÿ���ؼ��ֵ�Ͱӳ�亯����ʱ�临�Ӷ�O(N)
/// �����Ƚ��������㷨��ÿ��Ͱ�ڵ��������ݽ�������ʱ�临�ӶȦ�O(Ni*logNi)��NiΪ��i��Ͱ��������
/// 
/// ����������
/// ӳ�亯��f(k)�ܹ���N������ƽ���ķ��䵽M��Ͱ�У�����ÿ��Ͱ����[N/M]��������
/// ����������Ͱ������
/// 
/// <remarks>	liny, 2018/7/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class BucketSort
{
public:
	BucketSort(void);
	~BucketSort(void);

	template<typename T>
	static void bucketSort(T& arr)
	{
		if (arr == NULL && length(arr) == 0)
		{
			return;
		}
		int bucketNums = 10;
		std::list<std::list<int>> buckets;

		for (int i = 0;i < 10; i++)
		{
			std::list<int> newBucket;
			buckets.push_back(newBucket);
		}

		for (int i = 0; i < length(arr); i++)
		{
			buckets[f(arr[i])].push_back(arr[i]);
		}

		//��ÿ��Ͱ��������
		for (int i = 0; i < buckets.size();i++)
		{
			if (buckets[i])
			{
				Collections.sort(buckets[i]);//��ÿ��Ͱ���п���
			}
		}
		//��ԭ�ź��������
		int k = 0;
		for (size_t i = 0; i < buckets.size(); ++i)
		{
			for (size_t j = 0; j < buckets[i].size(); ++j)
			{
				arr[k++] = buckets[i][j];
			}
		}
	}

	static int f(int x)
	{
		return x / 10;
	}
};


#endif // BucketSort_h__
