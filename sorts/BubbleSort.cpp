/*
����һ��int���飬���дһ��ð�������㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;
int *BubbleSort(int *A, int n)
{
	if (n <= 0)
		return A;

	/*����n-1��ð��*/
	for (int i = 0; i < n - 1; ++i)
	{
		/*ÿ��ð�����ͷ��n-i-1β�ȽϹ���*/
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (A[j] > A[j + 1])
			{
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}//if
		}//for
	}//for
	return A;
}

//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	BubbleSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}