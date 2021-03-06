#include <iostream>
#include <vector>
#include <time.h>	// 随机数种子
#include <chrono>	// 统计运行时间需要

using namespace std;
using namespace chrono;



//===============伪代码描述===================
//简单桶排序,不需要维护链表:
/*  1.每个桶初始化为指向NULL的链表
*	2.每当碰到一个学生,根据他的grade把他的信息插到链表的后面
*	3.输出所有不是空的桶
*	4.排序完成
*/
/*
*****************
void Bucket_Sort(T arr[], int len)
{
	CountBucket[] = new T[len];	//初始化桶
	while (读取一个学生的grade) {
		将该生的信息插入到CountBucket[grade];
	}
	for (int i = 0; i < M; i++)		//M是捅的数量
	{
		if (桶不是空)
			输出整个链表;
	}
}
*********************
*/


/*******************************************************************

//Wikey vertion 
//看不懂
//设定结点
struct ListNode {
	explicit ListNode(int i = 0) :mData(i), mNext(NULL) {}
	ListNode* mNext;
	int mData;
};
//向链表中插入结点 --> ?
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

//桶排序
/*======================================================
*
*程序说明：	C++桶排序算法
*运行平台：	Linux/Windows
*创建日期：	20190831
*作    者：	LiuHuan
*
*======================================================*/


//__________________________________________太难了!!!!!!!!!!!!____________________________________________


#define RUN_SORT(FUNC)	\
{	\
	auto tStart = system_clock::now();	\
	FUNC;	\
	auto tEnd = system_clock::now();	\
	auto tCost = duration_cast<nanoseconds>(tEnd - tStart);	\
	cout << "耗时: " << tCost.count() << " ns(纳秒).\n" << endl;	\
}

template<typename T>
void mySwap(T& a, T& b)
{
	a ^= b ^= a ^= b;
}

void InsertSort(vector<int>& vec)
{
	int len = vec.size();
	// 从下标为1的元素选择合适位置，因为下标为0的元素只有一个，默认有序
	for (int i = 1; i < len; i++)
	{
		int temp = vec[i];
		int j = i;
		// 从已排序的右边开始比较，找到比其小的数
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
		for (int j = i + 1; j < len; j++)	// 待排序区
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
	// 确定元素的最值
	for (auto it : vec)
	{
		if (it > max)	max = it;
		if (it < min)	min = it;
	}

	// 桶数: (max - min) / array.length的结果为数组大小的倍数（最大倍数），以倍数作为桶数
	// 【注意1】当序列大小vec.size()比较小，而元素值很大且分散(max - min比较大)，会造成很多“空桶”, 增加系统开销
	// 比如(0, 13, 19892)——> 很多“空桶”
	// 【注意2】：当待排序序列元素个数很多(vec.size()很大), 但是每个元素却又很小时, 只有一个桶, 这种情况比较耗时
	int bucketNum = (max - min) / vec.size() + 1;

	// 初始化桶, 可以用数组实现, 也可以用vector实现, 这里选取vector实现, 原因下述
	// int** buckets = new int*[bucketNum];	// 数组实现桶，需要二维数组
	vector<vector<int> > vecBucket;	// vector容器实现桶，类似二维数组
	// 桶初始化
	for (int i = 0; i < bucketNum; i++)
	{
		vector<int> vecTmp;
		vecBucket.push_back(vecTmp);
	}
	// 用数组实现桶初始化
	// for (int i = 0; i < bucketNum; i++)
	// {
	// 	buckets[i] = new int[vec.size()];		// 每个桶最多存放vec.size()个元素
	// }

	// 将待排序元素挨个放入对应桶中
	for (int i = 0; i < (int)vec.size(); i++)
	{
		// 和上面【注意】结合看，如果只有1个桶, 要分开处理
		if (bucketNum == 1)
		{
			vecBucket[0].push_back(vec[i]);
		}
		else
		{
			int bucketIndex = (vec[i] - min) / bucketNum;	// 确定存放在哪个桶			
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			vecBucket[bucketIndex].push_back(vec[i]);	// 这是用vector实现桶的好处, 直接“接”在后面自动扩容即可, 数组实现还需代码处理
		}
	}

	vec.clear();
	// 遍历“桶组合”, 给每个桶中元素排序
	// 每个桶元素有序了, 则整个“桶组合”从“编号小”的桶遍历到“编号大”的桶，则为整体有序序列
	for (vector<vector<int> >::iterator iter = vecBucket.begin(); iter != vecBucket.end(); iter++)
	{
		vector<int> vecTmp = *iter;		// *iter也是一个vector, 内部存放了该桶内元素
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// 对每个桶进行排序, 这里借用选择排序
		// 当n较小时，对稳定性不作要求时宜用选择排序
		SelectSort(vecTmp);
		// InsertSort(vecTmp);	// 有兴趣读者也可以试用插入排序看看耗时
		for (auto it : vecTmp)
		{
			// 每个桶内元素有序后, 重新给vec赋值, 此时vec有序。
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
		if (cnt++ % 10 == 0)	// 每十个换行输出
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
		for (int i = 0; i < 10; i++)		// 注意这里元素值和序列大小的选取对排序性能有影响，建议读者自己改变参数调试, 研究一番
		{
			vec.push_back(rand() % 100);
		}
		cout << "************第[ " << cnt << " ]次桶排序前序列：\n";
		printVec(vec);

		RUN_SORT(BucketSort(vec))

			cout << "桶排序后序列：\n";
		printVec(vec);

	} while (cnt++ < 5);

	//system("pause");  // linux关闭，VS打开
	return 0;
}

