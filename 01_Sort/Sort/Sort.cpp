// Sort.cpp : ¶¨Òå¿ØÖÆÌ¨Ó¦ÓÃ³ÌÐòµÄÈë¿Úµã¡£
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>

#include "BubbleSort.h"
#include "SelectSort.h"
#include "InsertSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "BucketSort.h"
#include "STLSort.h"

template<typename T>
static int length(T& x)
{
	int s1 = sizeof(x);
	int s2 = sizeof(x[0]);
	int result = s1 / s2;
	return result;
}

template<typename T>
static void swap(T& i, T& j)
{
	T temp = i;
	i = j;
	j = temp;
}

template<typename T>
static void swap(T& arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//testÃ°ÅÝÅÅÐò;
	int arrBubble[] = {5, 3, 8, 6, 4};
	BubbleSort::bubbleSort(arrBubble);
	std::cout << "²âÊÔÃ°ÅÝÅÅÐò£º";
	for (int i = 0; i < length(arrBubble); i++)
	{
		std::cout << arrBubble[i] << std::setw(2);
	}
	std::cout << std::endl;

	//testÑ¡ÔñÅÅÐò;
	int arrSelect[] = {5, 3, 8, 6, 4};
	SelectSort::selectSort(arrSelect);
	std::cout << "²âÊÔÑ¡ÔñÅÅÐò£º";
	for (int i = 0; i < length(arrSelect); i++)
	{
		std::cout << arrSelect[i] << std::setw(2);
	}
	std::cout << std::endl;

	//test²åÈëÅÅÐò;
	int arrInsert[] = {5, 3, 8, 6, 4};
	InsertSort::insertSort(arrInsert);
	std::cout << "²âÊÔ²åÈëÅÅÐò£º";
	for (int i = 0; i < length(arrInsert); i++)
	{
		std::cout << arrInsert[i] << std::setw(2);
	}
	std::cout << std::endl;

	//test¿ìËÙÅÅÐò;
	int arrQuick[] = {5, 3, 8, 6, 4};
	QuickSort::sort(arrQuick);
	std::cout << "²âÊÔ¿ìËÙÅÅÐò£º";
	for (int i = 0; i < length(arrQuick); i++)
	{
		std::cout << arrQuick[i] << std::setw(2);
	}
	std::cout << std::endl;

	//test¶ÑÅÅÐò;
	int arrHeap[] = {5, 3, 8, 6, 4};
	HeapSort::heapSort(arrHeap);
	std::cout << "²âÊÔ¶ÑÅÅÐò£º";
	for (int i = 0; i < length(arrHeap); i++)
	{
		std::cout << arrHeap[i] << std::setw(2);
	}
	std::cout << std::endl;

	//testÏ£¶ûÅÅÐò;
	int arrShell[] = {5, 3, 8, 6, 4};
	ShellSort::shellSort(arrShell);
	std::cout << "²âÊÔÏ£¶ûÅÅÐò£º";
	for (int i = 0; i < length(arrShell); i++)
	{
		std::cout << arrShell[i] << std::setw(2);
	}
	std::cout << std::endl;

	//test¹é²¢ÅÅÐò;
	int arrMerge[] = {5, 3, 8, 6, 4};
	MergeSort::mergeSort(arrMerge);
	std::cout << "²âÊÔ¹é²¢ÅÅÐò£º";
	for (int i = 0; i < length(arrMerge); i++)
	{
		std::cout << arrMerge[i] << std::setw(2);
	}
	std::cout << std::endl;
	
	//testSTL
	STLSort::testSTLSort();

	system("pause");
	return 0;
}

