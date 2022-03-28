#include<stdio.h>
#include<stdlib.h>
char ss[100]={0};
typedef  struct symbol
{
	char zifu;
	struct symbol *next;
}symbol;

typedef  struct  symbolsign
{
	symbol *top;
	int	count;
}symbolsign;

void chushihua(symbolsign *Q,symbolsign *Q2)
{
	Q->top=NULL;
	Q->count=0;
	Q2->top=NULL;
	Q2->count=0;
}
void judgment(char a,symbolsign *Q,symbolsign *Q2)
{
	if(a>='0'&&a<='9')
	{
		symbol *New=(symbol *)malloc(sizeof(struct symbol));
		New->next=Q->top;
		New->zifu=a;
		Q->top=New;
		Q->count++;
	}
}
int main()
{
	int m=0;
	int n=0;
	symbolsign *Q;
	Q=(symbolsign *)malloc(sizeof(symbolsign)); 
	symbolsign *Q2;
	Q2=(symbolsign *)malloc(sizeof(symbolsign));
	chushihua(Q,Q2);
	char a=getchar();
	while(a!='\n')
	{
		if(a=='+'||a=='-')
		{
			m=1;
		}
		if(a=='*'||a=='/'||a=='(')
		{
			m=2;
		}
		if(Q2->top->zifu=='+'||Q2->top->zifu=='-')
		{
			n=1;
		}
		if(Q2->top->zifu=='*'||Q2->top->zifu=='/')
		{
			n=2;
		}
		
		if(a>='0'&&a<='9')
		{
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->next=Q->top;
			New->zifu=a;
			Q->top=New;
			Q->count++;
		}
		if(a=='+'||a=='-'||a=='*'||a=='/'||a=='(')
		{
			if(m>n)
			{
				symbol *New2=(symbol *)malloc(sizeof(struct symbol));
				New2->next=Q2->top;
				New2->zifu=a;
				Q2->top=New2;
				Q2->count++;
			}
			if(m<=n)
			{
				symbol *p;
				p=Q2->top; 
				Q2->top=Q2->top->next;
				p->next=Q->top;
				Q->top=p;
				symbol *New=(symbol *)malloc(sizeof(struct symbol));
				New->next=Q->top;
				New->zifu=a;
				Q->top=New;
				Q->count++;
			}
		}
		if(a==')')
		{
			while(Q2->top->zifu!='(')
			{
				symbol *p;
				p=Q2->top;
				Q2->top=Q2->top->next;
				p->next=Q->top;
				Q->top=p;
			}
		}
	}
	while(Q2->top!=NULL)
	{
		symbol *p;
		p=Q2->top;
		Q2->top=Q2->top->next;
		p->next=Q->top;
		Q->top=p;
	}
	symbol *p;
	p=Q->top;
	for(int i=0;i<Q->count+Q2->count;i++)
	{
		symbol *p2;
		p2=p;
		while(p2->next->next!=NULL)
		{
			p2=p2->next;
		}
		if(p2->next->zifu>='0'&&p2->next->zifu<='9')
		{
			p2->next->next=Q2->top;
			Q2->top=p2;
		}
		if(p2->next->zifu=='+')
		{
			int sum;
			sum=(int)Q2->top->zifu+(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
		}
		if(p2->next->zifu=='-')
		{
			int sum;
			sum=(int)Q2->top->zifu-(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
		}
		if(p2->next->zifu=='*')
		{
			int sum;
			sum=(int)Q2->top->zifu*(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
		}
		if(p2->next->zifu=='/')
		{
			int sum;
			sum=(int)Q2->top->zifu/(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
		}
		p2->next=NULL;
	}
	if(Q->top->zifu=='+')
	{
		int sum;
			sum=(int)Q2->top->zifu+(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
	}
	if(Q->top->zifu=='-')
	{
		int sum;
			sum=(int)Q2->top->zifu-(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
	}
	if(Q->top->zifu=='*')
	{
		int sum;
			sum=(int)Q2->top->zifu*(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
	}
	if(Q->top->zifu=='/')
	{
		int sum;
			sum=(int)Q2->top->zifu/(int)Q2->top->next->zifu;
			Q2->top=Q2->top->next->next;
			symbol *New=(symbol *)malloc(sizeof(struct symbol));
			New->zifu=(char)sum;
			New->next=Q2->top;
			Q2->top=New;
	}
	printf("%d",(int)Q2->top->zifu);
	
}                                                                  //暂时还没写注释，因为不知道错在哪了，还得修改一下 

