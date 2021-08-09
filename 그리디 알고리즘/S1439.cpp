#include <iostream>
using namespace std;

string s;
bool k= false;
int count=0;

int main(){
    cin>>s;
    int count=0;

    for(int i = 0; i<s.length(); i++){
        if(s[i] != s[i+1] && k == true){
            count++;
        }
        if(s[i] != s[i+1]){
            k  = !k;
        }
    }
    cout<< count;

}