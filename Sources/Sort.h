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
        int min = i;//ÿһ��ѭ���Ƚ�ʱ��min���ڴ�Ž�СԪ�ص������±꣬������ǰ���αȽ�������մ�ŵľ��Ǵ�������С��Ԫ�ص��±꣬����ÿ��������СԪ�ض�Ҫ���н�����
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        //���н��������min�����仯������н���
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
ƽ��ʱ�临�Ӷȣ�O(nlogn)
���ʱ�临�Ӷȣ�O(n)
���ʱ�临�Ӷȣ�O(nlogn)
�ռ临�Ӷȣ�O(n)
����ʽ��In-place
�ȶ��ԣ��ȶ�

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

	//���½����кõ�������д��������
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

��������ԭ����������Ҫ���Ǵ�С����
��һ��ô�͹����󶥶ѣ���������һ�ε�����ô����Ԫ�ؾ��ڶ�����С��Ԫ�ؾ���ĩβ�����ʱ����С�����һ����͵õ�һ�δ�С�һ�
�ڶ�������Ԫ�شӵ׵����������϶��ѣ��ٽ����Ѻ�ĩβԪ�ؽ�������Ԫ�ؾ͵���С��λ�ã�Ȼ��ִ�дδ��Ԫ��
���������ڵ�����ӽڵ㣬�ҽڵ� ������ڵ�
����������ṹ�ĵ���
	i
k		k+1

ע������ֻ��forѭ���е�һ��ѭ��ִ�е����ݣ�
����һ��ѭ����������ʱ�ٴ�ִ�У����������
for(int i= len/2-1;i>=0;i--){

int arr[] = {2,4,5,7};
��i= len/2-1 = 1;
��ô�����ĵ�����4��7���л�λ�ã���һ�����ṹͼ��֪���� 
����ǣ�arr[] = {2,7,5,4};
��i = 0ʱ��
����������ļ�齻����ʱ��7��2���н���
arr[] = {7,2,5,4};
������ɺ��������������ζ�����н�����飬Ҳ����2��4 ����
arr[] = {7,4,5,2};

��ô��εĵ��������˽�����Ԫ�غ�ĩβ

����ǵ�һ�εõ��ĵ������
arr[] = {2,4,5,7};

*/

/*
https://zhuanlan.zhihu.com/p/124885051
�����ǽڵ㼰�������ǽڵ�ĵ���

ƽ��ʱ�临�Ӷȣ�O(nlogn)
���ʱ�临�Ӷȣ�O(nlogn)
���ʱ�临�Ӷȣ�O(nlogn)
�ȶ��ԣ����ȶ�

��������ʵҲ��һ��ѡ��������һ������ѡ������
ֻ����ֱ��ѡ�������У�Ϊ�˴�R[1��n]��ѡ������¼��
��Ƚ�n-1�Σ�Ȼ���R[1��n-2]��ѡ������¼��Ƚ�n-2�Ρ�
��ʵ����n-2�αȽ����кܶ��Ѿ���ǰ���n-1�αȽ����Ѿ�������
������ѡ������ǡ���������ε��ص㱣���˲���ǰ��ıȽϽ����
��˿��Լ��ٱȽϴ���������n���ؼ������У�������ÿ���ڵ���Ƚ�log2(n)�Σ�
�����������ʱ�临�Ӷ�Ϊnlogn��
������Ϊ���ȶ����򣬲��ʺϼ�¼���ٵ�����

*/
//�����󶥶ѣ��ȱȽ�����childһ�ǵõ�child�д�ģ�Ȼ��Ƚ�child�ϴ�ĺ͸��ڵ�
void adjustHeap(int* arr, int i, int length) {
	//��ȡ����ǰԪ��i,Ҳ���Ǹ��ڵ� 
	int temp = arr[i];
	//k��������i����ڵ㣬k+1 �����ҽڵ�
    for(int k=i*2+1;k<length;k=k*2+1){//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
        //�������кܾ���õ�����child�нϴ��������
		if(k+1<length && arr[k]<arr[k+1]){//������ӽ��С�����ӽ�㣬kָ�����ӽ��
            k++;
        }
		//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
        if(arr[k] >temp){
            arr[i] = arr[k];
            i = k;//�������滻��λ��
        }else{
            break;
        }
    }
    arr[i] = temp;//��tempֵ�ŵ����յ�λ��
}

void HeapSort(int* arr,int len)
{
	//ÿ�ζ��ǲ���һ������
	//���ι����󶥶ѣ��õ�����Ԫ��
	for(int i= len/2-1;i>=0;i--){
		//�ӵ�һ����Ҷ�ӽ��������ϣ�������������ṹ
		adjustHeap(arr,i,len);
    }

	display(arr, len);

	for (int j = len - 1; j > 0 ;j--)
	{
		//ͨ������Ĳ������߱�ѭ������һ�β��� 0λ�õ�Ԫ��������
		Swap(arr[0], arr[j]);
		display(arr, len);

		//�����ķ�ΧԽ��Խ������
		adjustHeap(arr, 0, j);
		display(arr, len);
	}

}

/*

pivotkey = L[low]��
��λ�� ������ high-- �������λ��СԪ�����λ�ý��� 
��λ�� ������ low++ �������λ�ô�Ԫ�����λ�ý���
���õ���lowλ�þ���L[low] = pivotkey 
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
		// lowλ�õ�Ԫ���Ѿ���temp����
		L[low] = L[high];

		while (low < high && L[low] <= pivotkey)
		{
			low++;
		}
		// lowλ�õ�Ԫ���Ѿ���pivotkey����
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
		// lowλ�õ�Ԫ���Ѿ���temp����
		L[low] = L[high];

		while (low < high && L[low] <= pivotkey)
		{
			low++;
		}
		// lowλ�õ�Ԫ���Ѿ���pivotkey����
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
//�����ʱ����������
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
	//�� Tree.h TreeSumOfLeftLeaves
}


//RegisterStruct Sort1(&TestSort);