#include <iostream>
using namespace std;

int main(){
int count1 = 0;
int money;
int coin[]={500,100,50,10,5,1};

cin>>money;
money = 1000-money;

for (int i = 0;i<6;i++){
    int count = money / coin[i];
    money = money-(coin[i]*count);
    count1 += count;
    count = 0;
}
    cout << count1;
}