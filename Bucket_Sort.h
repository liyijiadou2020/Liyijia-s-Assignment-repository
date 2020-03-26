#pragma once
//Bucket Sort
#include<iostream>
#include<vector>

using namespace std;

void BucketSort(int* arr, int len);
void SelectSort(vector<int>& v);

//External interface
void BucketSort(int* arr, int len)
{
	//initialize vector
	vector<int> vec;
	for (int i = 0; i < len; i++)
	{
		vec.push_back(arr[i]);
	}
	//Find the Min and Max value
	int Max = vec[0];
	int Min = vec[0];
	for (auto it : vec)
	{
		if (it < Min)
			Min = it;
		if (it < Max)
			Max = it;
	}
	//Initialize Buckets
	int BucketNum = (Max - Min) / vec.size() + 1;
	vector<vector<int>> vecBucket;
	for (int i = 0; i < BucketNum; i++)
	{
		vector<int> vecTemp;
		vecBucket.push_back(vecTemp);
	}
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (BucketNum == 1) {		//	If there is only one bucket
			vecBucket[0].push_back(vec[i]);
		}
		else {
			int BucketIndex = (vec[i] - Min) / BucketNum;	//Locate which bucket to store
			BucketIndex = BucketIndex >= BucketNum ? BucketNum - 1 : BucketIndex;
			vecBucket[BucketIndex].push_back(vec[i]);
		}
	}

	vec.clear();
	/*
	*	Traversal all the buckets
	*	Sort each bucket
	*	After sorting each bucket, concatenate all the buckets from small number to large
	*	Sorted all the buckets
	*/
	for (vector<vector<int>>::iterator iter = vecBucket.begin(); iter != vecBucket.end(); iter++)	//Using iterator to travel
	{

		vector<int> vecTmp = *iter;	//*iter is also a vector,where storing elements in this bucket
		if (vecTmp.size() <= 0) {
			continue;
		}
		//Sort this bucket
		SelectSort(vecTmp);

		for (auto it : vecTmp)
		{
			vec.push_back(it);
			//cout << "int vec: " << it<<" ";
		}
	}	//vec is sorted
	//Reset arr
	for (int i = 0; i < len; i++)
		arr[i] = vec[i];
}

//Used in Bucket Sort
void SelectSort(vector<int>& v)
{
	int MinPos = 1;
	int len = v.size();
	for (int i = 0; i < len - 1; i++)
	{
		MinPos = i;
		for (int j = i + 1; j < len; j++)
		{
			if (v[MinPos] > v[j])
				MinPos = j;
		}
		if (MinPos != i)
			swap(v[MinPos], v[i]);
	}
}