/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.*/

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target);

int* twoSum(int* nums, int numsSize, int target) {
	int *result = (int *)malloc(sizeof(int)* 2);

	if (numsSize < 2)
		return NULL;

	for (int i = 0; i < numsSize;i++)
	for (int j = i+1; j < numsSize;j++)
		if (nums[i] + nums[j] == target)
		{
			result[0] = i;
			result[1] = j;
			return result;
		}

	return NULL;

}
int main()
{
	int nums[4] = { 2, 7, 11, 15 };
	int target = 13;
	int *res = (int *)malloc(sizeof(int)* 2);

	res = twoSum(nums, sizeof(nums)/sizeof(int), target);

	printf("index1=%d,index2=%d\n", res[0], res[1]);

	free(res);

	return 0;
}