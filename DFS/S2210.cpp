#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//DFS알고리즘

#define MAX 5
string Matrix[MAX][MAX];
vector <string> s;

//루프를 돌면서 한번에 좌표를 바꿔주기 위해서
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};

 
void DFS(int a, int b,int count, string str){
    string start = Matrix[a][b];

    //6번을 선택하면 종료함
    if(count == 6){
        s.push_back(str);
        return;
    }

    //x,y배열을 순환
    for(int i=0; i<4;i++){
        a = a+x[i];
        b = b+y[i];
        if(a>0 && a<=MAX && b>0 && b<=MAX){
            //Matrix를 벗어나지 않는다면
            count++;
            str = str + Matrix[a][b];
            DFS(a,b,count, str);
        }
    }

        
    
}

int main(){
        
    int A;//입력 변수
    
    //입력 루프
    for(int i=1; i<=MAX ; i++){
        for(int j=1; j<=MAX ; j++){
            cin>>A;
            Matrix[i][j]= A;
        }
    }
    string str;

    for(int i=1; i<=MAX; i++){
        for(int j=1; j<=MAX; j++){
            DFS(i,j,0,str);
        }
    }
    //중복 원소 제거
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    
    //개수 출력하기
    cout<<s.size();
}