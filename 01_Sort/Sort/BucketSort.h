#ifndef BucketSort_h__
#define BucketSort_h__

#include <list>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	桶排序算法.  </summary>
///
/// 利用函数的映射关系，减少了几乎所有的比较工作
/// 桶排序的f(k)值计算的作用=快排中划分、希尔排序中的子序列、归并排序中的子问题
/// 把大量数据分割成了基本有序的数据块（桶），然后只需对桶中的少量数据做先进的比较排序即可
/// 
/// 循环计算每个关键字的桶映射函数，时间复杂度O(N)
/// 利用先进的排序算法对每个桶内的所有数据进行排序，时间复杂度ΣO(Ni*logNi)，Ni为第i个桶的数据量
/// 
/// 尽量做到：
/// 映射函数f(k)能够将N个数据平均的分配到M个桶中，这样每个桶就有[N/M]个数据量
/// 尽量的增大桶的数量
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

		//对每个桶进行排序
		for (int i = 0; i < buckets.size();i++)
		{
			if (buckets[i])
			{
				Collections.sort(buckets[i]);//对每个桶进行快排
			}
		}
		//还原排好序的数组
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
