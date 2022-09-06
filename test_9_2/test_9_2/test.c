#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// O(2^N)
// 斐波那契数列的递归写法完全是一个实际没用的算法，因为太慢了
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


//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	// 跟[0, n]异或
//	for (int i = 0; i <= numsSize; i++)
//	{
//		x ^= i;
//	}
//
//	//在跟数组中值异或
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


//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
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
	// 前n-k个数逆置
	Reverse(nums, 0, numsSize - k - 1);
	// 后k个逆置
	Reverse(nums, numsSize - k, numsSize - 1);
	// 整体逆置
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