#pragma once
//Radix Sort
//Least Significant Digit First - LSD

#include<iostream>

using namespace std;

void RadixSort(int arr[], int len);			//Radix Sort
void CountSort_inRadix(int arr[], int len,int exp);	//equal to counting sort,realize with array

void RadixSort(int arr[], int len)			//Radix Sort
{
	//Get max number
	int Max = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > Max){
			Max = arr[i];
		}
	}
	//Count exp
	for (int exp = 1; Max/exp > 0; exp*=10) 
	{
		CountSort_inRadix(arr, len, exp);
	}
}

void CountSort_inRadix(int arr[], int len,int exp)	//equal to counting sort,realize with array
{
	const int Radix = 10;		//Base on 10
	int* output = new int[len];
	int Buckets[Radix] = { 0 };
	/*Store how many time element has occurred*/
	for (int i = 0; i < len; i++) {
		Buckets[arr[i] / exp % Radix]++;
	}
	/* Change Buckets[i], in order to set elements into output in right order */
	for (int i = 1; i < Radix; i++) {
		Buckets[i] += Buckets[i - 1];
	}
	/* */
	for (int i = len - 1; i >= 0; i--) {
		output[ Buckets[(arr[i] / exp) % Radix] - 1 ] = arr[i];
		Buckets[(arr[i] / exp) % Radix]--;
	}
	/* write all the elements into arr */
	for (int i = 0; i < len; i++) {
		arr[i] = output[i];
	}//arr sorted
	delete[] output;
}

