#include <iostream>
using namespace std;

int main(){
    char a;
    cin >>a;
    if(a == 'x' || a == 'X'){
        cout <<'A';
        return 0;
    }
    if(a == 'y' || a == 'Y'){
        cout << 'B';
        return 0;
    }
    if(a == 'z' || a == 'Z'){
        cout << 'C';
        return 0;
    }
    if(a > 96 && a <123){
        a-=32;
    }
    if(a > 64 && a <91){
        a+=3;
    }
    cout <<a;
    return 0;
}