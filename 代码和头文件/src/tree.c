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
    printf("������10���������������\n");
	for(i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
	//loop:
	loop:printf("1.��������\n2.ɾ������\n3.��������\n4.��������\n5.��������\n");
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("������Ҫ���������\n");
			int k;
			scanf("%d",&k);
			BST_insert(&T,k);
			break;
		case 2:
			printf("������Ҫɾ��������\n");
			int t;
			scanf("%d",&t);
			BST_delete(&T, t);
			break;
		case 3:
			printf("������������\n");
			BST_preorderR(T);
			break;
		case 4:
			printf("������������\n");
			BST_inorderR(T);
			break;
		case 5:
			printf("���к�������\n");
			BST_preorderR(T);
			break;

	}
	goto loop;
    BST_preorderR(T);
    BST_delete(&T, 66);
    BST_preorderR(T);
    
    
}
