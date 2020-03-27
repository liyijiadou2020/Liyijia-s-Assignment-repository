//Genaral Interface: void X_Sort(T arr[],int len)
#include"Bucket_Sort.h"
#include"Counting_Sort.h"
#include"Radix_Sort.h"

#define ARR_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

void Print(int* a, int size);
void Test(int arr[], int len);

int main()
{
	cout << "==Test Bucket Sort:\n";
	cout << "==Test Bucket Sort:\n";

	int arr1[] = { 8,6,16,9,18,6 };
	int length = ARR_SIZE(arr1);
	BucketSort(arr1, length);
	Print(arr1, length);

	cout << "\n==Test Counting Sort: \n";
	int arr2[] = {1,2,3,4,10,9,8,7,2,3,4,6,10,8,7};
	size_t length2 = ARR_SIZE(arr2);
	CountSort(arr2, length2);
	Print(arr2, length2);
	
	cout << "\n==Test Radix Sort: \n";
	int arr3[] = { 1,2,3,4,10,9,4,2,3,100,55,23,100,23,4,2,3,1002 };
	size_t length3 = ARR_SIZE(arr3);
	RadixSort(arr3, length3);
	Print(arr3, length3);
	
	return 0;
}

void Print(int* a, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
