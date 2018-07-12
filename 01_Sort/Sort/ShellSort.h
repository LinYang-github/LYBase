#ifndef ShellSort_h__
#define ShellSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	ϣ�������㷨.  </summary>
///
/// �ǲ��������һ�ָ�Ч�ʵ�ʵ�֣�Ҳ����С��������
/// �Ƚ��������ż�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ�������
/// �����������еļ�¼��������ʱ�ٶ�ȫ���¼����һ��ֱ�Ӳ�������
/// ����һ��һ����ǰ�ƣ�������Ծʽ�ģ����һ������ʱ������������
/// ʱ�临�Ӷȣ�O(n^1.3)
/// 
/// <remarks>	LinY, 2017/4/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class ShellSort
{
public:
	ShellSort(void);
	~ShellSort(void);

	template<typename T>
	static void shellInsert(T& arr, int d)
	{
		for (int i = d; i < length(arr); i++)
		{
			int j = i - d;
			int temp = arr[i];//��¼Ҫ���������;
			while(j >= 0 && arr[j] > temp)
			{
				//�Ӻ���ǰ���ҵ�����С������λ��;
				arr[j + d] = arr[j];//���Ų��;
				j -= d;
			}

			if (j != i - d)//���ڱ���С����;
			{
				arr[j+d] = temp;
			}
		}
	}

	template<typename T>
	static void shellSort(T& arr)
	{
		if (arr == NULL || length(arr) == 0)
		{
			return;
		}
		int d = length(arr)/2;
		while(d >= 1)
		{
			shellInsert(arr, d);
			d /=2;
		}
	}
};


#endif // ShellSort_h__
