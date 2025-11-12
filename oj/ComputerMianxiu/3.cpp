#include <iostream>
using namespace std;
int main(){
    int n;
    cin >>n;

    double in[n];
    for(int i=0; i<n; i++){
        cin >>in[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(in[j] < in[j+1]){
                double temp = in[j];
                in[j] = in[j+1];
                in[j+1] = temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout <<in[i] <<' ';
    }
    
    return 0;
}