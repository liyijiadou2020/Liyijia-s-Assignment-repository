#include <iostream>
#include <vector>
#include <time.h>	// ���������
#include <chrono>	// ͳ������ʱ����Ҫ

using namespace std;
using namespace chrono;



//===============α��������===================
//��Ͱ����,����Ҫά������:
/*  1.ÿ��Ͱ��ʼ��Ϊָ��NULL������
*	2.ÿ������һ��ѧ��,��������grade��������Ϣ�嵽����ĺ���
*	3.������в��ǿյ�Ͱ
*	4.�������
*/
/*
*****************
void Bucket_Sort(T arr[], int len)
{
	CountBucket[] = new T[len];	//��ʼ��Ͱ
	while (��ȡһ��ѧ����grade) {
		����������Ϣ���뵽CountBucket[grade];
	}
	for (int i = 0; i < M; i++)		//M��ͱ������
	{
		if (Ͱ���ǿ�)
			�����������;
	}
}
*********************
*/


/*******************************************************************

//Wikey vertion 
//������
//�趨���
struct ListNode {
	explicit ListNode(int i = 0) :mData(i), mNext(NULL) {}
	ListNode* mNext;
	int mData;
};
//�������в����� --> ?
ListNode* insert(ListNode* head, int val) {
	ListNode dummyNode;
	ListNode* newNode = new ListNode(val);
	ListNode* pre, * curr;
	dummyNode.mNext = head;
	pre = &dummyNode;
	curr = head;
	while (NULL != curr && curr->mData <= val) {
		pre = curr;
		curr = curr->mNext;
	}
	newNode->mNext = curr;
	pre->mNext = newNode;
	return dummyNode.mNext;
}


ListNode* Merge(ListNode* head1, ListNode* head2) {
	ListNode dummyNode;
	ListNode* dummy = &dummyNode;
	while (NULL != head1 && NULL != head2) {
		if (head1->mData <= head2->mData) {
			dummy->mNext = head1;
			head1 = head1->mNext;
		}
		else {
			dummy->mNext = head2;
			head2 = head2->mNext;
		}
		dummy = dummy->mNext;
	}
	if (NULL != head1) dummy->mNext = head1;
	if (NULL != head2) dummy->mNext = head2;

	return dummyNode.mNext;
}

void BucketSort(int n, int arr[]) {
	vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
	for (int i = 0; i < n; ++i) {
		int index = arr[i] / BUCKET_NUM;
		ListNode* head = buckets.at(index);
		buckets.at(index) = insert(head, arr[i]);
	}
	ListNode* head = buckets.at(0);
	for (int i = 1; i < BUCKET_NUM; ++i) {
		head = Merge(head, buckets.at(i));
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = head->mData;
		head = head->mNext;
	}
}
*/
//*******************************************************************

//Ͱ����
/*======================================================
*
*����˵����	C++Ͱ�����㷨
*����ƽ̨��	Linux/Windows
*�������ڣ�	20190831
*��    �ߣ�	LiuHuan
*
*======================================================*/


//__________________________________________̫����!!!!!!!!!!!!____________________________________________


#define RUN_SORT(FUNC)	\
{	\
	auto tStart = system_clock::now();	\
	FUNC;	\
	auto tEnd = system_clock::now();	\
	auto tCost = duration_cast<nanoseconds>(tEnd - tStart);	\
	cout << "��ʱ: " << tCost.count() << " ns(����).\n" << endl;	\
}

template<typename T>
void mySwap(T& a, T& b)
{
	a ^= b ^= a ^= b;
}

void InsertSort(vector<int>& vec)
{
	int len = vec.size();
	// ���±�Ϊ1��Ԫ��ѡ�����λ�ã���Ϊ�±�Ϊ0��Ԫ��ֻ��һ����Ĭ������
	for (int i = 1; i < len; i++)
	{
		int temp = vec[i];
		int j = i;
		// ����������ұ߿�ʼ�Ƚϣ��ҵ�����С����
		while (j > 0 && temp < vec[j - 1])
		{
			vec[j] = vec[j - 1];
			j--;
		}

		if (i != j)
		{
			vec[j] = temp;
		}
	}
}

void SelectSort(vector<int>& vec)
{
	int minPos = -1;
	int len = vec.size();
	for (int i = 0; i < len - 1; i++)
	{
		minPos = i;
		for (int j = i + 1; j < len; j++)	// ��������
		{
			if (vec[minPos] > vec[j])
			{
				minPos = j;
			}
		}

		if (minPos != i)
		{
			mySwap(vec[minPos], vec[i]);
		}
	}
}

