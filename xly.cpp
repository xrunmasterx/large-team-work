#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/*����ṹ��*/
struct Node          
{
	int sum;
  	struct Node *next;
  	struct Node *prior;
} ;
/*������������ */
struct Node *creat()                                
{
	int n;
	struct Node *head;                                       //���ͷ�ļ�
	struct Node *neww;                                       //����½��Ľڵ�
 	struct Node *endd;                                       //�����һ���ڵ�
	head=(struct Node*)malloc(sizeof(struct Node));         //Ϊ�½��ڵ㿪���µĿռ�
	head->next=NULL;                                          //����ͷ�ļ�ָ���ָ��    
	endd=head;                                                
	scanf("%d,&n");                                           //Ϊͷ�ڵ�¼������ 
	while(n>0)                                                //�ж�ͷ�ڵ������Ƿ����¼�� 
	{
		neww=(struct Node*)malloc(sizeof(struct Node));     //�����µĽڵ� 
		neww->sum=n;                                         //���½ڵ�¼������ 
		neww->next=NULL;                                      //�½ڵ�ָ����һ����ַΪ��ָ�� 
		endd->next=neww;                                      //��һ���ڵ�ָ����ָ�� 
		endd=neww;                                            //��һ���ڵ�ı��ָ�����һ���ڵ��ƶ� 
		scanf("%d",&n);                                       //�������������ٴ��ж��Ƿ����¼�� 
	}
	return head;
}; 
/*˫��������*/
struct Node *Tcreat()
{
	int n;
	struct Node *head;                                       //���ͷ�ļ�
	struct Node *neww;                                       //����½��Ľڵ�
 	struct Node *endd;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->prior=NULL;
	head->next=NULL;
	endd=head;
	scanf("%d",&n);
	while(n>0)
	{
	neww=(struct Node*)malloc(sizeof(struct Node));         
	neww->sum=n;
	neww->next=NULL;
	neww->prior=endd;                                         //�����뵥����Ĵ�����ͬ  �ô�����һ��ָ����һ�ڵ�Ĳ��� 
	endd->next=neww;                                          
	endd=neww;
	scanf("%d",&n);
	}
 } 
 /*��������ż����*/
 void turn(Node *head)
 {
 	struct Node *p1;
 	struct Node *p2;
 	struct Node *p3;
 	/*��ڵ�����һ�飬p1�����һ���ĩβ�ڵ㣬p2��Ǹ���ڵ��һ���ڵ㣬p3�����һ���һ���ڵ�*/
 	/*����һ���� 0 1 2 3...... ��p1���0 p2���1 p3���3*/
 	p1=head;
	p2=head->next;
	p3=head->next->next->next;
	while(p2->next=NULL)                   //�жϸ�����Ч�ڵ���Ϊ��������ż������p2ΪNULL��Ϊ���� 
	{
		p1->next=p2->next;                 //0�ڵ����һ���ڵ�ָ��2�ڵ� 
		p2->next->next=p2;                 //2�ڵ����һ���ڵ�ָ��1�ڵ� 
		p2->next=p3;                       //1�ڵ����һ���ڵ�ָ�� 3�ڵ� 
		p1=p2;                             //0�ڵ��ƶ���2�ڵ��λ�� 
		p2=p3;                             //1�ڵ��ƶ���3�ڵ��λ��  
		p3=p3->next->next;                 //3�ڵ��ƶ���5�ڵ��λ�� 
	 } 
 }
 /*�ҵ�������е�*/
 void middle(Node *head)
 {
 	struct Node *mid;                      //��������м�� 
 	struct Node *end;                      //������ǽ�β�� 
 	mid=head;
	end=head;
	while(end->next!=NULL)
	{
		mid=mid->next;
		end=end->next->next;
	 } 
	 printf("������м���Ϊ%d",mid->sum);
  } 
  /*�ж������Ƿ�ɻ�*/
  void cycle(Node *head)
  {
  	struct Node *mid;                      //��������м�� 
 	struct Node *end;                      //������ǽ�β�� 
 	mid=head;                              
	end=head;                            
	mid=mid->next;                         //midһ���ƶ�һ�� 
	end=end->next->next;                   //endһ���ƶ����� 
	while(end!=NULL)                       //�ж��Ƿ�ɻ��������ɻ����ú�������� ���ɻ�����������if�жϽ��� 
	{
	if(mid==end)                           //��������ɻ�������ѭ�� 
	{
		break;
	}
	mid=mid->next;
	end=end->next->next;
	}
	if(mid==end)                           //�ж����whileֹͣ��ڵ��Ƿ���ȣ��������ɻ������򲻳ɻ� 
	printf("�ɻ�");
	else
	printf("���ɻ�");
  }
  /*��ת����(�ǵݹ�)*/
  void rollback(Node *head)
  {
  	struct Node *p1;
 	struct Node *p2;
 	struct Node *p3;
 	/*����һ������ ��0 1 2 3...�� 
 	�� p1���0�ڵ� p2���1�ڵ� p3���3�ڵ� 
	 */
	 p1=head;
	 p2=head->next;
	 p3=head->next->next->next;       //�ȱ��3�ڵ㣬����3�ڵ��ȱʧ 
	 do
	 {
	 	p2->next->next=p2;            //2�ڵ���һ�ڵ�ָ��1�ڵ� 
	 	p2->next=p1;                  //1�ڵ���һ�ڵ�ָ��0�ڵ� 
	 	p1=p3;                        //��ʱ����������ڵ������p1��ǵ�����ƶ������ڵ����������� 
	 } 
	 while(p3!=NULL);                 //һֱ�������ֱ������ĩβ 
	 p1->next=NULL;                   //���β�ڵ�ָ���ָ�� 
  }
  
//void gotoxy(int x,int y)                                                                              //�������õĹ���ƶ����� 
//{
//	COORD gb;  //windows.h������ȷ�Ϲ��λ�õĺ��� 
//  	gb.X=x;
//  	gb.Y=y;    //�������xy���� 
//  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),gb);
//}
//  /*��ʼ����*/
//  int main()
//  {
//  	struct Node *head; 
//  	int choice;
//  	gotoxy(0,0);
//	printf("1.����������");
//	gotoxy(0,1);
//	printf("2.����˫������");
//	gotoxy(0,2);
//	printf("3.������ż����");
//	gotoxy(0,3);
//	printf("4.�ж������Ƿ�ɻ�");
//	gotoxy(0,4);
//	printf("5.��ת����");
//	gotoxy(0,5);
//    scanf("%d",&choice);
//	switch(choice)
//	{
//	case 1:
//		gotoxy(0,6);
//		head=creat();
//		printf("�������ɹ�"); 
//		break;
//	case 2:
//		head=Tcreat();
//		gotoxy(0,6);
//		printf("�������ɹ�"); 
//		break;
//	case 3:
//		if(head!=NULL)
//		turn(head);
//		gotoxy(0,6);
//		printf("������ż��ת�ɹ�");
//		break;
//	case 4:
//		if(head!=NULL)
//		gotoxy(0,6);
//		middle(head);
//		break; 
//	case 5:
//		if(head!=NULL)
//		gotoxy(0,6);
//		cycle(head);
//		break;
//	case 6:
//	if(head!=NULL)
//		rollback(head);
//		gotoxy(0,6);
//		printf("��������ɹ�");
//		break; 
//	}
//   } 
