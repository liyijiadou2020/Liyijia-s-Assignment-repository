#include<iostream>
#include"Sort.h"
#include"test sort.h"
using namespace std;


static int arr[] = { 8,6,16,4,7,14,18,2,5,9,15,17,20 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )



int main2() {

	int length = TBL_SIZE(arr);

	//Merge(arr, length);
	cout << "After Merge Sort : " << '\n';
	print(arr, length);


	return 0;
}