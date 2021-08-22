#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

struct state{
    int x, y, z;
};

queue <state> ripe;
int H, N, M;
int tomato[MAX][MAX][MAX];

int dx[6] = {0, 0, 1, 0, 0, -1};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {1, 0, 0, -1, 0, 0};


void BFS(){
    while (!ripe.empty()){
        //익은 토마토(1)의 좌표를 기록 후 큐에서 빼기
        int x = ripe.front().x;
        int y = ripe.front().y;
        int z = ripe.front().z;
        ripe.pop();

        for (int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (0 <= nx && 0 <= ny && 0 <= nz && M > nx && N > ny && H > nz && tomato[nx][ny][nz] == 0){
                //인덱스를 벗어나지 않으면서 안익은 토마토일때(0)
                tomato[nx][ny][nz] = tomato[x][y][z] + 1;
                ripe.push({nx, ny, nz});
            }
        }
    }

    int day = 0; 

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < H; k++){
                if (tomato[i][j][k] == 0){
                    cout << -1;
                    return;
                }
                if (day < tomato[i][j][k]){
                    day = tomato[i][j][k];
                }
            }
        }
    }

    cout << day - 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> H >> N >> M;
    // 좌표로 따지자면 Z, Y, X 순으로 입력

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < H; k++){

                cin >> tomato[i][j][k]; // (X,Y,Z)라고 생각하고 입력
                
                if (tomato[i][j][k] == 1){
                    ripe.push({i, j, k});
                }
            }
        }
    }

    BFS();

}