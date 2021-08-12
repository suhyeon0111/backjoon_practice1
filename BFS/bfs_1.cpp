#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

#define MAX_VERTEX_NUM 100

typedef struct{
    int vertexNum;
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}Graph;

int visited[MAX_VERTEX_NUM];

#define MAX_QUEUE_SIZE 20

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message){
    fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType*q){
    q->rear = 0;
    q->front=0;
}

int is_full(QueueType*q){
    return (q->front==(q->rear+1)%MAX_QUEUE_SIZE);
}

// int (QueueType*q){
//     return (is_emptyq->front == q->rear);
// }

void enqueue(QueueType*q, element item){
    if(is_full(q)){
      //  error("큐가 포화상태입니다.");
        return;
    }
    q->rear =(q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear]=item;
}

element dequeue(QueueType*q){
    if(q->front == q->rear){
        //error("큐가 공백 상태");
        return -1;
    }
    q->front=(q->front+1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

Graph* NewGraph(int vNum){
    Graph* graph = (Graph*)malloc(sizeof(Graph)); //메모리 할당
    graph->vertexNum = vNum; //
    memset(graph->adjMatrix, 0, sizeof(int)*MAX_VERTEX_NUM*MAX_VERTEX_NUM); //함수 메모리 초기화

    return graph;
}

void AddEdge(Graph* graph, int start, int end) {
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start]=1;
}
//그래프 출력
void printGraph(Graph *graph){
    for(int i =1;i<= graph->vertexNum;i++){
        for(int j = 1; j<=graph->vertexNum;j++){
            cout<<graph->adjMatrix[i][j];
        }
        cout<<endl;
    }
}

void BFS_Mat(Graph*g, int s){
    QueueType q;
    init_queue(&q);

    for(int i = 1; i<=g->vertexNum; i++) {
        visited[i]=0;
    }
    visited[s]=1;
    cout<<s;
    enqueue(&q, s);
    while (q.front != q.rear){
        int u = dequeue(&q);
        for(int v=1;v<=g->vertexNum;v++){
            if(g->adjMatrix[u][v]==1&&visited[v]==0){
                visited[v]=1;
                cout<<v;
                enqueue(&q,v);
            }
        }
    }
}
int main(){
    Graph *g = NewGraph(8);

    AddEdge(g,1,2);
    AddEdge(g,1,3);
    AddEdge(g,2,4);
    AddEdge(g,2,5);
    AddEdge(g,3,5);
    AddEdge(g,3,7);
    AddEdge(g,3,8);
    AddEdge(g,4,5);
    AddEdge(g,5,6);
    AddEdge(g,7,8);

    printGraph(g);
    cout<<endl<<"BFS: ";
    BFS_Mat(g,1);
}