//그래프 표현 -인접행렬

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define MAX_VERTEX_NUM 100

typedef struct{
    int vertexNum; //정점의 개수
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //인접행렬
}Graph;

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

int main(){
    Graph*g= NewGraph(6);
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
