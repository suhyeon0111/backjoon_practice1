#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 51

int N,M;// N세로,M가로
char Matrix[MAX][MAX];
int D=1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //입력
    cin>>N>>M;
    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> Matrix[i][j];
        }
    }

    int result = 1; //같은 꼭지점이 한개도 없을 경우를 대비하여 1로 처음 정의
    
    for(int i = 0; i < N ; i++ ){
        for( int j = 0 ; j < M ; j++ ){
              for(int D = 1; D < min(N,M) ; D++ ){    
                if(i + D < N && j + D < M && Matrix[i][j] == Matrix[i][j + D] && Matrix[i][j] == Matrix[i + D][j] && Matrix[i][j] == Matrix[i + D][j + D]){
                    result = max(result, D + 1);   
                }
            }
        }
    }

   result *= result;
   cout << result;

}
