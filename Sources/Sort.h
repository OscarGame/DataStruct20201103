#pragma once

#include<stdio.h>
#include<stdlib.h>

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void Swap(T& a,T& b)
{
	T c = a;
	a = b;
	b = c;
}

void display(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ",";
	}
	cout << "\n";
}


void selectSort(int arr[] ,int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;//每一趟循环比较时，min用于存放较小元素的数组下标，这样当前批次比较完毕最终存放的就是此趟内最小的元素的下标，避免每次遇到较小元素都要进行交换。
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        //进行交换，如果min发生变化，则进行交换
        if (min != i) {
            Swap(arr[min],arr[i]);
        }

		display(arr, len);
    }
} 

void insertion_sort(int arr[], int length)
{
	int i, j;
	for (i = 1; i < length; i++) {
		int tmp = arr[i];
		for (j = i; j > 0 ; j--) 
		{
			if (tmp < arr[j - 1])
			{
				tmp = j - 1;
				//arr[j] = arr[j - 1];
			}
			//display(arr, length);
		}
		arr[j] = tmp;
		display(arr, length);
		//cout << "==========" << endl;
	}
}

 void insertionSort(int arr[],int len) {
        for (int i = 1; i < len; i++) {
            int j = i;
            while (j > 0 && arr[j] < arr[j - 1]) {
                Swap<int>(arr[j],arr[j - 1]);
                j--;
            }
        }
    }

 void insertSort2(int arr[], int len)
 {
	 for (int i = 1; i < len; i++)
	 {
		 int j = i;
		 while (j > 0 && arr[j-1] >arr[j])
		 {
			 Swap<int>(arr[j], arr[j - 1]);
			 j--;
		 }
	 }
 }



void bubbleSort(int* a, int length)
{
      bool swapp = true;
      while(swapp)
	  {
        swapp = false;

        for (int i = 0; i < length-1; i++) {
            if (a[i]>a[i+1] ){
				Swap<int>(a[i],a[i+1]);
                swapp = true;
            }
        }
		display(a, length);
	  }
}

int shellSort2(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

void shellSort(int* arr,int n)
{
	for (int gap = n*0.5; gap >0 ; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j = i;
			for(; j >= gap && arr[j - gap] > temp ; j-=gap )
				arr[j] = arr[j - gap]; 
			arr[j] = temp; 
		}
	}
}

void shellSort3(int* arr,int n)
{
	for (int gap = n*0.5; gap >0 ; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > temp)
			{
				Swap<int>(arr[j],arr[j-gap]);
				j -= gap;
			}
		}
	}
}



/*
平均时间复杂度：O(nlogn)
最佳时间复杂度：O(n)
最差时间复杂度：O(nlogn)
空间复杂度：O(n)
排序方式：In-place
稳定性：稳定

*/
template<typename T>
void merge_sort2(T arr[], int len) {
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


void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;

    int len = end - start, mid = (len >> 1) + start;

    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);

    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];

    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];

	//重新将排列好的数据重写到数组中
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

// merge_sort
void merge_sort(int arr[], const int len) 
{
	int reg[6];
    merge_sort_recursive(arr, reg, 0, len - 1);
}



/*

做调整的原则：如果排序的要求是从小到大
第一那么就构建大顶堆，这样进行一次调整那么最大的元素就在顶，最小的元素就在末尾，这个时候将最小和最大兑换，就得到一次大小兑换
第二：最大的元素从底到上慢慢浮上顶堆，再将顶堆和末尾元素交换最大的元素就到最小的位置，然后执行次大的元素
第三：父节点大于子节点，右节点 大于左节点
做的是这个结构的调整
	i
k		k+1

注意这里只是for循环中的一次循环执行的内容，
当下一次循环满足条件时再次执行，比如下面的
for(int i= len/2-1;i>=0;i--){

int arr[] = {2,4,5,7};
当i= len/2-1 = 1;
那么做出的调整是4和7进行换位置（画一下树结构图就知道） 
结果是：arr[] = {2,7,5,4};
当i = 0时，
首先做顶层的检查交互此时，7和2进行交互
arr[] = {7,2,5,4};
交互完成后还满足条件，即次顶层进行交互检查，也就是2和4 交互
arr[] = {7,4,5,2};

那么这次的调整结束了交互顶元素和末尾

这就是第一次得到的调整结果
arr[] = {2,4,5,7};

*/

/*
https://zhuanlan.zhihu.com/p/124885051
该三角节点及其子三角节点的调整

平均时间复杂度：O(nlogn)
最佳时间复杂度：O(nlogn)
最差时间复杂度：O(nlogn)
稳定性：不稳定

堆排序其实也是一种选择排序，是一种树形选择排序。
只不过直接选择排序中，为了从R[1…n]中选择最大记录，
需比较n-1次，然后从R[1…n-2]中选择最大记录需比较n-2次。
事实上这n-2次比较中有很多已经在前面的n-1次比较中已经做过，
而树形选择排序恰好利用树形的特点保存了部分前面的比较结果，
因此可以减少比较次数。对于n个关键字序列，最坏情况下每个节点需比较log2(n)次，
因此其最坏情况下时间复杂度为nlogn。
堆排序为不稳定排序，不适合记录较少的排序。

*/
//构建大顶堆，先比较两个child一是得到child中大的，然后比较child较大的和父节点
void adjustHeap(int* arr, int i, int length) {
	//先取出当前元素i,也就是根节点 
	int temp = arr[i];
	//k在这里是i的左节点，k+1 就是右节点
    for(int k=i*2+1;k<length;k=k*2+1){//从i结点的左子结点开始，也就是2i+1处开始
        //下面这行很经典得到两个child中较大的索引，
		if(k+1<length && arr[k]<arr[k+1]){//如果左子结点小于右子结点，k指向右子结点
            k++;
        }
		//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
        if(arr[k] >temp){
            arr[i] = arr[k];
            i = k;//保留被替换的位置
        }else{
            break;
        }
    }
    arr[i] = temp;//将temp值放到最终的位置
}

