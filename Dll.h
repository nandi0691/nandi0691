#ifndef _DLL_H_ //This will prevent duplicate copying of header file
#define _DLL_H_

typedef struct Node{
	int Data;
	struct Node * pNext;
	struct Node * pPrev;
}node_;

node_ *head_Node;
void CreateHead(int Data);
void AddNode(int data);
void DelNode(int data);
struct Node * getHeadNode();
int getHeadData();
bool isHeadNodeExisting();
void FreeNode(struct Node * node);
void PrintNode();

#endif
