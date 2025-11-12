#include <iostream>
using namespace std;

long long Catalan(int n){
    if(n <= 1){
        return 1;
    }
    long long res = 0;
    for(int i=0; i<n; i++){
        res += Catalan(i)*Catalan(n-1-i);
    }
    return res;
}

int main(){
    int n;
    cin >>n;
    cout <<Catalan(n);
    return 0;
}