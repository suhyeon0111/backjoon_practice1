#include <iostream>
using namespace std;

int level[100];
int score = 0;


int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> level[i];
    }

    for (int i = N - 1; i > 0; i--){
        if (level[i - 1] >= level[i]){
            score += (level[i - 1] - level[i] + 1);
            level[i - 1] = level[i] - 1;
        }
    }

    cout << score;
}