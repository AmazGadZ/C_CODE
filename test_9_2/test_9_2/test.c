#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// O(2^N)
// 쳲��������еĵݹ�д����ȫ��һ��ʵ��û�õ��㷨����Ϊ̫����
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return (Fib(N - 1) + Fib(N - 2));
//}
//
//int main()
//{
//	printf("%lld\n", Fib(50));
//	return 0;
//}


//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	// ��[0, n]���
//	for (int i = 0; i <= numsSize; i++)
//	{
//		x ^= i;
//	}
//
//	//�ڸ�������ֵ���
//	for (int i = 0; i < numsSize; i++)
//	{
//		x ^= nums[i];
//	}
//	return x;
//}
//
//int main()
//{
//	int arr[] = { 9,6,4,2,3,5,7,0,1 };
//	int x = 0;
//	x = missingNumber(arr, 9);
//	printf("%d\n", x);
//}


//����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
void Reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;

		left++;
		right--;

	}
}

void rotate(int* nums, int numsSize, int k)
{
	if (k >= numsSize)
	{
		k %= numsSize;
	}
	// ǰn-k��������
	Reverse(nums, 0, numsSize - k - 1);
	// ��k������
	Reverse(nums, numsSize - k, numsSize - 1);
	// ��������
	Reverse(nums, 0, numsSize - 1);
}

int main()
{
	int nums[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int k = 3;
	rotate(nums, sz, k);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", nums[i]);
	}
}