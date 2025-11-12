#include <iostream>
using namespace std;

long long Fibonacci(int n){
    if(n <= 2){
        return 1;
    }
    long long num = Fibonacci(n-1) + Fibonacci(n-2);
    return num;
}

int main(){
    int n;
    cin >>n;
    cout <<Fibonacci(n);
    return 0;
}