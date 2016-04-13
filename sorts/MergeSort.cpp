/*
����һ��int���飬���дһ���鲢�����㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;
void MergeSort(int *A, int left, int right);
void Merge(int *A, int left, int mid, int right);

int* MergeSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;

	MergeSort(A, 0, n - 1);
	return A;
}

void MergeSort(int *A, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(A, left, mid);
	MergeSort(A, mid + 1, right);

	Merge(A, left, mid, right);
}

/*��������left~mid��mid+1~right���������кϲ�*/
void Merge(int *A, int left, int mid, int right)
{
	int *tmp = new int[right - left + 1];
	/*�ϲ�������Ԫ�ص�tmp��ʱ����*/
	int lhs = left, rhs = mid + 1, k = 0;
	while (lhs <= mid && rhs <= right)
	{
		if (A[lhs] <= A[rhs])
			tmp[k++] = A[lhs++];
		else
			tmp[k++] = A[rhs++];
	}//while

	/*ֱ�ӿ���ʣ��Ԫ��*/
	while (lhs <= mid)
	{
		tmp[k++] = A[lhs++];
	}//while

	while (rhs <= right)
	{
		tmp[k++] = A[rhs++];
	}//while

	/*������ʱ�������ݵ�ԭ����*/
	for (int i = left; i <= right; ++i)
	{
		A[i] = tmp[i - left];
	}//for

	delete[]tmp;
}


//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	MergeSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}