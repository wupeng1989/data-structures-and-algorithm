/*********************************************************
 * @auhtor: wupeng
 * @date: 2018-04-22
 * @version: v0.1
 * @desrciption：深入理解图的深度遍历，参考网址：
 * https://www.cnblogs.com/skywang12345/p/3711483.html
 * https://github.com/wangkuiwu/datastructs_and_algorithm
 * /blob/master/source/graph/iterator/udg/c/list_udg.c
 ********************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
int visited[MAXVEX];

/* 边表结点 */
typedef struct EdgeNode
{
    int adjvex; //邻接点域，存储该顶点对应的下标
    struct EdgeNode *next;
}T_EdgeNode;

/* 顶点表结点 */
typedef struct VertexNode
{
    char data; //顶点域，存储顶点信息
    T_EdgeNode *firstedge; //边表头指针
}T_VertexNode, AdjList[MAXVEX];

typedef struct 
{
    T_VertexNode vexs[MAXVEX];  
    int numvertexes; //图中当前的顶点数
    int numedges; //图中当前的边数
}LGraph;


/* 打印邻接图 */
void print_lgraph(LGraph G)
{
    int i, j;
    
     T_EdgeNode *e;
     
     printf("list Graph:\n");
     
     for(i = 0; i < G->numvertexes; i++)
     {
         printf("%d(%c)",i, G.vexs[i].data);
         e =  G.vexs[i].firstedge;
         wile(e != NULL)
         {
             printf("%d(%c) ", e->adjvex, G.vexs[e.adjvex].data);
             e = e->next;
         }
         printf("\n");
     }
    
}


/* 创建邻接表对应的无向图 */
void CreateALGraph (LGraph *G)
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    T_EdgeNode *e;
    
    printf("please input numvertex and numedge:\r\n");
    scanf("%d%d", &(G->numedges), &(G->numvertexes));
    
    /* 建立顶点表 */
    for(i = 0; i < G->numvertexes; i++)
    {
        scanf("%d",&(G->vexs[i]->data));
        G->vexs[i]->firstedge = NULL;
    }
    
    /* 建立边表 */
    for(k = 0; k < G->numedges; k++)
    {
        printf("input (vi,vj):"); //输入边上的顶点序号
        scanf("%d%d", &i, &j);
        
        e = (T_EdgeNode *)malloc(sizeof(T_EdgeNode));
        e->adjvex = j;
        e->next = G->vexs[i].firstedge;
        G->vexs[i].firstedge = e;
        
        e = (T_EdgeNode *)malloc(sizeof(T_EdgeNode));
        e->adjvex = i;
        e->next = G->vexs[j].firstedge;
        G->vexs[j].firstedge = e;
    }
}

/* 深度优先搜索遍历图的递归实现 */
static void DFS(LGraph G, int i)
{
    int w;
    T_EdgeNode *p;
    
    visited[i] = 1;
    printf("%c", G.vexs[i].data); //打印顶点
    
    p = G.vexs[i].firstedge;
    
    while(p)
    {
        if(!visited[p->adjvex])
        {
            DFS(G, p->adjvex)
        }
        
        p = p->next;
    }
}

/* 邻接表的深度遍历操作 */
void DFSTraverse(LGraph G)
{
    int i = 0;
    for(i = 0; i < G.numvertexes, i++)
    {
        visited[i] = { 0 };
    }
    
    for(i = 0; i < G.numvertexes; i++)
    {
        if(!visited[i])
        {
            DFS(G, i);
        }
    }
}


int main(int argc, char **argv)
{
	LGraph pg;
    
    CreateALGraph(&pg);
    print_lgraph(pg);
    
    DFS(pg);
	return 0;
}




