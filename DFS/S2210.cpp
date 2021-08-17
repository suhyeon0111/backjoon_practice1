#include <iostream>
#include <set>
#include <vector>
using namespace std;
//DFS알고리즘

#define MAX 5
char Matrix[MAX][MAX];
set <string> s; //중복되는 원소 자동 삭제
vector<char> v; 
//루프를 돌면서 한번에 좌표를 바꿔주기 위해서
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};

 
void DFS(int a, int b){
    //6번을 선택하면 종료함
    if(v.size()==6){
        string str = "";
        for (int i =5;i>=0;i--){
            str += v[i]; 
        } 
        s.insert(str);
        
        return;
    }

    //x,y배열을 순환
    for(int i=0; i<4;i++){
        int A = a+x[i];//x의 인덱스
        int B = b+y[i];//y의 인덱스
        if(0<A && A<=MAX && 0<B && B<=MAX){
            //Matrix를 벗어나지 않는다면
            v.push_back(Matrix[A][B]);
            DFS(A, B);
            v.pop_back();
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
            cin>> Matrix[i][j];
        }
    }

    for(int i=1; i<=MAX; i++){
        for(int j=1; j<=MAX; j++){
            v.push_back(Matrix[i][j]);
            DFS(i,j);
            v.pop_back();
        }
    }

    //개수 출력하기
    cout<<s.size()<<endl;
    return 0;
}