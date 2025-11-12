#include <iostream>
#include <string>
using namespace std;

string change(int n){
    if(n == 0){
        return "";
    }
    return change(n/2) + to_string(n%2);
}

int main(){
    int n;
    cin >>n;
    cout <<change(n);
    return 0;
}