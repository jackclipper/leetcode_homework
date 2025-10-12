#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    double temp[n];
    for(int i=0; i<n; i++){
        cin >>temp[i];
    }
    double max = temp[0];
    for(int i=1; i<n; i++){
        if(temp[i] > max){
            max = temp[i];
        }
    }
    cout <<max;
    return 0;
}