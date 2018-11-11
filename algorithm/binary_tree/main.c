/*********************************************************
 * @auhtor: wupeng
 * @date: 2018-04-23
 * @version: v0.1
 * @desrciption：深入理解二叉树，参考网站：
 * https://blog.csdn.net/deaidai/article/details/71834241
 ********************************************************/
 #include <stdio.h>
 typedef struct Node
 {
     char data;
     struct Node *lchild, *rchild;
 }*BiTree, BiTNode;
 
  /******************************************************
  * @function：创建二叉树
  * @pararm: str 字符数组  
  * @pararm：len 字符串长度
  * @description:
*******************************************************/
void CreateBiTree(BiTree *T)
{
    char ch;
    scanf("%c", &ch);
    if(ch == '#')
    {
        T = NULL;
    }
    else
    {
        T =  (BiTree)malloc(sizeof(BiTNode))；
        CreateBiTree(T->lchild );
        CreateBiTree(T->rchild );
    }
}


 /******************************************************
  * @function：前序遍历
  * @pararm: str 字符数组  
  * @pararm：len 字符串长度
  * @description:
*******************************************************/
void PreOrderTraverse(BiTree T)
{
    if(T == NUll)
    {
        return;
    }
    else
    {
        printf("%d ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }    
}





 /******************************************************
  * @function：中序遍历
  * @pararm: str 字符数组  
  * @pararm：len 字符串长度
  * @description:
*******************************************************/

 /******************************************************
  * @function：后序遍历
  * @pararm: str 字符数组  
  * @pararm：len 字符串长度
  * @description:
*******************************************************/

 /******************************************************
  * @function：树的深度
  * @pararm: str 字符数组  
  * @pararm：len 字符串长度
  * @description:
*******************************************************/
int Depth(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    else
    {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m > n)
        {
            return (m+1);
        }
        else
        {
            return (n+1);
        }    
    }
}






int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
