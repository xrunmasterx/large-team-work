#include <stdio.h>
#include"../inc/tree.h"
int main() {
    //printf("Hello, World!\n");
    int i,num;
    NodePtr T=NULL;

    int a[10]={98,64,33,48,64,21,57,89,66,10};
    for(i=0;i<10;i++)
    {
        BST_insert(&T,a[i]);
    }
    printf("如下有10个数，存放如树内\n");
	for(i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
	//loop:
	loop:printf("1.插入数字\n2.删除数字\n3.先序排序\n4.中序排序\n5.后序排序\n");
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("请输入要插入的数字\n");
			int k;
			scanf("%d",&k);
			BST_insert(&T,k);
			break;
		case 2:
			printf("请输入要删除的数字\n");
			int t;
			scanf("%d",&t);
			BST_delete(&T, t);
			break;
		case 3:
			printf("进行先序排序\n");
			BST_preorderR(T);
			break;
		case 4:
			printf("进行中序排序\n");
			BST_inorderR(T);
			break;
		case 5:
			printf("进行后序排序\n");
			BST_preorderR(T);
			break;

	}
	goto loop;
    BST_preorderR(T);
    BST_delete(&T, 66);
    BST_preorderR(T);
    
    
}
