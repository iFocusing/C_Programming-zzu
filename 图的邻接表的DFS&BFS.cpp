#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 50

typedef struct node{
	int adjvex;
	struct node *next;
}EdgeNode;

typedef struct vnode{    // vertex table node;
 	char vertex;
	EdgeNode *firstedge;
}VertexNode;

typedef VertexNode AdjList[MaxVertexNum];

typedef struct{
	AdjList adjlist;//adjacency list;
	int n ,e; 
}ALGraph; //graph type;

//——Establish a graph adjacency list——
void CreatALGraph(ALGraph *G)
{
     	int i,j,k;
     	char a;
     	EdgeNode *s;  // define table node;
     	printf("Please input VertexNum(n) and EdgesNum(e):");
     	scanf("%d%d",&G->n,&G->e);
     	fflush(stdin);
     	printf("Please input Vertex string:");
     	for(i=0;i<G->n;i++)
     	{
     		scanf("%c",&a);
     		G->adjlist[i].vertex=a;
     		G->adjlist[i].firstedge=NULL;
     	}
     	
     	
     	printf("Please input edges,Creat Adjacency list:\n");
     	for(k=0;k<G->e;k++)
     	{
     		scanf("%d%d",&i,&j);
     		s=(EdgeNode *)malloc(sizeof(EdgeNode));
     		s->adjvex=j;
     		s->next=G->adjlist[i].firstedge;
     		G->adjlist[i].firstedge=s;
     		s=(EdgeNode *)malloc(sizeof(EdgeNode));
     		s->adjvex=i;
     		s->next=G->adjlist[j].firstedge;
     		G->adjlist[j].firstedge=s;
         }
 }
 
//==Define symbol vector,it is global variable;==
typedef enum {FALSE,TURE} Boolean;
Boolean visited[MaxVertexNum];

//==Recursive algorithm of DFS==
void DFSM(ALGraph *G,int i)
{
	EdgeNode *p;
	printf("%c",G->adjlist[i].vertex);
	visited[i]=TURE;
	p=G->adjlist[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
		DFSM(G,p->adjvex);
		p=p->next;
	}
}

//==DFS==
void DFS(ALGraph *G)
{
	int i;
	for(i=0;i<G->n;i++)
	  visited[i]=FALSE;
	for(i=0;i<G->n;i++)
	  if(!visited[i])
	  DFSM(G,i);
}

//===BFS====
void BFS(ALGraph *G,int k)
{
	int i,f=0,r=0;
	EdgeNode *p;
	int cq[MaxVertexNum];  //Define FIFO queue;
	for(i=0;i<G->n;i++)
	  visited[i]=FALSE;
    for(i=0;i<G->n;i++)
      cq[i]=-1;   
    printf("%c",G->adjlist[k].vertex);
    visited[k]=TURE;
    cq[r]=k;   // 将访问过的序号入队；
	while(cq[f]!=-1)
	{
		i=cq[f];f=f+1;
		p=G->adjlist[i].firstedge;
		while(p)
		{
			if(!visited[p->adjvex])
			{
				printf("%c",G->adjlist[p->adjvex].vertex);
				visited[p->adjvex]=TURE;
				r=r+1;cq[r]=p->adjvex;
			}
			p=p->next;
		}
	 } 
 }
 
 //=======main function====
int main()
{
 	ALGraph *G;
 	G=(ALGraph *)malloc(sizeof(ALGraph));
 	CreatALGraph(G);
 	printf("Print Graph DFS:");
 	DFS(G);
 	printf("\n");
 	printf("Print Graph BFS:");
 	BFS(G,3);
 	printf("\n");
}

 
 
