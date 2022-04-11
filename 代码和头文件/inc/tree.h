//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType; 

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root; 
} BinarySortTree, *BinarySortTreePtr;

/*typedef struct QueueNode{
	NodePtr data;
	QueueNode *next;
}QueueNode,*pQueueNode;

typedef struct Queue{
	pQueueNode front;
	pQueueNode rear;
}Queue,*pQueue;
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
BST_init(NodePtr p)
{
	p=(NodePtr)malloc(sizeof(struct Node));
};

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr p, ElemType a,NodePtr f,NodePtr *p1)
{
	if(!p)
	{
		*p1=f;
		return false;
	}
	else if(a==p->value)
	{
		*p1=p;
		return true;
	}
	else if(a<p->value)
		return BST_search(p->left,a,p,p1);
	else
		return BST_search(p->right,a,p,p1);
};
/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
 
void BST_insert(NodePtr *p, ElemType a)
{
	NodePtr p1,s;
	if(!BST_search(*p,a,NULL,&p1))
	{
		s=(NodePtr)malloc(sizeof(struct Node));
		s->value=a;
		s->left=s->right=NULL;
		if(!p1)
			*p=s;
		else if(a<p1->value)
			p1->left=s;
		else
			p1->right=s;
	}
	else
		printf("树中已有该元素\n");
};

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
 void Delete(NodePtr *p)
{
    NodePtr q,s;
    if((*p)->right==NULL)      //右边没有子树，以左子树替换
    {
        q=*p;
        *p=(*p)->left;
        free(q);
    }
    else if((*p)->left==NULL)     //左边没有子树   
    {
        q=*p;
        *p=(*p)->right;
        free(q);
    }
    else
    {
        q=*p;
        s=(*p)->left;     //左遍历一次 
        while(s->right)    //右遍历到尾 
        {
            q=s;
            s=s->right;
        }
        (*p)->value=s->value;     //前面替换删除节点
        if(q!=*p)
            q->right=s->left;
        else
            q->left=s->left;
        free(s);
    }
}
void BST_delete(NodePtr *p, ElemType a)
{
	NodePtr p1;
    if(BST_search(*p,a,NULL,&p1))       //找与a相等的元素
    {
        if(a==(*p)->value)
            Delete(p);
        else if(a<(*p)->value)
            BST_delete(&(*p)->left,a);
        else
            BST_delete(&(*p)->right,a);
    }
    else
        printf("抱歉，当前二叉树中没有你要删除的元素。 \n");

	
}
	
/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr p)
{
	NodePtr p1,p2;
	if(p)
	{
		printf("%d\n",p->value);
		p1=p->left;
		BST_preorderR(p1);
		p2=p->right;
		BST_preorderR(p2);
	}
};

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr p, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr p)
{
	NodePtr p1,p2;
	if(p)
	{
		p1=p->left;
		BST_inorderR(p1);
		printf("%d\n",p->value);
		p2=p->right;
		BST_inorderR(p2);
	}
};

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr p)
{
	NodePtr p1,p2;
	if(p)
	{
		p1=p->left;
		BST_postorderR(p1);
		p2=p->right;
		BST_postorderR(p2);
		printf("%d\n",p->value);
	}
};


/*void enqueue(pQueue pq,NodePtr t){
	pQueueNode pNew=(pQueueNode)malloc(sizeof(QueueNode));
	pNew->data=t;
	pNew->next=NULL;
	pq->rear->next=pNew;
	pq->rear=pNew;
}
NodePtr dequeue(pQueue pq){
	pQueueNode pTemp=(pQueueNode)malloc(sizeof(QueueNode));
	pTemp=pq->front->next;
	if(pTemp->next==NULL){
		pq->rear=pq->front;
	}else{
		pq->front->next=pTemp->next;
	}
	NodePtr x=pTemp->data;
	free(pTemp);
	return x;
}


/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr p)
{
	/*pQueue pq=(pQueue)malloc(sizeof(Queue));
	pq->front=pq->front=(pQueueNode)malloc(sizeof(QueueNode));
	pq->front->next=NULL;
	pq->rear=pq->front;
	pQueueNode pNew=(pQueueNode)malloc(sizeof(QueueNode));
	pNew->data=p;
	pNew->next=NULL;
	pq->rear->next=pNew;
	pq->rear=pNew;
	while(pq->rear!=pq->front)
	{
		NodePtr x=dequeue(pq);
		printf("%d ",x->value);
		if(x->left){
			enqueue(pq,x->left);
		}
		if(x->right){
			enqueue(pq,x->right);
		}
	}*/
};


#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
