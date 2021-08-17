#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//DFS알고리즘

#define MAX 2
char Matrix[MAX][MAX];
vector <string> s;

//루프를 돌면서 한번에 좌표를 바꿔주기 위해서
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};

 
void DFS(int a, int b,int count, char str[]){
    //6번을 선택하면 종료함
    if(count == 6){
        string str2(str);
        s.push_back(str);
        cout << s.size()<<endl;
        return;
    }

    //x,y배열을 순환
    for(int i=0; i<4;i++){
        int ax = a+x[i];
        int bx = b+y[i];
        if(ax>0 && ax<=MAX && bx>0 && bx<=MAX){
            //Matrix를 벗어나지 않는다면
            count += 1;
            str[count] = Matrix[a][b];
            DFS(a, b, count, str);
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //입력 루프
    for(int i=1; i<=MAX ; i++){
        for(int j=1; j<=MAX ; j++){
            cin>>Matrix[i][j];
        }
    }

    for(int i=1; i<=MAX; i++){
        for(int j=1; j<=MAX; j++){
            char str[]={Matrix[i][j]};
            DFS(i,j,0,str);
        }
    }

    //중복 원소 제거
     sort(s.begin(), s.end());
     s.erase(unique(s.begin(), s.end()), s.end());
    
    //개수 출력하기
    cout<<"개수 출력하기"<<s.size()<<endl;
    return 0;
}