void BucketSort(vector<int>& vec)
{
	int max = vec[0];
	int min = vec[0];
	// ȷ��Ԫ�ص���ֵ
	for (auto it : vec)
	{
		if (it > max)	max = it;
		if (it < min)	min = it;
	}

	// Ͱ��: (max - min) / array.length�Ľ��Ϊ�����С�ı���������������Ա�����ΪͰ��
	// ��ע��1�������д�Сvec.size()�Ƚ�С����Ԫ��ֵ�ܴ��ҷ�ɢ(max - min�Ƚϴ�)������ɺܶࡰ��Ͱ��, ����ϵͳ����
	// ����(0, 13, 19892)����> �ܶࡰ��Ͱ��
	// ��ע��2����������������Ԫ�ظ����ܶ�(vec.size()�ܴ�), ����ÿ��Ԫ��ȴ�ֺ�Сʱ, ֻ��һ��Ͱ, ��������ȽϺ�ʱ
	int bucketNum = (max - min) / vec.size() + 1;

	// ��ʼ��Ͱ, ����������ʵ��, Ҳ������vectorʵ��, ����ѡȡvectorʵ��, ԭ������
	// int** buckets = new int*[bucketNum];	// ����ʵ��Ͱ����Ҫ��ά����
	vector<vector<int> > vecBucket;	// vector����ʵ��Ͱ�����ƶ�ά����
	// Ͱ��ʼ��
	for (int i = 0; i < bucketNum; i++)
	{
		vector<int> vecTmp;
		vecBucket.push_back(vecTmp);
	}
	// ������ʵ��Ͱ��ʼ��
	// for (int i = 0; i < bucketNum; i++)
	// {
	// 	buckets[i] = new int[vec.size()];		// ÿ��Ͱ�����vec.size()��Ԫ��
	// }

	// ��������Ԫ�ذ��������ӦͰ��
	for (int i = 0; i < (int)vec.size(); i++)
	{
		// �����桾ע�⡿��Ͽ������ֻ��1��Ͱ, Ҫ�ֿ�����
		if (bucketNum == 1)
		{
			vecBucket[0].push_back(vec[i]);
		}
		else
		{
			int bucketIndex = (vec[i] - min) / bucketNum;	// ȷ��������ĸ�Ͱ			
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			vecBucket[bucketIndex].push_back(vec[i]);	// ������vectorʵ��Ͱ�ĺô�, ֱ�ӡ��ӡ��ں����Զ����ݼ���, ����ʵ�ֻ�����봦��
		}
	}

	vec.clear();
	// ������Ͱ��ϡ�, ��ÿ��Ͱ��Ԫ������
	// ÿ��ͰԪ��������, ��������Ͱ��ϡ��ӡ����С����Ͱ����������Ŵ󡱵�Ͱ����Ϊ������������
	for (vector<vector<int> >::iterator iter = vecBucket.begin(); iter != vecBucket.end(); iter++)
	{
		vector<int> vecTmp = *iter;		// *iterҲ��һ��vector, �ڲ�����˸�Ͱ��Ԫ��
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// ��ÿ��Ͱ��������, �������ѡ������
		// ��n��Сʱ�����ȶ��Բ���Ҫ��ʱ����ѡ������
		SelectSort(vecTmp);
		// InsertSort(vecTmp);	// ����Ȥ����Ҳ�������ò������򿴿���ʱ
		for (auto it : vecTmp)
		{
			// ÿ��Ͱ��Ԫ�������, ���¸�vec��ֵ, ��ʱvec����
			vec.push_back(it);
		}
	}
}

template<typename T>
void printVec(const vector<T>& vec)
{
	int cnt = 1;
	for (auto it : vec)
	{
		cout << it << "\t";
		if (cnt++ % 10 == 0)	// ÿʮ���������
		{
			cout << "\n";
		}
	}
	cout << "\n\n";
}

int main()
{
	srand((unsigned int)time(NULL));
	int cnt = 1;
	do
	{
		vector<int> vec;
		for (int i = 0; i < 10; i++)		// ע������Ԫ��ֵ�����д�С��ѡȡ������������Ӱ�죬��������Լ��ı��������, �о�һ��
		{
			vec.push_back(rand() % 100);
		}
		cout << "************��[ " << cnt << " ]��Ͱ����ǰ���У�\n";
		printVec(vec);

		RUN_SORT(BucketSort(vec))

			cout << "Ͱ��������У�\n";
		printVec(vec);

	} while (cnt++ < 5);

	//system("pause");  // linux�رգ�VS��
	return 0;
}

