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
	//1.Ĭ�ϴ�С��������;
	std::sort(arr, arr+5);
	//2.���Լ������cmp����;
	std::sort(arr, arr+5, cmp);
	//3.��STL�ṩ�ķº���less;
	std::sort(arr, arr+5, std::less<int>());
	//4.��STL�ṩ�ķº���greater;
	std::sort(arr, arr+5, std::greater<int>());

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}
