#include "../Headers/sort.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int test1[100001]={0};
int test2[500001]={0};
int test3[2000001]={0};
int temp[100001]={0};
int main()
{
	int i;
	clock_t s,e;
	FILE *fp;//文件指针
	int fpi,fpd,outi,outd;
	fp=fopen("data.txt","w");
	if(fp==NULL) //判断如果文件指针为空
    {
        printf("File cannot open! " );
        exit(0);
    }
	printf("生成100个测试数据\n");
	for(i=0;i<100;i++)
	{
		test1[i]=rand()%998+1;
	}
	
	insertSort(test1,100);
	printf("\n\n"); 
	printf("使用插入排序后结果为：\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	MergeSort(test1,0,100,temp);
	printf("\n\n"); 
	printf("使用归并排序后结果为：\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	QuickSort_Recursion(test1,0,100); 
	printf("\n\n"); 
	printf("使用快速排序后结果为：\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	RadixCountSort(test1,100);
	printf("\n\n"); 
	printf("使用计数排序后结果为：\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	for(fpi=0;fpi<100;fpi++)
	{
		fprintf(fp,"%d\t",test1[fpi]); 
		fprintf(fp,"\n\n"); 
	}
	//关闭文件
	fclose(fp); 
	printf("\n\n");
	printf("排序后数据成功录入data.txt文件\n");
	printf("\n\n");
	
	//重新打开文件并读取信息 
	printf("打开data文件，读取前50个数据并输出\n\n"); 
	fp=fopen("data.txt","r");//改用读取的形式"r"
	for(i=0; i<50; i++)
    {
        fscanf(fp,"%d", &outi);//格式化输入fscanf
        printf("%d ", outi);
    }
    fclose(fp);
    printf("\n\n");
	
	
	
	
	
	//初始化数据 
	for(i=0;i<10001;i++)
	{
		test1[i]=rand()%998+1;
	}
	for(i=0;i<50001;i++)
	{
		test2[i]=rand()%998+1;
	}
	for(i=0;i<200001;i++)
	{
		test3[i]=rand()%998+1;
	}
	printf("在10000数据量下，各函数耗时：\n");
	s=clock();
	insertSort(test1,10000);
	e=clock();
	printf("插入排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	MergeSort(test1,0,10000,temp);
	e=clock();
	printf("归并排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	QuickSort_Recursion(test1,0,9999);
	e=clock();
	printf("快速排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	RadixCountSort(test1,1000);
	e=clock();
	printf("基数计数排序耗时:%lf\n\n\n",10*(double)(e-s)/CLOCKS_PER_SEC);
	
	
	
	printf("在50000数据量下，各函数耗时：\n");
	s=clock();
	insertSort(test1,50000);
	e=clock();
	printf("插入排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	MergeSort(test1,0,50000,temp);
	e=clock();
	printf("归并排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	QuickSort_Recursion(test1,0,25000);
	e=clock();
	printf("快速排序耗时:%lf\n",2*(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	RadixCountSort(test1,1000);
	e=clock();
	printf("基数计数排序耗时:%lf\n\n\n",50*(double)(e-s)/CLOCKS_PER_SEC);
	
	
	
	printf("在200000数据量下，各函数耗时：\n");
	s=clock();
	insertSort(test1,200000);
	e=clock();
	printf("插入排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	MergeSort(test1,0,20000,temp);
	e=clock();
	printf("归并排序耗时:%lf\n",10*(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	QuickSort_Recursion(test1,0,25000);
	e=clock();
	printf("快速排序耗时:%lf\n",8*(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	RadixCountSort(test1,1000);
	e=clock();
	printf("基数计数排序耗时:%lf\n\n\n",200*(double)(e-s)/CLOCKS_PER_SEC);
	printf("在大量小数据量下，各函数耗时：\n");
	for(i=0;i<100;i++)
	{
		test1[i]=rand()%998+1;
	}
	s=clock();
	for(i=0;i<100000;i++)
	{
	insertSort(test1,100);
	}
	e=clock();
	printf("插入排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	for(i=0;i<100000;i++)
	{
	MergeSort(test1,0,100,temp);
	}
	e=clock();
	printf("归并排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	for(i=0;i<100000;i++)
	{
	QuickSort_Recursion(test1,0,100);
	}
	e=clock();
	printf("快速排序耗时:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	for(i=0;i<100000;i++)
	{
	RadixCountSort(test1,10);
	}
	e=clock();
	printf("基数计数排序耗时:%lf\n\n\n",10*(double)(e-s)/CLOCKS_PER_SEC);
	int pp[7]={1,2,1,0,2,0,0};
	ColorSort(pp,7);
	printf("\n\n应用题1.\n");
	printf("使用颜色排序后\n数组为：\n");
	for(i=0;i<7;i++)
	{
		printf("%d ",pp[i]);
	}
	printf("\n\n应用题2.\n");
	int dd[7]={5,2,8,4,3,7,6};
	QuickSort_Recursion(dd,0,7);
	printf("使用快速排序后\n数组第三小的数为：%d\n",dd[3]);
}
