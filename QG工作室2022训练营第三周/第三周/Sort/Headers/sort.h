
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<stdio.h>
#include<string.h>
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
	int i,j,num;
	for(i=1;i<n;i++)            //一共进行n次 
	{
		num=a[i];               //对元素进行逐个标记 
		j=i-1;                  //标记元素位置 
		while(j>=0&&a[j]>num)   //如果a[i-1]>a[i] 则使该部分元素整体后移 
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=num;
	}
};


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i,j,p;                          //定义三个下标 
	i=begin;j=mid+1;p=begin;              //分别标志左头 右头 左头 
	while(i<=mid&&j<=end)                //这里是左右两边数据没有全部比较时，依次进行循环比较 
	{
		if(a[i]<a[j])                   //如果左头<右头 则temp数组的左头位置放小的数 也就是左头的值  以此类推 
		temp[p++]=a[i++];
		else
		temp[p++]=a[j++];
	}
	while(i<=mid)                        //上一步完成时，左边还有数据，则把排好的数据依次放入temp 
	{
		temp[p++]=a[i++];
	}
	while(j<=end)                       //右边还有数据依次放入 temp 
	{
		temp[p++]=a[j++];
	}
	p=begin;
	i=begin;
	while(p<=end)
	{
		a[i++]=temp[p++];               //最后将排序好的temp数组替代原来a数组 
	}
};


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)    //这里是进行递归，将数据依次二分直到只剩下一个数据进行比较 
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
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	if(begin>=end)                      //如果头>尾 直接重开 防止有人乱输入 
	return;
	int L=begin,R=end;                  //定义头尾标记 
	int pivot = a[L];                   //标记头部位置为基准点 
	while(L<R)                          //开始遍历 
	{
		while(L<R&&a[R]>=pivot)         
		{
			R--;	
		}
		if(L<R)                         //上述循环结束时a[R]<pivot 此时a[R] 应该移动到左边 
		{
			a[L]=a[R];	
		}
		while(L<R&&a[L]<=pivot)
		{
			L++;	
		}
		if(L<R)                         //上述循环结束时a[L]>pivot 此时a[L] 应该移动到右边 
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
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size)	;


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
	if(size<2)
	{
	return;
	}
	int count[max+1];               //定义一个桶来计数 
	int i;
	for(i=0;i<size;i++)
	{
		count[a[i]]++;              //记录各数出现次数 
	}
	for(i=1;i<max+1;i++)
	{
		count[i]+=count[i-1];       //计算各数出现累计值 
	}
	int sum[size];                  //创建新数组存放排序完的数据 
	for(i=0;i<size;i++)
	{
		sum[count[a[i]]-1]=a[i];    //通过这个来防止排序完成后的数字位置 
		count[a[i]]--;
	}
	for(i=0;i<size;i++)
	{
		a[i]=sum[i];
	}
};


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
 int GetDigit(int M, int i) //取整数M的第i位数
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
	int allot[10][size];	//分配数组大小 

	memset(allot, 0, sizeof(allot));//初始化分配数组 

	for(i = 1; i <= size; i++)
	{
		//分配相应位数的数据，并存入分配的数组里面 
		for(j = 0; j < size; j++)	
		{			
			digit = GetDigit(a[j], i);
			k = 0;
			while(allot[digit][k])
				k++;
			allot[digit][k] = a[j];
		}
		//将分配的数据依次收集到原数组中
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
		//每次分配，收集后初始化数组，用于下一位数的分配和收集
		memset(allot, 0, sizeof(allot));
	}
}
/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
	int p0,p1,p2;                //p0标记头部位置 p2标记尾部位置 p1对数组进行遍历 
	p0=0;
	p1=0;
	p2=size-1;
	int i;
	for(;p1!=p2;)                //这个循环可以一直遍历直到头部标记与尾部标记重合 
	{
		if(a[p1]==0)             //如果元素是0 则该元素与头部元素互换位置 头标记往后移动一位 
		{
			int t;
			t=a[p1];
			a[p1]=a[p0];
			a[p0]=t;
			p0++;
			p1=p0;
		}
		else if(a[p1]==1)        //如果元素是1，p1继续往后遍历 
		{
			p1++;
		}
		else if(a[p1]==2)        //如果元素是2，则该元素与尾部元素互换位置 尾标记向前移动一位 
		{
			int t;
			t=a[p1];
			a[p1]=a[p2];
			a[p2]=t;
			p2--;
			p1=p0;
		}
	}
	if(p1==p2)                     //当头尾重合时还需要排序一次  才能结束 
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
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */


#endif // QUEUE_H_INCLUDED
