#include <iostream>
#include <queue>
using namespace std;

struct state{
    int x, y; //토마토의 상태 좌표
};

int N, M;
queue <state> ripe;
int tomato[1000][1000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(){
    while(!ripe.empty() ){
        int X = ripe.front().x;
        int Y = ripe.front().y;
        ripe.pop();

        for (int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if (0 <= nx && 0 <= ny && nx < N && ny < M && tomato[nx][ny] == 0 ){
                //인덱스를 벗어나지 않으면서 안익은 토마토일 때
                //queue에 넣어줌
                tomato[nx][ny] = tomato[X][Y] + 1; //안익은 토마토를 익은 토마토로 바꿔줌
                ripe.push({nx, ny}); // 익은 토마토의 인덱스를 큐에 넣어줌
            }
        }
    }

        int day = 0; 
        // 1 1              1 -1
        // 1 0      or      -1 1 을 구별해야 하기에 day를 0을 기준으로 비교해야함 
        //출력은 앞의 경우 1일, 뒤의 경우 0일이므로 일반적인 식으로 쓰자면 day-1 

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (tomato[i][j] == 0){
                    //안익은 토마토가 있을 경우 -1을 출력
                    cout << -1;
                    return;
                }
                if (day < tomato[i][j]){
                    day = tomato[i][j]; //토마토 배열 안에 들어가있는 일수 비교하여 더 큰 것을 삽입
                }
            }
        }
    cout << day - 1;
    return;
}


int main(){
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1){
                ripe.push({i, j}); //index저장
            }
        }
    }
    //입력

    BFS();
  
}