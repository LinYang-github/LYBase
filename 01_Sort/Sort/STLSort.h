#ifndef STLSort_h__
#define STLSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	STL sort算法.  </summary>
///
/// 全排序：
/// sort				对给定区间所有元素进行排序					成熟的“快速排序算法”，结合内插排序算法
/// stable_sort			对给定区间所有元素进行稳定排序				归并排序
/// 局部排序：
/// partial_sort		对给定区间所有元素部分排序					堆排序
/// partial_sort_copy	对给定区间复制并排序						copy和partial_sort的组合
/// nth_element			找出给定区间的某个位置对应的元素
/// is_sorted			判断一个区间是否已经排好序
/// 分类算法：
/// partition			使得符合某个条件的元素放在前面
/// stable_partition	相对稳定的使得符合某个条件的元素放在前面
/// 
/// 仿函数列表：
/// equal_to			相等
/// not_equal_to		不相等
/// less				小于
/// greater				大于
/// less_equal			小于等于
/// greater_equal		大于等于
/// 
/// 带有stable的函数可保证相等元素的原本相对次序在排序后保持不变
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class STLSort
{
public:
	STLSort(void);
	~STLSort(void);

public:
	static bool cmp(int x, int y); 

	static void testSTLSort();
};


#endif // STLSort_h__
