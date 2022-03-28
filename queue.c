#include "../test3/queue.h"
#include<stdio.h>
#include<stdlib.h> 
int Length;                                                 //�˱���¼���û�����Ķ�����󳤶�ֵ 
int e,i;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *head;                                             //��ʼ��ʱ�ȴ���ͷ�ڵ㣬ͷ�ڵ㲻������ 
    head=(Node *)malloc(sizeof(struct node));
	head->data=NULL;                                        //ͷ�ڵ���������ָ��NULL 
	head->next=NULL;                                        //�ö��е�ͷ��β��Ƕ�ָ��ͷ�ڵ� 
	Q->front=head;
	Q->rear=head;
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node *p;                                                 //���������������ö���ֻ��һ��ֵ��ֱ���ͷ�Ψһ���Ǹ��ڵ� 
	if(Q->front==Q->rear)
	free(Q->front);
	else                                                     //�����в�ֻ��һ���ڵ㣬���ͷ��ʼ����ͷ�ڵ�һ��һ��ָ����һ���ڵ㣬�����ԭ��ͷ�ڵ�λ�õĽڵ� 
	{                                                        
		while(Q->front!=Q->rear)
		{
			p=Q->front;
			Q->front=p->next;
			free(p);
		}
		free(Q->front);                                      //ֱ�������ͷָ��ָ��βָ��λ�ã��������ָ�� 
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){                           
	if(Q->length==0)                                 //����ͨ��length������������δ¼��ڵ㣬��lengthΪ0 
	{
		printf("����Ϊ��\n");
		return TRUE;
	}
	else                                             //���������Ծɴ��ڽڵ㣬��length��Ϊ0 
	{
		printf("���в�Ϊ��\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */

Status GetHeadLQueue(LQueue *Q, void *e){                 
	if(Q->front!=Q->rear)                                    //��һ������������ֻ��һ���ڵ㣬�����Ԫ�ؾ���ͷָ��ָ���ֵ 
	{
		e=Q->front->data; 
		printf("������Ԫ��Ϊ%d\n",*(int *)e);
		return TRUE;
	}
	else if(Q->front==Q->rear&&Q->front->data!=NULL)         //����ĵڶ������ʱֻ��һ���ڵ㣬������֪���ýڵ��Ƿ�Ϊ�յ� �����ʱ�մ�����δ¼������ʱ��Ϊ�գ� 
	{
		e=Q->front->data;
		printf("������Ԫ��Ϊ%d\n",*(int *)e);
		return TRUE;
	}
	else                                                     //����ͷ�ڵ㲻Ϊ�գ�˵���Ѿ������˵�һ�����ݵ�¼�� 
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){                                 //�ö��еĳ��Ȳ��ܴ����û�����������г���Length
	if(Q->length<Length/*&&Q!=NULL*/)
	printf("���г���Ϊ%d\n",Q->length);
	else                                                     //��Q->length����Lengthʱ��Q->length���������� 
	printf("���г���Ϊ%d\n",Length);
	//if(Q->front==NULL)
	//printf("���г���Ϊ0\n");
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *New;
	if(Q->length<Length)                                          //�����length�ǵ�ǰ¼�����ݸ�������¼�����ݵĸ���ʼ��С�������г��ȣ���ֻ��β������ 
	{
		if(Q->front==Q->rear&&Q->rear->data==NULL)                //�����һ�λ�δ¼������ݣ���һ�����ݽ�¼�뵽ͷ�ڵ����� 
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
	else                                                           //����ʱ��⵽��������ݸ���Ҫ���������г��ȣ����ٶ��������Ժ�β�����ӵ�ͬʱ��ͷ���ڵ�Ҫɾ�� 
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node *Out;
	if(Q->front==Q->rear)                     //����ö���ֻ��һ���ڵ㣬ֱ���ͷŸýڵ� 
	{
	free(Q->front);	
	if(Q->length>0)
	Q->length--;
	} 
	else                                      //�����ֹһ���ڵ㣬��ͷ�ڵ����һλȻ�����ԭ��ͷ�ڵ�λ�õ�ָ�� 
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){                     
	while(Q->front!=Q->rear)
	{
		DeLQueue(Q);                       //�����ֹһ���ڵ� ����Ӧ��������е���� 
	}
	if(Q->length>0)                        //ÿ���һ���ڵ㣬length����-1 
	Q->length--;
	free(Q->front);                        //һֱ�����ֻʣ��һ���ڵ㣬���ͷŵ��ýڵ� 
	free(Q->rear);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	
}

/**                                                                //������ֱ����int main����ȡ���� ��������������ʲô�� 
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
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
	 InitLQueue(Q);                                //�ȴ���һ��Q�ṹ��ָ�� �ٸ�������һ��ռ� ִ�г�ʼ������ 
	 printf("��ʼ���ɹ�\n\n");
	 printf("�����������󳤶�\n");
	 scanf("%d",&Length);                          //�û�¼�������г������� 
	 printf("\n");
	 printf("���г���Ϊ%d\n\n",Length); 
	 printf("\n");
	 printf("�������������ָ�����\n");
	 scanf("%d",&e); 
	 printf("\n");
	 sum=e;                                    
	 for(i=1;i<=sum;i++)                        //����һ��ִ��sum��e���Σ��ֱ������¼�� 
	 {
	 	 datatype[i]=i;
	 	 EnLQueue(Q,&datatype[i]);
	 	 printf("���гɹ�\n");
	 }
	 Loop2:printf("\n");
	 printf("1.�������Ƿ�Ϊ��\n2.�鿴��ͷԪ��\n3.ȷ�϶��г���\n4.���г���\n5.��ն���\n");
	 scanf("%d",&choice);
	 if(choice==1)                                    //�������Ƿ�Ϊ��
	 {
	 	printf("\n");
	 	IsEmptyLQueue(Q);                          
	 	goto Loop2;
	 }
	 else if(choice==2)
	 {
	 	printf("\n");
	 	GetHeadLQueue(Q,&sum);                        //�鿴��ͷԪ��
	 	goto Loop2;
	 }
	 else if(choice==3)
	 {
	 	printf("\n");
	 	LengthLQueue(Q);                              //ȷ�϶��г���
	 	goto Loop2;
	 }
	 else if(choice==4)
	 {
	 	printf("\n");
	 	DeLQueue(Q);                                  //���г���
	 	printf("���ӳɹ�"); 
	 	goto Loop2;
	 }
	 else if(choice==5)
	 {
	 	printf("\n");
	 	ClearLQueue(Q);                               //��ն���
	 	printf("��ն��гɹ�");         
	 	goto Loop2;
	 }
	 else
	 goto Loop2;
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED

