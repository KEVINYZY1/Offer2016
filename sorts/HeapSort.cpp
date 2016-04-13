#include <iostream>
#include <time.h>
#include <cstdlib>
#define N 10
using namespace std;

//�������󶥶Ѻ���
void BuildMaxHeap(int * array);
//������������
void HeapSort(int * array);
//��������Ϊ�󶥶Ѻ���
void MaxHeapify(int * array, int n);
//���ضѵ����ݸ���
int HeapSize;

//int main()
//{
//	//����һ������������
//	int array[N];
//	//������������ӣ�����ÿ�β�����ͬ������� 
//	srand(time(0));
//	for (int i = 0; i < N; i++)
//	{
//		array[i] = rand() % 101;//���鸳ֵʹ�������������1-100֮��������   
//	}
//	cout << "����ǰ��" << endl;
//	for (int j = 0; j < N; j++)
//	{
//		cout << array[j] << "  ";
//	}
//	cout << endl << "�����" << endl;
//	//���ö��������Ը������������   
//	HeapSort(array);
//	for (int k = 0; k < N; k++)
//	{
//		cout << array[k] << "  ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

void HeapSort(int * array)
{
	BuildMaxHeap(array);
	for (int i = N - 1; i >= 0; i--)//�������±��0  -  N-1
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		HeapSize -= 1;
		MaxHeapify(array, 1);//�ڶ��У��Ѷ�Ԫ���±��1��ʼ
	}
}

void BuildMaxHeap(int * array)
{
	HeapSize = N;
	for (int i = N / 2; i >= 1; i--)//ע��i��ȡֵ,�ѵĸ߶ȴ�1  -  N/2
	{
		MaxHeapify(array, i);
	}
}

void MaxHeapify(int * array, int temp)
{
	int largest;//��tempΪ����������ĶѶ�
	int l = 2 * temp;//����tempΪ��������������
	int r = 2 * temp + 1;//����tempΪ����������Ҷ���

	if (l <= HeapSize && array[l - 1] > array[temp - 1])//�����ж�������Ƿ���ڣ���l<=HeapSize
	{
		largest = l;
	}
	else{
		largest = temp;
	}

	if (r <= HeapSize && array[r - 1] > array[largest - 1])//�����ж��Ҷ����Ƿ���ڣ���r<=HeapSize
	{
		largest = r;
	}

	if (largest != temp)
	{
		int t = array[temp - 1];
		array[temp - 1] = array[largest - 1];
		array[largest - 1] = t;
		MaxHeapify(array, largest);//����Ϊ�󶥶�
	}
}