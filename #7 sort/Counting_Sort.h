#pragma once
#include<iostream>
#include <cassert>

using namespace std;

void CountSort(int* a, size_t size)
{
	assert(a);
	size_t max = a[0];
	size_t min = a[0];
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i] > (int)max)
		{
			max = a[i];
		}
		if (a[i] < (int)min)
		{
			min = a[i];
		}
	}
	size_t range = max - min + 1;   
	size_t* count_arr = new size_t[range];
	memset(count_arr, 0, sizeof(size_t) * range);  //initialize to 0
	//count how many times
	for (size_t i = 0; i < size; ++i)   
	{
		count_arr[a[i] - min]++;
	}
	//Write to original array
	size_t index = 0;
	for (size_t i = 0; i < range; ++i)  //read from count_array
	{
		while (count_arr[i]--)
		{
			a[index++] = i + min;
		}
	}
	delete[] count_arr;
}