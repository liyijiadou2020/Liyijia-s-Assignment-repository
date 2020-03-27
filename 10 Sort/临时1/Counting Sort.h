#pragma once
#include<iostream>
using namespace std;

void Counting_Sort(int* ini_arr, int* sorted_arr, int n)
{
	/*
	* ini_arr - 初始待排序数组
	* sorted_arr - 已排好序的数组
	* n - 待排数组中元素的个数
	*
	*/
	int* count_arr = new int[100];
	for (int k = 0; k < 100; k++)  //将count_arr初始化为{0}
	{
		count_arr[k] = 0;
	}
	for (int i = 0; i < n; i++)		//ini_arr元素的值作为count_arr的下标
	{
		count_arr[ini_arr[i]]++;	//count_arr的元素存储的是ini_arr中相同元素出现的次数
	}
	for (j = n - 1; j > 0; j--)			//从ini_arr的最后一个元素开始
	{
		cout << " --count_arr [ini_arr[j] ] :" << --count_arr[ini_arr[j]] << '\n';
		sorted_arr[count_arr[ini_arr[j]]] = ini_arr[j];
	}
	delete[] count_arr;
}

