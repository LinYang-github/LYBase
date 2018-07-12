#ifndef STLSort_h__
#define STLSort_h__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	STL sort�㷨.  </summary>
///
/// ȫ����
/// sort				�Ը�����������Ԫ�ؽ�������					����ġ����������㷨��������ڲ������㷨
/// stable_sort			�Ը�����������Ԫ�ؽ����ȶ�����				�鲢����
/// �ֲ�����
/// partial_sort		�Ը�����������Ԫ�ز�������					������
/// partial_sort_copy	�Ը������临�Ʋ�����						copy��partial_sort�����
/// nth_element			�ҳ����������ĳ��λ�ö�Ӧ��Ԫ��
/// is_sorted			�ж�һ�������Ƿ��Ѿ��ź���
/// �����㷨��
/// partition			ʹ�÷���ĳ��������Ԫ�ط���ǰ��
/// stable_partition	����ȶ���ʹ�÷���ĳ��������Ԫ�ط���ǰ��
/// 
/// �º����б�
/// equal_to			���
/// not_equal_to		�����
/// less				С��
/// greater				����
/// less_equal			С�ڵ���
/// greater_equal		���ڵ���
/// 
/// ����stable�ĺ����ɱ�֤���Ԫ�ص�ԭ����Դ���������󱣳ֲ���
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
