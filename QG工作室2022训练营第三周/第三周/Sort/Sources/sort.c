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
	FILE *fp;//�ļ�ָ��
	int fpi,fpd,outi,outd;
	fp=fopen("data.txt","w");
	if(fp==NULL) //�ж�����ļ�ָ��Ϊ��
    {
        printf("File cannot open! " );
        exit(0);
    }
	printf("����100����������\n");
	for(i=0;i<100;i++)
	{
		test1[i]=rand()%998+1;
	}
	
	insertSort(test1,100);
	printf("\n\n"); 
	printf("ʹ�ò����������Ϊ��\n");
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
	printf("ʹ�ù鲢�������Ϊ��\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	QuickSort_Recursion(test1,0,100); 
	printf("\n\n"); 
	printf("ʹ�ÿ����������Ϊ��\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	RadixCountSort(test1,100);
	printf("\n\n"); 
	printf("ʹ�ü����������Ϊ��\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",test1[i]);
	}
	
	for(fpi=0;fpi<100;fpi++)
	{
		fprintf(fp,"%d\t",test1[fpi]); 
		fprintf(fp,"\n\n"); 
	}
	//�ر��ļ�
	fclose(fp); 
	printf("\n\n");
	printf("��������ݳɹ�¼��data.txt�ļ�\n");
	printf("\n\n");
	
	//���´��ļ�����ȡ��Ϣ 
	printf("��data�ļ�����ȡǰ50�����ݲ����\n\n"); 
	fp=fopen("data.txt","r");//���ö�ȡ����ʽ"r"
	for(i=0; i<50; i++)
    {
        fscanf(fp,"%d", &outi);//��ʽ������fscanf
        printf("%d ", outi);
    }
    fclose(fp);
    printf("\n\n");
	
	
	
	
	
	//��ʼ������ 
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
	printf("��10000�������£���������ʱ��\n");
	s=clock();
	insertSort(test1,10000);
	e=clock();
	printf("���������ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	MergeSort(test1,0,10000,temp);
	e=clock();
	printf("�鲢�����ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	QuickSort_Recursion(test1,0,9999);
	e=clock();
	printf("���������ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	RadixCountSort(test1,1000);
	e=clock();
	printf("�������������ʱ:%lf\n\n\n",10*(double)(e-s)/CLOCKS_PER_SEC);
	
	
	
	printf("��50000�������£���������ʱ��\n");
	s=clock();
	insertSort(test1,50000);
	e=clock();
	printf("���������ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	MergeSort(test1,0,50000,temp);
	e=clock();
	printf("�鲢�����ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	QuickSort_Recursion(test1,0,25000);
	e=clock();
	printf("���������ʱ:%lf\n",2*(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	RadixCountSort(test1,1000);
	e=clock();
	printf("�������������ʱ:%lf\n\n\n",50*(double)(e-s)/CLOCKS_PER_SEC);
	
	
	
	printf("��200000�������£���������ʱ��\n");
	s=clock();
	insertSort(test1,200000);
	e=clock();
	printf("���������ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	MergeSort(test1,0,20000,temp);
	e=clock();
	printf("�鲢�����ʱ:%lf\n",10*(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	QuickSort_Recursion(test1,0,25000);
	e=clock();
	printf("���������ʱ:%lf\n",8*(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	RadixCountSort(test1,1000);
	e=clock();
	printf("�������������ʱ:%lf\n\n\n",200*(double)(e-s)/CLOCKS_PER_SEC);
	printf("�ڴ���С�������£���������ʱ��\n");
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
	printf("���������ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	for(i=0;i<100000;i++)
	{
	MergeSort(test1,0,100,temp);
	}
	e=clock();
	printf("�鲢�����ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	for(i=0;i<100000;i++)
	{
	QuickSort_Recursion(test1,0,100);
	}
	e=clock();
	printf("���������ʱ:%lf\n",(double)(e-s)/CLOCKS_PER_SEC);
	s=clock();
	for(i=0;i<100000;i++)
	{
	RadixCountSort(test1,10);
	}
	e=clock();
	printf("�������������ʱ:%lf\n\n\n",10*(double)(e-s)/CLOCKS_PER_SEC);
	int pp[7]={1,2,1,0,2,0,0};
	ColorSort(pp,7);
	printf("\n\nӦ����1.\n");
	printf("ʹ����ɫ�����\n����Ϊ��\n");
	for(i=0;i<7;i++)
	{
		printf("%d ",pp[i]);
	}
	printf("\n\nӦ����2.\n");
	int dd[7]={5,2,8,4,3,7,6};
	QuickSort_Recursion(dd,0,7);
	printf("ʹ�ÿ��������\n�������С����Ϊ��%d\n",dd[3]);
}
