/*
 * ��Ŀ����������˳��ʹ����λ��ż��ǰ��
 * ����һ���������飬ʵ��һ�����������������������ֵ�˳��
 * ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
 * ����֤������������ż����ż��֮������λ�ò���
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty())
			return;

		int size = array.size();
		vector<int> odd, even;
		for (int i = 0; i < size; ++i)
		{
			if (array[i] & 0x1 == 1)
				odd.push_back(array[i]);
			else
				even.push_back(array[i]);
		}//for
		array.clear();
		for (size_t i = 0; i < odd.size(); ++i)
			array.push_back(odd[i]);
		for (size_t j = 0; j < even.size(); ++j)
			array.push_back(even[j]);
	}

};
//
//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5 };
//
//	Solution s;
//	s.reOrderArray(v);
//
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}