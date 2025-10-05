#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >>n >>k;
    int num[n];
    for(int i=0; i<n; i++){
        cin >>num[i];
    }
    for(int i=0; i<n; i++){
        if(num[i]==k){
            cout <<i;
            return 0;
        }
    }
    cout <<-1;
    return 0;
}