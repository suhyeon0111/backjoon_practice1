#include <iostream>
using namespace std;

int main(){
    int T; 
    cin>>T;
    int a,b,c;
        if(T%10!=0){
            cout<<-1;
        }   
        else{      
             a = T/300;
             b = (T%300)/60;
             c = ((T%300)%60)/10;
             cout<<a<<' '<<b<<' '<<c;
        }
    return 0;
}