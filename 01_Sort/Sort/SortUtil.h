#ifndef SortUtil_h__
#define SortUtil_h__

class SortUtil
{
public:
	SortUtil(void);
	~SortUtil(void);

public:

	template<typename T>
	static int length(T& x)
	{
		int s1 = sizeof(x);
		int s2 = sizeof(x[0]);
		int result = s1 / s2;
		return result;
	}


	template<typename T>
	static void swap(T& arr, int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
};


#endif // SortUtil_h__
