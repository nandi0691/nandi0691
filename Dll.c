#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"Dll.h"


void CreateHead(int Data)
{
	head_Node = (struct Node *)malloc(sizeof(struct Node));
	head_Node->Data = Data;
	head_Node->pPrev = NULL;
	head_Node->pNext = NULL;	
	printf("Created head node with data %d\n",Data);
}

struct Node * getHeadNode()
{
	return head_Node;
}

int getHeadData()
{
	return head_Node->Data;
}

bool isHeadNodeOnlyExisting()
{
	return (head_Node->pNext == NULL);

}
bool isHeadNodeExisting()
{
	return (head_Node != NULL);
}

void FreeNode(struct Node * node)
{
	free(node);
	node = NULL;
}
void DeleteOnlyHeadNode()
{
	printf("Only head Data found and Deleted %d\n",getHeadData());
	free(head_Node);
	head_Node = NULL;
}

void DeleteHeadNode()
{
	head_Node->pNext->pPrev = NULL;
	head_Node = head_Node->pNext;
	FreeNode(head_Node);
}
void DelNode(int Data)
{
	printf("data delete is requested for %d\n",Data);
	if(getHeadNode() == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	printf("Head Node is present\n");
	struct Node * trNode = getHeadNode();
	bool isDataFound = false;
	//Check and delete head node
	if(getHeadData() == Data)
	{
		printf("you are deleting head node\n");
		isDataFound = true;
		head_Node = trNode->pNext;
		printf("New head node is created\n");
		if(getHeadNode())
		{
			printf("Next node is existing\n");
			head_Node->pPrev = NULL;
		}
		free(trNode);
		trNode = NULL;
		return;
	}
	while(trNode->pNext != NULL)
	{
		if(trNode->Data == Data)
		{
			isDataFound = true;
			struct Node * delNode = trNode;
			delNode->pPrev->pNext = delNode->pNext;
			delNode->pNext->pPrev = delNode->pPrev;
			FreeNode(delNode);
			printf("Data found and Deleted %d\n",Data);
		}
		trNode = trNode->pNext;
	}
	//Check and delete the last Node
	if(trNode->Data == Data)
	{
		isDataFound = true;
		struct Node * delNode = trNode;
		delNode->pPrev->pNext = NULL;
		FreeNode(delNode);
		printf("Data found and Deleted %d\n",Data);
	}
	
	if(!isDataFound)
		printf("Data not found %d\n",Data);
}
void AddNode(int Data)
{
	if(!isHeadNodeExisting())
	{
		CreateHead(Data);		
		return;
	}
	struct Node * MyNode = getHeadNode();
	while(MyNode->pNext != NULL)
	{
		MyNode = MyNode->pNext;
	}
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));
	node->Data = Data;
	printf("Created Node with Data %d\n",Data);
	MyNode->pNext = node;
	node->pNext = NULL;
       	node->pPrev = MyNode;	
}

void PrintNode()
{
	printf("\n\nData is printed as below\nPrev\t\tValue\t\tAddress\t\tNext\n");
	if(!getHeadNode())
	{
		printf("(nil)\t\t(nil)\t\t(nil)\t\t(nil)\n");
		return;
	}

	struct Node * MyNode = getHeadNode();
	while(MyNode->pNext != NULL)
	{
		printf("%p\t\t%d\t\t%p\t\t%p\n",(void*)MyNode->pPrev,MyNode->Data,(void*)MyNode,(void*)MyNode->pNext);
		MyNode = MyNode->pNext;
	}
	printf("%p\t\t%d\t\t%p\t\t%p\n",(void*)MyNode->pPrev,MyNode->Data,(void*)MyNode,(void*)MyNode->pNext);
}
void AddHeadNode(int data)
{
	if(getHeadNode() == NULL)
	{
		CreateHead(data);
		return;
	}	

	struct Node * newHead = (struct Node *)malloc(sizeof(struct Node));
	newHead->Data = data;
	newHead->pNext = getHeadNode();
	newHead->pPrev = NULL;
	getHeadNode()->pPrev = newHead;
	head_Node = newHead;
}
int main()
{
	printf("Main program\n");
	PrintNode();
	AddHeadNode(100);
	PrintNode();
	AddHeadNode(101);
	PrintNode();
}
