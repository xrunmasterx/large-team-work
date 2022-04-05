
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<stdio.h>
#include<string.h>
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
	int i,j,num;
	for(i=1;i<n;i++)            //һ������n�� 
	{
		num=a[i];               //��Ԫ�ؽ��������� 
		j=i-1;                  //���Ԫ��λ�� 
		while(j>=0&&a[j]>num)   //���a[i-1]>a[i] ��ʹ�ò���Ԫ��������� 
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=num;
	}
};


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i,j,p;                          //���������±� 
	i=begin;j=mid+1;p=begin;              //�ֱ��־��ͷ ��ͷ ��ͷ 
	while(i<=mid&&j<=end)                //������������������û��ȫ���Ƚ�ʱ�����ν���ѭ���Ƚ� 
	{
		if(a[i]<a[j])                   //�����ͷ<��ͷ ��temp�������ͷλ�÷�С���� Ҳ������ͷ��ֵ  �Դ����� 
		temp[p++]=a[i++];
		else
		temp[p++]=a[j++];
	}
	while(i<=mid)                        //��һ�����ʱ����߻������ݣ�����źõ��������η���temp 
	{
		temp[p++]=a[i++];
	}
	while(j<=end)                       //�ұ߻����������η��� temp 
	{
		temp[p++]=a[j++];
	}
	p=begin;
	i=begin;
	while(p<=end)
	{
		a[i++]=temp[p++];               //�������õ�temp�������ԭ��a���� 
	}
};


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)    //�����ǽ��еݹ飬���������ζ���ֱ��ֻʣ��һ�����ݽ��бȽ� 
{
	if(begin<end)
	{
		int mid = (begin + end)/2;
		MergeSort(a,begin,mid,temp);
		MergeSort(a,mid+1,end,temp);
		MergeArray(a,begin,mid,end,temp);
	}
};


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	if(begin>=end)                      //���ͷ>β ֱ���ؿ� ��ֹ���������� 
	return;
	int L=begin,R=end;                  //����ͷβ��� 
	int pivot = a[L];                   //���ͷ��λ��Ϊ��׼�� 
	while(L<R)                          //��ʼ���� 
	{
		while(L<R&&a[R]>=pivot)         
		{
			R--;	
		}
		if(L<R)                         //����ѭ������ʱa[R]<pivot ��ʱa[R] Ӧ���ƶ������ 
		{
			a[L]=a[R];	
		}
		while(L<R&&a[L]<=pivot)
		{
			L++;	
		}
		if(L<R)                         //����ѭ������ʱa[L]>pivot ��ʱa[L] Ӧ���ƶ����ұ� 
		{
			a[R]=a[L];	
		}
		if(L>=R)
		{
			a[L]=pivot;	
		}	
	}
	 QuickSort_Recursion(a,begin,R-1);
	 QuickSort_Recursion(a,R+1,end);
};


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size)	;


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{
	int mid;
	if(a[begin]>a[(begin+end)/2])
	{
		mid=a[begin];
		a[begin]=a[(begin+end)/2];
		a[(begin+end)/2]=mid;
	}
	if(a[begin]>a[(begin+end)])
	{
		mid=a[begin];
		a[begin]=a[(begin+end)];
		a[(begin+end)]=mid;
	}
	if(a[(begin+end)/2]<a[(begin+end)])
	{
		mid=a[(begin+end)/2];
		a[(begin+end)/2]=a[(begin+end)];
		a[(begin+end)]=mid; 
	}
};


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
	if(size<2)
	{
	return;
	}
	int count[max+1];               //����һ��Ͱ������ 
	int i;
	for(i=0;i<size;i++)
	{
		count[a[i]]++;              //��¼�������ִ��� 
	}
	for(i=1;i<max+1;i++)
	{
		count[i]+=count[i-1];       //������������ۼ�ֵ 
	}
	int sum[size];                  //����������������������� 
	for(i=0;i<size;i++)
	{
		sum[count[a[i]]-1]=a[i];    //ͨ���������ֹ������ɺ������λ�� 
		count[a[i]]--;
	}
	for(i=0;i<size;i++)
	{
		a[i]=sum[i];
	}
};


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
 int GetDigit(int M, int i) //ȡ����M�ĵ�iλ��
{
	while(i > 1)
	{
		M /= 10;
		i--;
	}
	return M % 10;
}
void RadixCountSort(int *a,int size)
{
	int i, j, k, l, digit;
	int allot[10][size];	//���������С 

	memset(allot, 0, sizeof(allot));//��ʼ���������� 

	for(i = 1; i <= size; i++)
	{
		//������Ӧλ�������ݣ������������������� 
		for(j = 0; j < size; j++)	
		{			
			digit = GetDigit(a[j], i);
			k = 0;
			while(allot[digit][k])
				k++;
			allot[digit][k] = a[j];
		}
		//����������������ռ���ԭ������
		l = 0; 
		for(j = 0; j < 10; j++)	
		{	
			k = 0;
			while(allot[j][k] > 0)
			{
				a[l++] = allot[j][k];
				k++;
			}
		}
		//ÿ�η��䣬�ռ����ʼ�����飬������һλ���ķ�����ռ�
		memset(allot, 0, sizeof(allot));
	}
}
/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
	int p0,p1,p2;                //p0���ͷ��λ�� p2���β��λ�� p1��������б��� 
	p0=0;
	p1=0;
	p2=size-1;
	int i;
	for(;p1!=p2;)                //���ѭ������һֱ����ֱ��ͷ�������β������غ� 
	{
		if(a[p1]==0)             //���Ԫ����0 ���Ԫ����ͷ��Ԫ�ػ���λ�� ͷ��������ƶ�һλ 
		{
			int t;
			t=a[p1];
			a[p1]=a[p0];
			a[p0]=t;
			p0++;
			p1=p0;
		}
		else if(a[p1]==1)        //���Ԫ����1��p1����������� 
		{
			p1++;
		}
		else if(a[p1]==2)        //���Ԫ����2�����Ԫ����β��Ԫ�ػ���λ�� β�����ǰ�ƶ�һλ 
		{
			int t;
			t=a[p1];
			a[p1]=a[p2];
			a[p2]=t;
			p2--;
			p1=p0;
		}
	}
	if(p1==p2)                     //��ͷβ�غ�ʱ����Ҫ����һ��  ���ܽ��� 
	{
		if(a[p1]==0)
		{
			int t;
			t=a[p1];
			a[p1]=a[p0];
			a[p0]=t;
			p0++;
			p1=p0;
		}
		else if(a[p1]==1)
		{
			p1++;
		}
		else if(a[p1]==2)
		{
			int t;
			t=a[p1];
			a[p1]=a[p2];
			a[p2]=t;
			p2--;
			p1=p0;
		}
	}
};


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */


#endif // QUEUE_H_INCLUDED
