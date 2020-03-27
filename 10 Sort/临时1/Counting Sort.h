#pragma once
#include<iostream>
using namespace std;

void Counting_Sort(int* ini_arr, int* sorted_arr, int n)
{
	/*
	* ini_arr - ��ʼ����������
	* sorted_arr - ���ź��������
	* n - ����������Ԫ�صĸ���
	*
	*/
	int* count_arr = new int[100];
	for (int k = 0; k < 100; k++)  //��count_arr��ʼ��Ϊ{0}
	{
		count_arr[k] = 0;
	}
	for (int i = 0; i < n; i++)		//ini_arrԪ�ص�ֵ��Ϊcount_arr���±�
	{
		count_arr[ini_arr[i]]++;	//count_arr��Ԫ�ش洢����ini_arr����ͬԪ�س��ֵĴ���
	}
	for (j = n - 1; j > 0; j--)			//��ini_arr�����һ��Ԫ�ؿ�ʼ
	{
		cout << " --count_arr [ini_arr[j] ] :" << --count_arr[ini_arr[j]] << '\n';
		sorted_arr[count_arr[ini_arr[j]]] = ini_arr[j];
	}
	delete[] count_arr;
}

