#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair <int, int> meeting[100000];//끝나는 시간, 시작 시간 둘 다 저장하기 위해서
int N;

int main(){
    cin >> N;
   
    for (int i = 0; i < N; i++){
        cin >> meeting[i].second >> meeting[i].first;
    }

    sort(meeting, meeting+N); // 끝나는 시간으로 오름차순 정렬 

    int t = 0;
    int count = 0; //이미 회의 하나를 선택했기 때문에 1로 시작

    for (int i = 0; i < N; i++){
        if(t <= meeting[i].second){
            t = meeting[i].first;
            count++;
        }
    }

    cout << count;
}