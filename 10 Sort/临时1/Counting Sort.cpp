//#include"Counting Sort.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <Windows.h> 
#include <assert.h> 

using namespace std;


//wikey
void print_arr(int* arr, int n) {
	int i;
	printf("%d", arr[0]);
	for (i = 1; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}
//wikey
void counting_sort(int* ini_arr, int* sorted_arr, int n) {
	int* count_arr = (int*)malloc(sizeof(int) * 100);
	int i, j, k;
	for (k = 0; k < 100; k++)
		count_arr[k] = 0;
	for (i = 0; i < n; i++)
		count_arr[ini_arr[i]]++;
	for (k = 1; k < 100; k++)
		count_arr[k] += count_arr[k - 1];
	for (j = n; j > 0; j--)
	{
		int Jminus1 = j - 1;
		int temp = --count_arr[ini_arr[Jminus1]];

		std::cout << "--count_arr[ini_arr[Jminus1]] : " << temp<<'\n';
		sorted_arr[temp] = ini_arr[Jminus1];
	}
	free(count_arr);
}



//���������������޷������� 
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
	size_t range = max - min + 1;   //Ҫ���ٵ����鷶Χ 
	size_t* count = new size_t[range];
	memset(count, 0, sizeof(size_t) * range);  //��ʼ��Ϊ0 
	//ͳ��ÿ�������ֵĴ��� 
	for (size_t i = 0; i < size; ++i)   //��ԭ������ȡ����ԭ�������Ϊsize 
	{
		count[a[i] - min]++;
	}
	//д�ص�ԭ���� 
	size_t index = 0;
	for (size_t i = 0; i < range; ++i)  //�ӿ��ٵ������ж�ȡ�����ٵ������СΪrange 
	{
		while (count[i]--)
		{
			a[index++] = i + min;
		}
	}
	delete[] count;
}


void Print(int* a, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void TestCountSort()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2, 4, 5, 8, 9, 5, 11, 11, 22, 12, 12 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, size);
	Print(arr, size);
}

int main5()
{
	TestCountSort();
	system("pause");
	return 0;
}
