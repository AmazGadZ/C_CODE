#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//���趼������������������Ƿ�����

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
//ʱ�临�Ӷ��Ƕ��٣� O(N^2)
//ʲô�������� ���� 1+2+3+...+n-1
//ʲô�������ã� ˳������ O(N)
void InsertSort(int* a, int n)
{
	//[0, end]���� end+1λ�õ�ֵ�����ȥ����[0, end+1]����
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}	
}

void TestInsertSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//ֱ�Ӳ�������Ļ����ϵ��Ż�
//1. �Ƚ���Ԥ����������ӽ�����
//2. ֱ�Ӳ�������
//ʱ�临�Ӷ�:O(logN*N) ���� O(log3N*N)
//ƽ����ʱ�临�Ӷ���O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap = gap / 2;// logN
		gap = gap / 3 + 1;//log3N ����Ϊ�׵Ķ���
		//gap > 1ʱ����Ԥ���� �ӽ�����
		//gap ==1ʱ����ֱ�Ӳ������� ����

		//gap�ܴ�ʱ������Ԥ����ʱ�临�Ӷ�O(N)
		//gap��Сʱ�������Ѿ��ܽӽ������ˣ���ʱ���Ҳ��O(N)

		//�Ѽ��Ϊgap�Ķ�������ͬʱ��
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}	
}

void TestShellSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ��������
	while (child < n)
	{
		//1.ѡ�����Һ����д����һ��
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child += 1;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//����ʱ�临�Ӷ�O(N*logN��
void HeapSort(int* a, int n)
{
	//����  O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//�����򣬽���ѻ���С�ѣ������
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void TestHeapSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//ֱ��ѡ������,ʱ�临�Ӷ�O(N^2)
//�ܲ��Ϊ������Ҳ��O(N^2)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		//���begin��maxi�ص�����Ҫ����һ��maxi��λ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

void TestSelectSort()
{
	int a[] = { 9,3,5,2,7,8,6,1,9,4,0 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//ʱ�临�Ӷ� O(N^2)
//������O(N)
//��ֱ�Ӳ���������ȣ�˭���ã�
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}

}

void TestBubbleSort()
{
	int a[] = { 9,3,5,2,7,8,6,1,9,4,0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//�ڿӷ�
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	//O(N)
	while (begin < end)
	{
		//�ұ���С���ŵ����
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;

		//����Ҵ�
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//��ķŵ��ұߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;
	}

	pivot = begin;
	a[pivot] = key;

	return pivot;
}

//����ָ�뷨
int PartSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int keyi = begin;
	while (begin < end)
	{
		//��С
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}

		//�Ҵ�
		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[keyi]);
	return begin;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi]
			&& ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}

		cur++;
	}

	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyIndex = PartSort3(a, left, right);

	//[left, right]
	//[left, keyIndex-1] keyIndex [keyIndext+1, right]
	//������������������������Ǿ������ˣ���������������أ� ���εݹ�
	//QuickSort(a, left, keyIndex - 1);
	//QuickSort(a, keyIndex + 1, right);

	//С����
	if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}

	if (right - (keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
	}
}

//�ݹ��ȱ�ݣ�ջ֡���̫�ջ�ռ䲻���ã����ܻ����
//�ǵݹ�
//�ݹ�ķǵݹ飺1.ֱ�Ӹ�ѭ��(��) 2.�������ݽṹջģ��ݹ����(����һ��)
void QuickSortNonR(int* a, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyIndex = PartSort1(a, left, right);
		//[left, keyIndex-1] keyIndex [keyIndex+1, right]

		if (keyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex + 1);
		}

		if (left < keyIndex - 1)
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}
	}

	StackDestroy(&st);
}

void TestQuickSort()
{
	int a[] = { 49,38,65,97,76,13,27,49 };
	//QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	QuickSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	// ���� [left, mid] [mid+1, right]������ô���ǾͿ��Թ鲢��
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	
	//������ȥ
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//ʱ�临�Ӷȶ���O(N*logN)
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;//ÿ�����ݸ���
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i, i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//�鲢�������Ұ�������ܾͲ�����
			if (begin2 >= n)
				break;

			//�鲢�������Ұ���������ˣ�����һ��
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}

			//������ȥ
			for (int j = i; j <= end2; j++)
			{
				a[j] = tmp[j];
			}
		}

		gap *= 2;
	}
	
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 10,6,7,1,3,9,4,2,11 };
	//MergeSort(a, sizeof(a) / sizeof(int));
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//�ǱȽ�����
//��������˼����ɣ����÷�Χ���о�����
//ʱ�临�Ӷȣ�O(N+range)��˵���������ڷ�Χ���е�һ��������������
//�ռ临�Ӷȣ�O(range)
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);

	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(count);
}

void TestCountSort()
{
	int a[] = { 10,6,7,1,3,9,4,2,11 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


//�ݹ�ʵ��1+2+3+...+n
int f(int n)
{
	return n <= 1 ? 1 : n + f(n - 1);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestMergeSort();
	TestCountSort();

	//printf("%d\n", f(1000));
	return 0;
}  