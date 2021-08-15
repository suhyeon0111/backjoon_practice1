#include <iostream>
#include <algorithm>
using namespace std;

int N, L; //N 물이 새는 곳의 개수, L 테이프의 길이

int location[1000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>L;

    for(int i =0;i<N;i++){
        cin>>location[i]; 
    }

    sort(location, location+N);//오름차순 정렬

    int count=1;    

    int start = location[0];

    for(int i =1; i<N;i++){
        if(location[i]-start > L-1){
            start = location[i];
            count++;
        }
    }

cout<<count;//필요한 테이프의 최소 개수
}