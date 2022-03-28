#include "../test3/zhan.h" 
#include<stdio.h>
#include<stdlib.h>
//链栈

//初始化栈
Status initLStack(LinkStack *s)
{
    s->top=NULL;                                       //初始化的时候栈顶为空 
    s->count=0;                                        //count用来计数，记录栈内有几个数据 
    return SUCCESS;                                    //返回值为1 
};

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
	if(s->top!=NULL)                           //如果栈顶不是空指针则不为空 
	{
		printf("栈不为空\n");
		return ERROR;
	}
	else 
	{
		printf("栈为空\n");
		return SUCCESS;
	}
}
//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top==NULL)                             //如果栈顶是空指针返回0 
	{
		printf("此栈为空栈\n");
		return ERROR;
	}
	else                                         //若栈顶不是空指针 说明栈顶有元素 
	{ 
	*e=s->top->data;                             //将栈顶的元素赋值给指针e指向的地址 
	printf("栈顶元素为%d\n",*e);
	return SUCCESS;	
	} 
}

//清空栈
Status clearLStack(LinkStack *s)
{
	LinkStackPtr out;                            //定义每次清空的节点为out 
	while(s->top!=NULL)                          //若栈顶不为空 则清除栈顶元素 依次循环 
	{
		out=s->top;                              //out节点指向栈顶进行标记 
		s->top=s->top->next;                     //此时栈顶已被标记 所以栈顶向下一位移动，指向下一位节点 
		s->count--;                              //此时栈内节点数-1 
		free(out);                               //清除被标记的节点 
	}
	printf("清空成功\n");
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s)
{
	clearLStack(s);                              //运用上述clearLStack函数来清空栈，使得栈只剩下一个空的栈顶 
	free(s);                                     //此时再把空的栈顶也清除，便是销毁了该栈 
	printf("销毁成功\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length)
{
	*length=s->count;                            //栈的长度只需要根据入栈出栈的次数来统计即可 
	printf("栈长度为%d\n",*length);
	return SUCCESS;                              //入栈和出栈的次数有count来计算 
}

//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	StackNode *New=(StackNode *)malloc(sizeof(StackNode));          //为新的节点创建内存空间 
	if(New==NULL)
	{
		printf("入栈失败\n");
		return ERROR;
	}
	else
	{
		New->data=data;                                             //若创建成功 将要压入栈的数据录入该节点 
		New->next=s->top;                                           //该节点下一节点指向原本的栈顶，成为新的栈顶 
		s->top=New;                                                 //原栈顶的top标记移动到新的栈顶处 
		s->count++;                                                 //count用于计算录入多少个数据 
		printf("入栈成功\n");
		return SUCCESS;
	}
}

//出栈
Status popLStack(LinkStack *s,ElemType *data)
{
	LinkStackPtr out;
	if(s->top==NULL)
	{
		return ERROR;
	}
	else
	{
		out=s->top;                                                 //跟上述清除栈的类似 先用out标记栈顶 
		*data=out->data;                                            //将栈顶数据保存到data指向的地址，避免缺失 
		s->top=s->top->next;                                        //将栈顶往下移动一位，上面的栈顶即将出栈 
		free(out);                                                  //释放原栈顶 
		s->count--;
		printf("出栈成功\n");
		return SUCCESS;
	}
}
int main()
{
	LinkStack *head;
	head=(LinkStack *)malloc(sizeof(struct LinkStack));
	ElemType e;
	int a,length,n;
	printf("请输入压入栈的数字个数:\n");
	scanf("%d",&n);
	initLStack(head);
	Loop:printf("\n");
	printf("1.将1到%d压入栈\n",n);
	printf("2.判断栈是否为空\n");
	printf("3.得到栈顶元素\n");
	printf("4.清空栈\n");
	printf("5.销毁栈\n"); 
	printf("6.检测栈长度\n"); 
	printf("7.出栈\n\n"); 
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
