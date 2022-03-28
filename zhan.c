#include "../test3/zhan.h" 
#include<stdio.h>
#include<stdlib.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
    s->top=NULL;                                       //��ʼ����ʱ��ջ��Ϊ�� 
    s->count=0;                                        //count������������¼ջ���м������� 
    return SUCCESS;                                    //����ֵΪ1 
};

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if(s->top!=NULL)                           //���ջ�����ǿ�ָ����Ϊ�� 
	{
		printf("ջ��Ϊ��\n");
		return ERROR;
	}
	else 
	{
		printf("ջΪ��\n");
		return SUCCESS;
	}
}
//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top==NULL)                             //���ջ���ǿ�ָ�뷵��0 
	{
		printf("��ջΪ��ջ\n");
		return ERROR;
	}
	else                                         //��ջ�����ǿ�ָ�� ˵��ջ����Ԫ�� 
	{ 
	*e=s->top->data;                             //��ջ����Ԫ�ظ�ֵ��ָ��eָ��ĵ�ַ 
	printf("ջ��Ԫ��Ϊ%d\n",*e);
	return SUCCESS;	
	} 
}

//���ջ
Status clearLStack(LinkStack *s)
{
	LinkStackPtr out;                            //����ÿ����յĽڵ�Ϊout 
	while(s->top!=NULL)                          //��ջ����Ϊ�� �����ջ��Ԫ�� ����ѭ�� 
	{
		out=s->top;                              //out�ڵ�ָ��ջ�����б�� 
		s->top=s->top->next;                     //��ʱջ���ѱ���� ����ջ������һλ�ƶ���ָ����һλ�ڵ� 
		s->count--;                              //��ʱջ�ڽڵ���-1 
		free(out);                               //�������ǵĽڵ� 
	}
	printf("��ճɹ�\n");
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
	clearLStack(s);                              //��������clearLStack���������ջ��ʹ��ջֻʣ��һ���յ�ջ�� 
	free(s);                                     //��ʱ�ٰѿյ�ջ��Ҳ��������������˸�ջ 
	printf("���ٳɹ�\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	*length=s->count;                            //ջ�ĳ���ֻ��Ҫ������ջ��ջ�Ĵ�����ͳ�Ƽ��� 
	printf("ջ����Ϊ%d\n",*length);
	return SUCCESS;                              //��ջ�ͳ�ջ�Ĵ�����count������ 
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	StackNode *New=(StackNode *)malloc(sizeof(StackNode));          //Ϊ�µĽڵ㴴���ڴ�ռ� 
	if(New==NULL)
	{
		printf("��ջʧ��\n");
		return ERROR;
	}
	else
	{
		New->data=data;                                             //�������ɹ� ��Ҫѹ��ջ������¼��ýڵ� 
		New->next=s->top;                                           //�ýڵ���һ�ڵ�ָ��ԭ����ջ������Ϊ�µ�ջ�� 
		s->top=New;                                                 //ԭջ����top����ƶ����µ�ջ���� 
		s->count++;                                                 //count���ڼ���¼����ٸ����� 
		printf("��ջ�ɹ�\n");
		return SUCCESS;
	}
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{
	LinkStackPtr out;
	if(s->top==NULL)
	{
		return ERROR;
	}
	else
	{
		out=s->top;                                                 //���������ջ������ ����out���ջ�� 
		*data=out->data;                                            //��ջ�����ݱ��浽dataָ��ĵ�ַ������ȱʧ 
		s->top=s->top->next;                                        //��ջ�������ƶ�һλ�������ջ��������ջ 
		free(out);                                                  //�ͷ�ԭջ�� 
		s->count--;
		printf("��ջ�ɹ�\n");
		return SUCCESS;
	}
}
int main()
{
	LinkStack *head;
	head=(LinkStack *)malloc(sizeof(struct LinkStack));
	ElemType e;
	int a,length,n;
	printf("������ѹ��ջ�����ָ���:\n");
	scanf("%d",&n);
	initLStack(head);
	Loop:printf("\n");
	printf("1.��1��%dѹ��ջ\n",n);
	printf("2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("3.�õ�ջ��Ԫ��\n");
	printf("4.���ջ\n");
	printf("5.����ջ\n"); 
	printf("6.���ջ����\n"); 
	printf("7.��ջ\n\n"); 
	scanf("%d",&a);
	printf("\n");
	if(a==1)
	{
		for(e=1;e<=n;e++)
		{
			pushLStack(head,e);
		}
		goto Loop;
	}
	else if(a==7)
		{
			popLStack(head,&e);	
			goto Loop;
		} 
	else if(a==2)
		{
			isEmptyLStack(head);
			goto Loop;
		}
	else if(a==3)
		{
			getTopLStack(head,&e);
			goto Loop;
		}
	else if(a==4)
		{
			LStackLength(head,&length);
			goto Loop;
		}
	else if(a==5)
		{
			clearLStack(head);
			goto Loop;
		}
	else if(a==6)
		{
			destroyLStack(head);
			goto Loop;
		}
	return 0;
}


//#endif 
