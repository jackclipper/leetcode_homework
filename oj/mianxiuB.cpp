#include <iostream>
using namespace std;

int main(){
    char a;
    cin >>a;
    if(a > 96 && a <123){
        a-=32;
    }
    cout <<a;
    return 0;
}