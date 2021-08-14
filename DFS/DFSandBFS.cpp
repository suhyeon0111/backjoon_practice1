#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_VERTEX_NUM 1001
//DFS
//정점 번호 작은 것부터 방문
int N, M, V;//N 정점의 개수 , M 간선의 개수, V 탐색을 시작할 정점의 번호
bool visited[MAX_VERTEX_NUM];//방문 표시
queue<int> q;//큐
stack<int> s;//스택 
int Matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //연결 간선

//방문 초기화
void visited_reset(void){
    for (int i = 1;i <=N;i++){
        visited[i] =0;
    }
}
//DFS알고리즘
void DFS(int start){
    cout<<start<<" ";
        for(int i=1;i<=N;i++){
            if(Matrix[start][i]==1 && visited[i]==0){
                visited[i]=1;
                DFS(i);
            }
        }
}
//BFS알고리즘
void BFS(int start){
    visited_reset();//방문 초기화
    q.push(start);//첫 시작
    visited[start] = 1;//방문표시

    while(!q.empty()){//스택이 빌 때까지 반복
        int start = q.front();
        cout<<start<<" ";//맨 처음 노드 출력
        q.pop();

        for(int i =1;i<=N;i++){
            if(Matrix[start][i]==1 && visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
int main(){
//실행속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>V;

    int a, b;
//인접 행렬 그래프
    for(int i = 0; i<M; i++){
        cin>>a>>b;
        Matrix[a][b] =1;
        Matrix[b][a] = 1;
    }
    
    visited[V]=1;
    DFS(V);
    cout<<endl;
    
    BFS(V);
    cout<<endl;
}      