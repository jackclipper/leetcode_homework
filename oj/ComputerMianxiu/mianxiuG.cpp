#include <iostream>
using namespace std;

long long factorial(int n, long long s=1){
    if(n==1 || n==0){
        return s;
    }
    s *= n;
    return factorial((n-1), s);
}

int main(){
    int in;
    cin >>in;
    cout <<factorial(in, 1);
    return 0;
}