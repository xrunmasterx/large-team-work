#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/*单向结构体*/
struct Node          
{
	int sum;
  	struct Node *next;
  	struct Node *prior;
} ;
/*单链表创建函数 */
struct Node *creat()                                
{
	int n;
	struct Node *head;                                       //存放头文件
	struct Node *neww;                                       //存放新建的节点
 	struct Node *endd;                                       //存放上一个节点
	head=(struct Node*)malloc(sizeof(struct Node));         //为新建节点开辟新的空间
	head->next=NULL;                                          //先让头文件指向空指针    
	endd=head;                                                
	scanf("%d,&n");                                           //为头节点录入数据 
	while(n>0)                                                //判断头节点数据是否可以录入 
	{
		neww=(struct Node*)malloc(sizeof(struct Node));     //开创新的节点 
		neww->sum=n;                                         //给新节点录入数据 
		neww->next=NULL;                                      //新节点指向下一个地址为空指针 
		endd->next=neww;                                      //上一个节点指向新指针 
		endd=neww;                                            //上一个节点的标记指针向后一个节点移动 
		scanf("%d",&n);                                       //重新输入数据再次判断是否可以录入 
	}
	return head;
}; 
/*双向链表创建*/
struct Node *Tcreat()
{
	int n;
	struct Node *head;                                       //存放头文件
	struct Node *neww;                                       //存放新建的节点
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
	neww->prior=endd;                                         //上面与单链表的创建等同  该处多了一个指向上一节点的操作 
	endd->next=neww;                                          
	endd=neww;
	scanf("%d",&n);
	}
 } 
 /*单链表奇偶调换*/
 void turn(Node *head)
 {
 	struct Node *p1;
 	struct Node *p2;
 	struct Node *p3;
 	/*设节点两两一组，p1标记上一组的末尾节点，p2标记改组节点第一个节点，p3标记下一组第一个节点*/
 	/*若有一链表 0 1 2 3...... 则p1标记0 p2标记1 p3标记3*/
 	p1=head;
	p2=head->next;
	p3=head->next->next->next;
	while(p2->next=NULL)                   //判断该组有效节点数为奇数还是偶数，若p2为NULL则为奇数 
	{
		p1->next=p2->next;                 //0节点的下一个节点指向2节点 
		p2->next->next=p2;                 //2节点的下一个节点指向1节点 
		p2->next=p3;                       //1节点的下一个节点指向 3节点 
		p1=p2;                             //0节点移动到2节点的位置 
		p2=p3;                             //1节点移动到3节点的位置  
		p3=p3->next->next;                 //3节点移动到5节点的位置 
	 } 
 }
 /*找到链表的中点*/
 void middle(Node *head)
 {
 	struct Node *mid;                      //用来标记中间点 
 	struct Node *end;                      //用来标记结尾点 
 	mid=head;
	end=head;
	while(end->next!=NULL)
	{
		mid=mid->next;
		end=end->next->next;
	 } 
	 printf("链表的中间数为%d",mid->sum);
  } 
  /*判断链表是否成环*/
  void cycle(Node *head)
  {
  	struct Node *mid;                      //用来标记中间点 
 	struct Node *end;                      //用来标记结尾点 
 	mid=head;                              
	end=head;                            
	mid=mid->next;                         //mid一次移动一格 
	end=end->next->next;                   //end一次移动两格 
	while(end!=NULL)                       //判断是否成环，若不成环，该函数会结束 若成环，会在下面if判断结束 
	{
	if(mid==end)                           //避免链表成环陷入死循环 
	{
		break;
	}
	mid=mid->next;
	end=end->next->next;
	}
	if(mid==end)                           //判断最后while停止后节点是否相等，若相等则成环，否则不成环 
	printf("成环");
	else
	printf("不成环");
  }
  /*反转链表(非递归)*/
  void rollback(Node *head)
  {
  	struct Node *p1;
 	struct Node *p2;
 	struct Node *p3;
 	/*设有一个链表 （0 1 2 3...） 
 	则 p1标记0节点 p2标记1节点 p3标记3节点 
	 */
	 p1=head;
	 p2=head->next;
	 p3=head->next->next->next;       //先标记3节点，避免3节点的缺失 
	 do
	 {
	 	p2->next->next=p2;            //2节点下一节点指向1节点 
	 	p2->next=p1;                  //1节点下一节点指向0节点 
	 	p1=p3;                        //此时已完成两个节点的逆序，p1标记点向后移动两个节点继续逆序操作 
	 } 
	 while(p3!=NULL);                 //一直逆序操作直到链表末尾 
	 p1->next=NULL;                   //最后将尾节点指向空指针 
  }
  
//void gotoxy(int x,int y)                                                                              //做界面用的光标移动函数 
//{
//	COORD gb;  //windows.h内用于确认光标位置的函数 
//  	gb.X=x;
//  	gb.Y=y;    //定义光标的xy坐标 
//  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),gb);
//}
//  /*开始运行*/
//  int main()
//  {
//  	struct Node *head; 
//  	int choice;
//  	gotoxy(0,0);
//	printf("1.创建单链表");
//	gotoxy(0,1);
//	printf("2.创建双向链表");
//	gotoxy(0,2);
//	printf("3.链表奇偶调换");
//	gotoxy(0,3);
//	printf("4.判断链表是否成环");
//	gotoxy(0,4);
//	printf("5.反转链表");
//	gotoxy(0,5);
//    scanf("%d",&choice);
//	switch(choice)
//	{
//	case 1:
//		gotoxy(0,6);
//		head=creat();
//		printf("链表创建成功"); 
//		break;
//	case 2:
//		head=Tcreat();
//		gotoxy(0,6);
//		printf("链表创建成功"); 
//		break;
//	case 3:
//		if(head!=NULL)
//		turn(head);
//		gotoxy(0,6);
//		printf("链表奇偶调转成功");
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
//		printf("链表逆序成功");
//		break; 
//	}
//   } 
