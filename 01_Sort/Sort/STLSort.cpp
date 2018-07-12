#include "StdAfx.h"

#include <algorithm>
#include <iostream>
#include <functional>

#include "STLSort.h"


STLSort::STLSort(void)
{
}


STLSort::~STLSort(void)
{
}

bool STLSort::cmp( int x, int y )
{
	return x > y ? true : false;
}

void STLSort::testSTLSort()
{
	int arr[5] = {3, 2, 5, 8, 4};
	//1.默认从小到大排序;
	std::sort(arr, arr+5);
	//2.用自己定义的cmp函数;
	std::sort(arr, arr+5, cmp);
	//3.用STL提供的仿函数less;
	std::sort(arr, arr+5, std::less<int>());
	//4.用STL提供的仿函数greater;
	std::sort(arr, arr+5, std::greater<int>());

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}
