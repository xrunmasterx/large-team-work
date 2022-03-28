#include "../test3/queue.h"
#include<stdio.h>
#include<stdlib.h> 
int Length;                                                 //此变量录入用户输入的队列最大长度值 
int e,i;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *head;                                             //初始化时先创建头节点，头节点不放内容 
    head=(Node *)malloc(sizeof(struct node));
	head->data=NULL;                                        //头节点所有数据指向NULL 
	head->next=NULL;                                        //让队列的头和尾标记都指向头节点 
	Q->front=head;
	Q->rear=head;
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node *p;                                                 //分两种情况，如果该队列只有一个值，直接释放唯一的那个节点 
	if(Q->front==Q->rear)
	free(Q->front);
	else                                                     //若队列不只有一个节点，则从头开始，将头节点一个一个指向下一个节点，再清除原来头节点位置的节点 
	{                                                        
		while(Q->front!=Q->rear)
		{
			p=Q->front;
			Q->front=p->next;
			free(p);
		}
		free(Q->front);                                      //直到清除到头指针指向尾指针位置，再清除该指针 
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){                           
	if(Q->length==0)                                 //可以通过length来计数，若还未录入节点，则length为0 
	{
		printf("队列为空\n");
		return TRUE;
	}
	else                                             //若队列里仍旧存在节点，则length不为0 
	{
		printf("队列不为空\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */

Status GetHeadLQueue(LQueue *Q, void *e){                 
	if(Q->front!=Q->rear)                                    //第一种情况，如果不只有一个节点，则队首元素就是头指针指向的值 
	{
		e=Q->front->data; 
		printf("队列首元素为%d\n",*(int *)e);
		return TRUE;
	}
	else if(Q->front==Q->rear&&Q->front->data!=NULL)         //这里的第二种情况时只有一个节点，不过不知道该节点是否为空的 （如果时刚创建还未录入数据时就为空） 
	{
		e=Q->front->data;
		printf("队列首元素为%d\n",*(int *)e);
		return TRUE;
	}
	else                                                     //若该头节点不为空，说明已经进行了第一次数据的录入 
	{
		printf("队列为空\n");
		return FALSE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){                                 //该队列的长度不能大于用户输入的最大队列长度Length
	if(Q->length<Length/*&&Q!=NULL*/)
	printf("队列长度为%d\n",Q->length);
	else                                                     //当Q->length等于Length时，Q->length不会再增加 
	printf("队列长度为%d\n",Length);
	//if(Q->front==NULL)
	//printf("队列长度为0\n");
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *New;
	if(Q->length<Length)                                          //这里的length是当前录入数据个数，若录入数据的个数始终小于最大队列长度，则只在尾部增加 
	{
		if(Q->front==Q->rear&&Q->rear->data==NULL)                //如果第一次还未录入过数据，第一个数据将录入到头节点里面 
		{
			Q->rear->data=data;
			Q->length++;
		}
		else                                             
		{
			New=(Node *)malloc(sizeof(struct node));
			New->data=data;
			New->next=NULL;
			Q->rear->next=New;
			Q->rear=New;
			Q->length++;
		}
	}
	else                                                           //若此时检测到输入的数据个数要大于最大队列长度，则再队列满了以后尾部增加的同时，头部节点要删除 
	{
			Node *Old;
			New=(Node *)malloc(sizeof(struct node));
			Old=(Node *)malloc(sizeof(struct node));
			New->data=data;
			New->next=NULL;
			Q->rear->next=New;
			Q->rear=New;
			Old=Q->front;
			Q->front=Q->front->next;
			free(Old);
	}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node *Out;
	if(Q->front==Q->rear)                     //如果该队列只有一个节点，直接释放该节点 
	{
	free(Q->front);	
	if(Q->length>0)
	Q->length--;
	} 
	else                                      //如果不止一个节点，则将头节点后移一位然后清除原来头节点位置的指针 
	{
		Out=Q->front;
		Q->front=Q->front->next;
		if(Q->length>0)
		Q->length--;
		free(Out);
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){                     
	while(Q->front!=Q->rear)
	{
		DeLQueue(Q);                       //如果不止一个节点 ，则应用上面队列的清除 
	}
	if(Q->length>0)                        //每清除一个节点，length长度-1 
	Q->length--;
	free(Q->front);                        //一直清除到只剩下一个节点，再释放掉该节点 
	free(Q->rear);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	
}

/**                                                                //我这里直接用int main（）取代了 不清楚这个函数有什么用 
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	
}

int main()
{
	 int choice;
	 int sum;
	 LQueue *Q;
	 Q=(LQueue *)malloc(sizeof(LQueue));
	 InitLQueue(Q);                                //先创建一个Q结构体指针 再给它创建一块空间 执行初始化函数 
	 printf("初始化成功\n\n");
	 printf("请输入队列最大长度\n");
	 scanf("%d",&Length);                          //用户录入最大队列长度数据 
	 printf("\n");
	 printf("队列长度为%d\n\n",Length); 
	 printf("\n");
	 printf("请输入入列数字个数：\n");
	 scanf("%d",&e); 
	 printf("\n");
	 sum=e;                                    
	 for(i=1;i<=sum;i++)                        //这里一共执行sum（e）次，分别把数据录入 
	 {
	 	 datatype[i]=i;
	 	 EnLQueue(Q,&datatype[i]);
	 	 printf("入列成功\n");
	 }
	 Loop2:printf("\n");
	 printf("1.检查队列是否为空\n2.查看队头元素\n3.确认队列长度\n4.进行出队\n5.清空队列\n");
	 scanf("%d",&choice);
	 if(choice==1)                                    //检查队列是否为空
	 {
	 	printf("\n");
	 	IsEmptyLQueue(Q);                          
	 	goto Loop2;
	 }
	 else if(choice==2)
	 {
	 	printf("\n");
	 	GetHeadLQueue(Q,&sum);                        //查看队头元素
	 	goto Loop2;
	 }
	 else if(choice==3)
	 {
	 	printf("\n");
	 	LengthLQueue(Q);                              //确认队列长度
	 	goto Loop2;
	 }
	 else if(choice==4)
	 {
	 	printf("\n");
	 	DeLQueue(Q);                                  //进行出队
	 	printf("出队成功"); 
	 	goto Loop2;
	 }
	 else if(choice==5)
	 {
	 	printf("\n");
	 	ClearLQueue(Q);                               //清空队列
	 	printf("清空队列成功");         
	 	goto Loop2;
	 }
	 else
	 goto Loop2;
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED

