/*********************************************************
 * @auhtor: wupeng
 * @date: 2018-04-23
 * @version: v0.1
 * @desrciption：深入理解链表，参考网站：
 * https://blog.csdn.net/Lily_whl/article/details/71662133
 * https://blog.csdn.net/a1414345/article/details/52641794
 ********************************************************/
 
  /******************************************************
  * @function：合并两个有序链表
  * @pararm: str 字符数组  
  * @pararm：len 字符串长度
  * @description:
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct NOde
{
    DataType data;
    struct Node *next;
}Node, *PNode;

PNode NewNode(DataType data)
{
    PNode temp = (PNode)malloc (sizeof(Node));
    if(temp)
    {
        temp->data = data;
        temp->next = NULL;
    }
    
    return temp;
}

void PushFront(PNode* pHead, DataType data)
{
    PNode tempNode = NULL;
    assert(pHead);
    if(NULL == pHead)
    {
        *pHead = NewNode(data);
    }
    else
    {
        tempNode = NewNode(data);
        tempNode -> next = *pHead;
        *pHead = tempNode;
    }
}
/* 打印*/
void PirntList(PNode pHead)
{
    while(pHead != NULL)
    {
        printf("%d--> ", pHead->data);
        pHead = pHead->next;
    }
    printf("NULL\r\n");
}

PNode MergeTwoOrderedLists(PNode phead1, PNode phead2)
{
    PNode newhead = NULL;
    
    if(NULL == phead1)
    {
        return phead1;
    }
    if(NULL == phead2)
    {
        return phead2;
    }
    
    if(phead1->data > phead2->data)
    {
        newhead = phead1;
        newhead->next = MergeTwoOrderedLists(phead1->next, phead2);
    }
    else
    {
        newhead = phead2;
        newhead->next = MergeTwoOrderedLists(phead1, phead2->next);
    }
    
    return newhead;
}


int main()
{   
    PNode pHead1 = NULL;
    PNode pHead2 = NULL;
    PNode newHead = NULL;
    
    PushFront(&pHead1, 1);
    PushFront(&pHead1, 3);
    PushFront(&pHead1, 5);
    PushFront(&pHead1, 7);
    
    PushFront(&pHead2, 2);
    PushFront(&pHead2, 4);
    PushFront(&pHead2, 6); 
    PushFront(&pHead2, 8);
    
    PirntList(pHead1);
    PirntList(pHead2);
    
    newHead = MergeTwoOrderedLists(pHead1, pHead2);
    PirntList(newHead);
    return 0;
    
}





