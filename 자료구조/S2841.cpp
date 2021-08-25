#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, P;

stack <int> Strings[7];
pair <int, int> guitar;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;

    int count = 0; //손 움직이는 횟수

    for (int i = 0; i < N; i++){
        cin >> guitar.first >> guitar.second;
  
        if (Strings[guitar.first].empty()){
            Strings[guitar.first].push(guitar.second);
            count++;
            //맨 처음 줄에 손을 올렸을 때
        }

        else {
                if (guitar.second > Strings[guitar.first].top()){
                    //높은 플랫을 눌렀을 때
                    Strings[guitar.first].push(guitar.second);
                    count++;
                }
                
                if (guitar.second == Strings[guitar.first].top()){
                    //같은 플랫을 눌렀을 때
                    continue;
                }

                else{
                    //낮은 플랫을 눌렀을 때
                    while(!Strings[guitar.first].empty() && guitar.second < Strings[guitar.first].top()){
                        //해당 음의 스택이 빌 때까지
                        //낮은 플랫을 눌렀을 때
                        Strings[guitar.first].pop();
                        count++;
                    }
                
                    if (!Strings[guitar.first].empty() && guitar.second == Strings[guitar.first].top()){
                        //기준 플랫과 같은 프랫을 이미 누르고 있을 때
                        continue;
                    }
                    
                    Strings[guitar.first].push(guitar.second);
                    count++;
                }//else문 종료
        }  //else문 종료
    }//for문 종료 
        cout << count;
}
 

