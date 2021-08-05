#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> score[100000];

int main(){
    //실행속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,N;  //
    cin>>T; 
    //테스트 케이스 입력
    for(int j =0; j<T;j++){
        cin>>N;//지원자 수 입력

        for(int i =0;i<N;i++){
            cin >> score[i].first >> score[i].second;//차례로 서류, 면접 등수 입력
        }
        sort(score, score+N);//오름차순 정렬
        
        int count = 1;//1등은 무조건 포함
        int p = score[0].second;//1등을 기준

        for(int i =1;i<N;i++){
            //기준 등수보다 면접 등수가 크면 
            if(p>score[i].second){
                p = score[i].second;//기준등수를 바꿔줌
                count++;//신입사원 채용
            }
        }
        cout<<count<<endl;
        }
 }
   