void HeapSort(int* arr,int len)
{
	//每次都是操作一个子树
	//初次构建大顶堆，得到最大的元素
	for(int i= len/2-1;i>=0;i--){
		//从第一个非叶子结点从下至上，从右至左调整结构
		adjustHeap(arr,i,len);
    }

	display(arr, len);

	for (int j = len - 1; j > 0 ;j--)
	{
		//通过上面的操作或者本循环的上一次操作 0位置的元素是最大的
		Swap(arr[0], arr[j]);
		display(arr, len);

		//调整的范围越来越往上走
		adjustHeap(arr, 0, j);
		display(arr, len);
	}

}

/*

pivotkey = L[low]；
高位置 往低走 high-- 否则与高位置小元素与低位置交换 
低位置 往高走 low++ 否则与低位置大元素与高位置交换
最后得到的low位置就是L[low] = pivotkey 
*/
int Partition(int *L,int low,int high)
{
	int pivotkey;
	pivotkey = L[low];
	int temp = pivotkey;
	
	while (low < high)
	{
		while (low < high && pivotkey <= L[high] )
		{
			high--;
		}
		// low位置的元素已经在temp中了
		L[low] = L[high];

		while (low < high && L[low] <= pivotkey)
		{
			low++;
		}
		// low位置的元素已经在pivotkey中了
		L[high] = L[low];
	}

	L[low] = temp;
	return low;
}

int Partition2(int *L,int low,int high)
{
	int pivotkey = L[low];
	
	while (low < high)
	{
		while (low < high && pivotkey <= L[high] )
		{
			high--;
		}
		// low位置的元素已经在temp中了
		L[low] = L[high];

		while (low < high && L[low] <= pivotkey)
		{
			low++;
		}
		// low位置的元素已经在pivotkey中了
		L[high] = L[low];
	}

	L[low] = pivotkey;
	return low;
}


template<typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end) 
		return;

    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right) 
			left++;
        while (arr[right] >= mid && left < right) 
			right--;

        std::swap(arr[left], arr[right]);
    }

    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

template<typename T>
void quick_sort(T arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

void QSortDie(int *L,int low,int high)
{
	int pivot;
	while (low < high)
	{
		pivot = Partition(L, low, high);
		QSortDie(L, low, pivot);
		low = pivot + 1;
	}

}


void QSort(int *L, int len)
{
	int low = 0;
	int high = len - 1;
	
	QSortDie(L,low,high);

}

void QSort2(int *L,int low,int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high);
		QSort2(L,low,pivot - 1);
		QSort2(L, pivot + 1, high);
	}
}




#include "DataStructType.h"
//插入的时候就是有序的
void insert(ListNode* head,int val)
{
	//ListNode* dummyNode = nullptr;
	ListNode* newNode = new ListNode(val);
	//head->mNext = newNode;
	ListNode* cur = head;
	while (cur != nullptr && cur->mData <= val)
	{
		if (cur->mNext == nullptr)
		{
			break;
		}
		else 
		{
			cur = cur->mNext;
		}
		
	}
	newNode->mNext = cur->mNext;
	cur->mNext = newNode;
}

void BucketSort()
{
	ListNode* head = new ListNode(0);
	insert(head, 2);
	insert(head, 5);
	insert(head, 3);
	ListNode* curHead = head;

	ListNode* head2 = new ListNode(10);
	insert(head2, 8);
	insert(head2, 1);
	ListNode* curHead2 = head2;
	
	ListNode* merge = new ListNode(0);
	while (curHead2 != nullptr && curHead != nullptr)
	{
		if (curHead2->mData > curHead->mData)
		{
			merge->mNext = curHead;
			curHead = curHead->mNext;

			merge = curHead;
		} 
		else
		{
			merge->mNext = curHead2;
			curHead2 = curHead2->mNext;

			merge = curHead2;
		}
		
	}


	ListNode* cur = merge;
	while (cur != nullptr)
	{
		printf("cur.val = %d\n",cur->mData);
		cur = cur->mNext;
	}
}

void TestSort()
{
	int arr[] = {3,8,2,5,1,6};
	int len = sizeof(arr)/ sizeof(arr[0]);


	selectSort(arr,len);

	//insertion_sort(arr,len);
	//insertSort2(arr, len);

	//bubbleSort(arr,len);
	//shellSort2(arr, len);
	//shellSort3(arr,len);
	//mergeSort

	int* temp = new int[len];
	//MergeSort(arr,len,temp);
	//merge_sort(arr, len);
	//merge_sort2<int>(arr,len);
	
	//HeapSort(arr,len);
	//BucketSort();
//	QSort(arr,6);
	//QSort2(arr,0,5);
	display(arr, len);
	getchar();
	//在 Tree.h TreeSumOfLeftLeaves
}


//RegisterStruct Sort1(&TestSort);