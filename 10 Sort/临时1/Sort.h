#pragma once

#include<iostream>
using namespace std;


template<class T>
void Shell_Sort(T arr[], int len)
{
	int h = 1;
	while (h < len / 2) {	//用来取一开始的最大增量
		h *= 2;
	}
	while (h >= 1) {			//只要增量>=1就一直循环
		for (int i = h; i < len; i++)	//分组
		{
			for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) //组内排序
			{
				std::swap(arr[j], arr[j - h]);
			}
		}
		h /= 2;	//组内完成排序后再取更小的增量
	}
}

template<class T>
void print(T* arr, int len)
{
	cout << "Length of array: " << len << '\n';
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

//No work
//DrStream version1
void Shell_sort1(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) //gap change to half each time
	{
		for (int i = 0; i < n; i++) //分组
		{
			int CurretElement = a[i];
			int j = i;
			for (; (j > 0) && (a[j] > CurretElement); j -= gap) //每隔gap个取一个元素,放一组
			{
				a[j] = a[j - gap];
			}
			a[j] = CurretElement;
		}
	}
}

//Work
//DrStream version2
void Shell_sort2(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int j = gap; j < n; j++)	//Array strats from a[gap]
		{
			if (a[j] < a[j - gap]) {	//Each element compare with elements from its group
				int temp = a[j];
				int k = j - gap;
				while (k >= 0 && a[k] > temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
		}
	}
}


template<class T>
const T& min(const T& a, const T& b)
{
	return (b < a) ? b : a;
}



//Not work
//Wikey version
template<typename T> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
void Merge_Sort(T arr[], int len) {
	T* a = arr;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		T* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}



