//인접리스트
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX_VERTEX_NUM 100

typedef struct node{
    int vertex; //정점의 번호
    struct node* next; 
}Node;

typedef struct{
    int vertexNum;
    Node* adjList[MAX_VERTEX_NUM];
}Graph;

Graph* NewGraph(int vNum){ //vNum은 노드 개수
    Graph* graph = (Graph*)malloc(sizeof(Graph)); //동적 메모리 할당
    graph->vertexNum= vNum;

    for(int i = 0; i<=vNum;i++)
        graph->adjList[i] = NULL;
    
    return graph;
}

void AddEdge(Graph *g, int start, int end){
    Node *newNode  = (Node*)malloc(sizeof(Node));
    newNode->vertex = end;
    newNode->next = g->adjList[start];
    g->adjList[start] = newNode;
}

void printGraph(Graph *graph){
    Node *p;
    for(int i =1;i<=graph->vertexNum;i++){
        p = graph->adjList[i];
        cout<<i<<":";
        while(p != NULL){
            cout <<p->vertex;
            p = p->next;
        }
        cout<<endl;
    }
}

int main(){
    Graph *g = NewGraph(6);
    AddEdge(g,1,2);
    AddEdge(g,1,3);
    AddEdge(g,1,4);
    AddEdge(g,1,6);
    AddEdge(g,2,3);
    AddEdge(g,3,5);
    AddEdge(g,4,6);
    AddEdge(g,5,6);

    printGraph(g);
}